/*file Connect.h*/
#ifndef CONNECT_H_
#define CONNECT_H_
#include <iostream>
#include <vector>
#include <sys/select.h>
using namespace std;
class Connect{
private:
	vector<int> fds;
	int size;
	bool ifNull;
	int max;
public:
	Connect():ifNull(true),size(0),max(0){}
	virtual ~Connect(){};
	void put(int);
	void putFD(fd_set *);
	int getMax()const;
	void handle(fd_set *);
	void del(int);
	bool getIfNull();
};
#endif
