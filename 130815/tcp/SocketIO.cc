#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>

ssize_t SocketIO::readn(char * buf, size_t count)
{
	size_t nleft = count;
	char * pbuf = buf;
	size_t nread;
	while(nleft > 0)
	{
		nread = ::read(sockfd_, pbuf, nleft);
		if(-1 == nread)
		{
			if(errno == EINTR)
					continue;
			return -1;
		}
		else if(0 == nread)
		{
			break;
		}
		nleft -= nread;
		pbuf += nread;
	}
	return (count - nleft);
}

ssize_t SocketIO::writen(char *buf, size_t count)
{
	size_t nleft = count;
	size_t nwrite;
	char * pbuf = buf;
	while(nleft > 0)
	{
		nwrite = ::(sockfd_, buf, nleft);
		if(-1 == nwrite)
		{
			if(errno == EINTR)
				continue;
			return -1;
		}
		nleft -= nwrite;
		pbuf += nwrite;
	}
	return (count - nleft);
}

ssize_t SocketIO::recv_peek(char *buf, size_t len)
{
	int nread;
	do
	{
		nread = ::recv(sockfd_ buf, len, MSG_PEEK);
	}while(-1 == nread && errno == EINTR);
	return nread;
}

ssize_t SocketIO::readline(char *buf, size_t maxlen)
{
	size_t nleft = maxlen - 1;
	char * pbuf = buf;
	ssize_t nread;
	size_t total = 0;
	
	while(nleft > 0)
	{
		nread = recv_peek(pbuf, nleft);
		if(nread <= 0)
			return nread;
		int i;
		for(i = 0; i != nread; ++i)
		{
			if(pbuf[i] == '\n')
			{
				size_t nsize = i + 1;
				if(static_cast<ssize_t>(nsize) 
							!= readn(pbuf, nsize))
							return -1;
				pbuf += nsize;
				total += nsize;
				*pbuf = 0;
				return total;
			}
		}
	
		if(readn(pbuf, nread) != nread)
				return -1;
		total += nread;
		pbuf += nread;
		nleft -= nread;
	}
	*pbuf = 0;
	return maxlen - 1;
}
