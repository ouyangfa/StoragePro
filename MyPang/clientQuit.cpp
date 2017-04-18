#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <time.h>
#include "Connect.h"
#include "code.h"
extern Connect * serStruct;
using namespace std;
void clientQuit(int fd){
	Connect * c=serStruct;
	c->del(fd);
	enum code co=quitSucc;
	int size=send(fd,&co,sizeof(c),0);
	if(size>0){
		cout<<"用户:"<<fd<<"退出成功"<<endl;
	}
	close(fd);
	return;
}
