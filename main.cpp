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
    for (int i = 0; i < 100; i++) {
      Big_Number A(3, 1 + rand() % 1000);
      Big_Number B(3, 1 + rand() % 1000);
      cout << A << endl << B << endl;
        C = A / B;
        D = A % B;
        if(A == C * B + D && A - D == C * B);
        else{
            break;
        }
        cout << i << endl;
    }
    return 0;
}
