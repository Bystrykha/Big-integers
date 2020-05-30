#include "Big_Number.h"
#include <cstdlib>
#include <cmath>
using namespace std;

Big_Number::Big_Number() {                          //конструктор без аргументов
    taken_coefficient = all_coefficient = 1;
    integers = new Base;
    integers[0] = 0;
}

Big_Number::Big_Number(int k, int n) {              //конструктор с аргументами:
    if(k == 2){                                            //при k = 2 создаем большое число нужного размера, состоящее полностью из нулей
        taken_coefficient = all_coefficient = n;
        integers = new Base[taken_coefficient];
        for(int i = 0; i < taken_coefficient; i++) {
            integers[i] = 0;
        }
    }
    if(k == 3){                                            //при k = 3 создаем большое число нужного размера, состоящее из рандомных коэффициентов
        taken_coefficient = all_coefficient = n;
        integers = new Base[taken_coefficient];
        for(int i=0; i < all_coefficient; i++) {
            integers[i] = rand();
        }
    }
}

Big_Number::Big_Number(Big_Number &BN) {                        // конструктор крпирования
    taken_coefficient=BN.taken_coefficient;
    all_coefficient=BN.all_coefficient;
    integers = new Base[taken_coefficient];
    for(int i=0; i < all_coefficient; i++) integers[i]=BN.integers[i];
}

Big_Number::~Big_Number(){                  //диструктор
    delete[](integers);
    integers = NULL;
}

ostream &operator << (ostream &out, const Big_Number &BN) {
    bool is_write_zero = false;         //проупск первых нулей
    for(int i = 0; i < BN.taken_coefficient; i++){      //вывод с начала
        for(int j = Base_size * 8 - 4; j >= 0; j -= 4){
            int hex_coefficient = (BN.integers[i] >> j) & 15;    //15 - 4 единички в конце
            if((is_write_zero) || (!is_write_zero && hex_coefficient != 0)){
                out << hex << hex_coefficient;
                is_write_zero = true;
            }
        }
    }
    return out;
}

istream &operator >> (istream &in, Big_Number &BN) {
    string Your_BN;
    cin >> Your_BN;             //вводим строку
    BN.all_coefficient = BN.taken_coefficient = (Your_BN.size() * 4) / (Base_size * 8);     //определяем размер числа
    if(((Your_BN.size() * 4) % (Base_size * 8)) != 0) {     //добавляем место, если количетво символов не кратно основанию
        BN.all_coefficient++;
        BN.taken_coefficient++;
    }
    BN.integers = new Base[BN.taken_coefficient];   // выделяем место под большое число
    for(int i = 0; i<BN.all_coefficient; i++) BN.integers[i] = 0;   //заполняем нклями выделенную память(на всякий случай)
    int index_el_of_Mass = BN.all_coefficient-1;    //указывает номер элемента массива, в который попадет коэфф.
    int new_el = 0;     // сюда будем считывать символ из введенной нами строки (с преобразованным типом данных)
    int free_bits = Base_size * 8;  //указываем размер одного элемента большого числа
    for(int i = Your_BN.size() - 1; i >= 0; i--){       //заполнение с конца(последний символ строки станет последней цифрой большого числа(младшим разрядом))
        if('0' <= Your_BN[i] && Your_BN[i] <= '9') new_el = Your_BN[i] - '0';               //69 - 71стр : преобразование символа строки в целочисленную пременную(используя табл. ASCII)
        else if('a' <= Your_BN[i] && Your_BN[i] <= 'f') new_el = Your_BN[i] - 'a' + 10;
        else if('A' <= Your_BN[i] && Your_BN[i] <= 'F') new_el = Your_BN[i] - 'A' + 10;
        new_el = new_el << (Base_size * 8 - free_bits);     // сдвиг
        BN.integers[index_el_of_Mass] = BN.integers[index_el_of_Mass] | new_el;     //заполнение элемента большого числа(заполняем по 4 бита)
        free_bits = free_bits - 4;  //переходим на ноую часть байта
        if(free_bits == 0){     // если байт полностью заполнен, то заполняем следуюший элемент большого числа
            index_el_of_Mass --;
            free_bits = Base_size * 8;
        }
    }
}

bool Big_Number::operator > (const Big_Number &BN){     //перегрузки, начиная с 82 по 102 строку, используют один и тот же метод
    return this->Compare(BN) > 0;
}

bool Big_Number::operator < (const Big_Number &BN){
    return this->Compare(BN) < 0;
}

bool Big_Number::operator >= (const Big_Number &BN){
    return this->Compare(BN) >= 0;
}

bool Big_Number::operator <= (const Big_Number &BN){
    return this->Compare(BN) <= 0;
}

bool Big_Number::operator != (const Big_Number &BN){
    return this->Compare(BN) != 0;
}

bool Big_Number::operator == (const Big_Number &BN){
    return this->Compare(BN) == 0;
}

int Big_Number::Compare(const Big_Number & BN_2){
    int BN_2_Zero = BN_2.Count_Zero();  //вычисляем количество незначащих нулей(перед самим числом)
    int This_Zero = this->Count_Zero(); //вычисляем количество незначащих нулей(перед самим числом)
    if(this->taken_coefficient - This_Zero > BN_2.taken_coefficient - BN_2_Zero) return 1;      //стр. 109-111 : сравниваем по длине
    if(this -> taken_coefficient - This_Zero < BN_2.taken_coefficient - BN_2_Zero) return -1;
    for(int i = This_Zero, j = BN_2_Zero; i < this -> taken_coefficient; i++, j++){     //сравниваем коэфф. чисел, начиная с первого значащего коэфф (страрший значащий разряд)
        if(this -> integers[i] > BN_2.integers[j]) return 1;
        if(this -> integers[i] < BN_2.integers[j]) return -1;
    }   //цикл, пока разряд одного числа, не будет больше разряда другого
    return 0;
}

int Big_Number::Count_Zero() const {        //подсчет незначащих нулей
    for(int i = 0; i < all_coefficient; i++) if(integers[i] > 0) return i;
    return 0;
}

Big_Number Big_Number::operator+(const Big_Number &BN) {
    int max_size = max(taken_coefficient, BN.taken_coefficient);    //определяем размер наибольшего БЧ (большого числа)
    Big_Number Sum(2, max_size + 1);    //создаем новое БЧ с нужным размером, взятым с запасом
    Large_size remains = 0;    //сюда запишем сумму коэфф. БЧ-ел
    for(int i = taken_coefficient-1, j = BN.taken_coefficient-1, k = max_size; k >= 0; i--, j--, k--) {
        Large_size first_term = 0 , second_term = 0;   // сюда поподают коэфф. БЧ-ел
        if(i >= 0)  first_term = integers[i];   //если число кончилось, а цикл еще нет, считаем, что последующие разряды равны 0
        if(j >= 0)  second_term = BN.integers[j];   //если число кончилось, а цикл еще нет, считаем, что последующие разряды равны 0
        remains = first_term + second_term + remains;   //сумма(в remains после сдвига (134 стр.) то, что не вошло в предыдущую сумму
        Sum.integers[k] = remains;                  //запись в сумму
        remains >>= (Base_size * 8);                //сдвиг старшего разряда
    }
    return Sum;
}

Big_Number &Big_Number::operator=(const Big_Number& BN) {
    if(this != &BN){
        delete[] integers;              //удаляем масив с коэфф.
        taken_coefficient = BN.taken_coefficient;   //далее задаем новые параметры для БЧ и переписываем массив
        all_coefficient = BN.all_coefficient;
        integers = new Base[all_coefficient];
        for(int i = 0; i < all_coefficient; i++) integers[i] = BN.integers[i];
    }
    return *this;
}

Big_Number Big_Number::operator-(const Big_Number &BN) {
    Big_Number Result(2,taken_coefficient);
    if(taken_coefficient < BN.taken_coefficient) return Result; //если вычетаемое > уменьшаемого
    for(int i = taken_coefficient - 1, j = BN.taken_coefficient -1; i >= 0; i--, j--){ // i - счетчик уменьшаемого, j - счетчик вычитаемого
        Large_size first = integers[i], second = 0;    //переменные: first - уменьшаемое, second - вычетаемое
        if(j >= 0) second = BN.integers[j]; // запись вычетаемого
        if(first < second){ // если потребовался займ из следующих разрядов
            for(int k = i - 1; k >= 0; k--) {
                if(integers[k] > 0){    // когда коэфф., у которого занимаем, больше 0
                    for(int t = i - 1; t > k; t--){     // нули заменяем наибольшей цифрой
                        integers[t] += pow(2,Base_size * 8) - 1;
                    }
                    integers[k] -= 1;       // уменьшение коэфф., у которого заняли
                    first += pow(2,Base_size * 8); // увеличение уменьшаемого
                    break;
                }
            }
        }
        Result.integers[i] = first - second; //запись в ответ
    }
    return Result;
}

Big_Number Big_Number::operator*(int n) {
    int index = 0;
    Large_size res = 0;        //переменная для промежуточного результата
    Large_size term = 0;   // то, что перенесем в следующий разряд
    Big_Number Composition(2, taken_coefficient + 1);
    for(int i = taken_coefficient - 1; i >= 0; i--){
        Large_size factor = integers[i];
        res = factor * n + term;
        Composition.integers[i + 1] = res;  // i + 1: так как в результате произведения размер БЧ может получиться больше на 1, записываем промежуточный результат в соответствующий разряд
        term = res >> (Base_size * 8);
        index = i;
    }
    Composition.integers[index + 1] = res;
    return Composition;
}


Big_Number Big_Number::operator*(const Big_Number &BN) {
    Large_size Comp_size = taken_coefficient + BN.taken_coefficient;   // максимальный возможный размер результата
    Big_Number Composition(2, Comp_size);
    for(int j = BN.taken_coefficient - 1; j >= 0; j--){     //движемся по одному из множетелей от млажшего разряда к старшему
        Big_Number Term(2, taken_coefficient + 1);  //создаем БЧ, для записи промежуточного результата
        Large_size factor = BN.integers[j];    // коэфф. БЧ, на который будем умножать
        Term = *this * factor;  // умножение БЧ на коэфф. и запись промежуточного результата
        Term = Term << BN.taken_coefficient - 1 - j;    //сдвиг на соответствующее место (в зависимости от разряда коэфф.) (перегрузка сдвига ниже)
        Composition = Composition + Term;       //сумма промежуточного результата с конечным ответом
    }
    return Composition;
}

Big_Number Big_Number::operator<<(const int n) {        //сдвиг БЧ(повышение номера разряда всех коэфф.(увеличивает размер БЧ))
    if(n == 0) return *this;
    Big_Number New_Term(2, all_coefficient + n);
    for(int i = 0; i < all_coefficient; i++){
        New_Term.integers[i] = integers[i];
    }
    return New_Term;
}

Big_Number Big_Number::operator-=(const Big_Number &BN) {       //тут, думаю, понятно
    *this = *this - BN;
    return *this;
}


Big_Number Big_Number::operator+=(const Big_Number &BN) {
    *this = *this + BN;
    return *this;
}

Big_Number Big_Number::operator/(int n) {
    Big_Number Quotient(2, taken_coefficient);      // результат разности
    Large_size remainder = 0, use_coefficient = 0;     // remainder - остаток от деления, use_coefficient - та часть БЧ, которую будем делить
    for(int i = 0; i < taken_coefficient; i++){
        use_coefficient = integers[i] + (remainder << Base_size * 8);   // сдиг остатка на разряд и прибавление следующего коэффициента
        Quotient.integers[i] = use_coefficient / n;     // деление на число
        remainder = use_coefficient % n;    // вычисление остатка
    }
    return Quotient;
}

int Big_Number::operator%(int n) {
    if(n == 0){
        cout << "error";
        return 0;
    }
    Large_size remainder = 0, use_coefficient = 0;
    for(int i = 0; i < taken_coefficient; i++){
        use_coefficient = integers[i] + (remainder << Base_size * 8);
        remainder = use_coefficient % n;
    }
    return remainder;
}

Big_Number Big_Number::operator/( Big_Number &BN) {
    Big_Number Result(2, taken_coefficient), use_coefficient(2, taken_coefficient),
            remainder(2, BN.taken_coefficient), Zero(2, 1); // Result - результат деления, use_coefficient - "активная" часть делимого, remainder - остаток
            if(BN == Zero){
                cout << "error";
                return Zero;
            }
    for(int i = 0; i < taken_coefficient;){
        int c = 0;  // счетчик для сдвига результата делния
        while(use_coefficient < BN){        // увеличение "активной" части делителя, для последующего деления
            use_coefficient.Shift(1);   // сдвиг "активной" части БЧ
            use_coefficient.integers[taken_coefficient - 1] += integers[i]; // на освободившееся место ставлм соед. кофф. из БЧ
            i++;    // далее рассматриваем слкдующий коэфф. в БЧ
            if(c > 0)Result.Shift(1);   // если добавили более 1-го коэфф. к "активной" части, то, соответственно, результат увеличивается
            c = 1;  // счетчик
        }
        Large_size res = 0; // сюда попадет промежуточный результат деления
        while(use_coefficient >= BN){   // само деление, посредством вычетания делителя из "активной" части БЧ
            use_coefficient = use_coefficient - BN; // вычетание
            res += 1;   // увеличение промежуточного результата
        }
        Result.Shift(1); // сдвиг результата
        Result.integers[taken_coefficient-1] = res; // запись соответствующего коэфф. результата
        remainder = use_coefficient;    // запись остатка
    }
    return Result;
}

Big_Number Big_Number::Shift(int n) {       //сдвиг, без увеличения памяти в БЧ
    if (n < all_coefficient) {
    for(int i = n, j = 0; i < all_coefficient ; i++, j++) {
            integers[j] = integers[i];
            integers[i] = 0;
        }
    }
    else return *this;
    cout << "res = " << *this << endl;
    return *this;
}

string Big_Number::To_decimal(){    // перевод в 10-ую систему счисления
    Big_Number Number = *this, Zero(2, 1);  //Zero - ноль в виде БЧ
    string integer = "", null_srt = "";    // пустая строка
    int counter = 0;
    while(Number > Zero){
        counter ++;
        integer = (char)((Number % 10) + '0') + integer;    //запись в строку цифры
        Number = Number / 10;   // уменьшение БЧ
    }
    for(int i = 0; i < counter; i++){
        int code = integer[i];
        if(code < 48 || code > 57)return null_srt;
    }
    return integer;
}

Big_Number Big_Number::From_decimal(string str) {
    for(auto str_el: str){
        int code = str_el;
        if(48 < code || code > 57){
            Big_Number zero(2, 1);
            return zero;
        }
    }
    Big_Number Result(2,1), factor(2, 1);      //Result - результат, factor - множитель, для увеличения коэфф. в 10(в соответствующей степени)
    factor.integers[0] = 1; // начальное значение множителя
    for(int i = str.size() - 1; i >= 0  ; i--){
        Result += factor * ((int)str[i] - '0');    //запись в конечный результат
        factor = factor * 10;   // увеличение множителя
    }
    return Result;
}

Big_Number Big_Number::operator%(Big_Number &BN) {
    Big_Number Result(2, taken_coefficient), use_coefficient(2, taken_coefficient),
            remainder(2, BN.taken_coefficient), Zero(2, 1); // Result - результат деления, use_coefficient - "активная" часть делимого, remainder - остаток
    if(BN == Zero){
        cout << "error";
        return Zero;
    }
    for(int i = 0; i < taken_coefficient;){
        int c = 0;  // счетчик для сдвига результата делния
        while(use_coefficient < BN){        // увеличение "активной" части делителя, для последующего деления
            use_coefficient.Shift(1);   // сдвиг "активной" части БЧ
            use_coefficient.integers[taken_coefficient - 1] += integers[i]; // на освободившееся место ставлм соед. кофф. из БЧ
            i++;    // далее рассматриваем слкдующий коэфф. в БЧ
            if(c > 0)Result.Shift(1);   // если добавили более 1-го коэфф. к "активной" части, то, соответственно, результат увеличивается
            c = 1;  // счетчик
        }
        Large_size res = 0; // сюда попадет промежуточный результат деления
        while(use_coefficient >= BN){   // само деление, посредством вычетания делителя из "активной" части БЧ
            use_coefficient = use_coefficient - BN; // вычетание
            res += 1;   // увеличение промежуточного результата
        }
        Result.Shift(1); // сдвиг результата
        Result.integers[taken_coefficient-1] = res; // запись соответствующего коэфф. результата
        remainder = use_coefficient;    // запись остатка
    }
    return remainder;
}
