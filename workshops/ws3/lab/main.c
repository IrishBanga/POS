/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-02-03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void prnGrade(int mark);
int getNoOfStudents(void);
int getAverage(int NumberOfStudents);
void printReport(int NumberOfStudents, int average);

int main(void)
{
	int num;
	int average;
	printf("Class test marks report program...\n\n");
	num = getNoOfStudents();
	average = getAverage(num);
	printReport(num, average);
	return 0;
}


