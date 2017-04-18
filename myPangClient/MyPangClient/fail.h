#ifndef FAIL_H_
#define FAIL_H_
#include "code.h"
struct fail{
	enum code c;
	char hint[50];
};
#endif

