//
// Name: Huy Lam
// Section: GG
// Date: 28/11/2018
//

#include "Error.h"
#include <iostream>
#include <cstring>

namespace aid {
    
    Error::Error(const char* errorMessage) {
        if (errorMessage == nullptr || errorMessage[0] == '\0') {
            ptrMsg = nullptr;
        }
        else {
            ptrMsg = new char[strlen(errorMessage) + 1];
            strncpy(ptrMsg, errorMessage, (strlen(errorMessage) + 1));
        }
    }
    
    void Error::clear() {
        if (this->ptrMsg != nullptr) {
            this->ptrMsg = nullptr;
        }
    }
    
    bool Error::isClear() const {
        bool result = false;
        
        if (this->ptrMsg == nullptr || this->ptrMsg[0] == '\0') {
            result = true;
        }
        return result;
    }
    
    void Error::message(const char* str) {
        
        if (str != nullptr || str[0] != '\0') {
            delete [] ptrMsg;
            ptrMsg = new char[strlen(str) + 1];
            strncpy(ptrMsg, str, (strlen(str) + 1));
        }
        else {
            this->clear();
        }
    }
    
    const char* Error::message() const {
        if (!this->isClear()) {
            return this->ptrMsg;
        }
        else {
            return nullptr;
        }
    }
    
    std::ostream& operator<<(std::ostream& os, Error& er) {
        if (!er.isClear()) {
            os << er.message();
        }
        return os;
    }

    Error::~Error() {
        if (ptrMsg != nullptr) {
            delete [] ptrMsg;
            ptrMsg = nullptr;
        }
    }
    
    
    
    
}
