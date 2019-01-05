//
//  Passenger.hpp
//  at_home4
//
//  Created by Huy Lam on 2018-10-04.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Seneca ID: 114705162
// Section: GG
// Date: 07/10/2018

#ifndef Passenger_hpp
#define Passenger_hpp


#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H


namespace sict {
    
    
    class Passenger {
        char psgName[19];
        char psgDest[19];
        int yearDpt;
        int monthDpt;
        int dayDpt;
        
    public:
        Passenger();
        Passenger(const char*, const char*);
        Passenger(const char*, const char*, int, int, int);
        const char* name() const;
        bool canTravelWith(const Passenger&) const;
        bool isEmpty() const;
        void display() const;
        
    };
    
}
#endif

#endif /* Passenger_hpp */
