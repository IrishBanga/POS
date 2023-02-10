/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-02-10

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include "rental.h"
#include "utils.h"

void menu(void)
{
    printf("%-14s%-11s%s\n", "Equipment", "Price", "SKU");
	line('-', 28);
    printf("%-14s%-11s%s\n", "Skis","12.30","101");
    printf("%-14s%-11s%s\n", "Boots", "10.45", "102");
    printf("%-14s%-11s%s\n", "Poles", "2.99", "203");
    printf("%-14s%-11s%s\n", "Helmet", "3.99", "204");
    printf("%-14s%-11s%s\n", "Winter Pants", "14.30", "305");
    printf("%-14s%-11s%s\n", "Winter Jacket", "20.55", "306");
    line('-', 28);
}

double rent(int sku)
{
    double price = 0.0;
    switch (sku)
    {
    case 101:
        price = 12.30;
        printf("Skis ............. %5.2lf$\n",price);
        break;
    case 102:
        price = 10.45;
        printf("Boots ............ %5.2lf$\n", price);
        break;
    case 203:
        price = 2.99;
        printf("Poles ............ %5.2lf$\n", price);
        break;
    case 204:
        price = 3.99;
        printf("Helmet ........... %5.2lf$\n", price);
        break;
    case 305:
        price = 14.30;
        printf("Winter Pants .... %5.2lf$\n", price);
        break;
    case 306:
        price = 20.55;
        printf("Winter Jacket .... %5.2lf$\n", price);
        break;
    default:
        printf("Invalid Selection!\n");
        
    }
    return price;
}

void rental(void)
{
    menu();
    int sku;
    int done = 0;
    double total = 0.0;
    do
    {
        printf("Enter Sku or 0 to exit: ");
        sku = getInt();
        if (sku != 0)
        {
            total = total + rent(sku);
        }
        else
        {
            done = 1;
        }
    } 
    while (!done);

        line('-', 28);
        printf("%-19s%5.2lf\n","Total price:",total);
        printf("%-19s%5.2lf\n","Tax",total*0.13);
        printf("%-19s%5.2lf$\n","Total + Tax:",total*1.13);
        line('*', 28);
}
