#ifndef FUNS_H_
#define FUNS_H_
#include "Connect.h"
int init();
void HandleConnect(int,Connect *);
void HandleRequest(Connect *);
void doRequest(int);
#endif
