#include <iostream>
#include <string>
#include <map>

class ISite{
public:
	virtual std::string getPage(const int& num) = 0;
	virtual ~ISite() {}
};

class Site : public ISite{
public:
	std::string getPage(const int& num) override{
		std::string page = "This page of site " + std::to_string(num);
		return page;
	}
};

class SiteProxy : public ISite{
public:
	SiteProxy(ISite* site) : m_site(site) {}
	~SiteProxy(){
		delete m_site;
	}

	std::string getPage(const int& num) override{
		std::string page;
		if(m_cache.find(num) == m_cache.end()){
			page = m_site->getPage(num);
			m_cache[num] = page;
		}
		else{
			page = m_cache[num];
			page.insert(0, "from cache: ");
		}
		return page;
	}
private:
	ISite* m_site;
	std::map<int, std::string> m_cache;
};

int main(){
	
	ISite* mySite = new SiteProxy(new Site());

	std::cout << mySite->getPage(1) << std::endl;
	std::cout << mySite->getPage(2) << std::endl;
	std::cout << mySite->getPage(3) << std::endl;

	std::cout << mySite->getPage(2) << std::endl;

	return 0;
}
