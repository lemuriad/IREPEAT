# SPDX-FileCopyrightText: 2024 The Lemuriad <wjwray@gmail.com>
# SPDX-License-Identifier: BSL-1.0
project('irepeat', 'cpp',
  default_options : ['warning_level=3'],
  version : 'v0.6'
)

extra_args = meson.get_compiler('cpp').get_supported_arguments('/Zc:preprocessor')

irepeat_dep = declare_dependency(
  include_directories : include_directories('.'),
  compile_args : extra_args
).partial_dependency(includes : true, compile_args : true)

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
