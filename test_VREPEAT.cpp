#include "IREPEAT.hpp"

/*
   Tests for VREPEAT.hpp
 */

#define TEST_CASE(...) namespace test
#define CHECK(...) static_assert(__VA_ARGS__,"")
#define CHECKSTR(C,S) CHECK(c_str_cmp(STR(C),S))

int main() {}

// c_str_cmp(cstra,cstrb): C++11 constexpr C string compare, tail recurse.
constexpr bool c_str_cmp(const char* a, const char* b)
{
  return (*a == *b && (*a == 0 || c_str_cmp(a+1,b+1)));
}

// is_iota(array): C++11 constexpr test if array is index sequence 0,1,...
// poops out around 2^9
template <unsigned N,typename Int>
constexpr bool is_iota(Int(&a)[N], unsigned i=0)
{
  return a[i]-i == 0 && (i+1 == N || is_iota(static_cast<Int(&)[N]>(a),i+1));
}

TEST_CASE("Vertical REPEAT") {

#define VREPEAT_COUNT (0)
#define VREPEAT_MACRO SEQCAT
#define VREPEAT_SEPARATOR COMMA
constexpr int vrep0 {
#include "VREPEAT.hpp"
};
CHECK(vrep0 == 0);

#define VREPEAT_COUNT (f)
#define VREPEAT_MACRO HEXLIT
#define VREPEAT_SEPARATOR COMMA
constexpr int vreps0x10[] {
#include "VREPEAT.hpp"
};
CHECK(is_iota<0x10>(vreps0x10));

#define VREPEAT_COUNT (1)(0)
#define VREPEAT_MACRO HEXLIT
#define VREPEAT_SEPARATOR COMMA
constexpr int vreps0x11[] {
#include "VREPEAT.hpp"
};
CHECK(is_iota<0x11>(vreps0x11));

#define VREPEAT_COUNT (f)(e)
#define VREPEAT_MACRO HEXLIT
#define VREPEAT_SEPARATOR COMMA
constexpr int vreps0xff[] {
#include "VREPEAT.hpp"
};
CHECK(is_iota<0xff>(vreps0xff));

}

TEST_CASE("Nested REPEAT") {
/*
  Vertical repetition of horizontal expansion.
*/

#define CHAR_ARRAY_N(N) char xD(N)[1+HEXLIT(N)];

/* Generates vertical expansion of member arrays

struct char_triangle {
  char x0[1+0x0];
  char x1[1+0x1];
  ...
  char xf[1+0xf];
 };                    */

#define VREPEAT_COUNT (f)
#define VREPEAT_MACRO CHAR_ARRAY_N

struct char_triangle {
#include "VREPEAT.hpp"
};

#define REP(N) {IREPEAT(N,HEXLIT,COMMA)}

#define VREPEAT_COUNT (f)
#define VREPEAT_MACRO REP
#define VREPEAT_SEPARATOR COMMA
// Aggregate-initialize array members with nested iota REPS
constexpr char_triangle chartri{
#include "VREPEAT.hpp"
};

CHECK(is_iota<1>(chartri.x0));
CHECK(is_iota<2>(chartri.x1));
CHECK(is_iota<3>(chartri.x2));
// ...
CHECK(is_iota<15>(chartri.xe));
CHECK(is_iota<16>(chartri.xf));

#undef CHAR_ARRAY_N
#undef REP
#undef CHARTRI
}

#include "IREPEAT_UNDEF.hpp"
