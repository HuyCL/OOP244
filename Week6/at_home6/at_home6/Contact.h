//
//  Contact.hpp
//  at_home6
//
//  Created by Huy Lam on 2018-11-04.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Email: hlam25@myseneca.ca
// Date: 04/11/2018

#ifndef Contact_hpp
#define Contact_hpp

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H


namespace sict {
    
    const int MAX_CHAR = 20;
    
    class Contact {
        
        char name[MAX_CHAR];
        long long* ptrPhone;
        int pNum;
        
    public:
        Contact();
        Contact(const char*,  const long long*, const int);
        ~Contact();
        Contact(const Contact&);
        
        Contact& operator=(const Contact&);
        Contact& operator+=(const long long);
        
        bool isEmpty() const;
        void display() const;
        bool validation(const long long);
        
    };
    
}

#endif
#endif /* Contact_hpp */
