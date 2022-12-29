#include <iostream>

class ProviderCommunication{
public:
	void receive(){
		std::cout << "yndunum" << std::endl;
	}
	void payment(){
		std::cout << "vcharum" << std::endl;
	}
};

class Site{
public:
	void placement(){
		std::cout << "texavorum" << std::endl;
	}
	void del(){
		std::cout << "jnjum" << std::endl;
	}
};

class Database{
public:
	void insert(){
		std::cout << "basayum pahel" << std::endl;
	}
	void del(){
		std::cout << "basayic jnjel" << std::endl;
	}
};

class MarketPlace{
public:
	void productReceipt(){
		m_providerCom.receive();
		m_site.placement();
		m_database.insert();
	}
	void productRelease(){
		m_providerCom.payment();
		m_site.del();
		m_database.del();
	}
private:
	ProviderCommunication m_providerCom;
	Site m_site;
	Database m_database;
};

int main(){
	
	MarketPlace marketPlace;

	marketPlace.productReceipt();
	marketPlace.productRelease();

	return 0;
}
