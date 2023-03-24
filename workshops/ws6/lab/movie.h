/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-03-24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOVIES_H
#define SDDS_MOVIES_H

struct Movie
{
	char title[61];
	int year;
	char rating[4];
	int duration;
	char genre[61];
	float crating;
};

int loadMovie(struct Movie* mptr, FILE* fptr);
void printInWidth(const char str[], int width);


void list(const struct Movie* mptr, int row);
void display(const struct Movie* m);
const char* getMovieTitle(const struct Movie* mptr);

#endif // !SDDS_MOVIES_H
