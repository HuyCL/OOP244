//
//  SavingsAccount.hpp
//  in_lab8
//
//  Created by Huy Lam on 2018-11-14.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 20/11/2018

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include "Account.h"
#include <iostream>

namespace sict {
    
    class SavingsAccount: public Account {
        double currentRate;
    public:
        SavingsAccount(double, double);
        void monthEnd();
        void display(std::ostream&) const;
    };
    
}

#endif
