project('IREPEAT', 'cpp',
  version : '0.1'
)

if meson.get_compiler('cpp').get_id() == 'msvc'
  extra_args = ['/Zc:preprocessor']
else
  extra_args = []
endif

IREPEAT_dep = declare_dependency(
  include_directories : include_directories('.'),
  compile_args : extra_args
).partial_dependency(includes : 'true')

test('test IREPEAT',
  executable('test_IREPEAT', 'test_IREPEAT.cpp',
  cpp_args : extra_args)
)

test('test VREPEAT',
  executable('test_VREPEAT', 'test_VREPEAT.cpp',
  cpp_args : extra_args)
)
