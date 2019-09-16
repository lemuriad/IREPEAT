#if defined(C3)
#define CMP2(D) CMP3(D3) > 0 || HEX(C2) - HEX(D)
#define HI2 HI3(D2)
#else
#define CMP2(D) HEX(C2) - HEX(D)
#define HI2 (D2)
#endif

#define D2 0
#include "VREPEATx100.hpp"
#define D2 1
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 2
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 3
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 4
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 5
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 6
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 7
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 8
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 9
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 a
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 b
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 c
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 d
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 e
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#define D2 f
#if CMP2(D2) >= 0
#include "VREPEATx100.hpp"
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif

#undef CMP2
#undef HI2

#undef D2
#undef D3 // defined in VREPEATx10000.hpp, undef here saves x10 undef there
