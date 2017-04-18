/*file code.h*/
#ifndef CODE_H_
#define CODE_H_
enum code{
	signFail=0,//登录失败
	signSucc=1,//登录成功
	regFail=2,//注册失败
	regSucc=3,//注册成功
	noSuchOrder=-1,//没有相应命令
	quitSucc=4,//成功退出
	quitFail=5,//退出失败
};
#endif
