//
//  Hero.hpp
//  at_home7
//
//  Created by Huy Lam on 2018-11-11.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 13/11/2018

#ifndef SICT_HERO_H
#define SICT_HERO_H

#include <iostream>

namespace sict {
    
#define MAX_ROUNDS 100
    
    class Hero {
        
        char name[41];
        int health;
        int attack;
        
    public:
        Hero();
        Hero(const char*, int, int);
        
        void operator-=(int);
        bool isAlive() const;
        int attackStrength() const;
        friend std::ostream& operator<<(std::ostream&, const Hero&);
        
        // Additional Function(s)
        const char* getHeroName(); // Assist helper function getting member variable name
        bool isEmpty() const;
        
    };
    
    const Hero& operator*(const Hero&, const Hero&);
}

#endif

