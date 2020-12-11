all:
	gcc src/encode.h src/encode.c src/main.c -lpthread -lfuse -o steg-fs -D_FILE_OFFSET_BITS=64

clean:
	rm steg-fs
