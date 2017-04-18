/*file conf.h*/
#ifndef CONF_H_
#define CONF_H_
#include <string>
using namespace std;
const string s="10.21.27.100";
const int p=8888;
const int mc=10;
const int mt=10;
class conf{
public:
	string addr;
	int port;
	int maxClient;
	int macThread;
	conf(){
		addr=s;
		port=p;
		maxClient=mc;
		macThread=mt;
	}	
	~conf(){}
};
#endif
