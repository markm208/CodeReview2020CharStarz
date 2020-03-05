#pragma once
#include <iostream>
#include "mantissa.h"

using namespace std;

int main()
{
    char num[] = { '1','5','.','4','\0' };
    int x = 04534343;
    int y = 454454;
    cout << boolalpha << mantissa(num, x, y) << endl;
    cout << "Numerator: " << x << "\nDenominator: " << y;

    return 0;
}
