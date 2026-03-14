.PHONY: clean build

src := raycorex/triangle.cx raycorex/camera.cx
out :=  raycore/triangle.c   raycore/camera.c

build: $(out)
clean:
	rm -r raycore/

raycore/%.c: raycorex/%.cx | raycore/
	vexpand $< $@

raycore/:
	mkdir raycore/

