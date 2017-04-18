#include <sys/socket.h>
#include <iostream>
#include <cstring>
#include "code.h"
using namespace std;
bool clientQuit(int fd){
	int order=-1;
	char buff[5];
	memset(buff,0,sizeof(buff));
	int size=send(fd,&order,sizeof(order),0);
	if(size>0){
		size=recv(fd,buff,sizeof(buff),0);
		order=*(int *)buff;
		if(order==4){
			return true;
		}
		return false;	
	}
	return false;
}
