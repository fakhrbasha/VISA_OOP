#include <iostream>
using namespace std;

class User
{
private:
    string username = "user";
    int password = 1234;

public:
    bool authenticate(const string& name, int pass);
};