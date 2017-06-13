#include "pub.h"
int err_quit(const char *format, ...){
	//printf("开始创建quit log 文件%s\n",LOG_QUIT);
	//FILE * fp=fopen(LOG_QUIT,"a+");
	extern int errno;
	char filepath[255]="";
	strncpy(filepath,getenv("HOME"),strlen(getenv("HOME")));
	strncat(filepath,LOG_QUIT,sizeof(LOG_QUIT));
	//printf("组装成的文件全路径：%s\n",filepath);
	FILE * fp=fopen(filepath,"a+");
	if(NULL == fp){
		fp=fopen(filepath,"a+");
		if(NULL == fp){
			printf("创建quit日志文件出错\n");
			exit(-1);
		}
	}
	fprintf(fp,"errno[%d]:%s\n",errno,strerror(errno));
	va_list args;
	va_start(args,format);
	vfprintf(fp,format,args);
	va_end(args);
	fclose(fp);
	return 0;

}

int err_sys( const char *format){
	
	//printf("开始创建sys log文件%s\n",LOG_SYS);	
	//FILE * fp=fopen(LOG_SYS,"a+");
	char filepath[255]="";
    strncpy(filepath,getenv("HOME"),strlen(getenv("HOME")));
    strncat(filepath,LOG_SYS,sizeof(LOG_QUIT));
    //printf("组装成的文件全路径：%s\n",filepath);
    FILE * fp=fopen(filepath,"a+");
	if(NULL == fp){
        fp=fopen(filepath,"a+");
        if(NULL == fp){
            printf("创建sys日志文件出错\n");
            exit(-1);
        }
    }
	fprintf(fp,"errno[%d]:%s\n",errno,strerror(errno));
	fprintf(fp,format,"\n");
	fclose(fp);
	return 0;
}

int Socket(int family,int type,int protocol){
	int n;
	if((n=socket(family,type,protocol)) <0){
		err_sys("err socket");
	}
	return (n);
}

int Bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
{
	int n;
	if((n=bind(sockfd,addr,addrlen)) != 0){
		err_sys("bind error!\n");
		exit(-1);
	}
	return 0;
}

int Listen(int sockfd, int backlog)
{
	int n;
	if(n=(listen(sockfd,backlog)) != 0){
		err_sys("listen error!\n");
		exit(-1);
	}
	return 0;
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
	int n;
	if((n=accept(sockfd,addr,addrlen)) == -1){
		err_sys("accept error!\n");
		exit(-1);
	}
	return 0;
}

void Write(int fd, const void *buf, size_t count)
{
	ssize_t n;
	if((n=write(fd,buf,count)) == -1){
		err_sys("write error!\n");
		exit(-1);
	}
}

int Close(int fd)
{
	int n;
	if((n=close(fd)) != 0){
		err_sys("close error!\n");
		exit(-1);
	}
	return 0;
}
