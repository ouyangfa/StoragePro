/*file main.cpp*/
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <string>
#include "order.h"
#include "sign.h"
using namespace std;
extern void sign(int);
extern bool reg(int);
extern bool clientQuit(int);
struct sign sigInfo;
int main(){
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0){
		cout<<"socket() failed"<<endl;
		cout<<"errno:"<<errno<<endl;
		return 0;
	}
	int err=-1;
	struct sockaddr_in sock;
	sock.sin_family=AF_INET;
	err=inet_pton(AF_INET,"10.21.27.100",&sock.sin_addr);
	if(err<=0){
		cout<<"inet_pton() failed"<<endl;
		cout<<"errno:"<<errno<<endl;
		return 0;
	}
	sock.sin_port=htons(8888);
	memset(sock.sin_zero,0,sizeof(sock.sin_zero));
	memset(&sigInfo,0,sizeof(sigInfo));
	err=connect(fd,(struct sockaddr*)&sock,sizeof(sock));
	if(err<0){
		cout<<"connect() failed"<<endl;
		cout<<"errno:"<<errno<<endl;
		return 0;
	}
	int len;
	int myOrder=-2;
	sigInfo.isConnect=true;
	cout<<"欢迎使用！请输入命令继续，输入0进行登录，输入1进行注册."<<endl;
//	thread t_isConnect(isConnect);
//	t_isConnect.detach();
	while(sigInfo.isConnect){
		cin>>myOrder;
		switch(myOrder){
			case 0:{
				if(sigInfo.isSign){
					cout<<"你已经登录"<<endl;
					break;
					}
				else{sign(fd);
					}
				if(sigInfo.isSign){
					cout<<"登录成功"<<endl;
					cout<<sigInfo.name<<endl;
					}
				else{cout<<"登录失败"<<endl;}
				break;
				}
			case 1:{
				bool isReg=reg(fd);
				break;
				}
			case 2:{
				if(sigInfo.isSign){
						//thread
					}
				else{
					cout<<"请先登录再进行其他操作"<<endl;
					break;
					}
				}
			case 3:{
				if(sigInfo.isSign){
						//thread
					}
				else{
					cout<<"请先登录再进行其他操作"<<endl;
					break;
					}
				}
			case -1:{
					if(clientQuit(fd)){sigInfo.isConnect=false;}
					break;
				}
			default:
				cout<<"请先登录或者注册,请输入0或1"<<endl;	
				break;
			}
		
		
	}
	cout<<"再见！"<<sigInfo.name<<endl;
}
