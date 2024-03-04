#ifndef HEADER_CA2A0EA3D5856A49
#define HEADER_CA2A0EA3D5856A49

#include <iostream>

using namespace std;

struct Operation
{
    int id {};
    int userId {};
    int dateAsInt {};
    string date {};
    string item {};
    double amount {};

    bool operator < (const Operation & operation) const
    {
        return (dateAsInt < operation.dateAsInt);
    }
};

#endif // header guard

