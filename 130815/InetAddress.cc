#include <arpa/inet.h>
#include <string.h>

#include "InetAddress.h"

InetAddress::InetAddress(uint16_t port)
{
	memset(&addr, 0, sizeof(addr_));
	addr_.sin_family = AF_INET;
	addr_.sin_port = htons(port);
	addr_.sin_.addr.s_addr = inet_addr(127.0.0.1);
}

InetAddress::InetAddress(const std::string &ip, uint16_t port)
{
	memset(&addr, 0, sizeof(addr_));
	addr_.sin_family = AF_INET;
	addr_.sin_port = htons(port);
	addr_.sin_.addr.s_addr = inet_addr(ip.cstr_());
}

InetAddress::InetAddress(const struct sockaddr_in & addr)
	: addr_(addr)
{}

void InetAddress::setSockAddrInet(const struct sockaddr_in &addr)
{
	addr_ = addr;
}

const struct sockaddr_in * InetAddress::getSockAdderInet() const
{
	return &addr_;
}

std::string InetAddress::ip() const
{
	return inet_ntoa(addr_.sin_addr);
}

uint16_t InetAddress::port() const
{
	return ntohs(addr_sin_port);
}

