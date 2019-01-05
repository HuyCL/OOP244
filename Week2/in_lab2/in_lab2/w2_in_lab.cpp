//
//  main.cpp
//  in_lab2
//
//  Created by Huy Lam on 2018-09-18.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
/***********************************************************
 // Workshop 2: Dynamic Memory
 // File w2_in_lab.cpp
 // Version 2.0
 //
 // Name: Huy Lam
 // SID: 114705162
 // Section: GG
 // Date: 20/9/2018
 //
 // Revision History
 ///////////////////////////////////////////////////////////
 // Name     Date    Reason
 //
 ///////////////////////////////////////////////////////////
 ***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array
    
    Kingdom* pKingdom = nullptr;
    cout << "==========\n"
    << "Input data\n"
    << "==========\n"
    << "Enter the number of Kingdoms: ";
    cin >> count;
    cin.ignore();
    
    if (count < 1) return 1;
    

    pKingdom = new Kingdom[count];
    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;
         
    }
    cout << "==========" << endl << endl;
    
    // testing that "display(...)" works
    cout << "------------------------------" << endl
    << "The 1st kingdom entered is" << endl
    << "------------------------------" << endl;
    sict::display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;
    
    delete [] pKingdom;
    pKingdom = nullptr;
    return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(sict::Kingdom& kingdom) {
    
    cout << "Enter the name of the Kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number of people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}
