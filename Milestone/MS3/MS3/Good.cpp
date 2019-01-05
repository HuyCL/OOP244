//
//  Good.cpp
//  MS3
//
//  Created by Huy Lam on 2018-11-12.
//  Copyright © 2018 Huy Lam. All rights reserved.
//
// Name: Huy Lam
// Section: GG
// Date: 17/11/2018

#include "Good.h"
#include "Error.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <memory>


namespace aid {
    
    //------------------------------ Protected Member Functions ------------------------------//
    
    void Good::name(const char* n) {
        
        if (n != nullptr) {
            int len = strlen(n);
            goodName = new char[len];
            
            for (int i = 0; i < len; i++) {
                goodName[i] = n[i];
            }
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
        if (taxStatus) {
            return itemPrice() * (tax + 1);
        }
        else {
            return itemPrice();

        }
    }
    
    void Good::message(const char* msg) {
        Error::message(msg);
    }
    
    bool Good::isClear() const {
        return Error::isClear();
    }
    
    //-------------------------------- Public Member Functions --------------------------------//
    
    Good::Good(char type) {
        goodType = type;
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
            strncpy(unitSku, src.unitSku, max_sku_length);
            if (src.goodName != nullptr) {
                int len = strlen(src.goodName);
                goodName = new char[len];

                
                for (int i = 0; i < len; i++) {
                    goodName[i] = src.goodName[i];
                }
            }
            else {
                goodName = nullptr;
            }
            
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
        file << this->goodType << ',' << this->unitSku << ',' << this->unitDesc << ',' << this->goodName << ',' << this->qtyOnHand << ',' << this->qtyNeed << ',' << this->unitPrice << ',' << this->taxStatus;
        
        if (newLine) {
            file << std::endl;
        }
        
        return file;
    }
    
    std::fstream& Good::load(std::fstream& file) {
        
        Good temp;
        
        if (file.is_open()) {
            file >> temp.goodType;
            file >> temp.unitSku;
            file >> temp.unitDesc;
            file >> temp.goodName;
            file >> temp.qtyOnHand;
            file >> temp.qtyNeed;
            file >> temp.unitPrice;
            file >> temp.taxStatus;
            
            *this = temp;
        }
        
        return file;
    }
    
    std::ostream& Good::write(std::ostream& os, bool linear) const {
        
        if (linear) {
            os << std::setw(max_sku_length) << std::left << unitSku << "|" << std::setw(20) << std::left << goodName << "|" << std::setw(7) << std::fixed << std::setprecision(2) << std::right << itemCost() << "|" << std::setw(4) << std::right << qtyOnHand << "|" << std::setw(max_unit_length) << std::left << unitDesc << "|" << std::setw(4) << std::right << qtyNeed << "|";
        }
        else {
            os << "Sku: " << unitSku << "|" << std::endl <<
            "Name (no spaces): " << goodName << "|" << std::endl <<
            "Price: " << unitPrice << "|" << std::endl;
            
            if (taxStatus) {
                os << "Price after tax: " << itemCost() << std::endl;
            }
            else {
                os << "N/A" << std::endl;
            }
            
            os << "Quantity on hand: " << qtyOnHand << std::endl <<
            "Quantity needed: " << qtyNeed << std::endl;
        }
        
        return os;
    }
    
    std::istream& Good::read(std::istream& is) {
        
        Good temp;
        char option;
        
        temp.goodName = new char[max_name_length];
        
        std::cout << " Sku: ";
        is >> temp.unitSku;
        
        std::cout << " Name (no spaces): ";
        is >> temp.goodName;
        
        std::cout << " Unit: ";
        is >> temp.unitDesc;
        
        std::cout << " Taxed? (y/n): ";
        is >> option;
        
        if (option == 'y' || option == 'Y') {
            temp.taxStatus = true;
        }
        else if (option == 'n' || option == 'N') {
            temp.taxStatus = false;
        }
        else {
                is.setstate(std::ios::failbit);
            Error::message("Only (Y)es or (N)o are acceptable");
        }
        
        if (!is.fail()) {
            std::cout << " Price: ";
            is >> temp.unitPrice;
            
            if (is.fail()) {
                Error::message("Invalid Price Entry");
            }
        }
        
        if (!is.fail()) {
            std::cout << " Quantity on hand: ";
            is >> temp.qtyOnHand;
            
            if (is.fail()) {
                Error::message("Invalid Quantity Entry");
            }
        }
        
        if (!is.fail()) {
            std::cout << " Quantity needed: ";
            is >> temp.qtyNeed;
            if (is.fail())
                Error::message("Invalid Quantity Needed Entry");
        }

        if (!is.fail()) {
            *this = temp;
        }

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
        if (goodName == nullptr && unitSku[0] == '\0') {
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
    
    bool Good::operator>(const Good& obj) const {
        return (strcmp(this->goodName, obj.goodName) > 0) ? true : false;
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
    
    std::ostream& operator<<(std::ostream& os, const Good& obj) {
        return obj.write(os, true);
    }
    
    std::istream& operator>>(std::istream& is, Good& obj) {
        return obj.read(is);
    }
    
    double operator+=(double& extraCost, const Good& obj) {
        double updateCost;
        
        updateCost = obj.total_cost() + extraCost;
        
        return updateCost;
    }
}
