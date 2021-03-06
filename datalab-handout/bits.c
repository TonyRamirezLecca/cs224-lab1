 /*
	 * 
	 * CS:APP Data Lab 
	 * 
	 * Tony Ramirez // BYUID: ramirant
	 * Paden Allsup
	 * Keaton Kimball // BYUID: keaton36
	 * 
	 * bits.c - Source file with your solutions to the Lab.
	 *          This is the file you will hand in to your instructor.
	 *
	 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
	 * compiler. You can still use printf for debugging without including
	 * <stdio.h>, although you might get a compiler warning. In general,
	 * it's not good practice to ignore compiler warnings, but in this
	 * case it's OK.  
	 */

	#if 0
	/*
	 * Instructions to Students:
	 *
	 * STEP 1: Read the following instructions carefully.
	 */

	You will provide your solution to the Data Lab by
	editing the collection of functions in this source file.

	INTEGER CODING RULES:
	 
	  Replace the "return" statement in each function with one
	  or more lines of C code that implements the function. Your code 
	  must conform to the following style:
	 
	  int Funct(arg1, arg2, ...) {
		  /* brief description of how your implementation works */
		  int var1 = Expr1;
		  ...
		  int varM = ExprM;

		  varJ = ExprJ;
		  ...
		  varN = ExprN;
		  return ExprR;
	  }

	  Each "Expr" is an expression using ONLY the following:
	  1. Integer constants 0 through 255 (0xFF), inclusive. You are
		  not allowed to use big constants such as 0xffffffff.
	  2. Function arguments and local variables (no global variables).
	  3. Unary integer operations ! ~
	  4. Binary integer operations & ^ | + << >>
		
	  Some of the problems restrict the set of allowed operators even further.
	  Each "Expr" may consist of multiple operators. You are not restricted to
	  one operator per line.

	  You are expressly forbidden to:
	  1. Use any control constructs such as if, do, while, for, switch, etc.
	  2. Define or use any macros.
	  3. Define any additional functions in this file.
	  4. Call any functions.
	  5. Use any other operations, such as &&, ||, -, or ?:
	  6. Use any form of casting.
	  7. Use any data type other than int.  This implies that you
		 cannot use arrays, structs, or unions.

	 
	  You may assume that your machine:
	  1. Uses 2s complement, 32-bit representations of integers.
	  2. Performs right shifts arithmetically.
	  3. Has unpredictable behavior when shifting an integer by more
		 than the word size.

	EXAMPLES OF ACCEPTABLE CODING STYLE:
	  /*
	   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
	   */
	  int pow2plus1(int x) {
		 /* exploit ability of shifts to compute powers of 2 */ return (1 << x) + 1; }

	  /*
	   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
	   */
	  int pow2plus4(int x) {
		 /* exploit ability of shifts to compute powers of 2 */
		 int result = (1 << x);
		 result += 4;
		 return result;
	  }

	FLOATING POINT CODING RULES

	For the problems that require you to implent floating-point operations,
	the coding rules are less strict.  You are allowed to use looping and
	conditional control.  You are allowed to use both ints and unsigneds.
	You can use arbitrary integer and unsigned constants.

	You are expressly forbidden to:
	  1. Define or use any macros.
	  2. Define any additional functions in this file.
	  3. Call any functions.
	  4. Use any form of casting.
	  5. Use any data type other than int or unsigned.  This means that you
		 cannot use arrays, structs, or unions.
	  6. Use any floating point data types, operations, or constants.


	NOTES:
	  1. Use the dlc (data lab checker) compiler (described in the handout) to 
		 check the legality of your solutions.
	  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
		 that you are allowed to use for your implementation of the function. 
		 The max operator count is checked by dlc. Note that '=' is not 
		 counted; you may use as many of these as you want without penalty.
	  3. Use the btest test harness to check your functions for correctness.
	  4. Use the BDD checker to formally verify your functions
	  5. The maximum number of ops for each function is given in the
		 header comment for each function. If there are any inconsistencies 
		 between the maximum ops in the writeup and in this file, consider
		 this file the authoritative source.

	/*
	 * STEP 2: Modify the following functions according the coding rules.
	 * 
	 *   IMPORTANT. TO AVOID GRADING SURPRISES:
	 *   1. Use the dlc compiler to check that your solutions conform
	 *      to the coding rules.
	 *   2. Use the BDD checker to formally verify that your solutions produce 
	 *      the correct answers.
	 */


	#endif
	/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.

	   The GNU C Library is free software; you can redistribute it and/or
	   modify it under the terms of the GNU Lesser General Public
	   License as published by the Free Software Foundation; either
	   version 2.1 of the License, or (at your option) any later version.

	   The GNU C Library is distributed in the hope that it will be useful,
	   but WITHOUT ANY WARRANTY; without even the implied warranty of
	   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	   Lesser General Public License for more details.

	   You should have received a copy of the GNU Lesser General Public
	   License along with the GNU C Library; if not, see
	   <http://www.gnu.org/licenses/>.  */
	/* This header is separate from features.h so that the compiler can
	   include it implicitly at the start of every compilation.  It must
	   not itself include <features.h> or any other header that includes
	   <features.h> because the implicit include comes before any feature
	   test macros that may be defined in a source file before it first
	   explicitly includes a system header.  GCC knows the name of this
	   header in order to preinclude it.  */
	/* glibc's intent is to support the IEC 559 math functionality, real
	   and complex.  If the GCC (4.9 and later) predefined macros
	   specifying compiler intent are available, use them to determine
	   whether the overall intent is to support these features; otherwise,
	   presume an older compiler has intent to support these features and
	   define these macros by default.  */
	/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
	   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
	   2015-05-15).  */
	/* We do not support C11 <threads.h>.  */
	/* Rating 1 -- 2 points each */
	/* 
	 * evenBits - return word with all even-numbered bits set to 1
	 *   Legal ops: ! ~ & ^ | + << >>
	 *   Max ops: 8
	 *   Rating: 1
 */

int evenBits(void) {
	/*We set every other number in a byte to 1
	then we shift the number by 8 and repeat until
	all 32 bits are filled.*/

     int result = 0;
     int i = 0x55;

     result |= i;
	 result <<= 8;
     result |= i;
	 result <<= 8;
     result |= i;
	 result <<= 8;
     result |= i;


     return result;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
/*Minus one is just all 32 bits being switched to 1.
we got a number 0 and complemented it to get -1 in twos compelement*/
    int result = 0;
	result = ~result;

    return result;
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
	/*we declare an int and set it equal to !!n to determine if n is zero or non zero.
	  We then shift i 31 bits to the left resulting in 1000... or 0000...
	  We then shift n + (-1) times to the right to get the correct number of 1's on the left.
	  if n = 0, then shifting will change nothing.  */
	int i = !(!n);
	i <<= 31;
	i >>= (n + (~0));

	return i;
}
/* Rating 2 -- 3 points each */
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	/*We shifted n by 3 to multiply it by 8. Then we shifted x to the right by the new n.
	  Then we anded x with ff to clear the bits that were not in the first byte to return the byte.*/
	  n <<= 3;
	  x >>= n;
	  x &= 0xff;
	  return x;
}
 /* isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
/*We XOR both x and y together. If x == y, then x ^ y will return 0. If x and y are not equal, 
  x ^ y will return some non zero number. we then return !!x to return 0 or 1.*/
	  x = x ^ y;
	  return !(!x);
}
/* Rating 3 -- 2 points each */
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	x = !(!x);
	x <<= 31;
	x >>= 31;

	y = x & y;
	x = ~x;
	z = x & z;
	return z + y;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {

	return 2;
}
/* Rating 4 -- 1 point each */
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
	/*First grab the sign of the number. Then grab the sign of the two's complement (so you
	  can know if there's overflow. Then if the original sign is 1 and there is overflow, return 0.
	  if the original sign is 1 and there is no overflow, return the value. And if the original 
	  sign is 0 return the original number.)*/
	int sign = 0;
	int twosSign = 0;
    int	shouldYouReturnZero = 0;

    sign = x >> 31; //either all 1's or 0's
	twosSign = (~x + 1) >> 31;

    shouldYouReturnZero = !(twosSign & sign);

	x ^= sign; //will only complement if the sign is 1
	x = (x + (1 & sign));

	return x;
}
/* Float Rating 2 -- 3 points each */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {

    return uf;
}
/* Float Rating 4 -- 1 point each */
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  return 2;
}

/*	 * Tony Ramirez // BYUID: ramirant
	 * Paden Allsup
	 * Keaton Kimball // BYUID: keaton36
 */
