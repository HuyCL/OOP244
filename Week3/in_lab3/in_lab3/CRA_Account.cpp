//
//  CRA_Account.cpp
//  in_lab3
//
//  Created by Huy Lam on 2018-09-25.
//  Copyright © 2018 Huy Lam. All rights reserved.
//

#include "CRA_Account.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sict {

CRA_Account::CRA_Account() {
    
}

void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
    if (sin >= min_sin && sin <= max_sin) {
        strncpy(f_Name, familyName, sizeof(f_Name));
        strncpy(g_Name, givenName, sizeof(g_Name));
        si_no = sin;
    }
}
bool CRA_Account::isEmpty() const {
    bool result;
    if (si_no != 0) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}
void CRA_Account::display() const {
    if (isEmpty()) {
        cout << "Account object is empty!" << endl;
    } else {
        cout << "Family Name : " << f_Name << endl;
        cout << "Given Name  : " << g_Name << endl;
        cout << "CRA Account : " << si_no << endl;
    }
}
}
