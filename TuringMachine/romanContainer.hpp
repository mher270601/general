#ifndef __ROMAN__CONTAINER__HPP__
#define __ROMAN__CONTAINER__HPP__

#include <string>
#include <vector>

#include "romanLimitsTranslator.hpp"

namespace TuringMachine{

	class RomanContainer{
	public:
		//RomanContainer& operator=(const RomanContainer& rhs) = delete;
		//RomanContainer(const RomanContainer& rhs) = delete;
		void addSymbol(const std::string& symbol);
		void removeSymbol(const size_t count);
		size_t getSize() const;
		std::string getValue() const noexcept;
		void cPrint() const noexcept;
		RomanContainer() = default;
	private:
		bool checkValue(const std::string& value);
		bool checkLimit(const std::string& value);
	private:
		std::vector<std::string> m_data;
	};

}

#include "romanContainer.impl.cpp"

#endif // __ROMAN__CONTAINER__HPP__
