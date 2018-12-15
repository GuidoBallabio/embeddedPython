#pragma once
#include "ILoader.h"
#include <string>
#include <fstream>

template<typename T>
class LoaderFile : public ILoader<T>
{
public:
	LoaderFile(std::string inputName, std::string outputName): _inputName(inputName), _outputName(outputName)
	{}

	virtual size_t LoadData(T buffer[]) override
	{
		std::fstream fs(_inputName, std::fstream::in | std::fstream::binary | std::fstream::ate);

		if (!fs.is_open())
			throw new std::string("whoops");

		std::fstream::pos_type pos = fs.tellg();

		fs.seekg(0, std::fstream::beg);
		fs.read(reinterpret_cast<char*>(buffer), pos);

		return pos/sizeof(T);
	}

	virtual void ExportData(T buffer[], size_t size) override
	{
		std::fstream fs(_outputName, std::fstream::out | std::fstream::binary);

		if (!fs.is_open())
			throw new std::string("whoops");

		fs.write(reinterpret_cast<char*>(buffer), size*sizeof(T));
	}

	void SetOutputFile(std::string outputName)
	{
		_outputName = outputName;
	}

private:
	std::string _inputName;
	std::string _outputName;
};