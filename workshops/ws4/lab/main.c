/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Competion Date: 2023-02-10
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utils.h"
#include "rental.h"

int main(void) 
{
    printf("Welcome to Seneca Ski Equipment Rentals...\n"
        "------------------------------------------\n");
    menu();
    do 
    {
        rental();
        printf("Exit Program? ");
    } while (!yes());

    return 0;
}