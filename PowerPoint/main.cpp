//#include <iostream>

//#include "PowerPoint.hpp"

#include "pwpt_fileManager.hpp"
#include "cmd_add.hpp"
#include "Slide.hpp"
#include "Group.hpp"
#include "ETypes.hpp"

//#include "readInfo.hpp"

int main(int argc, char* argv[]){
	//PowerPoint::FileManager obj;
	PowerPoint::Triangle ob("objj", EColor::BLACK, EColor::WHITE, 12);
	PowerPoint::Rectangle ob1("myRectangle1", EColor::BLACK, EColor::WHITE, 12);
	PowerPoint::Circle ob2("myCircle1", EColor::BLACK, EColor::WHITE, 12);
	ob.MoveRight(8);
	ob1.MoveRight(9);
	ob2.MoveTop(3);
	ob2.MoveRight(18);
	//ob.
	ob.PrintMe();
	ob1.PrintMe();
	ob2.PrintMe();

	return 0;
}
