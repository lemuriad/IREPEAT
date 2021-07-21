project('IREPEAT', 'cpp',
  default_options : ['warning_level=3'],
  version : '0.3'
)

if meson.get_compiler('cpp').get_id() == 'msvc'
  extra_args = ['/Zc:preprocessor']
elif meson.get_compiler('cpp').get_id() == 'clang'
  extra_args = ['-std=c++17']
else
  extra_args = []
endif

IREPEAT_dep = declare_dependency(
  include_directories : include_directories('.'),
  compile_args : extra_args
).partial_dependency(includes : true, compile_args : true)

test('test IREPEAT',
  executable('test_IREPEAT', 'test_IREPEAT.cpp',
  dependencies : [IREPEAT_dep])
)

test('test VREPEAT',
  executable('test_VREPEAT', 'test_VREPEAT.cpp',
  dependencies : [IREPEAT_dep])
)
