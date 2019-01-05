//
// Name: Huy Lam
// Section: GG
// Date: 28/11/2018
//

#ifndef DATE_H
#define DATE_H
#include <iostream>

namespace aid {
    
    class Error {
        
        char* ptrMsg;
        
    public:
        
        // Constructor & Destructor
        explicit Error(const char* errorMessage = nullptr);
        Error(const Error& em) = delete;
        Error& operator=(const Error& em) = delete;
        virtual ~Error();
        
        
        void clear();
        bool isClear() const;
        void message(const char* str);
        const char* message() const;
        
        
    };
    
    // Helper Function
    std::ostream& operator<<(std::ostream& os, Error&);
}


#endif
