/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-02-03

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void prnGrade(int mark)
{
	if (mark <= 50)
	{
		printf("F");
	}
	else if (mark < 55) {
		printf("D");
	}
	else if (mark < 60) {
		printf("D+");
	}
	else if (mark < 65) {
		printf("C");
	}
	else if (mark < 70) {
		printf("C+");
	}
	else if (mark < 75) {
		printf("B");
	}
	else if (mark < 80) {
		printf("B+");
	}
	else if (mark < 90) {
		printf("A");
	}
	else if (mark <= 100) {
		printf("A+");
	}
}

int getNoOfStudents(void)
{
	int no;
	printf("Please enter the number of students: ");
	scanf("%d", &no);
	return no;
}

int getAverage(int NumberOfStudents)
{
	int i = 1;
	int mk = 0;
	int sum = 0;
	int avg = 0;
	printf("Enter %d student marks...\n",NumberOfStudents);
	while (i <= NumberOfStudents)
	{
		printf("%d> ", i);
		scanf("%d",&mk);
		if (mk < 0)
		{
			printf("Invalid Mark, values should be greater than or equal 0.\n");
		}
		else if (mk > 100)
		{
			printf("Invalid Mark, values should be less than or equal to 100.\n");
		}
		else
		{
			sum = sum + mk;
			i++;
		}
	}
	avg = sum / NumberOfStudents;
	return avg;
}
void printReport(int NumberOfStudents, int average)
{
	printf("Number of students: %d\n", NumberOfStudents);
	printf("Class average: %d\%% ", average);
	putchar('(');
	prnGrade(average);
	putchar(')');
}