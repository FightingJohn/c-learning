#ifndef _LYL_SOCKETIO_H
#define _LYL_SOCKETIO_H

#include <unistd.h>

class SocketIO
{
public:
	explicit SocketIO(int sockfd)
			:sockfd_(sockfd)
	{}
	
	ssize_t readn(char *buf, size_t count);
	ssize_t writen(char *buf, size_t count);
	ssize_t readline(char *buf, size_t maxlen);
private:
	ssize_t recv_peek(char *buf, size_t len);

private:
	const int sockfd_;
};

#endif
