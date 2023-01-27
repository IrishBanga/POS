/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-01-20

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void line(char fill, int length)
{
	int i = 0;
	while (i < length)
	{
		putchar(fill);
		i++;
	}
	putchar('\n');
}

void shoppingStats(int noOfItems)
{
	printf("Please enter the price of the %d items bought...\n", noOfItems);
	int i = 1;
	double price;
	double tp=0.0;
	double avg=0.0;
	while (i <= noOfItems)
	{
		printf("%d>",i);
		scanf("%lf",&price);
		tp = tp + price;
		i++;
	}
	avg = tp / noOfItems;
	line('-', 50);
	printf("Total price for all the items purchased: %.2lf\n",tp);
	printf("Average price of the items: %.2lf\n",avg);
	line('=', 50);
}