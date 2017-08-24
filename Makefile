procesodaemon: 
	gcc -Wall  daemonCPU.c -o programa
.PHONY: clean
clean:
	rm -rf programa monitorCPU
