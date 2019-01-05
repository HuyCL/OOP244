//
//  Passenger.cpp
//  in_lab4
//
//  Created by Huy Lam on 2018-10-04.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Seneca ID: 114705162
// Section: GG
// Date: 04/10/2018


// TODO: add file header comments here

// TODO: add your headers here

#include "Passenger.h"
#include <iostream>
#include <cstring>
using namespace std;

// TODO: continue your namespace here

namespace sict {

// TODO: implement the default constructor here
    
    Passenger::Passenger() {
        
        psgName[0] = '\0';
        psgDest[0] = '\0';
        
    }

// TODO: implement the constructor with 2 parameters here
    
    Passenger::Passenger(const char* pName, const char* dName) {
        
        if (pName != nullptr && dName != nullptr) {
            
            strncpy(psgName, pName, sizeof(psgName) - 1);
            strncpy(psgDest, dName, sizeof(psgDest) - 1);
            
        }
        
        else {
            
            psgName[0] = '\0';
            psgDest[0] = '\0';
            
        }
        
        
    }

// TODO: implement isEmpty query here
    
    bool Passenger::isEmpty() const {
        
        bool result = true;
        
        if (psgName[0] != '\0' && psgDest[0] != '\0') {
            result = false;
        }
        
        return result;

    }

// TODO: implement display query here

    void Passenger::display() const {
        
        if (isEmpty()) {
            
            cout << "No passenger!" << endl;
        
        }
        
        else {
            
            cout << psgName << " - " << psgDest << endl;
            
        }
        
    }

}
