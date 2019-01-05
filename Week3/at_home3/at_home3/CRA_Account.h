//
//  CRA_Account.hpp
//  at_home3
//
//  Created by Huy Lam on 2018-09-27.
//  Copyright © 2018 Huy Lam. All rights reserved.
//

// Name: Huy Lam
// Seneca ID: 114705162
// Section: GG
// Seneca Email: hlam25@myseneca.ca
// Date: 29/09/2018

#ifndef CRA_Account_hpp
#define CRA_Account_hpp

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
    
    const int max_name_length = 41;
    const int min_sin = 100000000;
    const int max_sin = 999999999;
    const int max_yrs = 4;
    
    class CRA_Account {
        char f_Name[max_name_length];
        char g_Name[max_name_length];
        int si_no;
        int returnYear[max_yrs];
        double balOwe[max_yrs];
        int numYears;
        
    public:
        void set(const char* familyName, const char* givenName, int sin);
        bool isEmpty() const;
        void display() const;
        void set(int year, double balance);
        bool validation(int);
    };
    
}

#endif

#endif /* CRA_Account_hpp */
