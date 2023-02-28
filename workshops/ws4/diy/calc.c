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
// a fucntion must have on point of entry and one point of exit
void operation(void) {
   if(scanf("%lf%c%lf%c", &num1, &func, &num2, &check) == 4 && check == '\n') {
      switch(func) {
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
         arg1 = (long)num1;
         arg2 = (long)num2;
         line('-', printf("%ld\n", arg1 % arg2) - 1);
         break;
      case '^':
         for(i = 1; i <= num2; i++) {
            exp = exp * num1;
         }
         line('-', printf("%.3lf\n", exp) - 1);
         break;
      default:
         printf("\'%c\' is not a valid operation, (only +,-,/,x,%% and ^ are acceptable)\n", func);
      }
   }
}
int calc(void)
{
   int success = 1;
    double num1, num2;
    char func;
    char arg;
    char check;
    long int arg1, arg2;
    int i;
    double exp=1;
    printf("> ");
    scanf("%c", &arg);
    if (arg == '?')
    {
       operation();
    }
    else if (arg == '\n')
    {
        success = 0;
    }
    else
    {
        printf("Invalid Command!\n[Question mark][First Number][Operation][Second Number]<ENTER>\n");
        flushKey();
    }  
    return success;
}

