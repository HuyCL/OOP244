//
//  iGood.hpp
//  MS4
//
//  Created by Huy Lam on 2018-11-22.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 23/11/2018

#ifndef AID_IGOOD_H
#define AID_IGOOD_H
#include <iostream>
#include <fstream>

namespace aid {
    
    class iGood {
        
    public:
        virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
        virtual std::fstream& load(std::fstream& file) = 0;
        virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool operator==(const char*) const = 0;
        virtual double total_cost() const = 0;
        virtual const char* name() const = 0;
        virtual void quantity(int) = 0;
        virtual int qtyNeeded() const = 0;
        virtual int quantity() const = 0;
        virtual int operator+=(int) = 0;
        virtual bool operator>(const iGood&) const = 0;
        virtual ~iGood() {};
        
    };
    
    std::ostream& operator<<(std::ostream&, const iGood&);
    std::istream& operator>>(std::istream&, iGood&);
    double operator+=(double&, const iGood&);
    iGood* CreateGood();
    iGood* CreatePerishable();
    
    
    
    
}






#endif
