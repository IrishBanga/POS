/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-02-22

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "classList.h"
#include "utils.h"

int main()
{
	int i;
	printf("Subject Performance report\n");
	printf("-------------------------\n");
	do {
		subjectMarksReport();
		printf(" Exit? ");
	} while (!yes());
	return 0;
}


