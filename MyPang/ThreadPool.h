/*file ThreadPool.h*/
#ifndef THREADPOOL_H_
#define THREADPOOL_H_
#include <thread>
#include <vector>
extern void run(int);
class ThreadPool{
private:
	int fd;
	int number;
	int size;
	vector<thread> ts;
public:
	ThreadPool(int f,int num=0,int s=3):number(num),size(s){
		fd=f;
	}
	~ThreadPool(){}
	void start(){
		for(int i=0;i<size;i++){	
			ts.push_back(thread(run,fd));
		}
		vector<thread>::iterator iter=ts.begin();
		while(iter!=ts.end()){
			iter->join();
			iter++;
		}
	}
};
#endif
