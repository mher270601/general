#include <iostream>
#include <string>

class TrafficLight;

class State{
public:
	virtual ~State() {}
	void setTrafficLight(TrafficLight* tl){
		m_trafficLight = tl;
	}
	virtual void nextState() = 0;
	virtual void previousState() = 0;
protected:
	TrafficLight* m_trafficLight;
};

class TrafficLight{
public:
	TrafficLight(State* st) : m_state(nullptr){
		setState(st);
	}
	void setState(State* st){
		if(m_state != nullptr) {
			delete m_state;
		}
		m_state = st;
		m_state->setTrafficLight(this);
	}
	void nextState(){
		m_state->nextState();
	}
	void previousState(){
		m_state->previousState();
	}
private:
	State* m_state;
};

class GreenState : public State{
public:
	void nextState() override;
	void previousState() override{
		std::cout << "Green state" << std::endl;
	}
};

class YellowState : public State{
public:
	void nextState() override;
	void previousState() override{
		std::cout << "Yellow state" << std::endl;
		m_trafficLight->setState(new GreenState());
	}
};

void GreenState::nextState(){
	std::cout << "From green to yellow" << std::endl;
	m_trafficLight->setState(new YellowState());
}

class RedState : public State{
public:
	void nextState() override{
		std::cout << "Red state" << std::endl;
	}
	void previousState() override{
		std::cout << "From green state to yellow" << std::endl;
		m_trafficLight->setState(new YellowState());
	}
};

void YellowState::nextState(){
	std::cout << "From yellow state to red" << std::endl;
	m_trafficLight->setState(new RedState());
}

int main(){
	
	TrafficLight* trafficLight = new TrafficLight(new YellowState());

	trafficLight->nextState();
	trafficLight->nextState();
	trafficLight->previousState();
	trafficLight->previousState();
	trafficLight->previousState();

	delete trafficLight;
	return 0;
}
