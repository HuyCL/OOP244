//
//  Passenger.hpp
//  in_lab4
//
//  Created by Huy Lam on 2018-10-04.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Seneca ID: 114705162
// Section: GG
// Date: 04/10/2018
//
#ifndef Passenger_hpp
#define Passenger_hpp

// TODO: add file header comments here

// TODO: add header file guard here

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: declare your namespace here

namespace sict {
    
// TODO: define the Passenger class here
    
    class Passenger {
        char psgName[19];
        char psgDest[19];
    public:
        Passenger();
        Passenger(const char*, const char*);
        bool isEmpty() const;
        void display() const;
    };

}
#endif
#endif /* Passenger_hpp */
