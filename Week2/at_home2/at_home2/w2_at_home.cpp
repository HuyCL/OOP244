//
//  main.cpp
//  at_home2
//
//  Created by Huy Lam on 2018-09-20.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
/***********************************************************
 // Workshop 2: Dynamic Memory
 // File w2_at_home.cpp
 // Version 2.0
 // Date ???????????
 // Author ?????????
 // Description
 // ?????????????????????
 //
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

void read(Kingdom&);

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
        cout << "Enter the name of the Kingdom: ";
        cin >> pKingdom[i].m_name;
        cout << "Enter the number of people living in " << pKingdom[i].m_name << ": ";
        cin >> pKingdom[i].m_population;
    }
    cout << "==========" << endl << endl;
    
    // testing that "display(...)" works
    cout << "------------------------------" << endl
    << "The 1st kingdom entered is" << endl
    << "------------------------------" << endl;
    display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;
    
    // expand the array of Kingdoms by 1 element
    Kingdom* ppKingdom = nullptr;
    ppKingdom = new Kingdom[count+1];
    for (int i = 0; i < count; i++) {
        ppKingdom[i] = pKingdom[i];
    }
    delete [] pKingdom;
    
    pKingdom = ppKingdom;
    // add the new Kingdom
    cout << "==========\n"
    << "Input data\n"
    << "==========\n"
    << "Kingdom #" << count + 1 << ": " << endl;

    cout << "Enter the name of the Kingdom: ";
    cin >> pKingdom[count].m_name;
    cout << "Enter the number of people living in " << pKingdom[count].m_name << ": ";
    cin >> pKingdom[count].m_population;
    cout << "==========\n" << endl;
    count++;
    // testing that the overload of "display(...)" works
    display(pKingdom, count);
    cout << endl;
    
    delete [] ppKingdom;
    return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {
    cout << "Enter the name of the Kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number of people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}
