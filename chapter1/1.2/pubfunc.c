#include "unp.h"

void err_quit(char *str, ...) 
{ 
	va_list ap; 

	va_start(ap,str); 
	vprintf(str,ap); 
	va_end(ap); 
	//printf("%s[%d]:%s\n",__FILE__,__LINE__,str); 

} 

void err_sys(char *str) 
{ 
	printf("%s\n",str); 
} 

