#include "InetAddress.h"
#include "socket.h"
#include "socketIO.h"

#include <stdio.h>
#include <string.h>

int main(void)
{
	InetAddress inetaddr("192.168.175.133", 8888);
	Socket socket;
	socket.ready(inetaddr);

	int peerfd = socket.accept();
	SocketIO sockIO(peerfd);
	char buf[1024];
	memset(buf, 0, 1024);
	while(1)
	{
		sockIO.readline(buf, 1024);
		printf("%s\n", buf);
		
		sockIO.writen(buf, strlen(buf));
	}
	return 0;
}
