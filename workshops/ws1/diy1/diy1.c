/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-01-25

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
void title(void);
void line(void);
void info(void);
int avg(void);

 main(void)
{
	title();
	line();
	info();
	line();
	avg();
	
	return 0;
}

int avg(void)
{
	int a, b, c,avg;
	printf("Enter the marks for the following subjects,\n");
	printf("IPC144: ");
	scanf("%d",&a);
	printf("ULI101: ");
	scanf("%d",&b);
	printf("EAC150: ");
	scanf("%d",&c);
	avg = (a + b + c) / 3;
	printf("The average is: %d\n", +avg);
	line();
}

void title(void)
{
	printf("IPC144 NBB\tWorkshop 1\tPart 2\n");
}

void line(void)
{
	int i = 0;
	while (i < 60) 
	{
		putchar('-');
		i++;
	}
	putchar('\n');
}

void info(void)
{
	printf("Name:\n\tIrish Banga\nEmail:\n\tibanga1@myseneca.ca\n");
}