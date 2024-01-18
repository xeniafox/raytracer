# raytracer

A CPU-based raytracer made from scratch for learning

## Requirements

- A compiler compatible with C++20.

## Building

Check out the `kfr` submodule.

```bash
git submodule init
git submodule update --recursive
```

Set your desired C and C++ compilers and linkers at `utils/gen`. The defaults are `gcc` and `g++` as compilers and `ld.gold` as linker.

Generate the needed build files with

```bash
./utils/gen
```

Then, build the project.

```bash
ninja -C build/raytracer
```

The resulting file will be in `build/raytracer/raytracer`.

## How to use

```bash
./build/raytracer/raytracer > image.ppm
```

Then, open the `image.ppm` file for the resulting picture.
