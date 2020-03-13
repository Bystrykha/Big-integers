#include "Big_Number.h"
#include <cstdlib>
using namespace std;

Big_Number::Big_Number() {
        taken_coefficient = all_coefficient = 1;
        integers = new Base;
        integers[0] = 0;
    }

Big_Number::Big_Number(int k, int n) {
    if(k == 2){
        taken_coefficient = all_coefficient = n;
        integers = new Base[taken_coefficient];
        for(int i = 0; i < taken_coefficient; i++) {
            integers[i] = 0;
        }
    }
    if(k == 3){
        taken_coefficient = all_coefficient = n;
        integers = new Base[taken_coefficient];
        for(int i=0; i < all_coefficient; i++) {
            integers[i] = rand();
            Len();
            }
    }
}

Big_Number::Big_Number(Big_Number &BN) {
    taken_coefficient=BN.taken_coefficient;
    all_coefficient=BN.all_coefficient;
    integers = new Base[taken_coefficient];
    for(int i=0; i < all_coefficient; i++) integers[i]=BN.integers[i];
}

Big_Number::~Big_Number(){
    delete[](integers);
    integers = NULL;
}

ostream &operator << (ostream &out, Big_Number &BN) { //пересмотри, возможно, прийдется дописать(((
    for(int i = BN.taken_coefficient - 1; i >= 0; i--){
        cout.width(Base_size / 4);
        cout.fill('0');
        cout << hex << (int)
        BN.integers[i];
    }
    return out;
}

ostream &operator >> (ostream &in, Big_Number &BN) {
    string Your_BN;
    cin >> Your_BN;
    BN.all_coefficient = BN.taken_coefficient = Your_BN.size();
    BN.integers = new Base[BN.taken_coefficient];
    int index_el_of_Mass = 0;
    int el = 0;
    int free_bits = 8;
    for(int i = 0, j = 1; i < BN.taken_coefficient; i++, j++){
        if('0' <= Your_BN[i] && Your_BN[i] <= '9') el = Your_BN[i] - '0';
        else if('a' <= Your_BN[i] && Your_BN[i] <= 'f') el = Your_BN[i] - 'a' + 10;
        else if('A' <= Your_BN[i] && Your_BN[i] <= 'F') el = Your_BN[i] - 'A' + 10;
        el = el << (j * 4);
        BN.integers[index_el_of_Mass] = BN.integers[index_el_of_Mass] | el;
        free_bits = free_bits - 4;
        if(free_bits == 0){
            index_el_of_Mass ++;
            j = 1;
            free_bits = 8;
        }
    }
}

void Big_Number::Len(){
    for(int i = taken_coefficient - 1; integers[i] == 0 && i > 0; i--) taken_coefficient--;
}



