About
-----
A personal project for building a raytracer written in C.

You can check out the outputs for the test programs; and also write you own scenes!


Usage
-----
Make sure you have all the [dependencies][deps] installed

run `build.sh`. This will install a program called `vexpand`, and runs vexpand on the source code.

`vexpand` is a small transpiler that expands 3 dimensional vector (vec3) expressions.

You can then go into any example and run `make` to transpile, compile, run and retrieve the output.

Note: Some scenes can take a (really) long time to render.

Dependencies
------------
* FFmpeg: more specifically `libavcodec` and `libavutil`. Most linux package managers provide this. You can also download from [their website][ffmpeg_home].

License
-------
Licensed under the [MIT License][licenselink]

Third-Party Software
--------------------
The random number generator at `./include/utils/pcg` directory is sourced from [pcg-c-basic][pcg_code] which is licensed under the Apache License, Version 2.0.
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
