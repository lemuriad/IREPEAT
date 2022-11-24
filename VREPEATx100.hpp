#if defined(C2)
#define OxD3D2 CAT(OxD3,D2)
#define D3D2D1 D3D2(D1)
#else
#define OxD3D2 0x
#define D3D2D1 (D1)
#endif

#define D1 0
#include "VREPEATx10.hpp"
#define D1 1
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 2
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 3
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 4
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 5
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 6
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 7
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 8
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 9
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 a
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 b
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 c
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 d
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 e
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
#include "VREPEATx10.hpp"
#define D1 f
#if CAT(OxD3D2,D1)*0x10 <= NREPEATS
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

#undef OxD3D2
#undef D3D2D1

#undef D1
#undef D2
