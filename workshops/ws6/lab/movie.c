/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227
Completion Date: 2023-03-24

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Movie.h"
#include "utils.h"

int loadMovie(struct Movie* mptr, FILE* fptr)
{
	return (fscanf(fptr, "%[^\t]\t%d\t%[^\t]\t%d\t%[^\t]\t%f\n", mptr->title, &mptr->year, mptr->rating, &mptr->duration, mptr->genre, &mptr->crating) == 6);
}

void printInWidth(const char str[], int width)
{
	printf("| %-*.*s |", width, width, str);
}

void list(const struct Movie* mptr, int row)
{
	printf("|%4d ",row);
	printInWidth(mptr->title, 20);
	printf(" %d ", mptr->year);
	printf("|%5s |",mptr->rating);
	printf(" %d:%.2d ", mptr->duration/60, mptr->duration%60);
	printInWidth(mptr->genre, 25);
	printf("  %.1f |", mptr->crating);
	putchar('\n');
}

void display(const struct Movie* m)
{
	printf("Title: %s\n", m->title);
	printf("Year: %d\n", m->year);
	printf("Rating: %s\n", m->rating);
	printf("Duration: %d:%.2d\n", m->duration / 60, m->duration % 60);
	printf("Genres: %s\n", m->genre);
	printf("Consumer Rating: %.1f\n", m->crating);
}

const char* getMovieTitle(const struct Movie* mptr)
{
	return mptr->title;
}