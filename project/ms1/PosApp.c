/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.c
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
#include <stdio.h>

void start(const char* action) {
	printf(">>>> %s...\n", action);
}
int loadItems(const char filename[]) {
	start("Loading Items");
	return 1;
}
void saveItems(const char filename[]) {
	start("Saving Items");
}

void inventory(void) {
	start("Inventory");
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