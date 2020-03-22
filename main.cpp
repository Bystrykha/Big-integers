#include <iostream>
#include <string>
#include "Big_Number.h"

using namespace std;

int main() {
   Big_Number a, b, c;
   int q;
   while(true) {
       cin >> a;
       cin >> b;
       c = a - b;
     cout <<"c = " << c << endl;
   }
   return 0;
}