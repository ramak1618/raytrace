.PHONY: build

coresrc := ../../src/vecs/vecs.c ../../src/raycore/triangle.c ../../src/raycore/camera.c ../../src/encoder/png.c
build:
	vexpand simple.cx simple.c
	gcc -O3 -flto -Wall -Wextra -Wpedantic -Werror -I"../../include/"  $(coresrc) simple.c -lm -lavcodec -lavutil -o simple.o 
	./simple.o
