//  Copyright (c) 2019 Will Wray https://keybase.io/willwray
//
//  Distributed under the Boost Software License, Version 1.0.
//        http://www.boost.org/LICENSE_1_0.txt
//
//  Repo: https://github.com/willwray/IREPEAT

#ifndef IREPEAT_HPP
#define IREPEAT_HPP
// IREPEAT_UNDEF.hpp #undef's all preprocessor names #define'd here
// including the IREPEAT_HPP header guard, for cleanup before reuse.

/*
   IREPEAT.hpp
   ===========
   C++ preprocessor macro utilities to generate indexed repetitions.
   Expands up to 2^16 repetitions (current 4 hex-digit index limit).

   Horizontal vs vertical repetition:
   ---------------------------------
   Macro expansion is 'horizontal'; expanding to a single long line.
   'Vertical' repetition works by repeated file inclusion to expand
   each repetition of a macro on its own line; see doc for examples
   using the VREPEAT.hpp header.

   This header defines indexed repeat macros IREPEAT and XREPEAT:

     IREPEAT(N,M,S) -> M((0)) S() M((1)) S() ... M(N-1) S() M(N)
     XREPEAT(N,M,S) -> M((0)) S() ... M(N-2) S() M(N-1)

   I for Inclusive: M(H) is repeated N+1 times for H in range [0,N]
   X for eXclusive: M(H) is repeated N times for H in range [0,N)

   Both N and the generated H... indices are represented as HEXS;
   sequences of up to 4 hexadecimal digits (with lowercase abcdef);
   HEXS number = (h0) | (h1)(h0) | (h2)(h1)(h0) | (h3)(h2)(h1)(h0)

   N is the number of XREPEATS. The number of IREPEATS is N + 1.
   M is a macro, or tokens, parameterized by HEXS repeat-index H.
   S is a separator-generator argument such that S() is a separator;
     COMMA, COLON and NOSEP gernerators are provided.

   The generated H... ordinals are of the same length as cardinal N:

     XREPEAT((0)(3),X,COLON); -> X((0)(0));X((0)(1));X((0)(2));

     IREPEAT((f)(f),x0D,COMMA) // Generates 256 comma separated ids
                               // x00,x01 ... x0f,x10 ... xfe,xff

   Number and sequence utilities:
   -----------------------------
   Indexed access,for the first four SEQ elements SEQ##N(SEQ):
   * SEQ0, SEQ1, SEQ2, SEQ3: N+1th SEQ elem or empty if off the end.

   * LEN(SEQ): Length of SEQ up to 15 elems, as a single hex digit.
   * RMLZ(HEXS): Remove a leading (0) for HEXS, preserve a sole (0).
   * RMLZ3(HEXS): Remove up to 3 leading zeros, for 4-digit HEXS.
   * SEQCAT(SEQ): Concatenate up to 16 catable SEQ elements.
   * RMLZCAT(HEXS): Remove leading zeros from HEXS then CAT remains.

   Add prefixes to concatenated digits:
   * HEXLIT(HEXS): adds 0x prefix to SEQCAT to make a hex literal.
   * xD(HEXS), XD(HEXS): add x/X prefix to RMLZCAT for short ids.
   * x0D(HEXS), X0D(HEXS): add x/X prefix to SEQCAT to make ids.

   Other common macro utils are provided with common short names.

   Sequences are flexible and efficient for further preprocessing.
   HEXS increment and decrement is possible to arbitrary precision;
   implementing arithemtic is out of scope here, see chaos-pp.
 */

// XREPEAT(HEXS,M,S) Exclusive indexed repeat to separated list.
// IREPEAT(HEXS,M,S) Inclusive indexed repeat to separated list.
//         HEXS: repeat count as HEXS digits, e.g. (f)(f) == 255
//         M: macro / tokens to expand, each with index M(hexs)
//         S: separator-generator, e.g. COMMA / COLON / NOSEP
#define XREPEAT(HEXS,M,S) DOREPEAT(X,LEN(HEXS),HEXS,S,M)
#define IREPEAT(HEXS,M,S) DOREPEAT(I,LEN(HEXS),HEXS,S,M)

// STR(X): Stringize
#define STR_(A) #A
#define STR(A) STR_(A)

// CAT(A,B): Concatenate pair of args
#define CAT_(A,B) A##B
#define CAT(A,B) CAT_(A,B)

// POSTCAT(P,...): Append-concat leading arg P to remaining arg(s)
#define POSTCAT_(P,...)__VA_ARGS__##P
#define POSTCAT(P,...) POSTCAT_(P,__VA_ARGS__)

// EAT (...) 'consumes' parenthesized (...)
// IDEN strips parens off parenthesized (...)
// IDEP adds another level of parens -> ((...))
#define EAT(...)
#define IDEN(...) __VA_ARGS__
#define IDEP(...) ((__VA_ARGS__))

// ARG0(...) expands to first argument, before ',', in (...)
#define ARG0_(A,...) A
#define ARG0(...) ARG0_(__VA_ARGS__)
// ARG1(...) expands to second argument, after ',', in (...)
#define ARG1_(_,B,...) B
#define ARG1(...) ARG1_(__VA_ARGS__)

// SHEAD(SEQ): SEQ HEAD, yields 1st SEQ elem, parens stripped.
#define SHEAD(SEQ) ARG0(SHED SEQ())
#define SHED(H) H,

// SEQ##N(SQ): Access by index up to 4th element. Zero-based index 0,1,2,3
// Returns empty for off-the-end access.
#define SEQ0 SHEAD
#define SEQ1(SQ) SEQ0(EAT SQ())
#define SEQ2(SQ) SEQ1(EAT SQ())
#define SEQ3(SQ) SEQ2(EAT SQ())
#define SEQ(N) CAT(SEQ,N)

// CSV(SEQ): Transform SEQ to list of elem,...
// SEQ is arbitrary length and may have empty elements.
// e.g. CSV((a)(b)()(c)(d)) -> a,b,,c,d,
#define CSV(SEQ) POSTCAT(_,CSVu SEQ)
#define CSVu(E) E,CSVv
#define CSVv(E) E,CSVu
#define CSVv_
#define CSVu_

// LEN(SEQ): Length of SEQ of up to 15 elems. Returns a single hex digit.
// SEQ of length 16 returns empty, more than 16 returns the 17th element.
// e.g. LEN((a)()(c)) -> 3
#define LEN(SEQ) VLEN(CSV(SEQ))

// VLEN(...): Variadic length of arg tuple (a,b,c,...) up to 15 args.
#define VLEN_(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,...) Q
#define VLEN(...) VLEN_(__VA_ARGS__,f,e,d,c,b,a,9,8,7,6,5,4,3,2,1,0)

// VCAT(...): Variadic cat of tuple args - up to the leading 16
#define VCAT_(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,...) \
A##B##C##D##E##F##G##H##I##J##K##L##M##N##O##P
#define VCAT(...) VCAT_(__VA_ARGS__,,,,,,,,,,,,,,,,)

// SEQCAT(SEQ): concatenate up to 16 leading sequence elements
#define SEQCAT(SEQ) VCAT(CSV(SEQ))
// RMLZCAT(HEXS): Remove leading zeros from HEXS seq then CAT the digits.
#define RMLZCAT(HEXS) VCAT(CSV(RMLZ3(HEXS)))

// RMLZ(HEXS): Remove a leading (0) from HEXS seq, leave sole (0) as (0).
#define RMLZ(HEXS) ARG1(RMLZ_ HEXS,,)HEXS
#define RMLZ_(D) CAT(RMLZ_,D)
#define RMLZ_0(D) ,EAT,
// RMLZ3(HEXS): Remove up to three leading (0)(0)(0) from HEXS seq.
#define RMLZ3(HEXS) RMLZ(RMLZ(RMLZ(HEXS)))

// xD(N), XD(N): Generate id; prepend 'x' or 'X' to significant hexits.
// x0D(N), X0D(N): Generate ids as above but preserve leading zeros.
#define xD(HEXS) CAT(x,RMLZCAT(HEXS))
#define XD(HEXS) CAT(X,RMLZCAT(HEXS))
#define x0D(HEXS) CAT(x,SEQCAT(HEXS))
#define X0D(HEXS) CAT(X,SEQCAT(HEXS))

#define HEX(D) CAT(0x,D)
#define HEXLIT(HEXS) HEX(SEQCAT(HEXS))

// Separator-generator function macros
#define NOSEP()
#define COMMA() ,
#define COLON() ;

// XREPS##N(S,M): N exclusive indexed repeats M(H)... with S() separator;
// N is a hex value <= 10, H... a hex index-sequence [0,N) == 0 ... N-1
#define XREPS0(S,M)
#define XREPS1(S,M) M(0)
#define XREPS2(S,M) M(0)S()M(1)
#define XREPS3(S,M) M(0)S()M(1)S()M(2)
#define XREPS4(S,M) M(0)S()M(1)S()M(2)S()M(3)
#define XREPS5(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)
#define XREPS6(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)
#define XREPS7(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)
#define XREPS8(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)
#define XREPS9(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)S()\
M(8)
#define XREPSa(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)S()\
M(8)S()M(9)
#define XREPSb(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)S()\
M(8)S()M(9)S()M(a)
#define XREPSc(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)S()\
M(8)S()M(9)S()M(a)S()M(b)
#define XREPSd(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)S()\
M(8)S()M(9)S()M(a)S()M(b)S()M(c)
#define XREPSe(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)S()\
M(8)S()M(9)S()M(a)S()M(b)S()M(c)S()M(d)
#define XREPSf(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)S()\
M(8)S()M(9)S()M(a)S()M(b)S()M(c)S()M(d)S()M(e)
#define XREPS10(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)S()\
M(8)S()M(9)S()M(a)S()M(b)S()M(c)S()M(d)S()M(e)S()M(f)

// IREPS##N(S,M): N+1 inclusive indexed repeats M(H)... with S() separator;
// N is a single hex digit, H... a hex index-sequence [0,N] == 0 ... N
#define IREPS0 XREPS1
#define IREPS1 XREPS2
#define IREPS2 XREPS3
#define IREPS3 XREPS4
#define IREPS4 XREPS5
#define IREPS5 XREPS6
#define IREPS6 XREPS7
#define IREPS7 XREPS8
#define IREPS8 XREPS9
#define IREPS9 XREPSa
#define IREPSa XREPSb
#define IREPSb XREPSc
#define IREPSc XREPSd
#define IREPSd XREPSe
#define IREPSe XREPSf
#define IREPSf XREPS10

// XREPT##N(T,M): N exclusive indexed repeats M(H)... with T() terminator;
// N is a single hex digit, H... a hex index-sequence [0,N) == 0 ... N-1
#define XREPT0(T,M) XREPS0(T,M)
#define XREPT1(T,M) XREPS1(T,M)T()
#define XREPT2(T,M) XREPS2(T,M)T()
#define XREPT3(T,M) XREPS3(T,M)T()
#define XREPT4(T,M) XREPS4(T,M)T()
#define XREPT5(T,M) XREPS5(T,M)T()
#define XREPT6(T,M) XREPS6(T,M)T()
#define XREPT7(T,M) XREPS7(T,M)T()
#define XREPT8(T,M) XREPS8(T,M)T()
#define XREPT9(T,M) XREPS9(T,M)T()
#define XREPTa(T,M) XREPSa(T,M)T()
#define XREPTb(T,M) XREPSb(T,M)T()
#define XREPTc(T,M) XREPSc(T,M)T()
#define XREPTd(T,M) XREPSd(T,M)T()
#define XREPTe(T,M) XREPSe(T,M)T()
#define XREPTf(T,M) XREPSf(T,M)T()

// REPS(V,N,S,M) repeat M(n) 'calls' with S() separator.
#define REPS_(V,D,S,M) V##REPS##D(S,M)
#define REPS(V,D,S,M) REPS_(V,D,S,M)

// XREPT(V,N,T,M) repeat M(n) 'calls' with T() terminator.
#define XREPT(D,S,M) XREPT##D(S,M)
#define IREPT(D,T,M) IREPS##D(T,M)T()
#define REPT(V,D,T,M) V##REPT(D,T,M)

// PRE_##E prepend hex digit (E) to start of parenthesized tokens
#define PRE_0(...) ((0)__VA_ARGS__)
#define PRE_1(...) ((1)__VA_ARGS__)
#define PRE_2(...) ((2)__VA_ARGS__)
#define PRE_3(...) ((3)__VA_ARGS__)
#define PRE_4(...) ((4)__VA_ARGS__)
#define PRE_5(...) ((5)__VA_ARGS__)
#define PRE_6(...) ((6)__VA_ARGS__)
#define PRE_7(...) ((7)__VA_ARGS__)
#define PRE_8(...) ((8)__VA_ARGS__)
#define PRE_9(...) ((9)__VA_ARGS__)
#define PRE_a(...) ((a)__VA_ARGS__)
#define PRE_b(...) ((b)__VA_ARGS__)
#define PRE_c(...) ((c)__VA_ARGS__)
#define PRE_d(...) ((d)__VA_ARGS__)
#define PRE_e(...) ((e)__VA_ARGS__)
#define PRE_f(...) ((f)__VA_ARGS__)

#define PRED(D) PRE_##D
#define PRE(D) PRED(D)

// POST_##E append hex digit (E) to end of parenthesized tokens
#define POST_0(...) (__VA_ARGS__(0))
#define POST_1(...) (__VA_ARGS__(1))
#define POST_2(...) (__VA_ARGS__(2))
#define POST_3(...) (__VA_ARGS__(3))
#define POST_4(...) (__VA_ARGS__(4))
#define POST_5(...) (__VA_ARGS__(5))
#define POST_6(...) (__VA_ARGS__(6))
#define POST_7(...) (__VA_ARGS__(7))
#define POST_8(...) (__VA_ARGS__(8))
#define POST_9(...) (__VA_ARGS__(9))
#define POST_a(...) (__VA_ARGS__(a))
#define POST_b(...) (__VA_ARGS__(b))
#define POST_c(...) (__VA_ARGS__(c))
#define POST_d(...) (__VA_ARGS__(d))
#define POST_e(...) (__VA_ARGS__(e))
#define POST_f(...) (__VA_ARGS__(f))

#define POST(D) POST_##D

// DOREPEAT: Dispatch to fixed-length N REPEAT##N
#define DOREPEAT(V,N,Ds,S,M) CAT(REPEAT,N)(V,Ds,S,M)
#define DOREP1(...) __VA_ARGS__
#define DOREP2(...) __VA_ARGS__
#define DOREP3(...) __VA_ARGS__
#define DOREP4(...) __VA_ARGS__

// REPEATN(...) N-digit repeaters
#define REPEAT1(V,D,S,M) DOREP1(REPS(V,IDEN D,S,M IDEP))

#define REPEAT2(V,DD,S,M) DOREP2(\
DOREP2(REPT(X,SHEAD(DD),(I,(f),S,M PRE)S,REPEAT1 POST))\
REPEAT1(V,EAT DD,S,M PRE(SHEAD(DD))))

#define REPEAT3(V,DDD,S,M) DOREP3(\
DOREP3(REPT(X,SHEAD(DDD),(I,(f)(f),S,M PRE)S,REPEAT2 POST))\
REPEAT2(V,EAT DDD,S,M PRE(SHEAD(DDD))))

#define REPEAT4(V,DDDD,S,M) DOREP4(\
DOREP4(REPT(X,SHEAD(DDDD),(I,(f)(f)(f),S,M PRE)S,REPEAT3 POST))\
REPEAT3(V,EAT DDDD,S,M PRE(SHEAD(DDDD))))

#endif
