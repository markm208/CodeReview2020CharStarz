#include "add_sub.hpp"
#include <iostream>
using namespace std;
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    if (add(c1,n1,d1,-c2,n2,d2,result,len) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    int length = len;
    if (d1 == 0 || d2 == 0)
    {
        cout << "Error: cannot divide by zero" << endl;
        return 1;
    }
    if (length == 0|| length == 1 || length == 2)
    {
        cout << "Error: length of array must be greater than 2 to show any numbers" << endl;
        return 1;
    }
    if(len > 10)
    {
        cout << "Error: Int can only hold numbers with a langth og 10 or less"  << endl;
        return 1;
    }
    // return value set to true;
    bool retVal = true;
    // int counter for left of decimal point.
    
    int whole_num = c1+c2;
    if (whole_num<0)
    {
        whole_num *= -1;
        result[0] = '-';
        length--;
    }
    //function call to get the least common denomintor
    int demominator = get_denominator(d1, d2);
    
    // function to add the numerators
    n1 *= demominator/abs(d1);
    n2 *= demominator/abs(d2);
    int numerator = get_numerator(n1, n2);
    //adds 1 to whole number if numerater in greater than the denominator.
    while(numerator > demominator)
    {
        numerator -= demominator;
        whole_num++;
    }
    //calculates the decimal point
    int decimal = ((1000000000/demominator)*numerator);
    if (whole_num == 0 && decimal == 0)
    {
        result[0] = '0';
        result[1] = '\n';
        length--;
        print(len,length, result);
        return 0;
    }
    // length of a whole number
    int size_of_int_whole = get_length_of_int(whole_num);
    // length of decemal
    int size_of_int_dec = get_length_of_int(decimal);
    
    //cout <<size_of_int_whole << ": " << size_of_int_dec << endl;
    //index of the first number in an int
    // adds everything left of the decimal
    add_to_array(whole_num, size_of_int_whole, result, length, len);
    
    if (is_length_1(length)|| decimal == 0)
    {
        result[len-1] = '\0';
        print(len,length, result);
        return 0;
    }
    //add decimal
    result[size_of_int_whole] = '.';
    length--;
    if (is_length_1(length))
    {
        result[len-1] = '\0';
        print(len,length, result);
        return 0;
    }
    // add rest of decimal points
    add_to_array(decimal, size_of_int_dec, result, length, len);
    if (is_length_1(length))
    {
        result[len-1] = '\0';
        print(len,length, result);
        return 0;
    }
    //cout << whole_num <<'.'<< decimal/10%10 << endl;
    print(len,length, result);
    return retVal;
}
// adds the numerator of a fraction
int get_numerator(int n1, int n2)
{
    return n1+n2;
}
//===
int get_denominator(int d1, int d2)
{
    return least_common_denominator(d1, d2);
}
//===
int greatest_common_denominator(int d1, int d2)
{
    if (d1 == 0)
        return d2;
    return greatest_common_denominator(d2 % d1, d1);
}
//===
int least_common_denominator(int d1, int d2)
{
    return (d1 * d2) / greatest_common_denominator(d1, d2);
}
// function to return a car value based on a number
char get_int_char(int num)
{
    char retVal = '0';
    switch (num)
    {
        case 0:
            retVal = '0';
            break;
        case 1:
            retVal = '1';
            break;
        case 2:
            retVal = '2';
            break;
        case 3:
            retVal = '3';
            break;
        case 4:
            retVal = '4';
            break;
        case 5:
            retVal = '5';
            break;
        case 6:
            retVal = '6';
            break;
        case 7:
            retVal = '7';
            break;
        case 8:
            retVal = '8';
            break;
        case 9:
            retVal = '9';
            break;
    }
    return retVal;
}
//function to find the size of an int
int get_length_of_int(int num)
{
    int count;
    //check if num is negative
    if (num > 0)
    {
        for (count =0 ; num > 0; count++)
        {
            num /=10;
        }
    }
    else
    {
        for (count =0 ; num < 0; count++)
        {
            num /=10;
        }
    }
    return count;
}
//converts ints to char and adds to array
void add_to_array(int num, int size, char arr[], int &length, int len)
{
    int num_index = get_index_size(size-1);
    for (int i=(len-length); i<size; i++)
    {
        if (length == 1)
        {
            break;
        }
        arr[i] = get_int_char((num/num_index)%10);
        //cout << get_int_char((num/num_index)%10) << endl;
        length--;
        num_index/=10;
    }
}
//check if length is 1
bool is_length_1(int length)
{
    if(length == 1)
    {
        return true;
    }
    return false;
}
//print
void print(int len, int length, char result[])
{
    for (int i=0; i<(len-length); i++)
    {
        cout << result[i];
    }
    cout << endl;
}
//get index size of starting num
int get_index_size(int size)
{
    int temp = 1;
    for (int i=0; i<size; i++)
    {
        temp*=10;
    }
    return temp;
}

