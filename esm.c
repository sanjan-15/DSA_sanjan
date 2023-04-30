
#include <stdio.h>
#include <stdlib.h>

// This program is written to explain about various C operators
// Logical AND and OR operators: &&, ||
// Bit-wise AND and OR operators: &, |

// Right shift operator >>
// Left shift operator <<
// and their relevance with unsigned and signed integers.
// Various data representations (decimal, binary, octal and hexadecimal)
// also explored here.

int main()
{
    printf("Welcome to the program on C operators.\n");

    printf("Size of int is sizeof(int) = %d bytes.\n", sizeof(int));

    printf("********* about the logical AND operator && ********\n");

    int i = 5, j = 6, k = 7, m = 8;
    printf("Both the operands to this operator need to be of boolean values, either TRUE or FALSE\n");
    if((i < j) && (k < m))
        printf("Both conditions are TRUE.\n");
    else
        printf("Either both or one of the conditions is FALSE.\n");

    printf("********* about the logical OR operator || ********\n");

    printf("Both operands to this operator need to be of boolean values, either TRUE or FALSE\n");
    if((i > j) || (k > m))
        printf("Either both or one of conditions is TRUE.\n");
    else
        printf("Both conditions are FALSE.\n");

    printf("********* about the bit-wise AND operator & ********\n");
    i = 0xA;   // In binary form 1010 (only the least significant four bits are shown the rest of them are zeros)
    j = 0x5;   // In binary form 0101 (-- do ---)

    int result = i & j; // bit-wise AND operation, will make all the bits zero
    printf("result = i & j = 0b1010 AND 0b0101 = 0b0 = %d\n", result);

    printf("********* about the bit-wise OR operator | ********\n");
    result = i | j; // bit-wise OR operation, will make all the least significant four bits as ones
    printf("result = i | j = 0b1010 OR 0b0101 = 0b1111 = %d\n", result);
    printf("result = i | j = 0b1010 OR 0b0101 = 0b1111 = %X (in hexadecimal form)\n", result);

    // Let us understand about the octal and hexadecimal formats now ...
    // When you compare the values printed in hexadecimal and octal forms
    // Remember that the binary value stored inside a variable is
    // 32 here, because size of int here is 4 bytes.
    // The octal and hexadecimal values look at the binary bit patterns
    // as set of either three binary values or four, respectively.

    printf("\n******** Example 1: (i >> n) right shift i by n bits *********\n");

    i = 0xAA;
    printf("i = %d (in decimal form)\n", i);
    printf("i = %X (in capital letters hexdecimal form)\n", i);
    printf("i = %x (in small letters hexdecimal form)\n", i);
    printf("i = %o (in octal form)\n", i);

    k = i >> 2;
    printf("The value of k = i >> 2 is below.\n");
    printf("k = %d (in decimal form)\n", k);
    printf("k = %X (in hexdecimal form)\n", k);


    printf("\n******** Example 2.1: (a >> n) right shift a by n bits *********\n");
    int a = 0x12F;
    result = a >> 3;
    printf("The value in a = %d (in decimal form)\n", a);
    printf("The value in a = %X (in hexadecimal form)\n", a);

    printf("The value of result = a >> 3 is below.\n");
    printf("result = %d (in decimal form)\n", result);
    printf("result = %X (in hexadecimal form)\n", result);

    printf("\n******** Example 2.2: (kInt >> n) right shift kInt by n bits *********\n");
    int kInt = 0x25;
    int res = kInt >> 2;
    printf("The value in a = %d (in decimal form)\n", kInt);
    printf("The value in a = %X (in hexadecimal form)\n", kInt);

    printf("The value of result = kInt >> 2 is below.\n");
    printf("result = %d (in decimal form)\n", res);
    printf("result = %X (in hexadecimal form)\n", res);

    printf("\n******** Example 2.3: (iInt >> n) right shift iInt by n bits *********\n");
    int iInt = 075;   // Please note that having a leading zero before the literals mean octal
    res = iInt >> 2;
    printf("The value in iInt = %d (in decimal form)\n", iInt);
    printf("The value in iInt = %X (in hexadecimal form)\n", iInt);
    printf("The value in iInt = %o (in octal form)\n", iInt);

    printf("The value of result = iInt >> 2 is below.\n");
    printf("result = %d (in decimal form)\n", res);
    printf("result = %X (in hexadecimal form)\n", res);

    printf("\n******** Example 2.4: (kInt >> n) right shift iInt by n bits *********\n");
    kInt = 0b1101;   // Please note that having a 0b before the literals mean binary form
    res = kInt >> 3;
    printf("The value in kInt = %d (in decimal form)\n", kInt);
    printf("The value in kInt = %X (in hexadecimal form)\n", kInt);

    printf("The value of result = kInt >> 3 is below.\n");
    printf("result = %d (in decimal form)\n", res);
    printf("result = %X (in hexadecimal form)\n", res);

     printf("\n******** Example 3.1: (iInt << n) left shift a by n bits *********\n");
    iInt = 0b101111;
    res = iInt << 2;
    printf("The value in iInt = %d (in decimal form)\n", iInt);
    printf("The value in iInt = %X (in hexadecimal form)\n", iInt);

    printf("The value of result = iInt << 2 is below.\n");
    printf("res = %d (in decimal form)\n", res);
    printf("res = %X (in hexadecimal form)\n", res);

    printf("\n******** Example 3.2: (kInt << n) left shift a by n bits *********\n");
    kInt = 0xC7;
    res = kInt << 3;
    printf("The value in kInt = %d (in decimal form)\n", kInt);
    printf("The value in kInt = %X (in hexadecimal form)\n", kInt);

    printf("The value of result = kInt << 3 is below.\n");
    printf("res = %d (in decimal form)\n", res);
    printf("res = %X (in hexadecimal form)\n", res);


//************
    // From the output of hex decimal form, you can find out that
    // the representation of -1 in 2's complement is all ones.
    // When you are printing it as decimal (%d) it is interpreted as -1
    // because we have mentioned the type of i as signed int here.

    printf("\n******** signed int *********\n");
    printf("\n********Example 4.1 signed sInt << n *********\n");
    signed int sInt = -1;
    printf("Signed int sInt = %d in decimal form\n", sInt);
    printf("Signed int sInt = %X in hexadecimal form\n", sInt);
    printf("Signed int sInt = %o in octal form\n", sInt);

    // When the value is shifted left by two bits, zeros move in
    // from the right side and the ones going out will be ignored.

    signed int sResult = sInt << 2;
    printf("Signed int sResult of sInt << 2 : %d in decimal form\n", sResult);
    printf("Shifting a value by two bits to left is equivalent to multiplying it by 4.\n");
    printf("sResult = sInt * 4 = -1 * 4 = %d\n", (sInt * 4));

    printf("Signed int sResult of sInt << 2 : %X in hexadecimal form\n", sResult);
    printf("Signed int sResult of sInt << 2 : %o in octal form\n", sResult);

    printf("\n********Example 4.2 signed sInt << n *********\n");
    sInt = -24;  // signed int type
    printf("Signed int sInt = %d in decimal form\n", sInt);
    printf("Signed int sInt = %X in hexadecimal form\n", sInt);
    sResult = sInt << 3;   // signed int type
    printf("Signed int sResult of sInt << 3 : %d in decimal form\n", sResult);
    printf("Shifting a value by two bits to left is equivalent to multiplying it by 8.\n");
    printf("sResult = sInt * 8 = -24 * 8 = %d\n", (sInt * 8));

    printf("Signed int sResult of sInt << 3 : %X in hexadecimal form\n", sResult);

    printf("\n********Example 5.1 signed sInt >> n *********\n");
    printf("This was not explained in the class. Try to understand it yourself.\n");
    printf("If required, I will explain this in class.\n");
    printf("When a signed int value is right shifted, the sign bit value is propagated inside.\n");

    sInt = -24;
    printf("Signed int sInt = %d in decimal form\n", sInt);
    printf("Signed int sInt = %X in hexadecimal form\n", sInt);
    sResult = sInt >> 3;   // signed int type
    printf("Signed int sResult of sInt >> 3 : %d in decimal form\n", sResult);
    printf("Shifting a value by three bits to right is equivalent to dividing it by 8.\n");
    printf("sResult = sInt / 8 = -24 / 8 = %d\n", (sInt / 8));

    printf("Signed int sResult of sInt >> 3 : %X in hexadecimal form\n", sResult);

    printf("\n********Example 5.2 signed sInt >> n *********\n");
    sInt = -4;
    printf("Signed int sInt = %d in decimal form\n", sInt);
    printf("Signed int sInt = %X in hexadecimal form\n", sInt);
    sResult = sInt >> 2;   // signed int type
    printf("Signed int sResult of sInt >> 2 : %d in decimal form\n", sResult);
    printf("Shifting a value by three bits to right is equivalent to dividing it by 8.\n");
    printf("sResult = sInt / 8 = -4 / 4 = %d\n", (sInt / 4));

    printf("Signed int sResult of sInt >> 2 : %X in hexadecimal form\n", sResult);


//********
    // Below we are converting the representation of -1, which is 32 ones
    // into an unsigned number and then storing it into variable
    // Remember here type cast does not change the actual contents
    // but now the value is going to be considered as the largest unsigned
    // number and not as -1

    unsigned int uInt = 0xFFFFFFFF; // 32 bit values in hexadecimal format the max unsigned value
    printf("\n******** unsigned int *********\n");
    printf("Unsigned int uInt = %d in decimal form\n", uInt);
    printf("Unsigned int uInt = %X in hexadecimal form\n", uInt);
    printf("Unsigned int uInt = %o in octal form\n", uInt);

    unsigned int uResult = uInt << 2;
    printf("Unsigned int uResult of uInt << 2 : %d in decimal form\n", uResult);
    printf("Unsigned int uResult of uInt << 2 : %X in hexadecimal form\n", uResult);
    printf("Unsigned int uResult of uInt << 2 : %o in octal form\n", uResult);
    printf("The value after left shift is lower than the original value, because\n");
    printf("the left shifted value cannot be accommodated within 32 bits\n");

    printf("Note: Left shifting the unsigned value by two bits brings in two zeros at LSB end.\n");
    printf("Two MSB bits are ignored on the left most side because the result is restricted to 32 bits.\n");

    return 0;
}
