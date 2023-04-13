/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 35
Module: PosApp
Filename: PosApp.c
Version 3.0
Author: Irish Banga
Revision History
-----------------------------------------------------------------------
Date        Reason
2023/04/02  Preliminary release
2023/04/07	Added cost(), listItems() and modified loadItems(), inventory()
            (descriptive comments alongwith functions)
2023/04/09	modified saveItems() -v31
2023/04/09  added billDisplay()  -v32
2023/04/09  added display() -v33
2023/04/09  added search() -v34
2023/04/10  modified POS() -v35
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
#include "utils.h"

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

/*
v31 saveItems()- added functionality to write all the items details from array structure 
into a file in commma separated format where each item record is separated by a newline
*/
void saveItems(const char filename[]) 
{
	start("Saving Items");
	FILE* file = fopen(filename, "w");
	if (file != NULL)
	{
		int i;
		for(i=0;i<noOfItems;i++)
		{
			fprintf(file, "%s,%s,%.2lf,%d,%d\n",items[i].sku, items[i].name, items[i].price, items[i].taxed, items[i].quantity);
		}
	}
	else
	{
		printf("Could not open >>%s<<\n",filename);
	}
	fclose(file);
	start("Done!");
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

/*
v35 POS()- added functionality to genrerate a proper billing reciept by sku input from user
adding an item to transaction, updating quantity in the inventory and calculating the total bill 
*/
void POS(void) 
{
	int find = 0;
	int itemcnt = 0;
	int bill[MAX_BILL_ITEMS+1] = {'\0'};
//	struct Item* iptr[MAX_BILL_ITEMS];

	start("Point Of Sale");
	int i;
	for (i = 0;find != -2 && i < MAX_BILL_ITEMS;)
	{
		find = search();
		if (find>=0)
		{
			if (items[find].quantity > 0)
			{
				items[find].quantity = items[find].quantity - 1;
				display(&items[find]);
				bill[i] = find;
	//			iptr[i] = &items[find];
				i++;
			}
			else
			{
				printf("Item sold out!\n");
			}
		}
		else if(find==-1)
		{
			printf("SKU not found!\n");
		}
	}
	itemcnt = i;
	double total = 0;
	if (itemcnt)
	{
		printf("+---------------v-----------v-----+\n");
		printf("| Item          |     Price | Tax |\n");
		printf("+---------------+-----------+-----+\n");
		for (i = 0; i < itemcnt;)
		{
			billDisplay(&items[bill[i]]);
	//		billDisplay(iptr[i]);
			total = total + cost(&items[bill[i]]); // perfect
		//	total = total + cost(iptr[i]);
			i++;
		}
		printf("+---------------^-----------^-----+\n");
		printf("| total:              %.2lf |\n", total);
		printf("^---------------------------^\n");
	}
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

/*
v32 billDisplay()- new function to generate billing receipt and return cost of item
*/
double billDisplay(const struct Item* item)
{
	char product[15] = { '\0' };
	strncpy(product, item->name, 14);
	printf("| %-14s|%10.2lf | %s |\n",product,cost(item), item->taxed ? "Yes" : "   ");
	return cost(item);
}

/*
v33 display()- new function to print item details in a detailed format
*/
void display(const struct Item* item)
{
	printf("=============v\n");
	printf("%-13s%s\n","Name:",item->name);
	printf("%-13s%s\n", "Sku:", item->sku);
	printf("%-13s%.2lf\n", "Price:", item->price);
	if (item->taxed)
	{
		printf("%-13s%.2lf\n", "Price + tax:",cost(item));
	}
	else
	{
		printf("%-13s%s\n", "Price + tax:","N/A");
	}
	printf("%-13s%d\n", "Stock Qty:", item->quantity);
	printf("=============^\n");
}

/*
v34 search()- new function
*/
int search(void)
{
	int i;
	char sku[MAX_SKU_LEN] = {'\0'};
	int index = NOT_FOUND;
	printf("Sku: ");
	scanf("%[^\n]",sku);
	flushKey();
	for (i = 0; index == NOT_FOUND && i < noOfItems; i++)
	{
		if (strcmp(items[i].sku, sku) == 0)
		{
			index = i;
		}
		else if (sku[0] == '\0')
		{
			index = END_POS;
		}
	}
	return index;
}