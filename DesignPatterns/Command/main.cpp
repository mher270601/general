#include <iostream>

#include "Command.hpp"

int main(){
	Conveyor* conveyor = new Conveyor();
	
	Multipult* multipult = new Multipult();
	multipult->setCommand(0, new ConveyorWorkCommand(conveyor));
	multipult->setCommand(1, new ConveyorAdjustCommand(conveyor));
	multipult->setCommand(10, new ConveyorAdjustCommand(conveyor));

	multipult->pressOn(0);
	multipult->pressOn(1);
	multipult->pressCancel();
	multipult->pressCancel();

	return 0;
}
