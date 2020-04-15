#ifndef add_sub_hpp
#define add_sub_hpp

#include <stdio.h>
#include <iostream>
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
int get_denominator(int d1, int d2);
int get_numerator(int n1, int n2);
int greatest_common_denominator(int d1, int d2);
int least_common_denominator(int d1, int d2);
char get_int_char(int num);
int get_length_of_int(int num);
int reverse_int(int num);
void add_to_array(int num, int size, char arr[], int & length, int len);
bool is_length_1(int length);
void print(int len,int length, char result[]);
int get_index_size(int size);

#endif /* add_sub_hpp */
