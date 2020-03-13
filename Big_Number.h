#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef unsigned char Base;
#define Base_size sizeof(Base)*1    //; ???


class Big_Number{


    Base *integers;
    int taken_coefficient, all_coefficient;

public:
    Big_Number();
    Big_Number(int k, int n);
    Big_Number(Big_Number &BN);
    ~Big_Number();
    friend ostream& operator << (ostream &out, Big_Number &BN);
    friend ostream& operator >> (ostream &in, Big_Number &BN);
    void Len();
};