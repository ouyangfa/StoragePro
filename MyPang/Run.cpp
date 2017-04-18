/*file Run.cpp*/
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <thread>
#include <mutex>
#include "common.h"
#include "reg.h"
#include "sign.h"
#include "code.h"
#include <string>
using namespace std;
bool sign(int,char*,string&);
mutex m;
void run(int fd){
	int fds=fd;
	int fdc=-1;
	struct sockaddr_in sock_client;
	socklen_t size_client=sizeof(sock_client);
	char buff[1024];
	memset(buff,0,1024);
	int size=0;
	while(1){
		m.lock();
		fdc=accept(fds,(struct sockaddr*)&sock_client,&size_client);
		m.unlock();
		if(fdc>0){
		string useName="";
		bool isSign=false;
		while(1){
			memset(buff,0,1024);
			size=recv(fdc,buff,1024,0);
			if(size>0){
				struct common * c=(struct common*)buff;
				switch(c->order){
					case 0://deng lu
						{
							isSign=sign(fdc,buff,useName);
							cout<<useName<<endl;
							break;
						}
					case 1://zhu ce
						{	
							struct reg * r=(struct reg*)buff;
							break;
						}	
					case 2:{
							//thread
						}
					case 3:{
							//thread
						}
					default:
							cout<<"other order"<<endl;
						break;
					}
				}
			}
		}	
	}	
}
