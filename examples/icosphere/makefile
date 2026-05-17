.PHONY: build

coresrc := ../../src/vecs/vecs.c ../../include/utils/pcg/pcg_basic.c ../../src/utils/random.c ../../src/raycore/triangle.c ../../src/raycore/camera.c ../../src/encoder/png.c ../../src/shapes/icosphere.c
build:
	vexpand sphere.cx sphere.c
	gcc -O3 -flto -Wall -Wextra -Wpedantic -Werror -I"../../include/"  $(coresrc) sphere.c -lm -lavcodec -lavutil -o sphere.o 
	./sphere.o
