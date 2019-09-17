#include "IREPEAT.hpp"

/*
   Tests for IREPEAT.hpp indexed repetition macros.

   Current tests are static_assert-able.
   Test cases for preprocessor fail -> compile-fail
   will require a test framework with test runner;
   the USE_DOCTEST switch is a start.
 */

#if defined(USE_DOCTEST)

  #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
  #include "doctest.h"

#else

  #define TEST_CASE(...) namespace test
  #define CHECK(...) static_assert(__VA_ARGS__,"")
  #define CHECKSTR(C,S) CHECK(c_str_cmp(STR(C),S))
  int main() {}

#endif

// c_str_cmp(cstra,cstrb): C++11 constexpr C string compare, tail recurse.
constexpr bool c_str_cmp(const char* a, const char* b)
{
  return (*a == *b && (*a == 0 || c_str_cmp(a+1,b+1)));
}

// is_iota(array): C++11 constexpr test if array is index sequence 0,1,...
// poops out around 2^9
template <unsigned N,typename Int>
constexpr bool is_iota(Int(&&a)[N], unsigned i=0)
{
  return a[i]-i == 0 && (i+1 == N || is_iota(static_cast<Int(&&)[N]>(a),i+1));
}

// Concatenation tests
TEST_CASE("CATS") {

// CAT a SEQ of up to 16 elements
CHECKSTR(
  SEQCAT((0)(1)(2)(3)(4)(5)(6)(7)(8)(9)(a)(b)(c)(d)(e)(f)), "0123456789abcdef"
);
// CAT of >16 length SEQ drops elements after 16th
CHECKSTR(
  SEQCAT(()(0)(1)(2)(3)(4)(5)(6)(7)(8)(9)(a)(b)(c)(d)(e)(f)), "0123456789abcde"
);

// Remove up to three leading (0)'s
CHECKSTR( RMLZCAT((0)(0)(0)(HELLO)), "HELLO" );

// Remove up to three leading (0)'s leaves a 4th non-terminal (0)
CHECKSTR( RMLZCAT((0)(0)(0)(0)(HELL)), "0HELL" );

// RMLZ leaves a single (0) intact
CHECKSTR( RMLZCAT((0)), "0" );

// Hex literal prepends 0x CAT of up to 16 elements
CHECK(
  HEXLIT((0)(1)(2)(3)(4)(5)(6)(7)(8)(9)(a)(b)(c)(d)(e)(f)) == 0x123456789abcdef
);

}

TEST_CASE("Horizontal REPEAT") {

CHECKSTR( XREPEAT((0),WhAtEvEr,COMMA), "");
CHECKSTR( XREPEAT((1),SEQCAT,COMMA), "0");
CHECKSTR( IREPEAT((0),SEQCAT,COMMA), "0");

CHECKSTR( XREPEAT((8),SEQCAT,NOSEP), "01234567");
CHECKSTR( XREPEAT((f),SEQCAT,NOSEP), "0123456789abcde");
CHECKSTR( IREPEAT((f),SEQCAT,NOSEP), "0123456789abcdef");
CHECKSTR( XREPEAT((1)(0),RMLZCAT,NOSEP), "0123456789abcdef");

using uchars = unsigned char[];
using u16s = unsigned short[];

CHECK(is_iota<0xff>(uchars{XREPEAT((f)(f),HEXLIT,COMMA)}));
CHECK(is_iota<0x100>(u16s{IREPEAT((f)(f),HEXLIT,COMMA)}));

// This check is too big for the C++11 is_iota constexpr eval
//CHECK(is_iota<0xfff>(u16s{XREPEAT((f)(f)(f),HEXLIT,COMMA)}));

// For larger sizes, just check sizes of 0-initialized arrays
#define ZERO(HEXS) 0
CHECK(sizeof(uchars{XREPEAT((f)(f)(f),ZERO,COMMA)}) == 0xfff);
CHECK(sizeof(uchars{XREPEAT((1)(2)(3)(4),ZERO,COMMA)}) == 0x1234);

}

TEST_CASE("Nested REPEAT") {
/*
  Vertical repetition of horizontal expansion is a good way to nest;
  see the equivalent test case in test_VREPEAT.cpp

  IREPEAT / XREPEAT macros can't be directly nested (blue paint).
  However, (undocumented) lower-level repeat macros can nest.

  Here, IREPEAT expands the low-level REPS macro to create
  a 'triangle' of aggregate initializations of increasing size.
*/

// struct char_triangle {
//    char x0[1+0x0];char x1[1+0x1]; ... char xf[1+0xf]; };

#define CHAR_ARRAY_N(N) char xD(N)[1+HEXLIT(N)];
struct char_triangle {IREPEAT((f),CHAR_ARRAY_N,NOSEP)};

#define REP(N) {REPS(I,IDEN N,COMMA,HEX)}
// Aggregate-initialize array members with nested iota REPS
#define CHARTRI char_triangle{IREPEAT((f),REP,COMMA)}

CHECK(is_iota<1>(CHARTRI.x0));
CHECK(is_iota<2>(CHARTRI.x1));
CHECK(is_iota<3>(CHARTRI.x2));
// ...
CHECK(is_iota<15>(CHARTRI.xe));
CHECK(is_iota<16>(CHARTRI.xf));

#undef CHAR_ARRAY_N
#undef REP
#undef CHARTRI
}

#include "IREPEAT_UNDEF.hpp"
