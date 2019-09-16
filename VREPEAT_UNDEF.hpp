/*
  User should first:
  #include "IREPEAT.hpp"
  #define VREPEAT_COUNT // HEXS repeat-count number
  #define VREPEAT_MACRO // Macro or include-file to repeat
*/
#if __has_include(STR(VREPEAT_MACRO))
#define VREPEAT_MACRO_STR STR(VREPEAT_MACRO)
#endif

#define NDIGITS LEN(VREPEAT_COUNT)
#if NDIGITS == 1
#  define C0 SEQ0(VREPEAT_COUNT)
#  include "VREPEATx10.hpp"
#elif NDIGITS == 2
#  define C1 SEQ0(VREPEAT_COUNT)
#  define C0 SEQ1(VREPEAT_COUNT)
#  include "VREPEATx100.hpp"
#elif NDIGITS == 3
#  define C2 SEQ0(VREPEAT_COUNT)
#  define C1 SEQ1(VREPEAT_COUNT)
#  define C0 SEQ2(VREPEAT_COUNT)
#  include "VREPEATx1000.hpp"
#elif NDIGITS == 4
#  define C3 SEQ0(VREPEAT_COUNT)
#  define C2 SEQ1(VREPEAT_COUNT)
#  define C1 SEQ2(VREPEAT_COUNT)
#  define C0 SEQ3(VREPEAT_COUNT)
#  include "VREPEATx10000.hpp"
#endif

#undef VREPEAT_MACRO_STR
#undef NDIGITS
