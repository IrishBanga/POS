/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 5
Module: PosApp
Filename: PosApp.c
Version 5.0
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
2023/04/14  modified search() to include values NOT_FOUND and END_POS
2023/04/14  added selectItems(), modified stockItem() -v4
2023/04/15	modified addItem(), removeItem() -v5
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

/*
v5 addItem()- modified to add Items to inventory by taking details as input in a defined format
*/
void addItem(void) 
{
	start("Adding Item");
	if (noOfItems < MAX_NO_ITEMS)
	{
		printf("SKU: ");
		scanf("%s", items[noOfItems].sku);
		printf("Name: ");
		scanf("%s", items[noOfItems].name);
		flushKey();
		printf("Price: ");
		items[noOfItems].price = getDouble();
		printf("Is the item Taxed? (Y)es/(N)o: ");
		items[noOfItems].taxed = yes();
		printf("Quantity: ");
		items[noOfItems].quantity = getMMInt(1, MAX_STOCK_NUMBER, "Quantity");
		noOfItems++;
		start("Done!");
	}
	else
	{
		printf("This system cannot store more that %d different Items in the inventory!\n", MAX_NO_ITEMS);
	}
}

/*
v5 removeItem()- modified to delete Items from the inventory
*/
void removeItem(void) 
{
	int i,remove;
	start("Remove Item");
	remove=selectItems();
	for (i = remove; i < noOfItems-1; i++)
	{
		items[i] = items[i + 1];
	}
	noOfItems--;
	start("Done!");
}

/*
v4 selectItems()- new function to select an item from the inventory
*/
int selectItems(void)
{
	int choice;
	printf("Select an item:\n");
	printf("-----v--------v--------------------v-------v---v-----v---------v\n");
	listItems();
	printf("Select row: ");
	choice = getMMInt(1,noOfItems,"Row Number");
	return choice-1;
}

/*
v4 stockItem()- added functionality for the user to update the quantity of an item upto MAX_STOCK_NUMBER
*/
void stockItem(void) 
{
	int sel,qty;
	start("Stock Items");
	sel=selectItems();
	display(&items[sel]);
	printf("Quantity to add: ");
	qty = getMMInt(1,MAX_STOCK_NUMBER-items[sel].quantity,"Quantity to Add");
	items[sel].quantity = items[sel].quantity + qty;
	start("Done!");
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
	start("Point Of Sale");
	int i;
	for (i = 0;find != END_POS && i < MAX_BILL_ITEMS;)
	{
		find = search();
		if (find>=0)
		{
			if (items[find].quantity > 0)
			{
				items[find].quantity = items[find].quantity - 1;
				display(&items[find]);
				bill[i] = find;
				i++;
			}
			else
			{
				printf("Item sold out!\n");
			}
		}
		else if(find==NOT_FOUND)
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
			total = total + cost(&items[bill[i]]);
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
v34 search()- new function to search for an item based on sku input by user
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