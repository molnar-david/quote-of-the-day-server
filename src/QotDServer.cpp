#include "QotDServer.h"

#include <sstream>

QotDServer::QotDServer(const char* ipAddress, int port, std::string filename)
	: TcpListener{ ipAddress, port }, m_qotd{ filename }
{
}

// Handler for client connections
void QotDServer::onClientConnected(int clientSocket)
{
	// Send a welcome message to the client
	std::ostringstream ss;
	ss << "Welcome to the Server of Wise Quotes!\r\n\r\n";
	std::string strOut{ ss.str() };

	sendToClient(clientSocket, strOut.c_str(), strOut.size());

	// And send a random quote right away
	strOut = m_qotd.GetRandomQuote();

	sendToClient(clientSocket, strOut.c_str(), strOut.size());
}

// Handler for client disconnections
void QotDServer::onClientDisconnected(int clientSocket)
{

}

// Handler for when a message is received from the client
void QotDServer::onMessageReceived(int clientSocket, const char* msg, int length)
{
	// Is the message a command?
	if (msg[0] == '\\')
	{
		std::string cmd{ std::string(msg, length) };

		// Quit the server
		if (cmd == "\\quit")
		{
			setRunning(false);
			return;
		}

		// Unknown command - continue
	}

	// Is the client asking for more quotes?
	std::string msgStr{ msg, static_cast<size_t>(length) };
	if (msgStr == "QUOTE")
	{
		std::string strOut{ m_qotd.GetRandomQuote() };
		sendToClient(clientSocket, strOut.c_str(), strOut.size());
	}
}
