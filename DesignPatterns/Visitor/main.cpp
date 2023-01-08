#include <iostream>
#include <string>

class Zoo;
class Cinema;
class Circus;

class IVisitor{
public:
	virtual void visit(Zoo& ref) = 0;
	virtual void visit(Cinema& ref) = 0;
	virtual void visit(Circus& ref) = 0;

	virtual ~IVisitor() = default;
};

class Place{
public:
	virtual void accept(IVisitor& v) = 0;

	virtual ~Place() = default;
};

class Zoo : public Place{
	void accept(IVisitor& v) override{
		v.visit(*this);
	}
};

class Cinema : public Place{
	void accept(IVisitor& v) override{
		v.visit(*this);
	}
};

class Circus : public Place{
	void accept(IVisitor& v) override{
		v.visit(*this);
	}
};

class HolidayMaker : public IVisitor{
public:
	void visit(Zoo& ref) override{
		m_value = "In zoo";
	}
	void visit(Cinema& ref) override{
		m_value = "In cinema";
	}
	void visit(Circus& ref) override{
		m_value = "In circus";
	}
public:
	std::string m_value;
};

int main(){
	Zoo zoo;
	Cinema cinema;
	Circus circus;

	Place* places[] = {&zoo, &cinema, &circus};

	for(auto place : places){
		HolidayMaker visitor;
		place->accept(visitor);
		std::cout << visitor.m_value << std::endl;
	}
}
