//
//  Account.cpp
//  in_lab8
//
//  Created by Huy Lam on 2018-11-14.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 15/11/2018

#include "Account.h"
#include <iostream>

namespace sict {
    
    Account::Account(double bal) {
        
        if (bal > 0) {
            currentBalance = bal;
        }
        else {
            currentBalance = 0;
        }
    }
    
    bool Account::credit(double cre) {
        
        bool result;
        
        if (cre > 0) {
            currentBalance += cre;
            result = true;
        }
        else {
            result = false;
        }
        
        return result;
    }
    
    bool Account::debit(double deb) {
        
        bool result;
        
        if (deb > 0) {
            currentBalance -= deb;
            result = true;
        }
        else {
            result = false;
        }
        
        return result;
    }
    
    double Account::balance() const {
        return currentBalance;
    }
    
}
