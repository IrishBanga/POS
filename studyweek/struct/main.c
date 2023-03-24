#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"

/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-02-25

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

/*
*Student:
Name
student number
email
*/
/*
*Subject:
Name
prefix
code
section
Students
*/
struct Name {
	char first[51];
	char last[101];
};

struct Student {
	struct Name name;
	long stno;
	char email[256];
};

struct Subject {
	char name[256];
	char pre[4];
	int code;
	char section[4];
	int numberOfStudents; //obviously should not be more that 40;
	struct Student student[40];
};

// write these two functions and get big bonus!!! yaaaay!
// user should enter the number of students

struct Subject getSubject()
{
	int i;
	struct Subject get;
	printf("Please enter subject details.\n");
	printf("Name    :");
	scanf("%[^\n]", &get.name);
	printf("Prefix  :");
	scanf("%s", &get.pre);
	printf("Code    :");
	scanf("%d", &get.code);
	printf("Section :");
	scanf("%s", &get.section);
	printf("Number Of Students:");
	scanf("%d", &get.numberOfStudents);
	flushKey();
	line('-', 35);

	for(i=0;i<get.numberOfStudents;i++)
	{
		printf("Student Number:%d\n", i + 1);
		printf("Name(first):");
		scanf("%s", &get.student[i].name.first);
		printf("Name(last) :");
		scanf("%s", &get.student[i].name.last);
		printf("ID         :");
		scanf("%ld", &get.student[i].stno);
		printf("E-mail     :");
		scanf("%s", &get.student[i].email);
		flushKey();
		line('-', 35);
	}
	return get;
}

void printSubject(struct Subject S);

int main() 
{
	struct Subject S;
	S = getSubject();
	printSubject(S);
	return 0;
}

void printSubject(struct Subject S)
{
	printf("Subject Details!\n");
	printf("Name    :%s\n", S.name);
	printf("Prefix  :%s\n", S.pre);
	printf("Code    :%d\n", S.code);
	printf("Section :%s\n", S.section);
	printf("Number Of Students:%d\n", S.numberOfStudents);
	line('-', 35);
	int i;
	for (i = 0; i < S.numberOfStudents; i++)
	{
		printf("Student Number:%d\n",i+1);
		printf("Name  :%s %s\n", S.student[i].name.first, S.student[i].name.last);
		printf("ID    :%ld\n", S.student[i].stno);
		printf("E-mail:%s\n", S.student[i].email);
		line('-', 35);
	}
}
