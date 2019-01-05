//
//  Contact.cpp
//  in_lab6
//
//  Created by Huy Lam on 2018-11-01.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Email: hlam25@myseneca.ca
// Date: 01/11/2018

#include "Contact.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

namespace sict {
    
    Contact::Contact() {
        
        name[0] = '\0';
        ptrPhone = nullptr;
        pNum = 0;
    }
    
    Contact::Contact(const char* n, const long long* phone, const int num) {
        
        if (n != nullptr && n[0] != '\0') {
            strncpy(name, n, sizeof(name));
        }
        else {
            name[0] = '\0';
        }
        
        if (phone != nullptr && num > 0) {
            ptrPhone = new long long[num];
            pNum = 0;
            
            for (int i = 0; i < num; i++) {
                
                if (validation(phone[i])) {
                    ptrPhone[pNum] = phone[i];   // Stores value of each address of "phone" to another pointer
                    pNum++;
                }
            }
        }
        else {
            ptrPhone = nullptr;
            pNum = 0;
        }
    }
    
    bool Contact::validation(const long long phone) {
        bool result = true;
        string strPhone = to_string(phone);     // Convert integer to a string
        
        if (phone <= 0 || strPhone.length() < 11 || strPhone.length() > 12 || strPhone[strPhone.length() - 7] == '0') {
            result = false;
        }
        
        return result;
    }
    
    bool Contact::isEmpty() const {
        
        bool result = false;
        
        if (name[0] == '\0' && ptrPhone == nullptr && pNum <= 0) {
            result = true;
        }
        
        return result;
    }
    
    void Contact::display() const {
        
        if (isEmpty()) {
            
            cout << "Empty contact!" << endl;
            
        }
        else {
            
            cout << name << endl;
            
            string pNumber;     //
            string country;     //
            string area;        // Variables are used to separate a whole number
            string num1;        //
            string num2;        //
            
            for (int i = 0; i < pNum; i++) {
                
                pNumber = to_string(ptrPhone[i]);
                
                if (pNumber.length() == 11) {
                    country = pNumber.substr(0, 1);
                    area = pNumber.substr(1, 3);
                    num1 = pNumber.substr(4, 3);
                    num2 = pNumber.substr(7,4);
                }
                
                if (pNumber.length() == 12) {
                    country = pNumber.substr(0, 2);
                    area = pNumber.substr(2, 3);
                    num1 = pNumber.substr(5, 3);
                    num2 = pNumber.substr(8, 4);
                }
                
                cout << "(+" << country << ") " << area << " " << num1 << "-" << num2 << endl;
            }
            
        }
        
    }
    
    Contact::~Contact() {
        
        if (ptrPhone != nullptr) {
            delete [] ptrPhone;
            ptrPhone = nullptr;
        }
    }
    
    
}
