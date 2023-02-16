/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-02-16

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "calc.h"
#include "utils.h"

int calc(void)
{
    double num1, num2;
    char func;
    char arg;
    char check;
    printf("> ");
    scanf("%c", &arg);
    if (arg == '?')
    {
        if (scanf("%lf%c%lf%c", &num1, &func, &num2, &check) == 4 && check == '\n')
        {
            switch (func)
            {
            case '+':
                line('-', printf("%.3lf\n", num1 + num2) - 1);
                break;
            case '-':
                line('-', printf("%.3lf\n", num1 - num2) - 1);
                break;
            case '/':
                line('-', printf("%.3lf\n", num1 / num2) - 1);
                break;
            case 'x':
                line('-', printf("%.3lf\n", num1 * num2) - 1);
                break;
            case '%':
                long  arg1 = (long)num1;
                long  arg2 = (long)num2;
                line('-', printf("%d\n", arg1 % arg2) - 1);
                break;
            case '^':
                int i;
                double exp = 1.0;
                for (i = 1; i <= num2; i++)
                {
                    exp = exp * num1;
                }
                line('-', printf("%.3lf\n", exp) - 1);
                break;
            default:
                printf("\'%c\' is not a valid operation, (only +,-,/,x,%% and ^ are acceptable)\n", func);
            }
        }
    }
    else if (arg == '\n')
    {
        return 0;
    }
    else
    {
        printf("Invalid Command!\n[Question mark][First Number][Operation][Second Number] < ENTER>\n");
        flushKey();
    }  
    return 1;
}

