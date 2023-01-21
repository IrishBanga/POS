/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-01-20

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <stdio.h>
void title(void);
void line(void);
void info(void);

int main(void)
{
	title();
	line();
	info();
	line();
	return 0;
}

void title(void)
{
	printf("IPC144 NBB\tWorkshhop1\tPart1\n");	
}

void line(void)
{
	printf("------------------------------------------------------------\n");
}

void info(void)
{
	printf("Name:\n\tIrish Banga\nEmail:\n\tibanga1@myseneca.ca\n");
}