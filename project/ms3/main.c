/*
Name: Irish Banga
Email: ibanga1@myseneca.ca
Student ID: 112435227

Citation and Sources...
Final Project Milestone 35
Module: main
Filename: main.c
Version 1.0
Author: Fardad Solimanloo
Revision History
-----------------------------------------------------------
Date        Reason
2023/04/01  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

// Final Project 
// Student POS App M31 tester program
// Version 1.0
// Date	2023-04-01
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
//
/////////////////////////////////////////////////////////////////
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include "PosApp.h"
//void fileDump(const char* filename);
//int main() {
//   fileDump("posdata.csv");
//   loadItems("posdata.csv");
//   saveItems("posdata_out.csv");
//   fileDump("posdata_out.csv");
//   return 0;
//}
//
//void fileDump(const char* filename) {
//   FILE* fptr= fopen(filename, "r");
//   if(fptr) {
//      char ch=0;
//      printf("Contents of file >>%s<<:\n",filename);
//      while(fscanf(fptr, "%c", &ch) == 1) {
//         putchar(ch);
//      }
//      fclose(fptr);
//      printf("End of data in >>%s<<\n", filename);
//   }
//   else {
//      printf("file: >>%s<< not found!\n", filename);
//   }
//}

// Final Project 
// Student POS App M32 tester program
// Version 1.0
// Date	2023-04-01
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
//
/////////////////////////////////////////////////////////////////
//#include "PosApp.h"
//int main() {
//    struct Item I[6] = {
//       {"3695","Honeydew Melon",5.99,0,20},
//       {"1679","Jack's Apple Juice",1.50,0,80},
//       {"6539","Joe's Organic Potato Chips",3.29,1,15},
//       {"9462","Kiwifruit",0.50,0,123 },
//       {"4297","Lays Chips S&V",3.69,1,1},
//       {"1234","Milk",3.99,0,1}
//    };
//    int i;
//    double total = 0;
//    printf("  Name                Price  taxed\n");
//    for (i = 0; i < 6; i++) {
//        total += billDisplay(&I[i]);
//    }
//    printf("total: %.2lf", total);
//    return 0;
//}

// Final Project 
// Student POS App M33 tester program
// Version 1.0
// Date	2023-04-01
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
//
/////////////////////////////////////////////////////////////////
//#include <stdio.h>
//#include "PosApp.h"
//int main() {
//    struct Item I[6] = {
//       {"3695","Honeydew Melon",5.99,0,20},
//       {"1679","Jack's Apple Juice",1.50,0,80},
//       {"6539","Joe's Organic Potato Chips",3.29,1,15},
//       {"9462","Kiwifruit",0.50,0,123 },
//       {"4297","Lays Chips S&V",3.69,1,1},
//       {"1234","Milk",3.99,0,1}
//    };
//    int i;
//    double total = 0;
//    for (i = 0; i < 6; i++) {
//        display(&I[i]);
//        total += cost(&I[i]);
//    }
//    printf("total: %.2lf", total);
//    return 0;
//}

// Final Project 
// Student POS App M34 tester program
// Version 1.0
// Date	2023-04-01
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
//
/////////////////////////////////////////////////////////////////
//#include <stdio.h>
//#include "PosApp.h"
//int main() {
//    int i;
//    int foundIndex;
//    loadItems("posdata.csv");
//    for (i = 0; (foundIndex = search()) != -2; i++) {
//        if (foundIndex >= 0) {
//            printf("SKU found at index %d\n", foundIndex);
//        }
//        else {
//            printf("SKU not found!\n");
//        }
//    }
//    printf("Search was executed %d times...", i);
//    return 0;
//}

// Final Project 
// Student POS App M35 tester program
// Version 1.0
// Date	2023-04-01
// Author	Fardad Soleimanloo
// Description
// This program test the student implementation of the Item class
// for submission.
//
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "PosUI.h"
void fileDump(const char* filename);
void ressetData();
int main() {
    ressetData();
    fileDump("posdata.csv");
    runPos("posdata.csv");
    fileDump("posdata.csv");
    return 0;
}

void ressetData() {
    FILE* f_origin = fopen("posdataOrigin.csv", "r");
    FILE* f_data = fopen("posdata.csv", "w");
    char ch;
    while (fscanf(f_origin, "%c", &ch) == 1) {
        fprintf(f_data, "%c", ch);
    }
    fclose(f_origin);
    fclose(f_data);
}
void fileDump(const char* filename) {
    FILE* fptr = fopen(filename, "r");
    if (fptr) {
        char ch = 0;
        printf("Contents of file >>%s<<:\n", filename);
        while (fscanf(fptr, "%c", &ch) == 1) {
            putchar(ch);
        }
        fclose(fptr);
        printf("End of data in >>%s<<\n", filename);
    }
    else {
        printf("file: >>%s<< not found!\n", filename);
    }
}
