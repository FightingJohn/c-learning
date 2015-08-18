#ifndef _LYL_TCPCONNECTION_H
#define _LYL_TCPCONNECTION_H

#include <>

class TcpConnection : private Noncopyable
{
public:
	TcpConnection (int sockfd);
	
	std::string receive();
	void send();

private:
	Socket sockfd_;
	Socket

}
