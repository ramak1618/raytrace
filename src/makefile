.PHONY: clean build

src := raycorex/triangle.cx raycorex/camera.cx shapex/icosphere.cx
out :=  raycore/triangle.c   raycore/camera.c  shapes/icosphere.c

build: $(out)
clean:
	rm -r raycore/

raycore/%.c: raycorex/%.cx | raycore/
	vexpand $< $@

raycore/:
	mkdir raycore/

shapes/%.c: shapex/%.cx | shapes/
	vexpand $< $@

shapes/:
	mkdir shapes/
