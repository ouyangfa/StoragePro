/*file sign.cpp*/
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include "sign.h"
#include <string>
#include "code.h"
using namespace std;
char uses[10][20]={"oyf","yfm","oyjj"};
char passes[10][20]={"123","321","231"};
bool sign(int fd,char * buff){
	struct sign* s=(struct sign*)buff;
	int useslen=3;
	int size=0;
	for(int i=0;i<3;i++){
		if(0==strcmp(s->name,uses[i])){
			if(0==strcmp(s->pass,passes[i])){
			//	usesName=s->name;
				enum code cSucc=signSucc;
				size=send(fd,&cSucc,sizeof(cSucc),0);
				if(0<size){
					cout<<"发送成功"<<endl;
				}
				cout<<"用户"<<s->name<<"登录成功";	
				return true;
			}
		}
	}
	enum code cFail=signFail;
	size=send(fd,&cFail,sizeof(cFail),0);
	cout<<"用户"<<s->name<<"登录失败"<<endl;
	return false;
}
