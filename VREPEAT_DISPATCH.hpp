// Dispatch of VREPEAT_MACRO with VREPEAT_INDEX argument
// VREPEAT_MACRO is a macro or include-filename

# define VREPEAT_INDEX HI1(D0)
# if defined VREPEAT_MACRO_STR
#  include VREPEAT_MACRO_STR
# else
VREPEAT_MACRO(VREPEAT_INDEX)
# endif
# undef VREPEAT_INDEX
#undef D0 // defined in VREPEATx10.hpp, undef here saves x10 undef there
