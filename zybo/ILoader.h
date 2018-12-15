#pragma once

template<typename T>
class ILoader
{
public:
	virtual size_t LoadData(T buffer[]) = 0;
	virtual void ExportData(T buffer[], size_t size) = 0;
};
