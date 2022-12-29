#include <iostream>
#include <string>

class Game{
public:
	static Game& getInstance(){
		static Game ob;
		return ob;
	}
	void Print_String(){
		std::cout << m_expr << std::endl; 
	}
	void Print_Int(){
		std::cout << m_int << std::endl;
	}
	void Incr(){
		++m_int;
	}
private:
	Game() = default;
	int m_int = 10;
	std::string m_expr = "My Game Class";
};
int main(){
	Game myGame1 = Game::getInstance();	
	Game myGame2 = Game::getInstance();
	myGame1.Print_String();
	myGame2.Print_Int();
	myGame1.Incr();
	myGame1.Print_Int();
	std::cout << &myGame1 << "  " << &myGame2 << std::endl;
	return 0;
}
