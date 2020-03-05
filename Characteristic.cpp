#include <iostream>
#include "Characteristic.h"

using namespace std;

//Returns the characteristic for a passed in c_str of a number
bool characteristic(char numString[], int& c)
{

	//a constant value that is the ascii value for 0
	//this allows us to convert the characters in numString to ints
	int asciiIndex = (int)'0';
	//whether or not the numString is valid
	bool retVal = true;
	//whether the number is negative, calculated at the end
	bool neg = false;

	//Make sure c starts at a clean value of 0
	c = 0;

	//our current index in the char[]
	int index = 0;
	//while we are on the left side of the decimal and not at the end of the char[]
	while (numString[index] != '.' && numString[index] != '\0')
	{
		//if the numString has a space as a character
		if (numString[index] == ' ')
		{
			//if it is in the middle of a number then the char[] is invalid
			if (c != 0 && !neg)
			{
				retVal = false;
				break;
			}
			else
			{
				//otherwise if it is at the beginning, continue until the number starts
				index++;
				continue;
			}
		} //the char[] has a - in it
		else if (numString[index] == '-')
		{
			//if it is in the middle of a number then the char[] is invalid
			if (c != 0)
			{
				retVal = false;
				break;
			}
			else
			{
				//otherwise if it is at the beginning, flag the number as a negative number
				neg = true;
			}
		} //if the char falls in the ascii range for numbers
		else if ((int)numString[index] >= 48 && (int)numString[index] <= 57)
		{
			//move our current number left by one digit by multiplying by 10
			//then add the new digit after converting from the ascii code to a regular number
			c = ((int)numString[index] - asciiIndex) + (c * 10);
		}
		else
		{ //if there are other characters in the numString the string is invalid
			retVal = false;
			break;
		}

		//increment the index we are looking at in the char[]
		index++;
	}

	//if there was a - preceding the number then multiply it by -1 to make it negative
	if (neg)
	{
		c *= -1;
	}

	//if the numString is invalid, reset the returned num to 0
	if (!retVal)
	{
		c = 0;
	}

	//returns whether the numString was invalid or not
	return retVal;
}