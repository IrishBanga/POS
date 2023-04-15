/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 4
Module: PosApp
Filename: PosApp.h
Version 4.0
Author: Irish Banga
Revision History
-----------------------------------------------------------
Date        Reason
2023/04/02  Preliminary release
2023/04/07	Added a structure, function prototypes, etc.
2023/04/09	added billDisplay() -v32
2023/04/09  added display() -v33
2023/04/09  added search() -v34
2023/04/14  added selectItems -v4
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------

*/

#include "POS.h"
#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H

void start(const char* action);
void inventory(void);
void addItem(void);
void removeItem(void);
void stockItem(void);
void POS(void);
int loadItems(const char filename[]);
void saveItems(const char filename[]);

//v2 additions
struct Item
{
	char sku[MAX_SKU_LEN];
	char name[60];
	double price;
	int taxed;
	int quantity;
};

double cost(const struct Item* item);
void listItems(void);
struct Item items[MAX_NO_ITEMS];
int noOfItems;

//v32 addition
double billDisplay(const struct Item* item);

//v33 addition
void display(const struct Item* item);

//v34 addition
int search(void);

//v4 addition
int selectItems(void);

#endif // !SDDS_POSAPP_H
