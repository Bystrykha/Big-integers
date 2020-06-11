/// исправлено:
/// 1)заменил тип int на больший в операторе '+' (так же произвел замену в других частях кода)
/// 2)дописал функцию Count_Zero
/// 3)убрал строку 111(там была проверка на уже выполненное условие)
/// 4)с all_coefficient работает деление, изначально, я бы не вводил это поле изначально, но поскольку оно указывалось в лекциях, оно есть и в программе,
///при удалении этого поля на данном этапе, возникли проблемы в "istream& operator >>", так же оно учавствует в методе Shift  в других частях кода
///в некоторых местах all_coefficient действительно можно заменить на taken_coefficient, но полный отказ от all_coefficient повлечет за собой переписывание второй части кода

#include <iostream>
#include <string>
#include <ctime>
#include "Big_Number.h"

using namespace std;

int main() {
//    int M = 10, T = 10, i = 0;
//    int n = 100;
//    int m = 60;
//    cout << n <<" " << m << endl;
//    cout << "1";
//    for( int h = 0; h < 1000; h++){
//        Big_Number A(3, n), B(3, m), C, D;
//        cout << "A = " << A << endl << "B = " << B << endl;
//        C = A/B;
//        D = A%B;
//        cout << "cerf";
//        i++;
//        cout << i;
//        if(A == C*B + D && A-D == C*B && D < B && --T);
//        else{
//            cout << "error";
//            break;
//        }
//    }
//for(int i = 0; i < 20; i++) {
    //Big_Number A, B, C;
//
//    C = A + B;
//    cout << C;
//}
//
//    srand( time( 0 ) );
//    cout << 1 + rand() % 1000 << endl;
//    system("pause");
    int n = 12, m;
    srand(time(0));
    Big_Number A, B, C, D;
    for (int i = 0; i < 10; i++) {
   //   Big_Number A(3, 1 + rand() % 30);
   //   Big_Number B(3, 1 + rand() % 30);
       //
        cin >> A >> B;
        cout << B << endl;
       // cout << "A = " << A << endl << "B = " << B << endl;
        C = A % B;
        cout << "C = " << C << endl;
        //cout << "AAAAA" << endl;
        D = A / B;
        //cout << "BBBBBBBB" << endl;
        //cout << "C = " << C << endl << "D = " << D << endl;
        //cout << A << " = " << C * B + D << endl << A - D << " = " << C * B << endl;
        if(A == C * B + D && A - D == C * B) cout << "OK" << endl;
        else{
            cout << "no OK" << endl;
            break;
        }
        cout << i << endl;
//       cout << C << endl;
//       cout << A << endl;
//       cout << B << endl;
    }
        return 0;
    }

// A = 7d8656c69bade53b33ee4f98bbf133fdf0 (20)
// B = 7b848410fa310728ad98d982f89ffff (15)
//45014db74d3d4fe895f94870fa00e32

//75ce0e858c0ad4c8a914c2008c6733fe
//7b848410fa310728ad98d982f89ffff

//6e15c6447c67c4561e3b34685cdd33ff

//665d7e036cc4b3e39361a6d02d533400
//665d7e036cc4b3e39361a6d02d533400

//201d2b5a17cde1286557615c351340df0
//7b848410fa310728ad98d982f89ffff
