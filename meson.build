project('IREPEAT', 'cpp',
  version : '0.1'
)

IREPEAT_dep = declare_dependency(
  include_directories : include_directories('.')
)
    
test('test IREPEAT',
  executable('test_IREPEAT', 'test_IREPEAT.cpp',
  cpp_args : '-pedantic')
)
