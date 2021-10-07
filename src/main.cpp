#include "QotD.h"
#include "TcpListener.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

void Listener_MessageReceived(TcpListener* listener, int client, std::string msg);

QotD qotd{ "wisdom.txt" };

int main()
{
	std::srand(std::time(nullptr));

	TcpListener server("127.0.0.1", 54000, Listener_MessageReceived);

	if (server.Init())
		server.Run();

	return 0;
}

void Listener_MessageReceived(TcpListener* listener, int client, std::string msg)
{
	if (msg == "QUOTE")
	{
		listener->Send(client, qotd.GetRandomQuote());
	}
}
