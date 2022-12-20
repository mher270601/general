#ifndef __ERRORS__CPP__
#define __ERRORS__CPP__
#include <exception>
#include <string>

class Invalid_function_decl : public std::exception{
	public:
		explicit Invalid_function_decl(std::string what_arg) : m_s_message(what_arg) {}
		//Invalid_function_decl(char* what_arg) : m_c_message(what_arg) {}
		~Invalid_function_decl() =default;
		std::string what(){
			return m_s_message;
		}
	private:
		//const char* m_c_message{nullptr};
		std::string m_s_message;
};

#endif // __ERRORS__CPP__
