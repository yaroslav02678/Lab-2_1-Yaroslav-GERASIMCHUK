#ifndef USER_H  
#define USER_H  

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>

using namespace std;

class User {
protected:
    string name;
    string password;

public:
    User(string& name, string& password);

    string getName() const;
    string getPassword() const;
    void virtual aboutAuthor() = 0;  
};

#endif