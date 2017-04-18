/*file HandleConnect.cpp*/
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "Connect.h"
#include <sys/types.h>
//#include "funs.h"
void handleConnect(int fd,Connect * c){
	int fdCli;
	struct sockaddr_in sockCli;
	socklen_t size=sizeof(sockCli);
	while(1){
		fdCli=accept(fd,(struct sockaddr*)&sockCli,&size);
		if(0<fdCli){
			std::cout<<"接收到一个用户:"<<fdCli<<std::endl;
			c->put(fdCli);
		}
	}
}
