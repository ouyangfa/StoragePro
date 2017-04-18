/*file: start.cpp*/
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <thread>
#include "conf.h"
#include <string>
#include "ThreadPool.h"
#include "Connect.h"
using namespace std;
extern void run(int);
extern void StartMyThreadPool(int);
extern void handleConnect(int i,Connect *c);
extern void handleRequest(Connect *c);
static Connect connes;
Connect * serStruct;
int init(){
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0){
		cout<<"socket() failed"<<endl;
		cout<<"errno:"<<errno<<endl;
		return -1;
	}	
	struct sockaddr_in sockSer;
	sockSer.sin_family=AF_INET;
	int err=0;
	conf myConf=conf();
	err=inet_pton(AF_INET,(myConf.addr).c_str(),&sockSer.sin_addr);
	if(err<=0){
		cout<<"inet_pton() failed"<<endl;
		cout<<"errno:"<<errno<<endl;
		return -1;
	}
	sockSer.sin_port=htons(myConf.port);
	socklen_t len=sizeof(sockSer);
	memset(sockSer.sin_zero,0,sizeof(sockSer.sin_zero));
	err=bind(fd,(struct sockaddr*)&sockSer,len);
	if(err<0){
		cout<<"bind() failed"<<endl;
		cout<<"errno:"<<errno<<endl;
		return -1;
	}
	listen(fd,5);
//	ThreadPool pool(fd);
//	pool.start();
//	static Connect connes;
	serStruct=&connes;
	thread t_handleConnect(handleConnect,fd,&connes);
	cout<<"创建线程a"<<endl;
	thread t_handleRequest(handleRequest,&connes);
	cout<<"创建线程b"<<endl;
	t_handleConnect.join();
	t_handleRequest.join();
//	StartMyThreadPool(fd,struct myConf & conf);
//	socklen_t size_client=sizeof(sockSer);
/*	while(1){
		int fd_client=0;
		struct sockaddr_in sock_client;
//		size_client=sizeof(sock);
		fd_client=accept(fd,(struct sockaddr *)&sock_client,&size_client);
		if(fd_client>0){
			thread t(run,fd_client);
			t.detach();
		}
	}*/
	return 0;
}
