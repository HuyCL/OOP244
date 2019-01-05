//
//  Passenger.cpp
//  at_home4
//
//  Created by Huy Lam on 2018-10-04.
//  Copyright © 2018 Huy Lam. All rights reserved.
// 
// Name: Huy Lam
// Seneca ID: 114705162
// Section: GG
// Date: 07/10/2018


#include "Passenger.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;


namespace sict {
    
    
    Passenger::Passenger() {
        
        psgName[0] = '\0';
        psgDest[0] = '\0';
        yearDpt = 0;
        monthDpt = 0;
        dayDpt = 0;
        
    }
    
    
    Passenger::Passenger(const char* pName, const char* dName) {
        
        if (pName != nullptr && dName != nullptr) {
            
            strncpy(psgName, pName, sizeof(psgName) - 1);
            strncpy(psgDest, dName, sizeof(psgDest) - 1);
            yearDpt = 2018;
            monthDpt = 10;
            dayDpt = 1;
        }
        
        
    }
    
    Passenger::Passenger(const char* pName, const char* dName, int year, int month, int day) {
        
        if (pName != nullptr && dName != nullptr && year >= 2018 && year <= 2020 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            
            strncpy(psgName, pName, sizeof(psgName) - 1);
            strncpy(psgDest, dName, sizeof(psgDest) - 1);
            yearDpt = year;
            monthDpt = month;
            dayDpt = day;
            
        }
        
        else {
            
            *this = Passenger();
            
        }
    }
    
    const char* Passenger::name() const {
        
        return psgName;
        
    }
    
    bool Passenger::canTravelWith(const Passenger& psg) const {
        bool result;
        
        if ((*this).yearDpt == psg.yearDpt && (*this).monthDpt == psg.monthDpt && (*this).dayDpt == psg.dayDpt && strcmp((*this).psgDest, psgDest) == 0) {
            
            result = true;
            
        }
        
        else {
            result = false;
        }
        
        return result;
    }
    
    bool Passenger::isEmpty() const {
        
        bool result = true;
        
        if (psgName[0] != '\0' && psgDest[0] != '\0') {
            result = false;
        }
        
        return result;
        
    }
    
    
    void Passenger::display() const {
        
        if (isEmpty()) {
            
            cout << "No passenger!" << endl;
            
        }
        
        else {
            
            cout << psgName << " - " << psgDest << " on " << yearDpt << "/" << setfill('0') << setw(2) <<  monthDpt << "/" << setfill('0') << setw(2) << dayDpt << endl;
            
        }
        
    }
    
}
