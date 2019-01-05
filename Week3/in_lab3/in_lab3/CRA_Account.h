//
//  CRA_Account.hpp
//  in_lab3
//
//  Created by Huy Lam on 2018-09-25.
//  Copyright © 2018 Huy Lam. All rights reserved.
//

#ifndef CRA_Account_hpp
#define CRA_Account_hpp

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
    
    const int max_name_length = 41;
    const int min_sin = 100000000;
    const int max_sin = 999999999;
    
    class CRA_Account {
        char f_Name[max_name_length];
        char g_Name[max_name_length];
        int si_no;
        
    public:
        void set(const char* familyName, const char* givenName, int sin);
        bool isEmpty() const;
        void display() const;
        CRA_Account();
    };
    
}

#endif

#endif /* CRA_Account_hpp */
