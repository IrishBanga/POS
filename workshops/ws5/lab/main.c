/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-02-17

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "classList.h"
#include "utils.h"

int main() 
{
	int num;
	int i;
	char subjectName[9+1];
	printf("Enter subject Name: ");
	scanf("%s",subjectName);
    printf("Enter the number of students (max 50): ");
	scanf("%d", &num);
	printf("Enter %d student numbers and student marks...\n",num);
	int stno[50];
	int mark[50];
	for (i = 0; i < num; i++)
	{
		printf("%d:\n",i+1);
		printf("Student Number: ");
		scanf("%d", &stno[i]);
		printf("Mark: ");
		scanf("%d", &mark[i]);
	}
	printReport(subjectName, stno, mark, num);
	return 0;
}