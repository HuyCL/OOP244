//
//  ChequingAccount.hpp
//  at_home8
//
//  Created by Huy Lam on 2018-11-15.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 20/11/2018

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include <iostream>
#include "Account.h"

namespace sict {
    
    class ChequingAccount : public Account {
        double transactionFee;
        double monthEndFee;
    public:
        ChequingAccount(double, double, double);
        bool credit(double);
        bool debit(double);
        void monthEnd();
        void display(std::ostream&) const;
    };
    
}


#endif
