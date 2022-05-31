#ifndef IREPEAT_HPP // IREPEAT_UNDEF.hpp #undef's all #define'd symbols
#define IREPEAT_HPP // including the IREPEAT_HPP header guard.

#define IREPEAT_HPP_DOC /*

  Copyright (c) 2019 Will Wray https://keybase.io/willwray

  Distributed under the Boost Software License, Version 1.0.
        http://www.boost.org/LICENSE_1_0.txt

  Repo: https://github.com/willwray/IREPEAT

  IREPEAT(HEXS,M,S) : Inclusive repeat of M(H) with separator S()
  XREPEAT(HEXS,M,S) : Exclusive repeat of M(H) with separator S()

    HEXS: repeat count as HEXS digits, e.g. (f)(f) == 255
    M: macro / tokens to expand, each with index M(H)
    S: separator-generator, e.g. COMMA / COLON / NOSEP
*/
#undef IREPEAT_HPP_DOC

#define XREPEAT(HEXS,M,S) IREPEAT(DECZ(HEXS),M,S) /*
        Exclusive repeat of M(H) with separator S() */

#define IREPEAT(HEXS,M,S) CAT(REPEAT,LEN(HEXS))(HEXS,S,M) /*
        Inclusive repeat of M(H) with separator S() */

#define STR_(A) #A
#define STR(A) STR_(A) // STR(X): Stringize

#define CAT_(A,B) A##B
#define CAT(A,B) CAT_(A,B) // CAT(A,B): Concatenate pair of args

#define POSTCAT_(P,...)__VA_ARGS__##P
#define POSTCAT(P,...) POSTCAT_(P,__VA_ARGS__) /*
        Append-concat leading arg P to remaining arg(s) */

#define EAT(...)                  // EAT (...) consumes paren-term (...)
#define IDEN(...) __VA_ARGS__     // IDEN strips parens
#define IDEP(...) ((__VA_ARGS__)) // IDEP adds another level of parens

#define ARG0_(A,...) A
#define ARG0(...) ARG0_(__VA_ARGS__)

#define ARG1_(_,B,...) B
#define ARG1(...) ARG1_(__VA_ARGS__)

#define SHEAD(SEQ) ARG0(SHED SEQ())
#define SHED(H) H,

#define SEQ0 SHEAD
#define SEQ1(SQ) SEQ0(EAT SQ())
#define SEQ2(SQ) SEQ1(EAT SQ())
#define SEQ3(SQ) SEQ2(EAT SQ())
#define SEQ(N) CAT(SEQ,N) // SEQ(N): index up to 4th element, zero-based

#define CSV(SEQ) POSTCAT(_,CSVu SEQ) // Transform SEQ to CSV list e,...
#define CSVu(E) E,CSVv // arbitrary length SEQ, may have empty elements
#define CSVv(E) E,CSVu // e.g. CSV((a)(b)()(c)(d)) -> a,b,,c,d
#define CSVv_
#define CSVu_

#define LEN(SEQ) VLEN(CSV(SEQ)) // Length of SEQ of up to 15 elems.

#define VLEN_(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,...) Q
#define VLEN(...) VLEN_(__VA_ARGS__,f,e,d,c,b,a,9,8,7,6,5,4,3,2,1,0) /*
   Variadic length of arg tuple (a,b,c,...) up to 15 args */

#define VCAT_(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,...) \
A##B##C##D##E##F##G##H##I##J##K##L##M##N##O##P
#define VCAT(...) VCAT_(__VA_ARGS__,,,,,,,,,,,,,,,,) /*
   Variadic cat of tuple args - up to the leading 16 */

#define SEQCAT(SEQ) VCAT(CSV(SEQ)) // CAT up to 16 leading SEQ elements

#define RMLZCAT(HEXS) VCAT(CSV(RMLZ3(HEXS))) /*
  Remove leading zeros from HEXS seq then CAT the digits */

#define RMLZ(HEXS) ARG1(RMLZ_ HEXS,,)HEXS /*
  Remove a leading (0) from HEXS seq, leave sole (0) as (0) */
#define RMLZ_(D) CAT(RMLZ_,D)
#define RMLZ_0(D) ,EAT,
#define RMLZ3(HEXS) RMLZ(RMLZ(RMLZ(HEXS)))

#define RMLF(HEXS) ARG1(RMLF_ HEXS,,)HEXS /*
  Remove a leading (f) from HEXS seq, leave no leading (f) */
#define RMLF_(D) CAT(RMLF_,D)
#define RMLF_f ,EAT,
#define RMLF4(HEXS) RMLF(RMLF(RMLF(RMLF(HEXS))))

#define xD(HEXS) CAT(x,RMLZCAT(HEXS)) // Prepend 'x' to HEXS hexits
#define XD(HEXS) CAT(X,RMLZCAT(HEXS)) // Prepend 'X' to HEXS hexits
#define x0D(HEXS) CAT(x,SEQCAT(HEXS)) // as ^ but preserve leading zeros
#define X0D(HEXS) CAT(X,SEQCAT(HEXS)) // as ^ but preserve leading zeros

#define HEX(D) CAT(0x,D)
#define HEXLIT(HEXS) HEX(SEQCAT(HEXS)) // Hexadecimal literal

#define NOSEP()
#define COMMA() ,
#define COLON() ;

#define XREPS0(S,M)
#define XREPS1(S,M) M(0)
#define XREPS2(S,M) M(0)S()M(1)
#define XREPS3(S,M) M(0)S()M(1)S()M(2)
#define XREPS4(S,M) M(0)S()M(1)S()M(2)S()M(3)
#define XREPS5(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)
#define XREPS6(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)
#define XREPS7(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)
#define XREPS8(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)
#define XREPS9(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)\
S()M(8)
#define XREPSa(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)\
S()M(8)S()M(9)
#define XREPSb(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)\
S()M(8)S()M(9)S()M(a)
#define XREPSc(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)\
S()M(8)S()M(9)S()M(a)S()M(b)
#define XREPSd(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)\
S()M(8)S()M(9)S()M(a)S()M(b)S()M(c)
#define XREPSe(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)\
S()M(8)S()M(9)S()M(a)S()M(b)S()M(c)S()M(d)
#define XREPSf(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)\
S()M(8)S()M(9)S()M(a)S()M(b)S()M(c)S()M(d)S()M(e)
#define XREPS10(S,M) M(0)S()M(1)S()M(2)S()M(3)S()M(4)S()M(5)S()M(6)S()M(7)\
S()M(8)S()M(9)S()M(a)S()M(b)S()M(c)S()M(d)S()M(e)S()M(f)

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

#define REPS_(V,D,S,M) V##REPS##D(S,M)
#define REPS(V,D,S,M) REPS_(V,D,S,M) // Repeat M(H) with S() separator

#define XREPT(D,S,M) XREPT##D(S,M)
#define IREPT(D,T,M) IREPS##D(T,M)T()
#define REPT(V,D,T,M) V##REPT(D,T,M) // Repeat M(H) with T() terminator

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

#define EVAL(...)__VA_ARGS__
#define EVAL2(...)EVAL(EVAL(__VA_ARGS__))
#define EVAL4(...)EVAL2(EVAL2(__VA_ARGS__))

#define REVERSE(HEXS) EVAL(IDEN EVAL4(POSTCAT(_,REVERSEu HEXS)()))
#define REVERSEu(E) POST_##E REVERSEv
#define REVERSEv(E) POST_##E REVERSEu
#define REVERSEv_
#define REVERSEu_

#define INC_0 (1)NOP
#define INC_1 (2)NOP
#define INC_2 (3)NOP
#define INC_3 (4)NOP
#define INC_4 (5)NOP
#define INC_5 (6)NOP
#define INC_6 (7)NOP
#define INC_7 (8)NOP
#define INC_8 (9)NOP
#define INC_9 (a)NOP
#define INC_a (b)NOP
#define INC_b (c)NOP
#define INC_c (d)NOP
#define INC_d (e)NOP
#define INC_e (f)NOP
#define INC_f (0)INC

#define DEC_0 (f)DEC
#define DEC_1 (0)NOP
#define DEC_2 (1)NOP
#define DEC_3 (2)NOP
#define DEC_4 (3)NOP
#define DEC_5 (4)NOP
#define DEC_6 (5)NOP
#define DEC_7 (6)NOP
#define DEC_8 (7)NOP
#define DEC_9 (8)NOP
#define DEC_a (9)NOP
#define DEC_b (a)NOP
#define DEC_c (b)NOP
#define DEC_d (c)NOP
#define DEC_e (d)NOP
#define DEC_f (e)NOP

#define NOPi(D) (D)NOPj
#define NOPj(D) (D)NOPi
#define NOPi_
#define NOPj_

#define INCi(D) CAT(CAT(INC_,D),j)
#define INCj(D) CAT(CAT(INC_,D),i)
#define INCi_ (1)
#define INCj_ (1)

#define DECi(D) CAT(CAT(DEC_,D),j)
#define DECj(D) CAT(CAT(DEC_,D),i)
#define DECi_
#define DECj_

#define INC(HEXS) REVERSE(EVAL(POSTCAT(_,EVAL(INCi REVERSE(HEXS)))))
#define DEC(HEXS) REVERSE(EVAL(POSTCAT(_,EVAL(DECi REVERSE(HEXS)))))

#define DECZ(HEXS) ARG1(EVAL(CHK0 RMLZ3(HEXS)),DEC(HEXS),)
#define CHK0(D) CAT(CHK0,D)
#define CHK00 ,,

#define DOREP1(...) __VA_ARGS__
#define DOREP2(...) __VA_ARGS__
#define DOREP3(...) __VA_ARGS__
#define DOREP4(...) __VA_ARGS__

#define REPEAT0(D,S,M)

#define REPEAT1(D,S,M) DOREP1(REPS(I,IDEN D,S,M IDEP))

#define REPEAT2(DD,S,M) DOREP2(\
DOREP2(REPT(X,SHEAD(DD),((f),S,M PRE)S,REPEAT1 POST))\
REPEAT1(EAT DD,S,M PRE(SHEAD(DD))))

#define REPEAT3(DDD,S,M) DOREP3(\
DOREP3(REPT(X,SHEAD(DDD),((f)(f),S,M PRE)S,REPEAT2 POST))\
REPEAT2(EAT DDD,S,M PRE(SHEAD(DDD))))

#define REPEAT4(DDDD,S,M) DOREP4(\
DOREP4(REPT(X,SHEAD(DDDD),((f)(f)(f),S,M PRE)S,REPEAT3 POST))\
REPEAT3(EAT DDDD,S,M PRE(SHEAD(DDDD))))

#endif
