//
//  Fraction.cpp
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

#include "Fraction.h"
#include <iostream>
using namespace std;

namespace sict {
    
    Fraction::Fraction() {
        num = 0;
        denom = 0;
    }
    
    Fraction::Fraction(int n, int d) {
        
        if (n >= 0 && d >= 0) {             // (n >= 0 && d > 0) was original condition because instruction stated
            num = n;                        // that denominator must be positive-valued but the output was off
            denom = d;
            reduce();
        }
        else {
            *this = Fraction();
        }
    }
    
    int Fraction::max() const {         // Compare numerator and denominator and return the higher value
        
        if (num > denom) {
            return num;
        }
        else {
            return denom;
        }
    }
    
    int Fraction::min() const {          // Compare numerator and denominator and return the lower value
        
        if (num < denom) {
            return num;
        }
        else {
            return denom;
        }
    }
    
    
    int Fraction::gcd() const {         // Finds the greatest common divisor (GCD) for reduce() function
        int mn = min();
        int mx = max();
        int g_c_d = 1;
        bool found = false;
        
        for (int x = mn; !found && x > 0; --x) {
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }
    
    
    void Fraction::reduce() {           // This function reduces the fraction to the lowest
        
        int common = gcd();
        num = num / common;
        denom = denom / common;
    }
    
    
    void Fraction::display() const {
        
        if (!isEmpty() && denom > 1) {
            cout << num << "/" << denom;
        }
        else if (!isEmpty() && denom == 1) {
            cout << num;
        }
        else {
            cout << "no fraction stored";
        }
    }
    
    
    bool Fraction::isEmpty() const {
        bool result;
        if (num == 0 && denom == 0) {
            result = true;
        }
        
        else {
            result = false;
        }
        
        return result;
    }
    
    Fraction Fraction::operator+(const Fraction& rhs) const {
        
        Fraction resultObj;     // New object is created to store the results
        
        if (!(*this).isEmpty() && !rhs.isEmpty()) {
            resultObj.num = (this->num * rhs.denom) + (this->denom * rhs.num);
            resultObj.denom = this->denom * rhs.denom;
            resultObj.reduce();
        }
        
        else {
            resultObj = Fraction();
        }
        
        return resultObj;
    }
    
    Fraction Fraction::operator*(const Fraction& rhs) const {
        
        Fraction resultObj;     // New object is created within the function to store the results
        
        if (!(*this).isEmpty() && !rhs.isEmpty()) {
            resultObj.num = this->num * rhs.num;
            resultObj.denom = this->denom * rhs.denom;
            resultObj.reduce();
        }
        
        else {
            resultObj = Fraction();
        }
        return resultObj;
    }
    
    bool Fraction::operator==(const Fraction& rhs) const {          // bool because we want the function to return
                                                                    // either true or false
        bool result;
        
        if (!(*this).isEmpty() && !rhs.isEmpty()) {
            
            if (this->num == rhs.num && this->denom == rhs.denom) {
                result = true;
            }
            else {
                result = false;
            }
        }
        
        else {
            result = false;
        }
        return result;
    }
    
    bool Fraction::operator!=(const Fraction& rhs) const {          // bool because we want the function to return
                                                                    // either true or false
        bool result;
        
        if (!(*this).isEmpty() && !rhs.isEmpty()) {
            
            if (!(*this == rhs)) {      // This "if" statement calls for operator==
                result = true;
            }
            else {
                result = false;
            }
        }
        
        else {
            result = false;
        }
        return result;
    }
    
    Fraction& Fraction::operator+=(const Fraction& rhs) {       // There is no "const" at the end because we're
                                                                // making changes to the current object
        if (!(*this).isEmpty() && !rhs.isEmpty()) {
            *this = *this + rhs;    // This line calls for operator+ that was written previously
            this->reduce();
        }
        
        else {
            *this = Fraction();
        }
        
        return *this;
    }
    
}
