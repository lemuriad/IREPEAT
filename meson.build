# SPDX-FileCopyrightText: 2024 The Lemuriad <wjwray@gmail.com>
# SPDX-License-Identifier: BSL-1.0
project('irepeat', 'cpp',
  default_options : ['warning_level=3'],
  meson_version : '>=0.54.0',
  version : 'v0.6'
)

headers = files(
  'irepeat/IREPEAT.hpp',
  'irepeat/IREPEAT_UNDEF.hpp',
  'irepeat/VREPEAT.hpp',
  'irepeat/VREPEAT_DISPATCH.hpp',
  'irepeat/VREPEATx10.hpp',
  'irepeat/VREPEATx100.hpp',
  'irepeat/VREPEATx1000.hpp',
  'irepeat/VREPEATx10000.hpp',
)

install_headers(headers, subdir: 'irepeat')

extra_args = meson.get_compiler('cpp').get_supported_arguments('/Zc:preprocessor')

irepeat_dep = declare_dependency(
  include_directories : include_directories('irepeat'),
  compile_args : extra_args
).partial_dependency(includes : true, compile_args : true)

meson.override_dependency('irepeat', irepeat_dep)

import('pkgconfig').generate(
  name: 'irepeat',
  subdirs: 'irepeat',
  filebase: 'irepeat',
  description: 'Preprocessor utilities to generate indexed repetitions.',
  url: 'https://github.com/Lemuriad/irepeat',
)

if get_option('tests').disable_auto_if(meson.is_subproject()).allowed()

  test('test IREPEAT',
    executable('test_IREPEAT', 'tests/test_IREPEAT.cpp',
    dependencies : [irepeat_dep])
  )

  test('test VREPEAT',
    executable('test_VREPEAT', 'tests/test_VREPEAT.cpp',
    dependencies : [irepeat_dep])
  )

endif
