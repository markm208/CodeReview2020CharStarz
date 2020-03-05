#include <iostream>
#include "multiply.hpp"
#include "divide.hpp"

using namespace std;

int main()
{
    cout<<"In-class Code Review"<<endl;

    char cArray[] = {1};
    int n1 = 23;
    int d1 = 100;
    int n2 = 3;
    int d2 = 10;

    int c1 = 24;
    int c2 = 12;

    int len = 12;

    cout << multiply(c1, n1, d1, c2, n2, d2, cArray, len) << endl;
    cout << divide(c1, n1, d1, c2, n2, d2, cArray, len) << endl;
    
    return 0;
}
