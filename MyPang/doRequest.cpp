/*file doRequest.cpp*/
#include <iostream>
#include <sys/socket.h>
#include "code.h"
#include "common.h"
#include "sign.h"
#include <cstring>
#define SIZE 1024
#include "funs.h"
extern bool sign(int,char *);
extern void clientQuit(int);
extern void regi(int,char *);
using namespace std;
void doRequest(int fd){
	char buff[SIZE];
	memset(buff,0,SIZE);
	int size=recv(fd,buff,SIZE,0);
	cout<<"size="<<size<<endl;
	if(size>0){
		struct common * c=(struct common *)buff;
		switch(c->myOrder){
			case sig:{
				if(sign(fd,buff)){}
				break;	
			}
			case reg:{
				regi(fd,buff);
				break;
			}
			case 2:{
				break;
			}
			case sig_out:{
				clientQuit(fd);
				break;
			}
			default:{
				enum code coDefault=noSuchOrder;
				size=send(fd,&coDefault,sizeof(coDefault),0);
				if(size>0){
					cout<<"未知命令回复成功"<<endl;
					return;
				}
			}
		}
	}
}
