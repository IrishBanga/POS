/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-01-20

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

// fill: the character to draw the line with.
// length number of characters to print.
void line(char fill, int length);

// noOfItem: the number of items purchased
void shoppingStats(int noOfItems);


int main(void) 
{
    int nitems;
	printf("Money Spending Calculator\n");
    line('=', 25);
    printf("How many items were bought?\n> ");
    scanf("%d", &nitems);
    shoppingStats(nitems);

    return 0;
}
