//
//  Contact.hpp
//  in_lab6
//
//  Created by Huy Lam on 2018-11-01.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Email: hlam25@myseneca.ca
// Date: 01/11/2018

#ifndef Contact_hpp
#define Contact_hpp

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H


namespace sict {
    
    const int MAX_CHAR = 31;
    
    class Contact {
        
        char name[MAX_CHAR];
        long long* ptrPhone;
        int pNum;
        
    public:
        Contact();
        Contact(const char*,  const long long*, const int);
        ~Contact();
        
        bool isEmpty() const;
        void display() const;
        bool validation(const long long);
        
    };
    
}

#endif
#endif /* Contact_hpp */
