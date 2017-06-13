#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <time.h>

#ifndef _MAXLINE_
#define MAXLINE 1200
#endif

#ifndef __LISTENQ__
#define LISTENQ 999
#endif

typedef struct sockaddr SA;
extern int err_quit(const char *format, ...);
extern int err_sys( const char *format);
int Socket(int family,int type,int protocol);
int Bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
int Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int Write(int fd, const void *buf, size_t count);
int Close(int fd);
