//
//  Kingdom.hpp
//  in_lab2
//
//  Created by Huy Lam on 2018-09-18.
//  Copyright © 2018 Huy Lam. All rights reserved.
//

#ifndef Kingdom_hpp
#define Kingdom_hpp

/***********************************************************
 // OOP244 Workshop 2: Dynamic Memory
 // File Kingdom.h
 // Version 1.0
 // Date ???????????
 // Author ?????????
 // Description
 // ?????????????????????
 //
 //
 // Revision History
 ///////////////////////////////////////////////////////////
 // Name     Date    Reason
 //
 ///////////////////////////////////////////////////////////
 ***********************************************************/

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H
namespace sict {

    struct Kingdom {
        char m_name[33];
        int m_population;
    };

    void display(const Kingdom&);
}
#endif
#endif /* Kingdom_hpp */
