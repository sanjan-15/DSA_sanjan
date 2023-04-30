#include <stdio.h>
#include <stdlib.h>

// Name: Prog_C_Operators_2
// This program is written to explain more about additional C operators
// Logical AND and OR operators: &&, ||
// Bit-wise AND and OR operators: &, |

// Logical NOT operator !
// Binary or bit-wise 1's complement operator ~
// Binary or bit-wise XOR operator ^
// Ternary operator ?:


int main()
{
    printf("Welcome to the 2nd program on addditonal C operators.\n");

    printf("Size of int is sizeof(int) = %d bytes.\n", sizeof(int));

    printf("\n********* about the logical NOT operator ! ********\n");

    int i = 5, j = 6, k = 7, m = 8;
    printf("Both the operands to this operator need to be of boolean values, either TRUE or FALSE\n");
    if( !(i > j) && !(k > m))
        printf("Both conditions are TRUE.\n");
    else
        printf("Either both or one of the conditions is FALSE.\n");

    printf("\n********* Example 1.1 about the bit-wise 1's complement operator ~  ********\n");

    printf("This bit-wise 1's complement operator ~ complements each bit\n");
    int iInt = 0;
    iInt = ~iInt; // complement each bit and assign it to the same variable
    // The above assignment makes all the 32-bits in iInt as ones
    // which is equivalent to -1 in decimal

    printf("The value in iInt = %x (in hexadecimal form)\n", iInt);
    printf("The value in iInt = %d (in decimal form)\n", iInt);

    printf("\n********* Example 1.2 about the bit-wise 1's complement operator ~  ********\n");

    printf("This bit-wise 1's complement operator ~ complements each bit\n");
    iInt = 0b1010;  // Decimal equivalent of 10 in binary form
    iInt = ~iInt; // complement each bit and assign it to the same variable
    // The above assignment makes all the most significant 28-bits to all ones
    // and the make the least significant nibble to 0b0101 (decimal equivalent of 5)
    // The result should be 0xFFFFFFF5

    printf("The original value 0x0000000A is changed to 0xFFFFFFF5\n");
    printf("The value in iInt = %x (in hexadecimal form)\n", iInt);
    printf("The value in iInt = %d (in decimal form)\n", iInt);
    printf("To verify the decimal value above, find the 2's complement of hexadecimal value printed above.\n");

    printf("\n********* Example 2.1 about the bit-wise XOR operator ^ ********\n");
    printf("This bit-wise XOR operator ^ finds the XOR of two values\n");
    iInt = 0b1010;     // decimal value of 10 in binary form
    int jInt = 0b0101; // decimal value of 5 in binary form
    int iResult = iInt ^ jInt; // the XOR of these two values should result in 0b1111

    printf("The XOR of iInt (0b1010) and jInt (0b0101) should be 0b(1111)\n");
    printf("The value in iResult = %x (in hexadecimal form)\n", iResult);
    printf("The value in iResult = %d (in decimal form)\n", iResult);

    printf("\n********* Example 2.2 about the bit-wise XOR operator ^ ********\n");
    printf("This bit-wise XOR operator ^ finds the XOR of two values\n");
    iInt = -1;  // All ones
    jInt = 0;   // all zeors
    iResult = iInt ^ jInt; // the XOR of these two values should result in all ones, which is -1

    printf("The XOR of iInt (all ones) and jInt (all zeros) should be (all ones)\n");
    printf("The value in iResult = %x (in hexadecimal form)\n", iResult);
    printf("The value in iResult = %d (in decimal form)\n", iResult);

    //The conditional operator is of the form Expression1? Expression2: Expression3
    // Here, Expression1 is the condition to be evaluated.
    // If the condition(Expression1) is True then we will execute and
    // return the result of Expression2 otherwise
    // if the condition(Expression1) is false then we will execute and
    // return the result of Expression3

    printf("\n********* Example 3.1 about the Ternary conditional operator ?: ********\n");
    iInt = 10;
    jInt = 20;

    iResult = (iInt < jInt)? iInt: jInt;

    printf("The above statement with the ternary operator evaluates (iInt < jInt)\n");
    printf("If it is TRUE, iInt is assigned to result otherwise jInt\n");
    printf("The (10 < 20) ? 10 : 20, so value in iResult = %d\n", iResult);

    iResult = (iInt > jInt)? iInt: jInt;

    printf("The above statement with the ternary operator evaluates (iInt < jInt)\n");
    printf("If it is TRUE, iInt is assigned to result otherwise jInt\n");
    printf("The (10 > 20) ? 10 : 20, so value in iResult = %d\n", iResult);

    return 0;
}