/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 2
Module: PosApp
Filename: PosApp.c
Version 2.0
Author: Irish Banga
Revision History
-----------------------------------------------------------------------
Date        Reason
2023/04/02  Preliminary release
2023/04/07	Added cost(), listItems() and modified loadItems(), inventory()
            (descriptive comments alongwith functions)
-----------------------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "POS.h"
#include "PosApp.h"
#include <string.h>

void start(const char* action) {
	printf(">>>> %s...\n", action);
}

/*
v2 loadItems()- added functionality to read contents from a file, 
update into an array structure and return number of successful reads
*/
int loadItems(const char filename[])
{
	start("Loading Items");
	FILE* ptr = fopen(filename,"r");
	if (ptr!=NULL)
	{
		int i = 0;
		while (i< MAX_NO_ITEMS && fscanf(ptr, "%[^,],%[^,],%lf,%d,%d\n", items[i].sku,items[i].name,&items[i].price,&items[i].taxed,&items[i].quantity) == 5)
		{
			i++;
		}
		noOfItems = i;
	}
	fclose(ptr);
	start("Done!");
	return noOfItems;
}

void saveItems(const char filename[]) {
	start("Saving Items");
}

/*
v2 inventory()- added functionality to display descriptive list of all items and calculate total asset value
*/
void inventory(void) 
{
	start("List Items");
	listItems();
	double tav = 0.0;
	int i;
	for (i = 0; i < noOfItems; i++)
	{
		
		tav= tav+(cost(&items[i]) * items[i].quantity);
	}
	printf("                               Total Asset: $  | %13.2lf |\n",tav);
	printf("-----------------------------------------------^---------------^\n");
}

void addItem(void) {
	start("Adding Item");
}
void removeItem(void) {
	start("Remove Item");
}
void stockItem(void) {
	start("Stock Items");
}
void POS(void) {
	start("Point Of Sale");
}

/*
v2 cost()- new function to calculate and return total cost of an item(tax inclusive)
*/
double cost(const struct Item* item) 
{
	double the_cost;
	the_cost =  (item->price * (1 + (item->taxed * TAX)));
	return the_cost;
}

/*
v2 listItems()- new function to display item details in a specified format
*/
void listItems(void) 
{
	char iName[18 + 1] = { '\0' };
	printf(" Row | SKU    | Item Name          | Price |TX | Qty |   Total |\n"
           "-----|--------|--------------------|-------|---|-----|---------|\n");
	int i;
	for (i = 0; i < noOfItems; i++)
	{
		strncpy(iName,items[i].name,18);
		printf("%4d | %6s | %-18s |%6.2lf | %c | %3d |%8.2lf |\n",i+1,items[i].sku,iName,items[i].price,items[i].taxed ? 'T' : ' ', items[i].quantity, (cost(&items[i]) * items[i].quantity));
	}
	printf("-----^--------^--------------------^-------^---^-----^---------^\n");
}