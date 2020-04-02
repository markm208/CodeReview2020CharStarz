#include <iostream>
#include "multiply.hpp"

using namespace std;

int multiplyTwoNums(int num1, int num2){

    int product = 0;

    //adding the larger number to itself
    
    if(num1 >= num2){
        for(int i = 0; i < num2; i++){
            product += num1;
        }
    }
    else{
        for(int i = 0; i < num1; i++){
            product += num2;
        }
    }

    return product;
}



bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len){

    int product = multiplyTwoNums(c1, c2);
 
    return true;
}