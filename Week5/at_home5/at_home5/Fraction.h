//
//  Fraction.hpp
//  at_home5
//
//  Created by Huy Lam on 2018-10-09.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Seneca ID: 114705162
// Seneca Email: hlam25@myseneca.ca
// Section: GG
// Date: 11/10/2018

#ifndef Fraction_hpp
#define Fraction_hpp

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
    
    class Fraction {

        int num;
        int denom;

        int max() const;
        int min() const;
        void reduce();
        int gcd() const;
    public:
 
        Fraction();
        Fraction(int, int);
        bool isEmpty() const;
        void display() const;
        
        // Overload operators
        Fraction operator+(const Fraction&) const;
        Fraction operator*(const Fraction&) const;
        bool operator==(const Fraction&) const;
        bool operator!=(const Fraction&) const;
        Fraction& operator+=(const Fraction&);
    };
}

#endif
#endif /* Fraction_hpp */
