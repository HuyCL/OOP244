//
//  SavingsAccount.cpp
//  in_lab8
//
//  Created by Huy Lam on 2018-11-14.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 20/11/2018

#include "SavingsAccount.h"
#include <iostream>
using namespace std;

namespace sict {
    
    SavingsAccount::SavingsAccount(double bal, double rate) : Account(bal) {
        if (rate > 0) {
            currentRate = rate;
        }
        else {
            currentRate = 0;
        }
    }
    
    void SavingsAccount::monthEnd() {
        
        double interest = balance() * currentRate;
        credit(interest);
    }
    
    void SavingsAccount::display(std::ostream& os) const {
        
        os << "Account type: Savings" << endl;
        os.precision(2);
        os << fixed << "Balance: $" << balance() << endl;
        os << fixed << "Interest Rate (%): " << (currentRate * 100) << endl;
    }
}
