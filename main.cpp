#include <iostream>
#include <string>
#include "Big_Number.h"

using namespace std;

int main() {
   Big_Number a, b, c;
   int q, w;
   cin >> a;
   cin >> b;
   cin >> q;
   if(a > b) cout << "a > b" << endl;
   if(a < b) cout << "a < b" << endl;
   if(a >= b) cout << "a >= b" << endl;
   if(a <= b) cout << "a <= b" << endl;
   if(a == b) cout << "a = b" << endl;
   if(a != b) cout << "a != b" << endl;
   c = a;
   cout << "c = " << c << endl;
   c = a + b;
   cout <<"a + b = " << c << endl;
   c = a - b;
   cout <<"a - b = " << c << endl;
   c = a * b;
   cout <<"a * b = " << c << endl;
   c = a * q;
   cout <<"a * q = " << c << endl;
   c = a / q;
   cout <<"a / q = " << c << endl;
   c = a / b;
   cout <<"a / b = " << c << endl;
   w = a % q;
   cout << "a % q = " << w << endl;
   c = Big_Number::From_decimal("68247244188094483");
   cout << c << endl;
   return 0;
}