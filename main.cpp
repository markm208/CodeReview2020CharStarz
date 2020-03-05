#include <iostream>
#include "add_sub.h"
using namespace std;

int main()
{
    cout<<"In-class Code Review"<<endl;
    char str[10];
    char str2[5];
    add(1, 2, 5, 1, 1, 6, str, 10);
    sub(3, 2, 5, 2, 1, 6, str2, 5);
    return 0;
}
