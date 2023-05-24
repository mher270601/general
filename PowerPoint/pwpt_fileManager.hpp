#ifndef __READ__INFO__HPP__
#define __READ__INFO__HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "InputCmd.hpp"
#include "PowerPoint.hpp"

class IBaseComponents{
public:
	virtual void GetData() = 0;
	virtual void ReadParseData() = 0;
	virtual void ParseLine(std::stringstream&) = 0;
	virtual ~IBaseComponents() = default;
private:
};

class FileManager : public IBaseComponents{
public:
	void GetData() override;
	void ReadParseData() override;
	static FileManager& GetInstance();
	FileManager& operator=(const FileManager& rhs) = delete;
	FileManager(const FileManager& rhs) = delete;
	virtual ~FileManager() = default;
	FileManager();
private:
	void ParseLine(std::stringstream&) override;
private:
	const std::string m_FPath;
	std::fstream m_file;
	std::shared_ptr<PowerPoint::CmdInput>& m_cmdInput = PowerPoint::CmdInput::GetInstance();
};

#include "pwpt_fileManager.impl.cpp"

#endif // __READ__INFO__HPP__
