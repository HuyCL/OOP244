//
//  CRA_Account.cpp
//  in_lab3
//
//  Created by Huy Lam on 2018-09-27.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Seneca ID: 114705162
// Section: GG
// Seneca Email: hlam25@myseneca.ca
// Date: 29/09/2018


#include "CRA_Account.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
namespace sict {

    bool CRA_Account::validation(int sin) {
        int result = 0;
        if (sin > min_sin && sin < max_sin) {
            int checkNo;
            int sin_ar[8];
            
            checkNo = sin % 10;

            for (int i = 8; i >= 0; i--) {
                sin_ar[i] = sin % 10;
                sin /= 10;
            }
            
            int sumTotal = 0;
            
           
            for (int i = 0; i < 4; i++){
                if (sin_ar[i] > 10) {
                    sumTotal += 1 + (sin_ar[i] % 10);      //makes it 1 + whatever the second number is
                    cout << sumTotal << endl;
                }
                else if (sin_ar[i] == 10) {
                    sumTotal += 1;
                    cout << sumTotal << endl;
                }
                else {
                    sumTotal += sin_ar[i];
                    cout << sumTotal << endl;
                }
            }
            
            for (int i = 0; i < 7; i+=2) {
                sumTotal += sin_ar[i];
            }
            
            int remainder = 10 - (sumTotal % 10);
            
            if (remainder == checkNo) {
                result = 1;
            }
            
        }
        
        return result;
    }
    void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
        if (validation(sin)) {
                si_no = sin;
                strncpy(f_Name, familyName, sizeof(f_Name));
                strncpy(g_Name, givenName, sizeof(g_Name));
                numYears = 0;
        }
    }
    bool CRA_Account::isEmpty() const {
        int result = 0;
        if (f_Name[0] == '\0' || g_Name[0] == '\0' || si_no == 0) {
            result = 1;
        }
        return result;
    }

void CRA_Account::display() const {
        if (isEmpty()) {
            cout << "Account object is empty!" << endl;
        } else {
            cout << "Family Name: " << f_Name << endl;
            cout << "Given Name : " << g_Name << endl;
            cout << "CRA Account: " << si_no << endl;
            for (int i = 0; i < max_yrs; i++) {
                if (balOwe[i] > 2) {
                    cout << fixed << setprecision(2) << "Year (" << returnYear[i] << ") balance owing: " << balOwe[i] << endl;
                } else if (balOwe[i] < -2) {
                    cout << "Year (" << returnYear[i] << ") refund due: " << (balOwe[i] * (-1)) << endl;
                } else {
                    cout << "Year (" << returnYear[i] << ") No balance owing or refund due!" << endl;
                }
            }
        }
    }

void CRA_Account::set(int year, double balance) {
        if (!isEmpty() && numYears < max_yrs) {
            returnYear[numYears] = year;
            balOwe[numYears] = balance;
            numYears++;
        }
    }
}
