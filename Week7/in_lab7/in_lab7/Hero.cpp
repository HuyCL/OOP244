//
//  Hero.cpp
//  in_lab7
//
//  Created by Huy Lam on 2018-11-07.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Email: hlam25@myseneca.ca
// Date: 08/11/2018

#include "Hero.h"
#include <iostream>

namespace sict {
    
    // Default Constructor
    Hero::Hero() {
        
        name[0] = '\0';
        health = 0;
        attack = 0;
        
    }
    
    // Constructor for incoming data validation
    Hero::Hero(const char* n, const int hp, const int atk) {
        
        if (n != nullptr && hp > 0 && atk > 0) {
            strncpy(name, n, 40);
            health = hp;
            attack = atk;
        }
        else {
            Hero();
        }
    }
    
    // Check if the object is empty
    bool Hero::isEmpty() const {
        
        bool result;
        
        if (name[0] == '\0' && health == 0 && attack == 0) {
            result = true;
        }
        else {
            result = false;
        }
        
        return result;
    }
    
    const char* Hero::getHeroName() {
        return name;
    }
    
    void Hero::operator-=(int atk) {
        if (atk > 0) {
            
            this->health -= atk;
            
            if (this->health < 0) {
                this->health = 0;
            }
            
        }
    }
    
    bool Hero::isAlive() const {
        
        return (this->health > 0) ? true : false;
        
    }
    
    int Hero::attackStrength() const {
        
        int result;
        
        if (isEmpty()) {
            result = 0;
        }
        else {
            result = this->attack;
        }
        
        return result;
        
    }
    
    std::ostream& operator<<(std::ostream& os, const Hero& hero) {
        
        if (hero.isEmpty()) {
            os << "No hero" << std::endl;
        }
        else {
            os << hero.name;
        }
        
        return os;
        
    }
    
    const Hero& operator*(const Hero& first, const Hero& second) {
        
        Hero hero1, hero2; // Local objects
        int counter;
        
        hero1 = first;     // Copy incoming objects to local
        hero2 = second;
        counter = 0;  // Keep track of rounds
        
        for (int i = 0; i < MAX_ROUNDS && hero1.isAlive() && hero2.isAlive(); i++) {
            hero1 -= hero2.attackStrength();        // Iteration continues until one dies or max round reached
            hero2 -= hero1.attackStrength();
            counter = i + 1;
        }
        if (!hero1.isAlive()) {
            std::cout << "Ancient Battle! " << hero1.getHeroName() << " vs " << hero2.getHeroName() << " : Winner is " << hero2.getHeroName() << " in " << counter << " rounds." << std::endl;
        
            return second;
        }
        else if (!hero2.isAlive()) {
            std::cout << "Ancient Battle! " << hero1.getHeroName() << " vs " << hero2.getHeroName() << " : Winner is " << hero1.getHeroName() << " in " << counter << " rounds." << std::endl;
                
            return first;
        }
        else if (!hero1.isAlive() && !hero2.isAlive()) {
            std::cout << "Ancient Battle! " << hero1.getHeroName() << " vs " << hero2.getHeroName() << " : Winner is " << hero1.getHeroName() << " in " << counter << " rounds." << std::endl;
                
            return first;
        }
        else {
            return first;
        }
        
    }

    
    
}
