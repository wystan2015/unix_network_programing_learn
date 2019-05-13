#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <stdarg.h>
#include <errno.h>

#ifndef __LOG_QUIT__
#define LOG_QUIT "/unix_network/log/log_quit.log"
#endif

#ifndef __LOG_QUIT__
#define LOG_SYS "/unix_network/log/log_sys.log"
#endif
