#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdarg.h>


#define MAXLINE 512
#define LISTENQ 12
typedef struct sockaddr SA;

