#ifndef __PARSE__EXPRESSION__VAR_OR_FUNC__HPP__
#define __PARSE__EXPRESSION__VAR_OR_FUNC__HPP__

#include <cassert>
#include <cstring>
#include <sstream>
#include <utility>
#include <vector>

#include "helpers.hpp"
#include "TokenType.hpp"

enum symType{
	VAR,
	FUNCTION
};

class SymbolTable{
	public:
		SymbolTable();
		~SymbolTable() =default;
		void InsertVar(const std::string& expr, const int& value = 0);
		void InsertFunc(const std::string& funcName, std::vector<std::string> argsNames, const size_t& argsCount, Node* tree);
		int getVarAddress(const std::string& exprName) const;
		int generateFunc(const std::string& funcDecl) const;
		int Size() const noexcept;
		bool checkFuncSurv(const std::string& fName) const noexcept;
		std::vector<int> data; 
	private:
		int m_size{0};
		using funcType = std::vector<std::pair<std::string, size_t>>; // funcName, argc
		std::vector<std::vector<std::string>> fArgs;
		funcType funcTable;
		std::vector<Node*> fTree;

		class Symbol{
		public:
			std::string name;
			size_t m_symIndx;
			Symbol(const std::string& expr, const size_t& symIndx) : name {expr},
						  		                 m_symIndx {symIndx}
			{}
		}; // class Symbol
		std::vector<Symbol> symVec;
	private: // HELPERS
		using argsPairType = std::vector<std::pair<std::string, std::string>>;
		std::string getCorrespExpr(const std::string& argName, const argsPairType& argsPair) const;
		size_t getFuncAddress(const std::string& m_funcName) const;
		int getValueOfFunc(Node* root, const argsPairType& argsPair) const;
		bool checkFunc(const std::string& funcName, const size_t& argc) const;
}; // class SymbolTable

#include "SymbolTable.impl.hpp"

#endif // __PARSE__EXPRESSION__VAR_OR_FUNC__HPP__
