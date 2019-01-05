//
//  Good.hpp
//  MS3
//
//  Created by Huy Lam on 2018-11-12.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 17/11/2018

#ifndef AMA_GOOD_H
#define AMA_GOOD_H

#include <iostream>
#include "Error.h"

namespace aid {
    
    const int max_sku_length = 7;
    const int max_unit_length = 10;
    const int max_name_length = 75;
    const double tax = 0.13;
    
    class Good : public Error {
        
        char goodType;
        char unitSku[max_sku_length + 1];
        char unitDesc[max_unit_length + 1];
        char* goodName;
        int qtyOnHand;
        int qtyNeed;
        double unitPrice;
        bool taxStatus;
        Error errorState;
        
    protected:
        void name(const char*);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double itemPrice() const;
        double itemCost() const;
        void message(const char*);
        bool isClear() const;
        
    public:
        Good(char type = 'N');
        Good(const char*, const char*, const char*, int onHand = 0, bool taxStatus = true, double beforeTax = 0, int itemNeed = 0);
        Good(const Good&);
        Good& operator=(const Good&);
        ~Good();
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        bool operator>(const Good&) const;
        int operator+=(int);
        
    };
    
    std::ostream& operator<<(std::ostream&, const Good&);
    std::istream& operator>>(std::istream&, Good&);
    double operator+=(double&, const Good&);
    
}

#endif
