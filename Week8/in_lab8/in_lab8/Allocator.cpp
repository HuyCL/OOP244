//
//  iAccount.cpp
//  in_lab8
//
//  Created by Huy Lam on 2018-11-14.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 15/11/2018

#include "SavingsAccount.h"
#include "iAccount.h"

namespace sict {
    
    const double interestRate = 0.05;
    
    iAccount* CreateAccount (const char* type, double bal) {
        
        iAccount *addr;
        addr = nullptr;
        
        if (type[0] == 'S') {
            addr = new SavingsAccount(bal, interestRate);
        }
        
        return addr;
        
    }
}
