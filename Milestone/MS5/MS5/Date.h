//
// Name: Huy Lam
// Section: GG
// Date: 28/11/2018
//


#ifndef AMA_DATE_H
#define AMA_DATE_H

#include <iostream>

namespace aid {
    
    #define NO_ERROR 0
    #define CIN_FAILED 1
    #define DAY_ERROR 2
    #define MON_ERROR 3
    #define YEAR_ERROR 4
    #define PAST_ERROR 5
    
    const int min_year = 2018;
    const int max_year = 2038;
    const int min_date = 751098;
    
    class Date {
        
        int year;     // Must be between min_year and max_year
        int month;    // Must be between 1 and 12
        int day;      // Must be between 1 and the number of days in the month
        int state;    // Status of an error
        int compare;  
        
        
        int mdays(int, int)const;
        void errCode(int);
        
    public:
        
        // Constructors
        Date();
        Date(int, int, int);
        
        // Relational Operators
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        
        // Queries & Modifier
        int errCode() const;
        bool bad()const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        
    };
    
    // Helper
    std::ostream& operator<<(std::ostream& ostr, Date&);
    std::istream& operator>>(std::istream& istr, Date&);
    
}
#endif
