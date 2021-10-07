#pragma once

#include <fstream>
#include <string>
#include <vector>

// Quote of the Day
class QotD
{
private:
	std::vector<std::string> m_quotes;

public:
	QotD(std::string filename);
	std::string GetRandomQuote();
};