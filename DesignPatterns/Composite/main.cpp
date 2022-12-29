#include <iostream>

#include "PowerPoint.hpp"

int main(){
	PowerPoint::IAttributeModifier::IObjectPtr p1 = std::make_shared<PowerPoint::Text>("Synopsys", Color::Black, Color::White, 2);
	PowerPoint::IAttributeModifier::IObjectPtr p2 = std::make_shared<PowerPoint::Rectangle>(Color::Black, Color::White, 2);

	PowerPoint::Group::GroupPtr g1 = std::make_shared<PowerPoint::Group>();
	g1->AddGroup(p1);
	PowerPoint::Group::GroupPtr g2 = std::make_shared<PowerPoint::Group>();
	g2->AddGroup(p2);
	g1->AddGroup(g2);
	g1->PrintMe();
	return 0;
}
