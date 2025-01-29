#ifndef __PROCESS__MANAGER__HPP__
#define __PROCESS__MANAGER__HPP__

#include <vector>
#include <string>

namespace TuringMachine{

	class Manager{
	public:
		Manager& operator=(const Manager& rhs) = delete;
		Manager(const Manager& rhs) = delete;
		static Manager& getInstance(const std::string& expr);
		void Execute();
	private:
		Manager() = delete;
		Manager(const std::string& expr);
		std::string expr;
	};

} // namespace TuringMachine

#include "processManager.impl.cpp"

#endif // __PROCESS__MANAGER__HPP__
