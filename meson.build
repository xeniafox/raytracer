# project definition
project('raytracer', 'cpp', default_options : ['cpp_std=c++20'])

# source files
source_files = [
  'src/math.cc',
  'src/hittable.cc',
  'src/hittable_list.cc',
  'src/hit_record.cc',
  'src/color.cc',
  'src/material.cc',
  'src/ray.cc',
  'src/sphere.cc',
  'src/camera.cc',
  'src/dielectric.cc',
  'src/lambertian.cc',
  'src/metal.cc',
  'src/main.cc'
]

# libbacktrace
backtrace = dependency('libbacktrace', version : 'cci.20210118')

# kfrlib
cmake = import('cmake')
kfr_submodule = cmake.subproject('kfr')
kfr = kfr_submodule.dependency('kfr')

# binary
executable('raytracer', source_files, override_options : ['cpp_std=c++20'], dependencies : [backtrace, kfr])

# documentation
doxygen = find_program('doxygen', required : false)
if doxygen.found()
  message('Doxygen found')
  run_target('docs', command : [doxygen, meson.source_root() + '/Doxyfile'])
else
  warning('Documentation generation disabled as doxygen could not be found')
endif
