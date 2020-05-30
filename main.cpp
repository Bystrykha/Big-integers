/// исправлено:
/// 1)заменил тип int на больший в операторе '+' (так же произвел замену в других частях кода)
/// 2)дописал функцию Count_Zero
/// 3)убрал строку 111(там была проверка на уже выполненное условие)
/// 4)с all_coefficient работает деление, изначально, я бы не вводил это поле изначально, но поскольку оно указывалось в лекциях, оно есть и в программе,
///при удалении этого поля на данном этапе, возникли проблемы в "istream& operator >>", так же оно учавствует в методе Shift  в других частях кода
///в некоторых местах all_coefficient действительно можно заменить на taken_coefficient, но полный отказ от all_coefficient повлечет за собой переписывание второй части кода

#include <iostream>
#include <string>
#include "Big_Number.h"

using namespace std;

int main() {
   Big_Number a, b, c;
   int q, w;
   cin >> a;
  // cin >> b;
   cin >> q;
  /* if(a > b) cout << "a > b" << endl;
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
   cout << c << endl; */
  a.Shift(q);
  cout << a;
   return 0;
}