#if 0
 SPDX-FileCopyrightText: 2023 The Lemuriad <opensource@lemurianlabs.com>
 SPDX-License-Identifier: BSL-1.0
#endif
#if defined(C1)
#define OxD3D2D1 CAT(OxD3D2,D1)
#else
#define OxD3D2D1 0x
#define D3D2D1
#endif

#define D0 0
#include "VREPEAT_DISPATCH.hpp"
#define D0 1
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 2
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 3
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 4
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 5
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 6
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 7
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 8
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 9
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 a
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 b
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 c
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 d
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 e
#if CAT(OxD3D2D1,D0) <= NREPEATS
#include "VREPEAT_DISPATCH.hpp"
#define D0 f
#if CAT(OxD3D2D1,D0) <= NREPEATS
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

#undef OxD3D2D1

#undef D0
#undef D1
