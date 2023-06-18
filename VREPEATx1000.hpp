#if 0
 SPDX-FileCopyrightText: 2023 The Lemuriad <opensource@lemurianlabs.com>
 SPDX-License-Identifier: BSL-1.0
#endif
#if defined(C3)
#define OxD3 CAT(0x,D3)
#define D3D2 (D3)(D2)
#else
#define OxD3 0x
#define D3D2 (D2)
#endif

#define D2 0
#include "VREPEATx100.hpp"
#define D2 1
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 2
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 3
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 4
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 5
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 6
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 7
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 8
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 9
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 a
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 b
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 c
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 d
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 e
#if CAT(OxD3,D2)*0x100 <= NREPEATS
#include "VREPEATx100.hpp"
#define D2 f
#if CAT(OxD3,D2)*0x100 <= NREPEATS
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

#undef OxD3
#undef D3D2

#undef D2
#undef D3
