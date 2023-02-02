/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-01-20

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


void rectangle(char leftTop, char top, char topRight,
    char right, char rightButtom, char buttom,
    char buttomLeft, char left, char fill,
    int width, int height);



int main(void)
{
    rectangle('+', '-', '+', '|', '+', '-', '+', '|', ' ', 20, 8);
    rectangle('/', '-', '\\', '|', '/', '-', '\\', '|', 'X', 50, 14);
    return 0;
}