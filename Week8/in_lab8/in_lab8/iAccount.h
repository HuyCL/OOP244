//
//  iAccount.hpp
//  in_lab8
//
//  Created by Huy Lam on 2018-11-14.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 15/11/2018

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

#include <iostream>

namespace sict {
    
    class iAccount {
        
    public:
        virtual bool credit(double) = 0;
        virtual bool debit(double) = 0;
        virtual void monthEnd() = 0;
        virtual void display(std::ostream&) const = 0;
        virtual ~iAccount() {};
        
    };
    
    iAccount*  CreateAccount(const char*, double);
    
}

#endif
