//
// Name: Huy Lam
// Section: GG
// Date: 28/11/2018
//


#include "Good.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <memory>
using namespace std;

namespace aid {
    
    //------------------------------ Protected Member Functions ------------------------------//
    
    void Good::name(const char* n) {
        
        if (n != nullptr) {
            goodName = new char[strlen(n)];
            
            strncpy(goodName, n, sizeof(goodName) - 1);
        }
        else {
            goodName = nullptr;
        }
        
    }
    
    const char* Good::name() const {
       return ((goodName[0] != '\0') ? goodName : nullptr);
    }
    
    const char* Good::sku() const {
        return unitSku;
    }
    
    const char* Good::unit() const {
        return unitDesc;
    }
    
    bool Good::taxed() const {
        return taxStatus;
    }
    
    double Good::itemPrice() const {
        return unitPrice;
    }
    
    double Good::itemCost() const {
        if (taxed()) {
            return itemPrice() * (tax + 1);
        }
        else {
            return itemPrice();

        }
    }
    
    void Good::message(const char* msg) {
        errorState.message(msg);
    }
    
    bool Good::isClear() const {
        return errorState.isClear();
    }
    
    //-------------------------------- Public Member Functions --------------------------------//
    
    Good::Good(char fileType) {
        
        goodType = fileType;
        unitSku[0] = '\0';
        unitDesc[0] = '\0';
        goodName = nullptr;
        qtyOnHand = 0;
        qtyNeed = 0;
        unitPrice = 0;
        taxStatus = false;
    }
    
    Good::Good(const char* sku, const char* goodName, const char* unit, int onHand, bool tax, double beforeTax, int itemNeed) {
        
        strncpy(unitSku, sku, max_sku_length);
        name(goodName);
        strncpy(unitDesc, unit, max_unit_length);
        qtyOnHand = onHand;
        taxStatus = tax;
        unitPrice = beforeTax;
        qtyNeed = itemNeed;
        
    }
    // Copy Constructor
    Good::Good(const Good& src) {
        *this = src;
    }
    // Copy Assignment
    Good& Good::operator=(const Good& src) {
        
        if (this != &src) {
            
            goodType = src.goodType;
            delete [] goodName;
            name(src.goodName);
            strncpy(unitSku, src.unitSku, max_sku_length);
            strncpy(unitDesc, src.unitDesc, max_unit_length);
            qtyOnHand = src.qtyOnHand;
            taxStatus = src.taxStatus;
            unitPrice = src.unitPrice;
            qtyNeed = src.qtyNeed;
            
        }
        
        return *this;
    }
    
    // Destructor
    Good::~Good() {
        if (goodName != nullptr) {
            delete [] goodName;
            goodName = nullptr;
        }
    }
    
    std::fstream& Good::store(std::fstream& file, bool newLine) const {
        file << goodType << ',' << unitSku << ',' << goodName << ',' << unitDesc << ',' << taxStatus << ',' << unitPrice << ',' << qtyOnHand << ',' << qtyNeed;
        
        if (newLine) {
            file << std::endl;
        }
        
        return file;
    }
    
    std::fstream& Good::load(std::fstream& file) {
        
        char gSku[max_sku_length];
        char gName[max_name_length];
        char gUnit[max_unit_length];
        int onhd;
        int need;
        double singleCost;
        char taxInput;
        bool taxSt;
        
        if (file.is_open()) {
            file.getline(gSku, max_sku_length, ',');
            
            file.getline(gName, max_name_length, ',');
            
            file.getline(gUnit, max_unit_length, ',');
            
            file >> taxInput;
            
            taxSt = false;
            
            if (taxInput == '1') {
                taxSt = true;
            }
            if (taxInput == '0') {
                taxSt = false;
            }
            file.ignore();
            
            file >> singleCost;
            file.ignore();
            
            file >> onhd;
            file.ignore();
            
            file >> need;
            file.ignore();
            
            *this = Good(gSku, gName, gUnit, onhd, taxSt, singleCost, need);
            
        }
        
        return file;
    }
    
    std::ostream& Good::write(std::ostream& os, bool linear) const {
        
        if (errorState.isClear()) {
            if (linear) {
                os << setw(max_sku_length) << left << sku() << '|'
                << setw(20) << left << name() << '|'
                << setw(7) << fixed << setprecision(2) << right << itemCost() << '|'
                << setw(4) << right << quantity() << '|'
                << setw(10) << left << unit() << '|'
                << setw(4) << right << qtyNeeded() << '|';
            }
            else {
                os << " Sku: " << sku() << std::endl <<
                " Name (no spaces): " << name() << std::endl <<
                " Price: " << itemPrice() << std::endl;
                
                os << " Price after tax: ";
                if (taxed()) {
                    os << itemCost() << std::endl;
                }
                else {
                    os << " N/A" << std::endl;
                }
                
                os << " Quantity on Hand: " << quantity() << " " << unit() << std::endl;
                os << " Quantity needed: " << qtyNeeded();
            }
        }
        else {
            os << errorState.message();
        }
        
        return os;
    }
    
    std::istream& Good::read(std::istream& is) {
        
        is.clear();
        char option;
        
        goodName = new char[max_name_length];
        
        std::cout << " Sku: ";
        is >> unitSku;
        
        std::cout << " Name (no spaces): ";
        is >> goodName;
        
        std::cout << " Unit: ";
        is >> unitDesc;
        
        std::cout << " Taxed? (y/n): ";
        is >> option;
        
        if (option == 'y' || option == 'Y') {
            taxStatus = true;
        }
        else if (option == 'n' || option == 'N') {
            taxStatus = false;
        }
        else {
            is.setstate(ios::failbit);
            errorState.message("Only (Y)es or (N)o are acceptable");
            return is;
        }
        
        if (!is.fail()) {
            std::cout << " Price: ";
            is >> unitPrice;
            
            if (is.fail()) {
                errorState.message("Invalid Price Entry");
                return is;
            }
        }
        
        if (!is.fail()) {
            std::cout << " Quantity on hand: ";
            is >> qtyOnHand;
            
            if (is.fail()) {
                errorState.message("Invalid Quantity Entry");
                return is;
            }
        }
        
        if (!is.fail()) {
            std::cout << " Quantity needed: ";
            is >> qtyNeed;
            if (is.fail()) {
                errorState.message("Invalid Quantity Needed Entry");
                return is;
            }
        }

        if (!is.fail()) {
            errorState.message("");
        }
        is.ignore();
        return is;
    }
    
    bool Good::operator==(const char* sku) const {
        return (strcmp(sku, this->unitSku) == 0) ? true : false;
    }
    
    double Good::total_cost() const {
        return ((unitPrice * qtyOnHand) * (tax + 1));
    }
    
    void Good::quantity(int no) {
        if (no > 0) {
            qtyOnHand = no;
        }
    }
    
    bool Good::isEmpty() const {
        if (goodName == nullptr) {
            return true;
        }
        
        return false;
    }
    
    int Good::qtyNeeded() const {
        return qtyNeed;
    }
    
    int Good::quantity() const {
        return qtyOnHand;
    }
    
    bool Good::operator>(const char* sku) const {
        return (strcmp(unitSku, sku) > 0) ? true : false;
    }
    
    bool Good::operator>(const iGood& obj) const {
        return (strcmp(this->goodName, obj.name()) > 0) ? true : false;
    }
    
    int Good::operator+=(int unitQty) {
        if (unitQty > 0) {
            qtyOnHand += unitQty;
            return qtyOnHand;
        }
        else {
            return qtyOnHand;
        }
    }
    
    std::ostream& operator<<(std::ostream& os, const iGood& obj) {
        return obj.write(os, true);
    }
    
    std::istream& operator>>(std::istream& is, iGood& obj) {
        return obj.read(is);
    }
    
    double operator+=(double& extraCost, const iGood& obj) {
        double updateCost;
        
        updateCost = obj.total_cost() + extraCost;
        
        return updateCost;
    }
}
