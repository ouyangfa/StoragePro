/*file HandleRequest.cpp*/
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Connect.h"
#include "sign.h"
#include "code.h"
#include <sys/select.h>
#include <time.h>
void handleRequest(Connect * c){
	time_t now;
	static fd_set scanfd;
	struct timeval timeout;
	timeout.tv_sec=1;
	timeout.tv_usec=0;
	int err=-1;
	while(1){
		if(c->getIfNull()){continue;}
		FD_ZERO(&scanfd);
		c->putFD(&scanfd);
		err=select(c->getMax()+1,&scanfd,NULL,NULL,&timeout);
		switch(err){
			case 0:
				break;
			case -1:
				cout<<"发生错误"<<endl;
				break;
			default:{
					std::cout<<"用户"<<c->getMax()-1<<"活动"<<std::endl;
					c->handle(&scanfd);
					break;
				}
		}	
	}
}
