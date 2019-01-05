//
//  ChequingAccount.cpp
//  at_home8
//
//  Created by Huy Lam on 2018-11-15.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 20/11/2018

#include "ChequingAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace sict {
    
    ChequingAccount::ChequingAccount(double bal, double transFee, double endFee) : Account(bal){
        transactionFee = (transFee > 0) ? transFee : 0.0;
        monthEndFee = (endFee > 0) ? endFee : 0.0;
    }
    
    bool ChequingAccount::credit(double cre) {
        
        if (Account::credit(cre)) {
            Account::debit(transactionFee);
            return true;
        }
        
        return false;
    }
    
    bool ChequingAccount::debit(double add) {
        
        if(Account::debit(add + transactionFee)) {
            return true;
        }
        
        return false;
    }
    
    void ChequingAccount::monthEnd() {
        Account::debit(monthEndFee);
    }

    void ChequingAccount::display(std::ostream& os) const {
        os << "Account type: Chequing" << endl <<
        "Balance: $" << fixed << setw(6) << setprecision(2) << Account::balance() << endl <<
        "Per Transaction Fee: " << fixed << setw(3) << setprecision(2) << transactionFee << endl <<
        "Monthly Fee: " << fixed << setw(3) << setprecision(2) << monthEndFee << endl;
    }
}
