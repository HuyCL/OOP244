//
// Name: Huy Lam
// Section: GG
// Date: 28/11/2018
//

#include "Date.h"

namespace aid {
    
    //--------------------------------- Private Member Functions ---------------------------------//
    
    int Date::mdays(int mon, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    
    
    void Date::errCode(int error) {
        state = error;
    }
    
    //--------------------------------- Public Member Functions ---------------------------------//
    
    // Constructor with no parameter
    Date::Date() {
        year = 0;
        month = 0;
        day = 0;
        compare = 0;
        state = NO_ERROR;
    }
    
    
    // Constructor with three parameters
    Date::Date(int yr, int mth, int d) {
        
        bool validYr;
        bool validMonDay;
        int mon_days = mdays(mth, yr);
        
        // Verify year
        if (yr >= min_year && year <= max_year) {
            validYr = true;
        }
        else {
            validYr = false;
        }
        
        // Verify number of days for the month
        if (mon_days != -1 && d <= mon_days) {
            validMonDay = true;
        }
        else {
            validMonDay = false;
        }
        
        // Copy all values when both verification is true
        if (validYr && validMonDay) {
            year = yr;
            month = mth;
            day = d;
            state = NO_ERROR;
            compare = yr * 372 + mth * 13 + d;
        }
        else {
            *this = Date();
            state = NO_ERROR;
        }
    }
    
    
    //-->Queries & Modifier<--//
    
    int Date::errCode() const
    {
        return state;
    }
    
    
    bool Date::bad() const {
        bool result;
        if (state != NO_ERROR) {
            result = true;
        }
        else {
            result = false;
        }
        
        return result;
    }
    
    
    std::istream& Date::read(std::istream& is) {
        char s;
        is >> year >> s >> month >> s >> day;
        errCode(NO_ERROR);
        if (is.fail()) {
            *this = Date();
            errCode(CIN_FAILED);
        }
        else if (year < min_year || year > max_year) {
            *this = Date();
            errCode(YEAR_ERROR);
        }
        else if (month < 1 || month > 12) {
            *this = Date();
            errCode(MON_ERROR);
        }
        else if (day > mdays(month, year)) {
            *this = Date();
            errCode(DAY_ERROR);
        }
        else if ((year * 372 + month * 31 + day) < min_date) {
            *this = Date();
            errCode(PAST_ERROR);
        }
        
        is.clear();
        return is;
    }
    
    
    std::ostream& Date::write(std::ostream& os) const {
        
        os << year << "/";
        
        if (month < 10) {
            os << 0;
        }
        
        os << month << "/";
        
        if (day < 10) {
            os << 0;
        }
        
        os << day;
        
        return os;
    }
    
    //-->Helper Functions<--//
    
    std::istream& operator>>(std::istream& is, Date& obj) {
        return obj.read(is);
    }
    
    
    std::ostream& operator<<(std::ostream& os, Date& obj) {
        return obj.write(os);
    }
    
    //-->Relational Operators<--//
    bool Date::operator==(const Date& rhs) const {
        bool result;
        
        if (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day) {
            result = true;
        }
        else {
            result = false;
        }
        
        return result;
    }
    
  
    bool Date::operator!=(const Date& rhs) const {
        bool result;
        
        if (!(*this == rhs)) {
            result = true;
        }
        else {
            result = false;
        }
        
        return result;
    }
    

    bool Date::operator<(const Date& rhs) const {
        
        bool result;
        
        if (this->year < rhs.year) {
            result = true;
        }
        else if (this->year == rhs.year && this->month < rhs.month) {
            result = true;
        }
        else if (this->year == rhs.year && this->month == rhs.month && this->day < rhs.day) {
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }
    
   
    bool Date::operator>(const Date& rhs) const {
        
        bool result;
        
        if (!(*this < rhs)) {
            result = true;
        }
        else {
            result = false;
        }
        
        return result;
    }
    
 
    bool Date::operator<=(const Date& rhs) const {
        bool result;
        
        if (*this < rhs || *this == rhs) {
            result = true;
        }
        else {
            result = false;
        }
        
        return result;
    }
    

    bool Date::operator>=(const Date& rhs) const {
        bool result;
        
        if (*this > rhs || *this == rhs) {
            result = true;
        }
        else {
            result = false;
        }
        
        return result;
    }
    
    int Date::getDay() const {
        return day;
    }
    
    int Date::getMonth() const {
        return month;
    }
    
    int Date::getYear() const {
        return year;
    }
}
