# SPDX-FileCopyrightText: 2023 The Lemuriad <opensource@lemurianlabs.com>
# SPDX-License-Identifier: BSL-1.0
project('irepeat', 'cpp',
  default_options : ['warning_level=3'],
  version : 'v0.6'
)

if meson.get_compiler('cpp').get_id() == 'msvc'
  extra_args = ['/Zc:preprocessor']
elif meson.get_compiler('cpp').get_id() == 'clang'
  extra_args = []
else
  extra_args = []
endif

irepeat_dep = declare_dependency(
  include_directories : include_directories('.'),
  compile_args : extra_args
).partial_dependency(includes : true, compile_args : true)

if get_option('tests').disable_auto_if(meson.is_subproject()).allowed()

  test('test IREPEAT',
    executable('test_IREPEAT', 'test_IREPEAT.cpp',
    dependencies : [irepeat_dep])
  )

  test('test VREPEAT',
    executable('test_VREPEAT', 'test_VREPEAT.cpp',
    dependencies : [irepeat_dep])
  )

endif
