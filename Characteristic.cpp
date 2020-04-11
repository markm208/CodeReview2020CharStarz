#include <iostream>
#include "Characteristic.h"

using namespace std;

//Saves the characteristic in c and returns true if it worked and false if something went wrong
bool characteristic(const char numString[], int& c)
{

	//a constant value that is the ascii value for 0
	//this allows us to convert the characters in numString to ints
	int asciiIndex = (int)'0';
	//whether or not the numString is valid
	bool retVal = true;
	//whether the number is negative, calculated at the end
	bool neg = false;
	bool pos = false;

	bool atLeastOneDigit = false;

	//Make sure c starts at a clean value of 0
	c = 0;

	//our current index in the char[]
	int index = 0;

	int decCount = 0;
	//Checks for multiple decimal points that would make an invalid number
	while (numString[index] != '\0')
	{
		//Make sure there is at least one numeric digit in the numString
		if ((int)numString[index] >= 48 && (int)numString[index] <= 57)
		{
			atLeastOneDigit = true;
		} //Count the number of decimal points
		else if (numString[index] == '.')
		{
			decCount++;
		} //Make sure there are no invalid characters in the numString
		else if (numString[index] != '+' && numString[index] != '-' && numString[index] != ' ')
		{
			retVal = false;
		}
		index++;
	}

	//if it was an empty numString
	if (index == 0)
	{
		retVal = false;
	}

	//If there are multiple decimal points the number is invalid
	if (decCount > 1)
	{
		retVal = false;
	}

	//reset index for use in the next loop
	index = 0;

	//while we are on the left side of the decimal and not at the end of the char[]
	while (numString[index] != '.' && numString[index] != '\0' && retVal == true)
	{
		//Deals with spaces in the numstring
		if (numString[index] != ' ' && index != 0 && numString[index - 1] == ' ' && (neg || pos || c != 0))
		{
			retVal = false;
			break;
		}

		//if the numString has a space as a character
		if (numString[index] == ' ')
		{
			//if it is at the beginning or end, continue until the number starts
			index++;
			continue;
		} //the char[] has a - in it
		else if (numString[index] == '-')
		{

			//if it is in the middle of a number then the char[] is invalid
			if (c != 0 || neg)
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
		else if (numString[index] == '+')
		{
			//if it is in the middle of a number then the char[] is invalid
			if (c != 0)
			{
				retVal = false;
				break;
			}
			else
			{
				//Allows us to deal with spaces and + signs better
				pos = true;
			}
		} //if the char falls in the ascii range for numbers
		else if ((int)numString[index] >= 48 && (int)numString[index] <= 57)
		{

			//Ensures we can never return numbers that passed INT_MAX
			if (INT_MAX - ((int)numString[index] - asciiIndex) < (c * 10))
			{
				retVal = false;
				break;
			}
			
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

	//if there are no numeric digits in the numString
	if (!atLeastOneDigit)
	{
		retVal = false;
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