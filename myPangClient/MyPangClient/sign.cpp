/*file sign.cpp*/
#include <iostream>
#include <sys/socket.h>
#include <cstring> 
#include "sign.h"
#include "code.h"
#include <sys/types.h>
#include <string>
using namespace std;
extern struct sign sigInfo;
void sign(int fd){
	memset(&sigInfo,0,sizeof(sigInfo));
	sigInfo.order=0;
	sigInfo.isConnect=true;
	while(1){
	cout<<"请输入用户名：";
		cin>>sigInfo.name;
		if(strlen(sigInfo.name)<=0){
			cout<<"用户名不能为空,请重新输入";		
			continue;
		}
		break;
	}
	while(1){
		cout<<"请输入密码：";
		cin>>sigInfo.pass;
		if(strlen(sigInfo.pass)<=0){
			cout<<"密码不能为空，请重新输入";
			continue;
		}
		break;
	}
	size_t len=sizeof(sigInfo);
	int size=0;
	size=send(fd,&sigInfo,len,0);
	if(size>0){
		cout<<"正在验证。。。"<<endl;
		enum code c;
		size=0;
		while(1){
			size=recv(fd,&c,sizeof(c),0);
			if(size>0){
				switch(c){
					case signFail:{
						cout<<"登录失败，请重新登录";
						return;}
					case signSucc:{
						cout<<"登录成功，欢迎光临";
						sigInfo.isSign=true;
						return;}
					default:
						break;
				}
			}
			continue;	
			
		}
	}
}
