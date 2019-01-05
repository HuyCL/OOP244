//
//  Kingdom.hpp
//  at_home2
//
//  Created by Huy Lam on 2018-09-20.
//  Copyright © 2018 Huy Lam. All rights reserved.
//

#ifndef Kingdom_hpp
#define Kingdom_hpp

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H
namespace sict {
    
    struct Kingdom {
        char m_name[33];
        int m_population;
    };
    
    void display(const Kingdom&);
    void display(const Kingdom[], int);
}
#endif

#endif /* Kingdom_hpp */
