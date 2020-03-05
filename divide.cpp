#include <iostream>
#include "divide.hpp"

using namespace std;

int divideTwoNums(int dividend, int divisor, int& defaultRemainder){

    int quotient = 0;
    int remainder = 0;

    int tempDividend = abs(dividend); 
    int tempDivisor = abs(divisor); 

    if(tempDividend >= tempDivisor){
        while(tempDividend >= tempDivisor){
            tempDividend -= tempDivisor;
            quotient++;
            remainder = tempDivisor;
        }
    }
    else{
        quotient = 0;
        remainder = tempDividend;
    }

    defaultRemainder = remainder;

    return quotient;
}

bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len){
    
    int throwaway = 0;

    int quotient = divideTwoNums(c1, c2, throwaway);

    return true;
}
