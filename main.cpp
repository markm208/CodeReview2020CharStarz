#include <iostream>
#include "multiply.hpp"
#include "divide.hpp"

using namespace std;


void getNewNumerators(int& numeratorOne, int denominatorOne, int& numeratorTwo, int denominatorTwo);

int main(){

    return 0;
}

// int moveXtoRight(int rightSideNum){
//     int decimalPlaces = 0;
//     int localNum = rightSideNum;
//     int throwaway = 0;


//     while(localNum > rightSideNum){

//         decimalPlaces = divideTwoNums(localNum, 10, throwaway);

//     }

//     cout << decimalPlaces << endl;

//     return decimalPlaces;

// }

// void getNewNumerators(int& numeratorOne, int denominatorOne, int& numeratorTwo, int denominatorTwo){

//     int moveNumOne = moveXtoRight(denominatorOne);
//     int moveNumTwo = moveXtoRight(denominatorTwo);
   
//     int newNumeratorOne = numeratorOne;
//     int newNumeratorTwo = numeratorTwo;

//     if(moveNumOne >= moveNumTwo){

//         for(int i = 0; i < moveNumOne; i++){
//             newNumeratorOne += multiplyTwoNums(newNumeratorOne, 10);
//             newNumeratorTwo += multiplyTwoNums(newNumeratorTwo, 10);
//         }

//     }
//     else{
//         for(int i = 0; i < moveNumTwo; i++){
//             newNumeratorOne += multiplyTwoNums(newNumeratorOne, 10);
//             newNumeratorTwo += multiplyTwoNums(newNumeratorTwo, 10);
//         }
//     }

//     numeratorOne = newNumeratorOne;
//     numeratorTwo = newNumeratorTwo;

// }
