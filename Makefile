INCLUDE=-Iinclude/
LIBS=-Llib/
ServidorWeb: src/ServidorWeb.c
	gcc -Wall  -I$PATH_TO_LIBMHD_INCLUDES -L$PATH_TO_LIBMHD_LIBS -lmicrohttpd src/ServidorWeb.c -o bin/ServidorWeb
.PHONY: clean
clean:
rm -rf obj/* bin/* lib/*
