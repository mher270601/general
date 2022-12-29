#include <iostream>

#include "adapter.hpp"

int main()
{
    float dram = 55;

    exchangeRate* amd = new ArmenianRate(dram);
    exchangeRate* usd = new AdapterForUSARate(USARate(55));

    std::cout << amd->getValue() << " dram" << std::endl; // dram
    std::cout << usd->getValue() << " (55dolar) in dram" << std::endl; // dram

    delete amd;
    delete usd;

    return 0;
}
