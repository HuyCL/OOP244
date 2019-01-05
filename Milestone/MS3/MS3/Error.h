//
//  Date.hpp
//  MS2
//
//  Created by Huy Lam on 2018-11-06.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Email: hlam25@myseneca.ca
// Date: 17/11/2018

#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

namespace aid {
    
    class Error {
        
        char* ptrMsg;
        
    public:
        
        // Constructor & Destructor
        explicit Error(const char* errorMessage = nullptr);
        Error(const Error& em) = delete;
        Error& operator=(const Error& em) = delete;
        virtual ~Error();
        
        
        void clear();
        bool isClear() const;
        void message(const char* str);
        const char* message() const;
        
        
    };
    
    // Helper Function
    std::ostream& operator<<(std::ostream& os, Error&);
}


#endif
