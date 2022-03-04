#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"
#include <sstream>
using namespace std;
//using std::cout, std::endl, std::cin;
using std::istringstream;
using std::string;
char digit;

int main() {
    
cout << "String Calculator" << endl;
cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;

istringstream inSS;
string userInput;
string num_1;
string operator_;
string num_2; 
int i = 0;
   
cout << ">> ";
getline(cin, userInput);   
inSS.str(userInput);
cout << endl;
inSS >> num_1 >> operator_ >> num_2;

    while (i == 0) {
        if ((num_1 == "q") || (num_1 == "quit")){
            break;
        
        } else if (operator_ == "+") {
            cout << "ans ="; 
            cout << endl;
            cout << endl;
            cout << add(num_1, num_2);
        
        } else if (operator_ == "-") {
            cout << "ans ="; 
            cout << endl;
            cout << endl;
            cout << subtract(num_1, num_2);
        
        } else if (operator_ == "*") {
            cout << "ans ="; 
            cout << endl;
            cout << endl;
            cout << multiply(num_1, num_2);
        }
        cout << endl << endl;
        cout << ">> ";
        inSS.clear();
        getline(cin, userInput);   
        inSS.str(userInput);
        cout << endl;
        inSS >> num_1 >> operator_ >> num_2;
    } 

cout << "farvel!" << endl;
}


