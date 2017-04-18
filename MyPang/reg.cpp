/*file reg.cpp*/
#include <iostream>
#include <sys/socket.h>
#include "reg.h"
#include <mysql/mysql.h>
#include <string>
#include <cstring>
#include "fail.h"
#include "code.h"
using namespace std;
void regi(int fd,char * buff){
	struct reg* _reg=(struct reg *)buff;
	string str_reg;
	str_reg.append("insert into user(name,pass,email,sex,age,buileTime) value('");
	str_reg.append(_reg->name);
	str_reg.append("','");
	str_reg.append(_reg->pass);
	str_reg.append("','");
	str_reg.append(_reg->email);
	str_reg.append("','");
	str_reg.append(_reg->sex);
	str_reg.append("',");
	char tmp[3];
	sprintf(tmp,"%d",_reg->age);
	str_reg.append(tmp);
	str_reg.append(",");
	str_reg.append("NOW())");
	cout<<str_reg<<endl;
	cout<<str_reg.c_str()<<endl;
	string str_query="select * from user where name='";
	str_query.append(_reg->name);
	str_query.append("'");
	cout<<str_query<<endl;
	cout<<str_query.c_str()<<endl;
	MYSQL mySqlConn;
	mysql_init(&mySqlConn);
	if(mysql_real_connect(&mySqlConn,"localhost","oyf","","myPang",0,NULL,CLIENT_FOUND_ROWS)){
		cout<<"connect mysql success"<<endl;
		MYSQL_RES * MR;
		unsigned int num_fields;
		if(!mysql_query(&mySqlConn,str_query.c_str())){
			cout<<"查询成功"<<endl;
			MR=mysql_store_result(&mySqlConn);
			if(!MR){
				cout<<"获取结果集错误"<<endl;
				return;
			}	
			cout<<"获取结果成功"<<endl;
			if(MR->row_count==0){
				if(!mysql_query(&mySqlConn,str_reg.c_str())){
					//注册成功	
					struct fail f1;
					f1.c=regSucc;
					strcpy(f1.hint,"注册成功");
					send(fd,&f1,sizeof(f1),0);
				}
				else{
					struct fail f2;
					f2.c=regFail;
					strcpy(f2.hint,"注册失败，数据库方面原因");
					send(fd,&f2,sizeof(f2),0);
					//注册失败
				}
			}
			else{
				struct fail f3;
				f3.c=regFail;
				strcpy(f3.hint,"已存在该用户");
				send(fd,&f3,sizeof(f3),0);
				//已存在该用户
			}	
		}
		else{
			struct fail f4;
			f4.c=regFail;
			strcpy(f4.hint,"注册发生错误，请重新注册");
			send(fd,&f4,sizeof(f4),0);
			//注册发生错误
		}
	}
	mysql_close(&mySqlConn);
	cout<<"关闭数据库链接"<<endl;
	return;	
	
}
