#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    int decimal;
    if (digit == '0') {
        decimal = 0;
        return decimal;
    }
    if (digit == '1') {
        decimal = 1;
        return decimal;
    }
    if (digit == '2') {
        decimal = 2;
        return decimal;
    }
    if (digit == '3') {
        decimal = 3;
        return decimal;
    }
    if (digit == '4') {
        decimal = 4;
        return decimal;
    }
    if (digit == '5') {
        decimal = 5;
        return decimal;
    }
    if (digit == '6') {
        decimal = 6;
        return decimal;
    }
    if (digit == '7') {
        decimal = 7;
        return decimal;
    }
    if (digit == '8') {
        decimal = 8;
        return decimal;
    }
    if (digit == '9') {
        decimal = 9;
        return decimal;
    }
    else {
        throw std::invalid_argument("Invalid input");
    }
    return 0;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    char digit;
    if (decimal == 0) {
        digit = '0';
        return digit;
    }
    if (decimal == 1) {
        digit = '1';
        return digit;
    }
    if (decimal == 2) {
        digit = '2';
        return digit;
    }
    if (decimal == 3) {
        digit = '3';
        return digit;
    }
    if (decimal == 4) {
        digit = '4';
        return digit;
    }
    if (decimal == 5) {
        digit = '5';
        return digit;
    }
    if (decimal == 6) {
        digit = '6';
        return digit;
    }
    if (decimal == 7) {
        digit = '7';
        return digit;
    }
    if (decimal == 8) {
        digit = '8';
        return digit;
    }
    if (decimal == 9) {
        digit = '9';
        return digit;
    }
    else {
        throw std::invalid_argument("Invalid input");
    }
    return '\0';
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    
    int numSize;
    numSize = num.size();
    int i = 0;
    
    if (num.at(0) != '-') {                      // Positive
        for (i = 0; i < numSize; ++i) {  // Check the leading zero in the string.
            if (num == "0") {
                num = "0";
                break;
            }
            
            else { 
            
                if (num.at(0) != '0') {
                break;
                }
                
                
                else if (num.at(0) == '0') {
                    num.replace(0, 1, "");
                }
                else {
                    num = "0";
                }  
            
            }
        }
    }
    else {                                        // Negative
        //while (i == 0) {                         // Check the leading zero in the string.
        for (i = 0; i < numSize; ++i) {
            if (num == "-0") {
                num = "0";
                break;
            }  
            else { 
                
                if (num.at(1) != '0') {
                break;
                }
                if (num.at(1) == '0') {
                    num.replace(1, 1, "");
                }
                else {
                    num = "0";
                }  
            }
        }
    }   
                                        
    return num; 
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    

    int numSizeLhs;
    int numSizeRhs;
    int lastDecimalLhs;
    int lastDecimalRhs;
    int total;
    int extra;
    int i = 0;
    numSizeLhs = lhs.size();
    numSizeRhs = rhs.size();
    string last_digit;
    string last_digit_total;
    int last_digit_int;
    string lhs_tmp;
    string rhs_tmp;
    lhs_tmp = lhs;
    rhs_tmp = rhs;
   
    
    if ((lhs.at(0) == '-') && (rhs.at(0) != '-')) {
        rhs.insert(0, "-");
        last_digit_total = subtract(lhs, rhs);  
    }
    else if ((lhs.at(0) != '-') && (rhs.at(0) == '-')) {
        rhs.replace(0, 1, "");
        last_digit_total = subtract(lhs, rhs);  
    }
    else {
    if ((lhs.at(0) == '-') && (rhs.at(0) == '-')) {
        lhs.replace(0, 1, "0"); 
        rhs.replace(0, 1, "0");    
    }
    
    

    if (numSizeLhs > numSizeRhs) {                                         //Deal with range
        for (i = 0; i < (numSizeLhs - numSizeRhs); ++i) { 
            
                rhs.insert(0, "0");
              
        }
        numSizeRhs = numSizeLhs;
    }
    if (numSizeRhs > numSizeLhs) {                                         //Deal with range
        for (i = 0; i < (numSizeRhs - numSizeLhs); ++i) { 
           
                lhs.insert(0, "0");
        
        }
        numSizeLhs = numSizeRhs;
    }
    
    
    
    extra = 0;
    for (i = 0; (i < numSizeLhs || i < numSizeRhs) ; ++i) {
        
        
        lastDecimalLhs = digit_to_decimal(lhs.at(numSizeLhs - (i+1)));   // Change string to number
        lastDecimalRhs = digit_to_decimal(rhs.at(numSizeRhs - (i+1)));
        
        
        total = lastDecimalLhs + lastDecimalRhs + extra;  // Do addition
        if (total <= 9) {
            extra = 0;
            last_digit = decimal_to_digit(total);
            last_digit_total.insert(0, last_digit);
        }
        else if (total >= 10) {     // If the sum exceed 10 in that decimal
            total = total % 10;
            last_digit = decimal_to_digit(total);
            last_digit_total.insert(0, last_digit);
                        
            extra = 1;
            
            if (i == (numSizeLhs - 1)) {
                lastDecimalLhs = 0;
                lastDecimalRhs = 0;
                total = lastDecimalLhs + lastDecimalRhs + extra;
                last_digit = decimal_to_digit(total);
                last_digit_total.insert(0,last_digit);
            
            }
            else {
                last_digit = decimal_to_digit(total); // Change number to string
            }
        }
    }
    
    if ((lhs_tmp.at(0) == '-') && (rhs_tmp.at(0) == '-')) {
        last_digit_int = last_digit_total.size();
        if (last_digit_int == 1){
            last_digit_total = last_digit_total;
        }
        else if (last_digit_total.at(0) == '0') {
            last_digit_total.replace(0, 1, "-");
        }
        else if (last_digit_total.at(0) != '0') {
            last_digit_total.insert(0, "-");
        }
    }   // close if neg

    
     
    }
    return last_digit_total;
}  


string subtract(string lhs, string rhs) {
    // TODO(student): implement
    int numSizeLhs;
    int numSizeRhs;
    int numSizeLhs_tmp;
    int numSizeRhs_tmp;
    int lastDecimalLhs;
    int lastDecimalRhs;
    int different;
    int borrow;
    int i = 0;
    numSizeLhs = lhs.size();
    numSizeRhs = rhs.size();
    numSizeLhs_tmp = numSizeLhs;
    numSizeRhs_tmp = numSizeRhs;
    string last_digit;
    string last_digit_total;
    //int last_digit_int;
    string lhs_tmp;
    string rhs_tmp;
    lhs_tmp = lhs;
    rhs_tmp = rhs;
    int tmp;
    if (lhs == rhs) {
        last_digit_total = "0";
    }
    else if ((lhs.at(0) == '-') && (rhs.at(0) != '-')) {   
        rhs.insert(0, "-");
        last_digit_total = add(lhs, rhs);
    }
    else if ((lhs.at(0) != '-') && (rhs.at(0) == '-')) {   
        lhs.insert(0, "-");
        last_digit_total = add(lhs, rhs);
        tmp = 1;
    }
    else {
    if ((lhs.at(0) == '-') && (rhs.at(0) == '-')) {      // if they both negative
        lhs.replace(0, 1, "0"); 
        rhs.replace(0, 1, "0");    
    }
    if (numSizeLhs > numSizeRhs) {                                         //Deal with range
        for (i = 0; i < (numSizeLhs - numSizeRhs); ++i) { 
            rhs.insert(0, "0");   
        }
        numSizeRhs = numSizeLhs;
    }
    if (numSizeRhs > numSizeLhs) {                                         //Deal with range
        for (i = 0; i < (numSizeRhs - numSizeLhs); ++i) { 
            lhs.insert(0, "0");
        }
        numSizeLhs = numSizeRhs;
    }
    int tmp = 0;      // check equal range but lhs < rhs in some digits
    for (i = 0; (i < numSizeLhs || i < numSizeRhs) ; ++i) {
        lastDecimalLhs = digit_to_decimal(lhs.at(numSizeLhs - (numSizeLhs - i)));   // Change string to number
        lastDecimalRhs = digit_to_decimal(rhs.at(numSizeRhs - (numSizeRhs - i)));
        if (lastDecimalLhs > lastDecimalRhs) {
            
           break;
        }  
        else if (lastDecimalLhs < lastDecimalRhs) {
            tmp = 1;
            break;
        }  
        
    }
   
    borrow = 0;
    for (i = 0; (i < numSizeLhs || i < numSizeRhs) ; ++i) {
    
        if (tmp == 1) {
            lastDecimalLhs = digit_to_decimal(rhs.at(numSizeLhs - (i+1)));   // Change string to number
            lastDecimalRhs = digit_to_decimal(lhs.at(numSizeRhs - (i+1)));
        }
        else {
            lastDecimalLhs = digit_to_decimal(lhs.at(numSizeLhs - (i+1)));   // Change string to number
            lastDecimalRhs = digit_to_decimal(rhs.at(numSizeRhs - (i+1)));
        }
        
        
        if (borrow == 1) {
            lastDecimalLhs = lastDecimalLhs - 1;
        }
        
        different = lastDecimalLhs - lastDecimalRhs;  // Do subtraction
        if (different >= 0) {
            last_digit = decimal_to_digit(different);  // Number to string
            last_digit_total.insert(0, last_digit);    // Last Output
            borrow = 0;
        }
        else if (different < 0) {
            
            
            if (i == (numSizeLhs - 1)) {    // first position
                lastDecimalLhs = 0;
                lastDecimalRhs = 0;
                different = (-1) * different;
                last_digit = decimal_to_digit(different);  // Number to string
                last_digit_total.insert(0, "-" + last_digit);
            
            }
            else {
                different = different + 10;
                borrow = 1;
                last_digit = decimal_to_digit(different);
                last_digit_total.insert(0, last_digit);
            }
        }
    }
    if (last_digit_total.at(0) == '0') {
        last_digit_total.replace(0, 1, "");
    }
    if ((numSizeRhs_tmp > numSizeLhs_tmp) || (tmp == 1)) {       // if L < R
        last_digit_total.insert(0, "-");
        
    }
    if ((lhs_tmp.at(0) == '-') && (rhs_tmp.at(0) == '-')) {
        if (last_digit_total.at(0) == '-') {
            last_digit_total.replace(0, 1,"");
        }
        else {
            last_digit_total.insert(0, "-");
        }
    }
    } // end big else
    if (tmp == 1) {
        last_digit_total.replace(0, 1, "");
    }
    last_digit_total = trim_leading_zeros(last_digit_total);
    return last_digit_total;
    

}   


string multiply(string lhs, string rhs) {
    // TODO(student): implement
    int lastDecimalLhs;
    int lastDecimalRhs;
    int total;
    int i;
    int numSizeLhs;
    int numSizeRhs;
    int extra = 0;
    string last_digit_total;
    string total_digit;
    string lhs_tmp;
    string rhs_tmp;
    lhs_tmp = lhs;
    rhs_tmp = rhs;
    numSizeLhs = lhs.size();
    numSizeRhs = rhs.size();
    
    if ((lhs.at(0) == '-') && (rhs.at(0) != '-')) {   
        lhs.replace(0, 1, "0");
        
    }
    else if ((lhs.at(0) != '-') && (rhs.at(0) == '-')) {   
        rhs.replace(0, 1, "0");
        
        
    }
    else if ((lhs.at(0) == '-') && (rhs.at(0) == '-')) {
        lhs.replace(0, 1, "0"); 
        rhs.replace(0, 1, "0");    
    }
    if (numSizeLhs > numSizeRhs) {                                         //Deal with range
        for (i = 0; i < (numSizeLhs - numSizeRhs); ++i) { 
            rhs.insert(0, "0");   
        }
        numSizeRhs = numSizeLhs;
    }
    if (numSizeRhs > numSizeLhs) {                                         //Deal with range
        for (i = 0; i < (numSizeRhs - numSizeLhs); ++i) { 
            lhs.insert(0, "0");
        }
        numSizeLhs = numSizeRhs;
    }
    int j;
    int m =0;
    //string zero;
    string adding;
    string add_tmp;
    string new_inside;
    string new_outside = "0";
    
    for (j = 0; j < numSizeRhs ; ++j) {
        
        extra = 0;
        lastDecimalRhs = digit_to_decimal(rhs.at(numSizeRhs - (j+1))); // fixed last number
        if (j != 0) {
            new_outside = add(new_outside, last_digit_total);
            
            
        }
        
        if (j != 0) {
             last_digit_total = "0";
             for  (m = 0; m < j-1 ;++m) {
                last_digit_total.push_back('0');
            
            }
        }
        for (i = 0; i < numSizeLhs; ++i) {    // multiply through each top number by fixed second number
            
            
            lastDecimalLhs = digit_to_decimal(lhs.at(numSizeLhs - (i+1)));   // Change string to number
            total = (lastDecimalLhs * lastDecimalRhs) + extra;
            
            if (total < 10) {
                extra = 0;
                total_digit = decimal_to_digit(total);
                last_digit_total.insert(0, total_digit);
                
            }
            else if (total >= 10) {
                extra = (total / 10);
                total = total % 10;
                total_digit = decimal_to_digit(total);
                last_digit_total.insert(0, total_digit);
                if (i == (numSizeLhs - 1)) {             // last step
                    lastDecimalLhs = 0;
                    lastDecimalRhs = 0;
                    total = (lastDecimalLhs + lastDecimalRhs) + extra;
                    total_digit = decimal_to_digit(total);
                    last_digit_total.insert(0,total_digit);
                    
                }
                
                new_inside = last_digit_total;    
            }
          
          new_inside = add(new_outside, last_digit_total);
        
        }

    }
    last_digit_total = new_inside;
 
    if ((lhs_tmp.at(0) == '-') && (rhs_tmp.at(0) != '-')) {   
        last_digit_total.insert(0,"-");
        
    }
    else if ((lhs_tmp.at(0) != '-') && (rhs_tmp.at(0) == '-')) {   
        last_digit_total.insert(0,"-");
        
        
    }
last_digit_total = trim_leading_zeros(last_digit_total);
return last_digit_total;
}
   




