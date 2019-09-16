#if defined(C2)
#define CMP1(D) CMP2(D2) > 0 || HEX(C1) - HEX(D)
#define HI1 HI2(D1)
#else
#define CMP1(D) HEX(C1) - HEX(D)
#define HI1 (D1)
#endif

#define D1 0
#include "VREPEATx10.hpp"
#define D1 1
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 2
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 3
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 4
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 5
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 6
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 7
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 8
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 9
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 a
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 b
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 c
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 d
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 e
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
#define D1 f
#if CMP1(D1) >= 0
#include "VREPEATx10.hpp"
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

#undef CMP1
#undef HI1

#undef D1
#undef D2 // defined in VREPEATx1000.hpp, undef here saves x10 undef there
