#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef unsigned char Base;
#define Base_size sizeof(Base)*1    //хранятся байты


class Big_Number{


    Base *integers;
    int taken_coefficient, all_coefficient;

public:
    Big_Number();
    Big_Number(int k, int n);
    Big_Number(Big_Number &BN);
    ~Big_Number();
    bool operator >(const Big_Number &BN);
    bool operator <(const Big_Number &BN);
    bool operator >=(const Big_Number &BN);
    bool operator <=(const Big_Number &BN);
    bool operator !=(const Big_Number &BN);
    bool operator ==(const Big_Number &BN);
    Big_Number &operator=(const Big_Number& BN);
    Big_Number operator+(const Big_Number &BN);
    Big_Number operator-(const Big_Number &BN);
    Big_Number operator*(int n);
    Big_Number operator<<(const int n);
    Big_Number operator*(const Big_Number &BN);
    Big_Number operator-=(const Big_Number &BN);
    Big_Number operator+=(const Big_Number &BN);
    int Compare(const Big_Number &BN_2);
    int Count_Zero() const;

    friend ostream& operator << (ostream &out, Big_Number &BN);
    friend istream& operator >> (istream &in, Big_Number &BN);
};