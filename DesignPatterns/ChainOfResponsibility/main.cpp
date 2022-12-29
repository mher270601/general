#include <iostream>
#include <memory>

class BaseHandler{
public:
	BaseHandler* SetNext(BaseHandler* handler){
		m_ptr = handler;
		return m_ptr;
	}

	virtual void Handler(size_t Request) = 0;
	virtual ~BaseHandler(){
		delete m_ptr;
	}
protected:
	BaseHandler* m_ptr;
};

class Handler1 : public BaseHandler{
public:
	void Handler(size_t Request) override {
		if(Request == 1){
			std::cout << "Handler 1" << std::endl;
		}
		else{
			if(m_ptr != nullptr){
				m_ptr->Handler(Request);
			}
			else{
				std::cout << "Nullptr" << std::endl;
				return;
			}
		}
	}
private:
};

class Handler2 : public BaseHandler{
public:
	void Handler(size_t Request) override {
		if(Request == 2){
			std::cout << "Handler 2" << std::endl;
		}
		else{
			if(m_ptr != nullptr){
				m_ptr->Handler(Request);
			}
			else{
				std::cout << "Nullptr" << std::endl;
				return;
			}
		}
	}
private:
};

class Handler3 : public BaseHandler{
public:
	void Handler(size_t Request) override {
		if(Request == 3){
			std::cout << "Handler 3" << std::endl;
		}
		else{
			if(m_ptr != nullptr){
				m_ptr->Handler(Request);
			}
			else{
				std::cout << "Nullptr" << std::endl;
				return;
			}
		}
	}
private:
};

int main(){
	
	Handler1* h1 = new Handler1;
	Handler2* h2 = new Handler2;
	Handler3* h3 = new Handler3;
	h1->SetNext(h2)->SetNext(h3);
	// h1->SetNext(h2)h2
	h1->Handler(1);
	h1->Handler(3);	
	h1->Handler(4);	

	return 0;
}
