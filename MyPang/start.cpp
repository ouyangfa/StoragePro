/*file start.cpp*/
#include <iostream>
extern int init();
using namespace std;
int main(){
	int err=-1;
	err=init();
	if(err<0){
		cout<<"init() failed"<<endl;
		return 0;
	}
	return 0;
}
