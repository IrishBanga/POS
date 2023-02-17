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

void printReport(const char subjectCode[], const int studentNumbers[],
    const int marks[], int noOfStudents)
{
    int i, avg, lm, hm;
    lm = hm = 0;
    avg = 0;
    printf("SUBJECT MARKS REPORT!\n");
    printf("  +---------------+\n");
    printf("  | %-14s|\n",subjectCode);
    printf("  +--------+------+\n");
    printf("  | Std No | mark |\n");
    printf("  +--------+------+\n");
    for (i = 0; i < noOfStudents; i++)
    {
        if (i == 0)
        {
            lm = hm = marks[i];
        }
        else
        {
            if (marks[i] > hm)
                hm = marks[i];
            if (marks[i] < lm)
                lm = marks[i];
        }
        avg = avg + marks[i];
        printf("  | %06d |%5d |\n", studentNumbers[i], marks[i]);
    }
    printf("  +--------+------+\n");
    printf("  |%-8s|%5d |\n","Average",avg/noOfStudents);
    printf("  |%-8s|%5d |\n","Highest",hm);
    printf("  |%-8s|%5d |\n","Lowest",lm);
    printf("  +--------+------+\n");
}