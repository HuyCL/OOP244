//
//  Account.hpp
//  in_lab8
//
//  Created by Huy Lam on 2018-11-14.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 20/11/2018

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include <iostream>
#include "iAccount.h"

namespace sict {
    
    class Account: public iAccount {
        
        double currentBalance;
        
    protected:
        double balance() const;
        
    public:
        Account(double);
        bool credit(double);
        bool debit(double);
        
    };
    
}

#endif
