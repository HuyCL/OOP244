//
//  Kingdom.cpp
//  in_lab2
//
//  Created by Huy Lam on 2018-09-18.
//  Copyright © 2018 Huy Lam. All rights reserved.
//

#include "Kingdom.h"
#include <iostream>
using namespace std;
/***********************************************************
 // OOP244 Workshop 2: Dynamic Memory
 // File Kingdom.cpp
 // Version 1.0
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


namespace sict {
    void display (const Kingdom& k) {
        cout << k.m_name << ", population " << k.m_population << endl;
    }
}
