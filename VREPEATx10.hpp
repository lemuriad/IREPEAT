#if defined(C1)
#define CMP0(D) CMP1(D1) > 0 || HEX(C0) - HEX(D)
#else
#define CMP0(D) HEX(C0) - HEX(D)
#define HI1
#endif

#define D0 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 1
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 2
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 3
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 4
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 5
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 6
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 7
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 8
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 9
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 a
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 b
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 c
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 d
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 e
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 f
#if CMP0(D0) >= 0
#include "VREPEAT_DISPATCH.hpp"
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

#undef CMP0


#undef D0
#undef D1 // defined in VREPEATx100.hpp, undef here saves x10 undef there
