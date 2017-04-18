/*file reg.cpp*/
#include <sys/socket.h>
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include "reg.h"
#include "code.h"
#include "fail.h"
using namespace std;
bool reg(int fd){
	struct reg r;
	memset(&r,0,sizeof(r));
	r.order=1;
	while(1){
		cout<<"用户名：";
		cin>>r.name;
		if(strlen(r.name)<=0){
			cout<<"用户名不能为空"<<endl;
			continue;	
		}
		break;
	}
	char pas[20];
	while(1){
		memset(pas,0,20);
		cout<<"密码：";
		cin>>pas;
		cout<<"请再次输入密码：";
		cin>>r.pass;
		if(strlen(pas)<=0||strlen(r.pass)<=0){
			cout<<"密码不能为空"<<endl;
			memset(r.pass,0,sizeof(r.pass));
			continue;
		}
		if(0==strcmp(pas,r.pass)){
			break;
		}
		memset(r.pass,0,sizeof(r.pass));
		continue;
	}	
	while(1){
		memset(r.email,0,sizeof(r.email));
		cout<<"请输入email地址：";
		cin>>r.email;
		if(strlen(r.email)<=0){
			cout<<"email不能为空"<<endl;
			continue;
		}
		break;
	}
	while(1){
		memset(r.sex,0,sizeof(r.sex));
		cout<<"请输入性别，男或女:";
		cin>>r.sex;
		if(strlen(r.sex)<=0){
			cout<<"性别不能为空"<<endl;
			continue;
		}
		//if(strcmp)
		break;
	}
	
	memset(&(r.age),0,sizeof(r.age));
	cout<<"请输入年龄:";
	cin>>r.age;
	size_t len=sizeof(r);
	int size=0;
	size=send(fd,&(r),len,0);
	if(size>0){
		cout<<"正在注册...";
		char buff[1024];
		while(1){
			size=0;
			size=recv(fd,buff,sizeof(buff),0);
			if(size>0){
				struct fail *f=(struct fail*)buff;
				switch(f->c){
					case regFail:
						cout<<"注册失败"<<endl;
						return false;
					case regSucc:
						cout<<"注册成功！"<<endl;
						return true;
					default:
						return false;
				}
			}
			continue;
		}
	}	
	
}
