// Name: Huy Lam
// Seneca ID: 114705162
// Seneca Email: hlam25@myseneca.ca
// Section: GG
// Date: 11/10/18

#include "Fraction.h"
#include <iostream>
using namespace std;

namespace sict {
    
    Fraction::Fraction() {
        num = 0;
        denom = 0;
    }
    
    Fraction::Fraction(int n, int d) {
        
        if (n >= 0 && d >= 0) {
            num = n;
            denom = d;
            reduce();
        }
        else {
            *this = Fraction();
        }
    }
    
    int Fraction::max() const {
        
        if (num > denom) {
            return num;
        }
        else {
            return denom;
        }
    }
    
    int Fraction::min() const {
        
        if (num < denom) {
            return num;
        }
        else {
            return denom;
        }
    }
    

int Fraction::gcd() const {
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


    void Fraction::reduce() {
        
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

    Fraction Fraction::operator+(const Fraction &rhs) const {
        Fraction result;
        if (!(*this).isEmpty() && !rhs.isEmpty()) {
            result.num = ((*this).num * rhs.denom) + ((*this).denom * rhs.num);
            result.denom = (*this).denom * rhs.denom;
            result.reduce();
        }
        else {
            result = Fraction();
        }
        
        return result;
    }
    
}
