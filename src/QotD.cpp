#include "QotD.h"

#include <cstdlib>
#include <iostream>

QotD::QotD(std::string filename)
{
	// Open filename
	std::ifstream file{ filename };
	if (!file)
	{
		std::cerr << "Could not open " << filename << '\n';
		return;
	}

	std::string quote{};
	// Read until a '%' delimiter is found
	while (getline(file, quote, '%'))
	{
		m_quotes.push_back(quote);

		// Remove the newline character right after our '%' delimiter,
		// that would otherwise be parsed to the front of our quote
		std::string temp;
		getline(file, temp);
	}
}

std::string QotD::GetRandomQuote()
{
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };

	// Return a random quote with index between [0, m_quotes.size() - 1]
	return m_quotes[m_quotes.size() * std::rand() * fraction];
}