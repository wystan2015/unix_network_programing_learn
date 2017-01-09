#include  "unp.h"

extern void err_quit(char *str, ...);
extern void err_sys(char *str);

int main(int argc,char ** argv)
{
	int sockfd,n;
	char recvline[MAXLINE +1];
	struct sockaddr_in servaddr;
	
	if(argc != 2) {
		
		//snprintf(errmsg,sizeof(errmsg),"usage: %s <IPaddress>",argv[0]);
		err_quit("usage: %s <IPaddress>\n",argv[0]);
		return 0;	
	}

	
	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0 ) {
		err_sys("socket error");
		return -1;
	}	
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	if(inet_pton(AF_INET,argv[1],&servaddr) < 0) {
		err_quit("inet_pton error for ");
		return -1;
		//err_quit("inet_pton error for %s",argv[1]);
	}	

	if(connect(sockfd,(SA*)&servaddr,sizeof(servaddr)) < 0) {
		err_sys("connect error");
		return -1;
	}
	
	while((n = read(sockfd,recvline,MAXLINE)) > 0) {
		recvline[n] = 0;
		if(fputs(recvline,stdout) == EOF) {
			err_sys("fputs error");
			return -1;
		}	
	}	
	
	if(n < 0) {
		err_sys("read err");
		return -1;
	}

	return 0;
}
