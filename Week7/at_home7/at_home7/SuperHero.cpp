//
//  SuperHero.cpp
//  at_home7
//
//  Created by Huy Lam on 2018-11-11.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 13/11/2018

#include "SuperHero.h"
#include <iostream>
#include <cstring>


namespace sict {
    
    SuperHero::SuperHero() : Hero(){
        
        superBonus = 0;
        superDefense = 0;
    }
    
    SuperHero::SuperHero(const char* n, int hp, int atk, int atkBonus, int def) : Hero(n, hp, atk) {
        
        superBonus = atkBonus;
        superDefense = def;
        

    }
    
    
    int SuperHero::attackStrength() const {
        
        int result;
        
        if (Hero::isEmpty()) {
            result = 0;
        }
        else {
            result = Hero::attackStrength() + superBonus;
        }
        
        return result;

    }
    
    int SuperHero::defend() const {
        
        int result;
        
        if (Hero::isEmpty()) {
            result = 0;
        }
        else {
            result = this->superDefense;
        }
        
        return result;
    }


    const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
        
        SuperHero super1, super2;
        int counter;
        
        super1 = first;
        super2 = second;
        counter = 0;
        
        for (int i = 0; i < MAX_ROUNDS && super1.isAlive() && super2.isAlive(); i++) {
            super1 -= super2.attackStrength() - super1.defend();
            super2 -= super1.attackStrength() - super2.defend();
            counter = i + 1;
        }
        if (!super1.isAlive()) {
            std::cout << "Super Fight! " << super1.getHeroName() << " vs " << super2.getHeroName() << " : Winner is " << super2.getHeroName() << " in " << counter << " rounds." << std::endl;
            
            return second;
        }
        else if (!super2.isAlive()) {
            std::cout << "Super Fight! " << super1.getHeroName() << " vs " << super2.getHeroName() << " : Winner is " << super1.getHeroName() << " in " << counter << " rounds." << std::endl;
            
            return first;
        }
        else if (!super1.isAlive() && !super2.isAlive()) {
            std::cout << "Super Fight! " << super1.getHeroName() << " vs " << super2.getHeroName() << " : Winner is " << super1.getHeroName() << " in " << counter << " rounds." << std::endl;
            
            return first;
        }
        else {
            return first;
        }
    }
    
}
