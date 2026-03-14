.PHONY: clean build install uninstall

cc ?= gcc
compile_flags := -Wall -Wextra -Wpedantic -Werror
src := vexpand.c
out := vexpand.o
inst := /usr/bin/vexpand

build: $(src)
	$(cc) $(compile_flags) $(src) -o $(out)

clean: $(out)
	rm $(out)

install: $(out)
	cp -i $(out) $(inst)

uninstall: $(inst)
	rm $(inst)
