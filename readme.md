# **`IREPEAT`**

## C++ preprocessor macros for indexed repetitions

<details><summary>Copyright &copy; 2024 The Lemuriad. Distributed under the Boost Software License, V1.0</summary>

### **Boost Software License** - Version 1.0 - August 17th, 2003

```txt
Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
```

[![License](https://img.shields.io/badge/license-boost%201.0-blue.svg)](https://www.boost.org/LICENSE_1_0.txt)

Also at [boost.org](http://www.boost.org/LICENSE_1_0.txt) and accompanying file [LICENSE_1_0.txt](LICENSE_1_0.txt)

</details>

------

![GitHub Actions Badge](../../actions/workflows/ci.yml/badge.svg)
GitHub Actions meson build: linux gcc10 & 12, clang 12 & 14, macos 12, windows latest

------

### IREPEAT, XREPEAT and VREPEAT

Preprocessor utilities to generate indexed repetitions, for codegen & etc.  
The maximum repetition count is 2^16 = 65536; a 4 hex-digit index limit.

------

```c++
// IREPEAT_example.hpp
#include "IREPEAT.hpp"
IREPEAT((f)(f),HEXLIT,COMMA) // Generate 256 values 0-255
#include "IREPEAT_UNDEF.hpp"
```

<details><summary><b>Preprocess</b>: e.g. <code>cpp -P -E IREPEAT_example.hpp</code> ...</summary>

The provided `HEXLIT` macro is expanded 256 times to a comma-separated list  
of hexadecimal literals, ranging from `0x00` to `0xff` inclusive. The double-digit  
output reflects the number of digits in the specified end index `(f)(f)`:

```cpp
0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,...
 ... 0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff
```

</details>

------

### **`IREPEAT.hpp`**: Horizontal repetition

<details><summary>Macro expansion is '<b>horizontal</b>'; replacements are made within a single line.</summary>

Indexed-repeat macros expand to a single long line of separated repetitions:

```cpp
IREPEAT(N,M,S) -> M((0)) S() M((1)) S() ... M(N-1) S() M(N)
XREPEAT(N,M,S) -> M((0)) S() ... M(N-2) S() M(N-1)
```

**I** for **I**nclusive: **M(H)** is repeated **N+1** times for **H** in range **[0,N]**  
**X** for e**X**clusive: **M(H)** is repeated **N** times for **H** in range **[0,N)**

* **N** is the number of **XREPEAT**s. The number of **IREPEAT**s is **N + 1**.
* **M** is a macro, or tokens, parameterized by HEXS repeat-index H.
* **S** is a separator-generator argument, i.e. **S()** expands to a separator.

Number **N** (the provided 'cardinal') and its generated repeat-indices **H**... ('ordinals')  
are represented as 'HEXS'; sequences of (adjacent parenthesized) hex digits:

```cpp
 XREPEAT((0)(3),X,COLON); -> X((0)(0));X((0)(1));X((0)(2));
 XREPEAT((0)(0),X,COLON); -> ; // caution; 0-length XREPEAT
```

Note that generated indices have the same number of digits as their cardinal **N**.  
Beware of vanishing zero-length XREPEAT; use IREPEAT, I repeat, use IREPEAT.

</details>

------

### **`VREPEAT.hpp`**: Vertical repetition

<details><summary>'<b>Vertical</b>' repetition expands each rep on its own line by repeated <code>#include</code></summary>

First, #define `VREPEAT_MACRO` and `VREPEAT_COUNT` (inclusive),  
and optionally #define `VREPEAT_SEPARATOR` to add separators,  
then `#include "VREPEAT.hpp"` to process the repetitions:

```cpp
#include "IREPEAT.hpp"

#define VREPEAT_COUNT (f)(f) // 0xff for 256 incl. reps
#define VREPEAT_MACRO Iteration HEXLIT
#define VREPEAT_SEPARATOR COMMA
#include "VREPEAT.hpp"

#include "IREPEAT_UNDEF.hpp"
```

Preprocesses to:

```cpp
Iteration 0x00,
Iteration 0x01,
  ...
Iteration 0xfe,
Iteration 0xff
```

`VREPEAT_MACRO` expands either (1) as a macro or (2) by `#include`:

1. `VREPEAT_MACRO(VREPEAT_INDEX)`

2. `#include STR(VREPEAT_MACRO)`

`#include` expansion (2) is used if `__has_include__(STR(VREPEAT_MACRO))`  
i.e. the stringized `VREPEAT_MACRO` is the name of a file in the include path.

Otherwise, macro expansion (1) is used with `VREPEAT_SEPARATOR()` appended,  
if defined, on all but the final repeat (when `NREPEAT == NREPEATS`).  
A separator is not added after #include expansion (2); add it in the file if needed.

The following preprocessor names are set automatically:

* `VREPEAT_INDEX`: The repeat index digits in HEXS format
* `C3`,`C2`,`C1`,`C0`: Individual hex digits of `VREPEAT_COUNT`
* `D3`,`D2`,`D1`,`D0`: Individual hex digits of `VREPEAT_INDEX`
* `NREPEAT`: The repeat index as an integer literal
* `NREPEATS`: `VREPEAT_COUNT` as an integer literal

`#include "VREPEAT.hpp"` undef's these symbols and all others it defines  
so can be used repeatedly.

</details>

------

### **`HEXS`**: hexadecimal digit sequences

<details><summary><b>Numbers</b> are represented as hex digit sequences, e.g. <code>(1)(f) == 0x1f == 31</code></summary>

The HEXS representation here has up to 4 parenthesized hexadecimal digits:

```cpp
HEXS = (h0) | (h1)(h0) | (h2)(h1)(h0) | (h3)(h2)(h1)(h0)
```

The hex letter-digits are required to be lowercase only.

Four digits is a practical repeat-count limit; 2^16 reps take ~1s and ~1Gbyte.

</details>

## [Documentation page](documentation.md)

```c++
// Don't forget to #undef your #define's
#include <IREPEAT_UNDEF.hpp>
```

------

## Credits

Props to pre-pro pioneers, particularly Paul Mensonides.  
