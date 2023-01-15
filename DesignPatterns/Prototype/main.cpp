#include <iostream>
#include <string>

class Animal{
public:
	virtual void setName(std::string* name){}
	virtual std::string getName() = 0;
	virtual Animal* clone() const = 0;
};

class Sheep : public Animal{
public:
	Sheep() = default;
	~Sheep(){
		delete m_name;
	}	
	void setName(std::string* name) override{
		m_name = name;
	}
	std::string getName() override{
		return *m_name;
	}
	Sheep* clone() const override{
		return new Sheep(*this);
	}
private:
	Sheep(const Sheep& donor) {
		this->m_name = donor.m_name;
	}
private:
	std::string* m_name;
};

int main(){
	Sheep* sheepDonor = new Sheep();
	std::string name = "Dolli";
	sheepDonor->setName(&name);

	Sheep* sheepClone = sheepDonor->clone();
	std::cout << sheepDonor->getName() << std::endl;
	std::cout << sheepClone->getName() << std::endl;
	return 0;
}
