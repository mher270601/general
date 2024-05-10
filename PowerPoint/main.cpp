//#include <iostream>

//#include "PowerPoint.hpp"

#include <memory>

#include "pwpt_fileManager.hpp"
#include "cmd_add.hpp"
#include "Slide.hpp"
#include "Group.hpp"
#include "ETypes.hpp"

//#include "readInfo.hpp"

int main(int argc, char* argv[]){
	PowerPoint::FileManager& fm = PowerPoint::FileManager::GetInstance();
	fm.GetData();
	std::cout << "CURRENT PRINT <->" << std::endl;
	//PowerPoint::FileManager obj;
	PowerPoint::Triangle ob("objj", EColor::BLACK, EColor::WHITE, 12);
	PowerPoint::Rectangle ob1("myRectangle1", EColor::BLACK, EColor::WHITE, 12);
	PowerPoint::Circle ob2("myCircle1", EColor::BLACK, EColor::WHITE, 12);
	ob.MoveRight(8);
	ob1.MoveRight(9);
	ob2.MoveTop(3);
	ob2.MoveRight(18);
	
	std::shared_ptr<PowerPoint::Triangle> obTr = std::make_shared<PowerPoint::Triangle>("objj11", EColor::BLACK, EColor::WHITE, 12);
	std::shared_ptr<PowerPoint::Rectangle> obRc = std::make_shared<PowerPoint::Rectangle>("Reccc222", EColor::BLACK, EColor::WHITE, 16);
	std::shared_ptr<PowerPoint::Circle> obCr = std::make_shared<PowerPoint::Circle>("Circleee222", EColor::BLACK, EColor::WHITE, 16);

	// PowerPoint::Groups
	PowerPoint::Group group1("group11");
	group1.AddObject(obTr);
	group1.AddObject(obRc);
	//group1.AddObject(obCr);
	std::cout << "Groups ----->\n" << std::endl;
	group1.SetSize(23);
	group1.PrintMe();
	std::cout << "\nStart removing\n" << std::endl;
	//group1.RemoveObject(obTr);
	group1.RemoveObject(obCr);
	group1.PrintMe();
	std::cout << "End groups ----->\n\n" << std::endl;
	//ob.
	ob.PrintMe();
	ob1.PrintMe();
	ob2.PrintMe();

	return 0;
}
