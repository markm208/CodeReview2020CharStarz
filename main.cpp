#include <iostream>
#include "Characteristic.h"

using namespace std;

int main()
{
    cout<<"In-class Code Review"<<endl;

    //test char[]
	char a[] = { '1', '2', '5', '4', '.', '4', '9', '\0' };

	//the result int
	int character;
	if (characteristic(a, character))
	{
		cout << character << endl;
	}
	else
	{
		cout << "the result was invalid" << endl;
	}

	char b[] = { '-', '2', '5', '.', '4', '9', '\0' };

	if (characteristic(b, character))
	{
		cout << character << endl;
	}
	else
	{
		cout << "the result was invalid" << endl;
	}

	char c[] = { '-', '2', '5', '9', '\0' };

	if (characteristic(c, character))
	{
		cout << character << endl;
	}
	else
	{
		cout << "the result was invalid" << endl;
	}

    return 0;
}
