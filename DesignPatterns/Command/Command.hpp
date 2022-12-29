#ifndef __COMMAND__HPP__
#define __COMMAND__HPP__

#include <iostream>
#include <vector>
#include <stack>

class ICommand{
public:
	virtual void positive() = 0;
	virtual void negative() = 0;
};

class Conveyor{
public:
	void on(){
		std::cout << "is ON" << std::endl;
	}
	void off(){
		std::cout << "is OFF" << std::endl;
	}
	void speedIncrease(){
		std::cout << "Speed is increased" << std::endl;
	}
	void speedDecrease(){
		std::cout << "Speed is decreased" << std::endl;
	}
};

class ConveyorWorkCommand : public ICommand{
public:
	ConveyorWorkCommand(Conveyor* conveyor) : m_conveyor(conveyor) {}
	void positive() override {
		m_conveyor->on();
	}
	void negative() override {
		m_conveyor->off();
	}
private:
	Conveyor* m_conveyor;
};

class ConveyorAdjustCommand : public ICommand{
public:
	ConveyorAdjustCommand(Conveyor* conveyor) : m_conveyor(conveyor) {}
	void positive() override {
		m_conveyor->speedIncrease();
	}
	void negative() override {
		m_conveyor->speedDecrease();
	}
private:
	Conveyor* m_conveyor;
};

class Multipult{
public:
	Multipult(){
		m_commands.resize(2);
	}
	void setCommand(int button, ICommand* command){
		m_commands[button] = command;
	}
	void pressOn(int button){
		m_commands[button]->positive();
		m_history.push(m_commands[button]);
	}
	void pressCancel(){
		if(!m_history.empty()){
			m_history.top()->negative();
			m_history.pop();
		}
	}
private:
	std::vector<ICommand*> m_commands;
	std::stack<ICommand*> m_history;
};

#endif // __COMMAND__HPP__
