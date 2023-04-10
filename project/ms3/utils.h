/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 34
Module: utils
Filename: utils.h
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

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

int getInt(void);
int getIntMM(int min, int max);
double getDouble(void);
double getDoubleMM(double min, double max);
void line(char fill, int length);
int getMMInt(int min, int max, const char valueName[]);

void flushKey();
int yes(void);
char getSingleChar(void);




#endif // !SDDS_UTILS_H


