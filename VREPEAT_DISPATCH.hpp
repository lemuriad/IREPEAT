// Dispatch of VREPEAT_MACRO with VREPEAT_INDEX argument
// VREPEAT_MACRO is a macro or include-filename

#define VREPEAT_INDEX D3D2D1(D0)
#define NREPEAT CAT(OxD3D2D1,D0)
#if defined VREPEAT_MACRO_STR
#  include VREPEAT_MACRO_STR
#elif defined (VREPEAT_SEPARATOR) && NREPEAT < NREPEATS
VREPEAT_MACRO(VREPEAT_INDEX)VREPEAT_SEPARATOR()
#else
VREPEAT_MACRO(VREPEAT_INDEX)
#endif
#undef VREPEAT_INDEX
#undef NREPEAT
#undef D0 // defined in VREPEATx10.hpp, undef here saves x10 undef there
