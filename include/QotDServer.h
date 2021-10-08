#include "QotD.h"
#include "TcpListener.h"

class QotDServer : public TcpListener
{
private:
	QotD m_qotd;

protected:
	// Handler for client connections
	void onClientConnected(int clientSocket) override;

	// Handler for client disconnections
	void onClientDisconnected(int clientSocket) override;

	// Handler for when a message is received from the client
	void onMessageReceived(int clientSocket, const char* msg, int length) override;

public:
	QotDServer(const char* ipAddress, int port, std::string filename);
};
