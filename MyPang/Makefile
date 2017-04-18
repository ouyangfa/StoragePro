main:start.cpp
	g++ -std=c++11 -o main.out start.cpp init.cpp sign.cpp clientQuit.cpp doRequest.cpp reg.cpp HandleConnect.cpp HandleRequest.cpp Connect.cpp `mysql_config --cflags --libs` -pthread
#test:start.o init.o Connect.o HandleConnect.o HandleRequest.o doRequest.o sign.o 
#	g++ -o test start.o init.o Connect.o HandleConnect.o HandleRequest.o doRequest.o sign.o -g
#start.o:start.cpp
#	g++ -o start.o start.cpp -g	
#Connect.o:Connect.cpp Connect.h doRequest.o 
#	g++ -std=c++11 -o Connect.o Connect.cpp Connect.h doRequest.o -pthread -g
#clientQuit.o:clientQuit.cpp init.o 
#	g++ -g -o clientQuit.o clientQuit.cpp init.o
#HandleRequest.o:HandleRequest.cpp Connect.o
#	g++ -o HandleRequest.o HandleRequest.cpp Connect.o -g
#HandleConnect.o:HandleConnect.cpp Connect.o
#	g++ -o HandleConnect.o HandleConnect.cpp Connect.o -g
#doRequest.o:doRequest.cpp
#	g++  -o doRequest.o doRequest.cpp -g
#sign.o:sign.cpp sign.h code.h
#	g++ -o sign.o sign.cpp sign.h code.h -g
#init.o:init.cpp HandleConnect.o HandleRequest.o
#	g++ -std=c++11 -o init.o init.cpp -pthread -g

