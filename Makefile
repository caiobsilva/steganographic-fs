all: steg-fs

steg-fs: steg-fs
	gcc src/encode.h src/encode.c src/main.c -o steg-fs -D_FILE_OFFSET_BITS=64 -lfuse

clean:
	rm steg-fs
