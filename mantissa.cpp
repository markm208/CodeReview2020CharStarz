#include <iostream>
using namespace std;


int charArrayLength(const char charArray[])
{/*
 Takes in a null terminated char array and returns its length, including the null terminator
 */
    int length = 0;
    while (charArray[length++] != '\0');
    return length;
}

bool isADigit(char charToTest)
/*
takes in a single char and returns true if the char is a number
*/
{
    bool retVal = false;
    char digits[] = { '0','1','2','3','4','5','6','7','8','9' };
    for (int i = 0; i < 11; i++)
    {
        if (digits[i] == charToTest)
        {
            retVal = true;
            break;
        }
    }
    return retVal;
}

/*
int takeToPower(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }

    int retVal = base;

    for (int i = 0; i < exponent - 1; i++)
    {
        retVal *= base;
    }
    return retVal;
}
*/
/*
int charArrayToInt(char charArray[])
{
    int finalInt = 0;
    int size = charArrayLength(charArray) - 1;

    for (int i = 0; i < size; i++)
    {
        if (isADigit(charArray[i]))
        {
            int temp = ((int)charArray[i] - (int)'0') + (finalInt * 10);

            //this check prevents an overflow if temp has passed INT_MAX
            if (temp > finalInt)
            {
                finalInt = temp;
            }
            else
            {
                finalInt = -1;
                break;
            }
        }
    }
    return finalInt;
}
*/


//takes in a char array of numbers and an int numerator and denominator. returns true if the array is made up a valid decimal number
//makes the numerator into the right side of the decimal point of the original array
//makes the denominator into the proper multiple of 10 based on the numerator
bool mantissa(const char numString[], int& numerator, int& denominator)
{
    numerator = 0;
    //numerator will have a maximum of 10 digits   
    bool goodNumber = true;
    bool rightOfDecimal = false;
    int decimalCounter = 0;
    int numSize = 0;
    int arrSize = charArrayLength(numString);

    for (int i = 0; i < arrSize; i++)
    {
        char currentValue = numString[i];

        if (!isADigit(numString[i]))
        {
            //allows for + or - as the first value
            if (i == 0 && (currentValue == '+' || currentValue == '-'))
            {
                continue;
            }

            //allows for leading or trailing spaces
            if (currentValue == ' ')
            {
                continue;
            }

            //only allows for one decimal in the original array
            if (currentValue == '.' && ++decimalCounter < 2)
            {
                rightOfDecimal = true;
                continue;
            }

            if (currentValue == '\0')
            {
                break;
            }

            else
            {
                goodNumber = false;
                break;
            }
        }

        //builds the numerator from the numbers on the right side of the decimal place
        if (rightOfDecimal)
        {
            if (numSize < 8)
            {
                numerator = ((int)numString[i] - (int)'0') + (numerator * 10);
                numSize++;
            }
            else
            {
                break;
            }
        }
    }
    denominator = 1;

    for (int i = 0; i < numSize; i++)
    {
        denominator *= 10;
    }

    return goodNumber;
}

