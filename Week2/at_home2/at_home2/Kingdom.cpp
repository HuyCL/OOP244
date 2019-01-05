//
//  Kingdom.cpp
//  at_home2
//
//  Created by Huy Lam on 2018-09-20.
//  Copyright © 2018 Huy Lam. All rights reserved.
//

#include "Kingdom.h"
#include <iostream>
using namespace std;
namespace sict {
    void display (const Kingdom& k) {
        cout << k.m_name << ", population " << k.m_population << endl;
        
    }
    void display (const Kingdom k[], int count) {
        int total = 0;
        cout << "------------------------------" << endl;
        cout << "Kingdoms of SICT" << endl;
        cout << "------------------------------" << endl;
        for (int i = 0; i < count; i++) {
            cout << k[i].m_name << ", population " << k[i].m_population << endl;
            total += k[i].m_population;
        }
        cout << "------------------------------" << endl;
        cout << "Total population of SICT: " << total << endl;
        cout << "------------------------------" << endl;
    }
}

