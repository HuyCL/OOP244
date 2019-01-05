//
//  Contact.cpp
//  at_home6
//
//  Created by Huy Lam on 2018-11-04.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Email: hlam25@myseneca.ca
// Date: 04/11/2018

#include "Contact.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

namespace sict {
    
    // Default Constructor
    Contact::Contact() {
        
        name[0] = '\0';
        ptrPhone = nullptr;
        pNum = 0;
    }
    
    // Constructor With Three Paramaters
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
    
    // Validate Phone Number
    bool Contact::validation(const long long phone) {
        bool result = true;
        string strPhone = to_string(phone);     // Convert integer to a string
        
        if (phone <= 0 || strPhone.length() < 11 || strPhone.length() > 12 || strPhone[strPhone.length() - 7] == '0') {
            result = false;
        }
        
        return result;
    }
    
    // Check State of Object
    bool Contact::isEmpty() const {
        
        bool result = false;
        
        if (name[0] == '\0' && ptrPhone == nullptr && pNum <= 0) {
            result = true;
        }
        
        return result;
    }
    
    // Print Out Stored Data
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
    
    // Destructor For Deallocation
    Contact::~Contact() {
        
        if (ptrPhone != nullptr) {
            delete [] ptrPhone;
            ptrPhone = nullptr;
        }
    }
    
    // Copy Constructor
    Contact::Contact(const Contact& src) {
        
        // This constructor calls for assignment operator
        ptrPhone = nullptr;
        *this = src;
        
    }
    
    // Copy Assignment Operator
    Contact& Contact::operator=(const Contact& src) {
        
        if (this != &src) {
            
            // Shallow copy non-resource instance variables
            strncpy(name, src.name, sizeof(name));
            pNum = src.pNum;
            
            // Deep copy source resource to another resource
            if (src.ptrPhone != nullptr) {
                
                ptrPhone = new long long[pNum]; // Allocate dynamic memory
                
                for (int i = 0; i < pNum; i++) {    // Loop and copy data from original source to new source
                    ptrPhone[i] = src.ptrPhone[i];
                }
                
            }
            else {
                ptrPhone = nullptr;
            }
        }
        
        return *this;
    }
    
    // Overloaded Operator
    Contact& Contact::operator+=(const long long newPhone) {
        
        if (validation(newPhone) && !isEmpty()) {
            
            int count; // Used to track when 'for' loop stops
            int resize = pNum + 1; // New array size
            long long* storage = new long long[resize]; // New temporary allocated memory
            
            for (count = 0; count < pNum; count++) {    // Copy existing data to new temporary memory
                storage[count] = ptrPhone[count];
            }
            storage[count] = newPhone;  // Append 
            pNum = resize;
            
            delete [] ptrPhone;
            
            ptrPhone = new long long[resize];
            ptrPhone = storage;
            
        }
        
        return *this;
    }
}
