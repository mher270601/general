#ifndef __TURING__GENERATOR__HPP__
#define __TURING__GENERATOR__HPP__

#include <string>

#include "romanContainer.hpp"

namespace TuringMachine{

	class TuringGenerator{
	public:
		TuringGenerator& operator=(const TuringGenerator& rhs) = delete;
		TuringGenerator(const TuringGenerator& rhs) = delete;
		static TuringGenerator& getInstance(const std::string& expr);
		void generateTuringCode();
	private:
		//size_t getRomanValueIndex(const char& value);
		TuringGenerator() = delete;
		TuringGenerator(const std::string& expr);
	private:
		std::vector<RomanContainer> m_dataContainer;
		std::string expr;
	};

} // namespace TuringMachine

#include "turingGenerator.impl.cpp"

#endif // __TURING__GENERATOR__HPP__
