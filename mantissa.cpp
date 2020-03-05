
#include <iostream>
using namespace std;

//takes in a char array of numbers and an int numerator and denominator. returns true if the array is made up a valid decimal number
//makes the numerator into the right side of the decimal point of the original array
//makes the denominator into the proper multiple of 10 based on the numerator
//if the array is not a proper decimal, the passed ints numerator and denominator will remain unchanged
bool mantissa(char numString[], int& numerator, int& denominator)
{
    //numerator will have a maximum of 10 digits
    char arrNumerator[10];
    bool goodNumber = true;
    bool rightOfDecimal = false;
    int decimalCounter = 0;
    int newIndex = 0;

    for (unsigned int i = 0; i < strlen(numString); i++)
    {
        char currentValue = numString[i];

        if (!isdigit(numString[i]))
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
            if (currentValue == '.' && decimalCounter++ < 1)
            {
                rightOfDecimal = true;
                continue;
            }

            else
            {
                goodNumber = false;
                break;
            }
        }

        //builds a second array from the numbers on the right side of the decimal place
        if (rightOfDecimal)
        {
            arrNumerator[newIndex++] = numString[i];
        }
    }
    //closes the temp array
    arrNumerator[newIndex] = '\n';

    //builds the denominator array only taking numbers into account
    //prevents trailing spaces
    char arrDenominator[10];
    int numIndex = 0;
    while (isdigit(arrNumerator[numIndex++]) && numIndex < 9)
    {
        arrDenominator[numIndex] = '0';
    }
    arrDenominator[0] = '1';
    arrDenominator[numIndex] = '\n';

    //sets the passed numerator to the numerator array only if the char array was able to be processed correctly as a number
    numerator = goodNumber ? atoi(arrNumerator) : numerator;

    //sets the passed denominator to the denominator array only if the char array was able to be processed correctly as a number
    denominator = goodNumber ? atoi(arrDenominator) : denominator;

    return goodNumber;
}
