#include <iostream>
#include "User.h"
using namespace std;

bool User::authenticate(const string& name, int pass){
    
    if (name == username && pass == password)
    {
        cout << endl<< "Access granted!!" << endl;
        return true;
    }
    return false;

}