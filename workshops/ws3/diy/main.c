/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-02-08

I have done all the coding by myself and only copied the code that my professor provided
to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getInt(void);
int getIntMM(int min, int max);
double getDouble(void);
double getDoubleMM(double min, double max);
void line(char fill, int length);

int main(void) 
{
	int value;
	double dvalue;
	printf("Enter an Integer value: ");
	value = getInt();
	printf("You entered: %d\n", value);
	line('*', 50);
	//********************************************
	printf("Enter an Integer value between 10 and 20 inclusive: ");
	value = getIntMM(10, 20);
	printf("You entered: %d\n", value);
	line('*', 50);
	//********************************************
	printf("Enter a Double value: ");
	dvalue = getDouble();
	printf("You entered: %.2lf\n", dvalue);
	line('*', 50);
	//********************************************
	printf("Enter a Double value between 10.1 and 20.1 inclusive: ");
	dvalue = getDoubleMM(10.1, 20.1);
	printf("You entered: %.2lf\n", dvalue);
	line('*', 50);
	//********************************************
	return 0;
}