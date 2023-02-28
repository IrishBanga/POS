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

void flushKey();

int getInt()
{
    int value = 0;
    int done = 0;
    char check = 0;
    while (!done) 
    {
        if (scanf("%d", &value) == 1)
        {
           if(getchar() == '\n') {
              done = 1;
           }
           else {
              flushKey();
           }
        }
        else
        { 
            flushKey();
            if (value == 0)
            {
                printf("Invalid Integer, try again: ");

            }
            else
            {
                printf("Enter only an integer, try again: ");
            }
        }
    }
    return value;
}


int getIntMM(int min, int max)
{
    int value;
    int done = 0;
    value = getInt();
    while (!done)
    {
        if (value >= min && value <= max)
        {
            done = 1;
        }
        else
        {
            printf("[%d<=Number<=%d], try again: ",min,max);
            value = getInt();
        }
    }
    return value;
}

double getDouble(void)
{
    double dvalue = 0.0;
    int done = 0;
    char check = 0;
    while (!done) 
    {
        if (scanf("%lf%c", &dvalue, &check) == 2 && check == '\n')
        {
            done = 1;
        }
        else
        { 
            flushKey();
            if (dvalue == 0.0)
            {
                printf("Invalid Double, try again: ");

            }
            else
            {
                printf("Enter only a Double, try again: ");
            }
        }
    }
    return dvalue;
}

double getDoubleMM(double min, double max)
{
    double dvalue;
    int done = 0;
    dvalue = getDouble();
    while (!done)
    {
        if (dvalue >= min && dvalue <= max)
        {
            done = 1;
        }
        else
        {
            printf("[%.3lf<=Number<=%.3lf], try again: ",min,max);
            dvalue = getDouble();
        }
    }
    return dvalue;
}

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

void flushKey()
{
    char ch = 'x';
    while (ch != '\n')
    {
        ch = getchar();
    }
}