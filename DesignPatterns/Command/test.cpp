class ICommand{
public:
	virtual void positive() = 0;
	virtual void negative() = 0;
//protected:
};

class Conveyor{
public:
	void on(){
		cout << "on" << endl;
	}
	void off(){
		cout << "off" << endl;
	}
	void increase(){
		cout << "increase" << endl;
	}
	void decrease(){
		cout << "decrease" << endl;
	}
};

class SwitchCommand : public ICommand{
public:
	SwitchCommand(Conveyor* ptr) m_conveyor(ptr){}
	void positive() override{
		m_conveyor->on();
	}
	void negative() override{
		m_conveyor->off();
	}
private:
	Conveyor* m_conveyor;
};

class AdjustCommand : public ICommand{
public:
	AdjustCommand(Conveyor* ptr) m_conveyor(ptr){}
	void positive() override{
		m_conveyor->increase();
	}
	void negative() override{
		m_conveyor->decrease();
	}
private:
	Conveyor* m_conveyor;
};

class Multipult{
public:
	Multipult(){}
	void setCommand(size_t indx, ICommand* ptr){
		m_commands[indx] = ptr;
	}
	void pressOn(size_t indx){
		m_commands[indx]->positive();
	}
	void pressOff(size_t indx){
		m_commands[indx]->negative();
	}
private:
	vector<ICommand*> m_commands;
	stack<ICommand*> m_history
};




















///////////////////////////////////////// TRAFFIC
//
//
class TrafficLight;

class State{
public:
	virtual ~State(){
		delete m_ptr;
	}
	setTrafficLight(TrafficLight* ptr) m_ptr(ptr){}
	virtual void nextState() = 0;
	virtual void previosState() = 0;

protected:
	TrafficLight* m_ptr;
};

class TrafficLight{
public:
	TrafficLight(State* st) m_state(nullptr){
		setState(st);
	}
	void setState(State& st){
		if(m_state != nullptr){
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
	void nextState() override{
		//...
	}
};






///////////////////// ChainOfResponsibility
//
//
class BaseHandler{
public:
	BaseHandler* setHandler(BaseHandler* handler){
		m_ptr = handler;
	}
	virtual void Handler(size_t request) = 0;
	virtual ~BaseHandler(){
		delete m_ptr;
	}
protected:
	BaseHandler* m_ptr;
};

class Handler1 : public BaseHandler{
public:
	void Handler(size_t request) override{
		if(request == 1){
			cout << "handle" << endl;
		}
		else{
			if(m_ptr != nullptr){
				m_ptr->Handler(request);
			}
			else{
				cout << "nullptr" << endl;
				return;
			}
		}
	}
};
