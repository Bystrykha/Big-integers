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
    Big_Number A, B, C, D, q, w, e;
    for (int i = 0; i < 10; i++) {
      Big_Number A(3, 1 + rand() % 30);
      Big_Number B(3, 1 + rand() % 30);
        cin >> A >> B >> C >> D;
        //C = A / B;
        //D = A % B;
        cout << "E - GOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
        e = A - D;
        cout <<"e = " << e << endl;
        cout << "E - ENNNNNNNNNNNNNNNNNNNNNNNNND" << endl;
        q = C * B;
        q = q + D;
        w = C * B;
        cin >> m;
        cout << "A = " << A << endl << "B = " << B << endl << "C = " << C << endl << "D = " << D << endl;
        cout << A << " = " << q << endl << w << " = " << e << endl;
        if(A == C * B + D && A - D == C * B) cout << "OK" << endl;
        else{
            cout << "no OK" << endl;
            break;
        }
    }
        return 0;
    }

// A = 69a6b66239d29bb866fd4383fc93bca626a031b4f487c6
// B = 5bf8c4ac7e
// C = 1261388896e84261d4711dc77c44bd859113c
// D = 4a0f99bc3e