#if defined(C4) // C4 would be a 5th count digit
#define CMP3(D) CMP4(D4) > 0 || HEX(C3) - HEX(D)
#define HI3 HI4(D3)
#else
#define CMP3(D) HEX(C3) - HEX(D)
#define HI3 (D3)
#endif

#define D3 0
#include "VREPEATx1000.hpp"
#define D3 1
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 2
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 3
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 4
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 5
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 6
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 7
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 8
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 9
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 a
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 b
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 c
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 d
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 e
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
#define D3 f
#if CMP3(D3) >= 0
#include "VREPEATx1000.hpp"
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

#undef CMP3
#undef HI3

#undef D3
#undef D4
