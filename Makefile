INCLUDE=-Iinclude/
LIBS=-Llib/
rocesodaemon: 
	gcc -Wall  daemonCPU.c -o programa
	.PHONY: clean
clean:
rm -rf obj/* bin/* lib/*
