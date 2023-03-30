/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 1
Module: PosUI
Filename: PosUI.c
Version 1.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/04/02  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/
#include "utils.h"

int menu(void)
{
	printf("The Sene-Store\n"
		"1 - Inventory\n"
		"2 - Add item\n"
		"3 - Remove item\n"
		"4 - Stock item\n"
		"5 - POS\n"
		"0 - exit program\n"
	    "> ");
	return getMMInt(0, 5, "Selection");
}

void runPos(const char filename[])
{
	int choice;
	int done = 0;
	printf(">>>> Loading Items...\n");
	while (!done)
	{
		
		choice = menu();
		switch (choice)
		{
		case 1:
			printf(">>>> Inventory...\n");
			break;
		case 2:
			printf(">>>> Adding item...\n");
			break;
		case 3:
			printf(">>>> Remove item...\n");
			break;
		case 4:
			printf(">>>> Stock items...\n");
			break;
		case 5:
			printf(">>>> Point Of Sale...\n");
			break;
		default:
			done = 1;
			//printf("Goodbye!\n");
		}
	}
	printf(">>>> Saving Items...\n");
	printf("Goodbye!\n");
}