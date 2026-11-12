About
-----
A personal project for building a raytracer written in C.

You can check out the outputs for the test programs; and also write you own scenes!


Usage
-----
Make sure you have all the [dependencies][deps] installed

```
git clone https://github.com/ramak1618/raytrace
cd raytrace
cmake -S . -B build/ 
cmake --build build/
sudo cmake --install build/
```

There are three things built and installed:

* `vexpand`: A small transpiler that expands 3 dimensional vector (vec3) expressions
* `libraytrace.so`: A shared library containing the API.
* `raycore`: The public header files to include from. You will find it at \<include-dir\>/raycore

You can go into any example after this and:
```
cmake -S . -B build/
cmake --build build/
```
This will automatically compile the source and generate the image for you.

[Note: Some scenes can take a (really) long time to generate] 

There are currently no docs for the API, so you will have to read the source code yourself :(

Advanced Usage
--------------
You can mention `-DCMAKE_BUILD_TYPE` to be `release`, `debug` or `asan`.

`release` is the same as default with -O3 optimizations.

`debug` is no optimizations with debugging symbols.

`asan` is no optimizations with AddressSanitizer + debugging symbols.


Dependencies
------------
* FFmpeg: more specifically `libavcodec` and `libavutil`. Most linux package managers provide this. You can also download from [their website][ffmpeg_home].

License
-------
Licensed under the [MIT License][licenselink]

Third-Party Software
--------------------
The random number generator at `./external/pcg` directory is sourced from [pcg-c-basic][pcg_code] which is licensed under the Apache License, Version 2.0.
A copy of the license is included in that directory.

References
----------
* [Raytracing In One Weekend Series][oneweekend]

* [PBRT][pbrt]

* [Icosahedron stuff][icostuff]

* [PCG Random Number Generator][pcg]

[licenselink]: LICENSE
[oneweekend]: https://raytracing.github.io/
[pbrt]: https://pbrt.org/
[icostuff]: https://geometryofthinking.com/2023/08/30/the-icosahedron/
[deps]: #Dependencies
[ffmpeg_home]: https://ffmpeg.org/
[pcg_code]: https://github.com/imneme/pcg-c-basic/
[pcg]: https://www.pcg-random.org/
