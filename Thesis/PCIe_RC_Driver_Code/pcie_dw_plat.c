// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2025 Synopsys, Inc.
 *
 * Author: Mher Tadevosyan <tmher@synopsys.com>
 *
 * Based on:
 *   - drivers/pci/pcie_dw_ti.c
 */

#include <stdio.h>
#include <linux/bitfield.h>
#include <common.h>
#include <dm.h>
#include <pci.h>
#include <asm/global_data.h>
#include <linux/bitops.h>
#include <power-domain.h>
#include <asm/io.h>
#include <dm/device_compat.h>
#include <dm/device.h>
#include <asm/io.h>
#include <p2sb.h>

#include "pcie_dw_common.h"
        
DECLARE_GLOBAL_DATA_PTR;

#define PLR_OFFSET                      0x700
#define PCIE_PORT_DEBUG0                (PLR_OFFSET + 0x28)
#define PORT_LOGIC_LTSSM_STATE_MASK     0x1f
#define PORT_LOGIC_LTSSM_STATE_L0       0x11

#define PCIE_LINK_UP_TIMEOUT_MS         100

/**
 * struct pcie_dw_plat - SNPS DW PCIe controller state
 *
 * @pci: The common PCIe DW structure
 */
struct pcie_dw_plat {
        /* Must be first member of the struct */
        struct pcie_dw dw;
};

/**
 * pcie_dw_of_to_plat() - Translate from DT to device state
 *
 * @dev: A pointer to the device being operated on
 *
 * Translate relevant data from the device tree pertaining to device @dev into
 * state that the driver will later make use of. This state is stored in the
 * device's private data structure.
 *
 * Return: 0 on success, else -EINVAL
 */
static int pcie_dw_of_to_plat(struct udevice *dev)
{
        struct pcie_dw_plat *pcie = dev_get_priv(dev);

	/* Get the controller base address */	
	pcie->dw.dbi_base = (void *)dev_read_addr_name(dev, "dbi");
	if((fdt_addr_t)pcie->dw.dbi_base == FDT_ADDR_T_NONE){
		return -EINVAL;
	}

	/* Get the config space base address and size */
	pcie->dw.cfg_base = (void *)dev_read_addr_size_name(dev, "config", &pcie->dw.cfg_size);
	if((fdt_addr_t)pcie->dw.cfg_base == FDT_ADDR_T_NONE){
		return -EINVAL;
	}

	/* Get the iATU base address and size */
	pcie->dw.atu_base = (void *)dev_read_addr_name(dev, "atu");
	if((fdt_addr_t)pcie->dw.atu_base == FDT_ADDR_T_NONE){
		return -EINVAL;
	}

        return 0;
}

/**
 * is_link_up() - Return the link state
 *
 * @regs_base: A pointer to the PCIe DBI registers
 *
 * Return: 1 (true) for active line and 0 (false) for no link
 */
static int is_link_up(struct pcie_dw_plat *pci)
{
        u32 val;

        val = readl(pci->dw.dbi_base + PCIE_PORT_DEBUG0);
        val &= PORT_LOGIC_LTSSM_STATE_MASK;

        return (val == PORT_LOGIC_LTSSM_STATE_L0);
}

/**
 * pcie_dw_plat_probe() - Probe the PCIe bus for active link
 *
 * @dev: A pointer to the device being operated on
 *
 * Probe for an active link on the PCIe bus and configure the controller
 * to enable this port.
 *
 * Return: 0 on success, else -ENODEV
 */
static int pcie_dw_plat_probe(struct udevice *dev)
{
	struct pcie_dw_plat *pci = dev_get_priv(dev);
	struct udevice *ctlr = pci_get_controller(dev);
	struct pci_controller *hose = dev_get_uclass_priv(ctlr);

	if(device_get_uclass_id(dev) != UCLASS_PCI){
		dev_err(dev, "invalid uclass id\n");
		return -ENODEV;
	} 

	pci->dw.first_busno = dev_seq(dev);
	pci->dw.dev = dev;

	if(!is_link_up(pci)){
		printf("PCIE-%d: Link down!\n", dev_seq(dev));
		return -ENODEV;
	}

	pcie_dw_setup_host(&pci->dw);
	printf("PCIE: successfully configured as host\n");

        printf("PCIE-%d: Link up (Gen%d-x%d, Bus%d)\n", dev_seq(dev),
               pcie_dw_get_link_speed(&pci->dw),
               pcie_dw_get_link_width(&pci->dw),
               hose->first_busno);

        pcie_dw_prog_outbound_atu_unroll(&pci->dw, PCIE_ATU_REGION_INDEX0,
                                         PCIE_ATU_TYPE_MEM,
                                         pci->dw.mem.phys_start,
                                         pci->dw.mem.bus_start, pci->dw.mem.size);
	
	return 0;
}

static const struct udevice_id pcie_dw_plat_of_match[] = {
	{ .compatible = "snps,dw-pcie" }
};

static const struct dm_pci_ops pcie_dw_ops = {
	.read_config	= pcie_dw_read_config,
	.write_config	= pcie_dw_write_config,
};

U_BOOT_DRIVER(pcie_dw_plat) = { 
        .name                   = "pcie_dw_plat", 
        .id                     = UCLASS_PCI,
	.of_match		= pcie_dw_plat_of_match,
        .probe                  = pcie_dw_plat_probe,
	.ops			= &pcie_dw_ops,
	.of_to_plat     	= pcie_dw_of_to_plat,
	.priv_auto		= sizeof(struct pcie_dw_plat),
}; 
