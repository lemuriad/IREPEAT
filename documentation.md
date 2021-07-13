IREPEAT, XREPEAT and VREPEAT
============================

C++ preprocessor macro utilities for indexed repetitions
--------------------------------------------------------

Expands up to 2^16 repetitions (current 4 hex-digit index limit).

Horizontal vs vertical repetition
---------------------------------

Headers `IREPEAT.hpp` and `VREPEAT.hpp` provide for horizontal
and vertical expansions.

Macro expansion is inherently 'horizontal', expanding to a single
long line.  
'Vertical' repetition works by repeated file inclusion to expand
each repetition of a macro on its own line.

IREPEAT.hpp
-----------

This header defines horizontal indexed repeat macros `IREPEAT` and `XREPEAT`:

* `IREPEAT(N,M,S)` -> `M((0)) S() M((1)) S() ... M(N-1) S() M(N)`  
* `XREPEAT(N,M,S)` -> `M((0)) S() ... M(N-2) S() M(N-1)`

`I` for Inclusive: `M(H)` is repeated `N+1` times for `H` in range `[0,N]`  
`X` for eXclusive: `M(H)` is repeated `N` times for `H` in range `[0,N)`

* `N` is the number of `XREPEAT`s. The number of `IREPEAT`s is `N+1`.
* `M` is a macro, or tokens, parameterized by `HEXS` repeat-index `H`.
* `S` is a separator-generator argument such that `S()` is a separator;  
  `COMMA`, `COLON` and `NOSEP` generators are provided.

HEXS number representation
--------------------------

Both `N` and the generated `H...` indices are represented as `HEXS`;  
sequences of up to 4 hexadecimal digits, individually parenthesised  
(with the alphabetic hex digits lowercase - a,b,c,d,e,f).

E.g. `(0)` represents 0, `(f)` represents 15, `(2)(0)` represents 32.

Examples
--------

`(0)` generates a single repetition with `IREPEAT`, nothing with `XREPEAT`:

```cpp
  IREPEAT((0),X,COMMA) -> X(0)
  XREPEAT((0),X,COMMA) -> 
```

The generated `H...` ordinals are of the same length as cardinal `N`:

* `XREPEAT((0)(3),X,COLON);` -> `X((0)(0));X((0)(1));X((0)(2));`  
* `IREPEAT((f)(f),x0D,COMMA)` -> `x00,x01 ... x0f,x10 ... xfe,xff`  
256 comma separated ids, using the provided `x0D` macro listed below.

Number and sequence utilities
-----------------------------

Indexed access, for the first four `SEQ` elements `SEQ##N(SEQ)`:

* `SEQ0`, `SEQ1`, `SEQ2`, `SEQ3`: N+1th SEQ elem or empty if off the end.
* `LEN(SEQ)`: Length of `SEQ` up to 15 elems, as a single hex digit.
* `RMLZ(HEXS)`: Remove a leading `(0)` for `HEXS`, preserve a sole `(0)`.
* `RMLZ3(HEXS)`: Remove up to 3 leading zeros, for 4-digit `HEXS`.
* `SEQCAT(SEQ)`: Concatenate up to 16 catable `SEQ` elements.
* `RMLZCAT(HEXS)`: Remove leading zeros from `HEXS` then `CAT` remains.

Add prefixes to concatenated digits:

* `HEXLIT(HEXS)`: adds `0x` prefix to `SEQCAT` to make a hex literal.
* `xD(HEXS)`, `XD(HEXS)`: add `x`/`X` prefix to `RMLZCAT` for short ids.
* `x0D(HEXS)`, `X0D(HEXS)`: add `x`/`X` prefix to `SEQCAT` to make ids.

Other common macro utils are provided with common short names.  
Sequences are flexible and efficient for further preprocessing.  
`HEXS` increment and decrement is possible to arbitrary precision;  
implementing arithemtic is out of scope here, see chaos-pp.

VREPEAT.hpp
-----------

This header defines vertical indexed repeat macro `VREPEAT`.

Here is a basic usage example:

```c++
#include "IREPEAT.hpp"
#define VREPEAT_COUNT (4)
#define VREPEAT_MACRO Iteration
#define VREPEAT_SEPARATOR() ,
#include "VREPEAT.hpp"             // 
#include "IREPEAT_UNDEF.hpp"
```

The `"VREPEAT.hpp"` header depends on prior inclusion of `"IREPEAT.hpp"`.

The `VREPEAT` parameters are set to:

* An inclusive `VREPEAT_COUNT` of 4
* A `VREPEAT_MACRO` - here the symbol `Iteration`
* A `VREPEAT_SEPARATOR` - here just the comma `,`

Preprocessing with `cc -E -P "VREPEAT_example.hpp"`  
generates:

```
Iteration((0)),
Iteration((1)),
Iteration((2)),
Iteration((3)),
Iteration((4))
```

Normally, the macro will use its argument e.g. as the repetition count of an `IREPEAT`.

For more examples see `test_IREPEAT.cpp` and `test_VREPEAT.cpp`.
