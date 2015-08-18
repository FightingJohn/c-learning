#ifndef _LYL_INETADDRESS_H
#define _LYL_INETADDRESS_H

#include <unistd.h>
#include <arpa/inet.h>
#include <string>

class InetAddress
{
public:
	explicit InetAddress(uint16_t port);
	InetAddress(const std::string &ip, uint16_t port);
	InetAddress(const struct sockaddr_in &addr);
	
	void setSockAddrIner(const struct sockaddr_in & addr);
	const struct sockaddr_in * getSocketAddrInet() const;

	std::string ip() const;
	uint16_t port() const;

private:
	struct sockaddr_in addr_;

};

#endif
