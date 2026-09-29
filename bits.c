/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x|~y);
}


/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return ~(~(x & ~y) & ~(~x & y));

}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if(!x){
        if(!y){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(!y){
        return 0;
    }

    return !((x>>31)^(y>>31));
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int result=0;
    int shift;

    shift=(v>0xFFFF)<<4;
    result=result|shift;
    v=v>>shift;

    shift=(v>0xFF)<<3;
    result=result|shift;
    v=v>>shift;

    shift=(v>0xF)<<2;
    result=result|shift;
    v=v>>shift;

    shift=(v>0x3)<< 1;
    result = result | shift;
    v = v >> shift;

    shift=(v>0x1);
    result=result|shift;

    return result;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x,int n,int m)
{
    int nShift=n<<3;
    int mShift=m<<3;

    int nByte=(x>>nShift)&0xff;
    int mByte=(x>>mShift)&0xff;

    int nMask=0xff<<nShift;
    int mMask=0xff<<mShift;

    x=x&~nMask;
    x=x&~mMask;

    x=x|(nByte<<mShift);
    x=x|(mByte<<nShift);

    return x;
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v)
{
    v=((v>>1)&0x55555555)|((v&0x55555555)<<1);
    v=((v>>2)&0x33333333)|((v&0x33333333)<<2);
    v=((v>>4)&0x0f0f0f0f)|((v&0x0f0f0f0f)<<4);
    v=((v>>8)&0x00ff00ff)|((v&0x00ff00ff)<<8);
    v=(v>>16)|(v<<16);

    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x,int n)
{
    int mask;
    mask=~(((1<<31)>>n)<<1);

    return (x>>n)&mask;
}
/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x)
{
    int count=0;
    int y;
    y=~((x>>16)^0xffff);
    y=!!y;
    count=count+(y<<4);
    x=x<<(y<<4);
    y=~((x>>24)^0xff);
    y=!!y;
    count=count+(y<<3);
    x=x<<(y<<3);
    y=~((x>>28)^0xf);
    y=!!y;
    count=count+(y<<2);
    x=x<<(y<<2);
    y=~((x>>30)^0x3);
    y=!!y;
    count=count+(y<<1);
    x=x<<(y<<1);
    count=count+((x>>31)&1);

    return count;
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x)
{
    unsigned sign=0;
    unsigned abs;
    unsigned frac;
    unsigned exp;
    unsigned mask;
    unsigned rest;
    int shift;
    int i;
    if(x==0){
        return 0;
    }
    if(x<0){
        sign=0x80000000;
        abs=-x;
    }
    else{
        abs=x;
    }
    i=31;
    while(((abs>>i)&1)==0){
        i=i-1;
    }

    exp=i+127;

    if(i<=23){
        frac=(abs<<(23-i))&0x7fffff;
    }
    else{
        shift=i-23;
        frac=(abs>>shift)&0x7fffff;
        mask=(1<<shift)-1;
        rest=abs&mask;
        if(rest>(1<<(shift-1))){
            frac=frac+1;
        }
        else if(rest==(1<<(shift-1))){
            if(frac&1){
                frac=frac+1;
            }
        }

        if(frac>>23){
            exp=exp+1;
            frac=0;
        }
    }

    return sign|(exp<<23)|frac;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf)
{
    unsigned sign=uf&0x80000000;
    unsigned exp=(uf>>23)&0xff;
    unsigned frac=uf&0x7fffff;

    if(exp==0xff){
        return uf;
    }
    if(exp==0){
        frac=frac<<1;
    }
    else{
        exp=exp+1;
    }
    if(exp==0xff){
        frac=0;
    }

    return sign|(exp<<23)|frac;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1,unsigned uf2)
{
    int sign;
    int exp;
    int shift;
    unsigned fracHigh;
    unsigned fracLow;
    unsigned val;

    sign=uf2>>31;

    exp=((uf2>>20)&0x7ff)-1023;

    if(exp<0){
        return 0;
    }

    if(exp>30){
        return 0x80000000;
    }

    fracHigh=uf2&0xfffff;
    fracLow=uf1;

    if(exp>=20){
        val=fracHigh<<12;
        val=val|(fracLow>>20);
        val=val<<(exp-20);
    }
    else{
        val=fracHigh<<12;
        val=val|(fracLow>>20);
        val=val>>(20-exp);
    }

    val=val|(1<<exp);

    if(sign){
        return -val;
    }

    return val;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x)
{
    unsigned exp;

    if(x>127){
        return 0x7f800000;
    }

    if(x>=-126){
        exp=x+127;
        return exp<<23;
    }

    if(x>=-149){
        return 1<<(x+149);
    }

    return 0;
}

