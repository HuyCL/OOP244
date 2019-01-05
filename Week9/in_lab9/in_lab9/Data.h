//
//  Data.hpp
//  in_lab9
//
//  Created by Huy Lam on 2018-11-22.
//  Copyright © 2018 Huy Lam. All rights reserved.
//

#ifndef SICT_DATA_H
#define SICT_DATA_H
#include <iostream>

namespace sict {
    // These numbers define
    // a) the range of data we expect to see in this workshop
    //    0 to 1 billion
    //    use them in the min and max function
    // b) the output column width for a single data field
    
    const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
    const int SMALLEST_NUMBER = 0;
    const int COLUMN_WIDTH    = 15;
    
    // max returns the largest item in data
    //
    template <typename T>
    T max(const T* data, int n) {
        T maxValue = 0;
        
        for (int i = 0; i < n; i++) {
            
            if (data[i] < LARGEST_NUMBER || data[i] > SMALLEST_NUMBER) { // Make sure the data is within range
                
                if (maxValue < data[i]) {
                    maxValue = data[i];
                }
            }
        }
        
        return maxValue;
    }
    
    
    // min returns the smallest item in data
    //
    template <typename T>
    T min(const T* data, int n) {
        
        T minValue = data[0];
        
        for (int i = 1; i < n; i++) {
            
            if (data[i] < LARGEST_NUMBER || data[i] > SMALLEST_NUMBER) {
                if (minValue > data[i]) {
                    minValue = data[i];
                }
            }
        }
        
        return minValue;
    }
    
    // sum returns the sum of n items in data
    //
    template <typename T>
    T sum(const T* data, int n) {
        
        T total = 0;
        
        for (int i = 0; i < n; i++) {
            total += data[i];
        }
        
        return total;
    }
    
    // average returns the average of n items in data
    //
    template <typename T>
    double average(const T* data, int n) {
        
        double avg = sum(data, n) / n;
        
        return avg;
        
    }
    
    // read extracts n items from input and stores them in data
    // - the items are comma separated
    // - this function assumes that a comma exists at the next field to be read
    // - for example: ,data1, data2,data3, ...., datan
    //
    template <typename T>
    bool read(std::istream& input, T* data, int n) {
        
        for (int i = 0; i < n; i++) {
            
            input.ignore(); // Ignore character comma ','
            
            input >> data[i];
            
            if(input.fail()) {
                return false;
            }
        }
        
        return true;
    }
    
    // display inserts n items of data into std::cout
    //
    template <typename T>
    void display(const char* name, const T* data, int n) {
        
        std::cout.width(20);
        std::cout.setf(std::ios::right);
        std::cout << name;
        
        for (int i = 0; i < n; i++) {
            std::cout.width(COLUMN_WIDTH);
            std::cout << data[i];
        }
        
        std::cout << std::endl;
    }
    
    
    bool readRow(std::istream& input, const char* name, int* data, int n);
    bool readRow(std::istream& input, const char* name, double* data, int n);
    void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif
