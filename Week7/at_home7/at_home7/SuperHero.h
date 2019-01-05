//
//  SuperHero.hpp
//  at_home7
//
//  Created by Huy Lam on 2018-11-11.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 13/11/2018

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include <iostream>
#include "Hero.h"

namespace sict {
    
    class SuperHero : public Hero {

        int superBonus;
        int superDefense;
        
    public:
        SuperHero();
        SuperHero(const char*, int, int, int, int);
        int attackStrength() const;
        int defend() const;
        
    };
    
    const SuperHero& operator*(const SuperHero&, const SuperHero&);
    
}

#endif
