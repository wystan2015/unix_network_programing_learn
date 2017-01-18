#include "unp.h"
#include <time.h>

int main(int argc,char **argv)
{

	int listenfd,connfd;
	struct sockaddr_in servaddr;
	char buff[MAXLINE];
	time_t ticks;

	listenfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port = htons(8888);

	bind(listenfd,(SA*)&servaddr,sizeof(servaddr));
	printf("bind ok\n");
	listen(listenfd,LISTENQ);

	for(;;) {
		connfd = accept(listenfd,(SA*)NULL,NULL);
		printf("accept a connfd:%d\n",connfd);
		ticks = time(NULL);
		snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
		printf("buffer to send:%s\n",buff);
		write(connfd,buff,strlen(buff));
		close(connfd);
	}

	return 0;
}
