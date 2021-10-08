#include "QotDServer.h"

#include <cstdlib>
#include <ctime>
#include <string>

int main()
{
	std::srand(std::time(nullptr));

	QotDServer server{ "127.0.0.1", 54000, "wisdom.txt"};

	if (server.init() != 0)
	{
		return 0;
	}

	server.run();

	return 0;
}
