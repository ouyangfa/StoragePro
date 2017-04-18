#include <iostream>
#include "Connect.h"
#include <vector>
#include <sys/select.h>
#include <thread>
extern void doRequest(int);
using namespace std;
void Connect::put(int fd){
	fds.push_back(fd);
	cout<<"线程:"<<fd<<"入池"<<endl;
	if(max<fd){
		max=fd;
	}
	size++;
	ifNull=false;
}
void Connect::putFD(fd_set * fs){
	vector<int>::iterator iter=fds.begin();
	while(iter!=fds.end()){
		FD_SET(*iter,fs);
	//	cout<<*iter<<"入池"<<endl;
		iter++;
	}
}
int Connect::getMax()const{
	return max;
}
void Connect::handle(fd_set * fs){
	vector<int>::iterator iter=fds.begin();
	int i=0;
	while(iter!=fds.end()){
		if(FD_ISSET(*iter,fs)){
			thread t(doRequest,*iter);			
			t.detach();
			cout<<"创建线程"<<endl;
		}
		cout<<"i="<<++i<<endl;
		cout<<"有线程："<<*iter<<endl;
		if(fds.empty()){
			return;
		}
		else{
			iter++;
		}
	}
}
void Connect::del(int fd){
	vector<int>::iterator iter=fds.begin();
	max=*iter;
	while(iter!=fds.end()){
		if((*iter)==fd){
			fds.erase(iter);
			cout<<"用户:"<<*iter<<"出池"<<endl;
			size--;
			continue;
		}
		if(*iter>max){
			max=*iter;
		}
		iter++;
	}
	if(size==0){
		ifNull=true;
	}
}
bool Connect::getIfNull(){
		return ifNull;
	}
