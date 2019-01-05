//
// Name: Huy Lam
// Section: GG
// Date: 28/11/2018
//

#include "Perishable.h"
#include <iostream>

namespace aid {
    
    Perishable::Perishable() : Good('P'){   // Let 'Good' constructor know that 'Perishable' constructor has been called and change the type from 'N' to 'P'
        perishExpDate = Date();
    }
    
    std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
        
        Good::store(file, false);   // Call for store function in 'Good' class to append product information
        
        file << "," << perishExpDate.getYear() << "/" << perishExpDate.getMonth() << "/" << perishExpDate.getDay(); // Append YYYY/MM/DD to the file
        
        if (newLine) {
            file << std::endl;      // Append new line if true
        }
        
        return file;
    }
    
    std::fstream& Perishable::load(std::fstream& file) {
        
        Good::load(file); // Call for 'Good' load function to extract product information
        perishExpDate.read(file);   //
        file.get();
        
        return file;
    }
    
    std::ostream& Perishable::write(std::ostream& os, bool linear) const {
        
        Good::write(os, linear);
        
        if (isClear() && !isEmpty()) {
            
            if (linear) {
                perishExpDate.write(os);
            }
            else {
                os << std::endl <<" Expiry date: ";
                perishExpDate.write(os);
            }
        }
        
        return os;
    }
    
    std::istream& Perishable::read(std::istream& is) {
        Date temp;      // Temporary Date object to hold user input
        is.clear();     // Clear the input buffer before accept user input
        Good::read(is); // Call for 'Good' read function and prompt for input
        
        if (is.good()) { // Checks the state of input stream and prompt for date if true
            std::cout << " Expiry date (YYYY/MM/DD): ";
            temp.read(is);
        }
        
        if (temp.errCode() == CIN_FAILED) {
            errorState.message("Invalid Expiry in Date Entry");
            is.setstate(std::ios_base::failbit);

        }
        
        else if (temp.errCode() == YEAR_ERROR) {
            errorState.message("Invalid Year in Date Entry");
            is.setstate(std::ios_base::failbit);

        }
        
        else if (temp.errCode() == MON_ERROR) {
            errorState.message("Invalid Month in Date Entry");
            is.setstate(std::ios_base::failbit);
        }
        
        else if (temp.errCode() == DAY_ERROR) {
            errorState.message("Invalid Day in Date Entry");
            is.setstate(std::ios_base::failbit);
        }
        
        else if (temp.errCode() == PAST_ERROR) {
            errorState.message("Invalid Expiry in Date Entry");
            is.setstate(std::ios_base::failbit);
        }

        else if (temp.errCode() == NO_ERROR) {
            perishExpDate = temp;   // Copy temporary Date object to instance Date object
        }
        
        return is;
    }
    
    const Date& Perishable::expiry() const {
        return perishExpDate;
    }
}
