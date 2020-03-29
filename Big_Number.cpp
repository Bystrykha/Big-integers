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
    if(this -> taken_coefficient - This_Zero == BN_2.taken_coefficient - BN_2_Zero)
        for(int i = This_Zero, j = BN_2_Zero; i < this -> taken_coefficient; i++, j++){     //сравниваем коэфф. чисел, начиная с первого значащего коэфф (страрший значащий разряд)
            if(this -> integers[i] > BN_2.integers[j]) return 1;
            if(this -> integers[i] < BN_2.integers[j]) return -1;
        }   //цикл, пока разряд одного числа, не будет больше разряда другого
    return 0;
}

int Big_Number::Count_Zero() const {        //подсчет незначащих нулей
    for(int i = 0; i < all_coefficient; i++)
        if(integers[i] > 0) return i;
}

Big_Number Big_Number::operator+(const Big_Number &BN) {
    int max_size = max(taken_coefficient, BN.taken_coefficient);    //определяем размер наибольшего БЧ (большого числа)
    Big_Number Sum(2, max_size + 1);    //создаем новое БЧ с нужным размером, взятым с запасом
    int remains = 0;    //сюда запишем сумму коэфф. БЧ-ел
    for(int i = taken_coefficient-1, j = BN.taken_coefficient-1, k = max_size; k >= 0; i--, j--, k--) {
        int first_term = 0 , second_term = 0;   // сюда поподают коэфф. БЧ-ел
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
    cout << "first = " << *this << endl << "second = " << BN << endl;
    cout <<"all = " << all_coefficient << endl << "take = " << taken_coefficient << endl;
    int max_size = taken_coefficient;    //орпеделяем размер наибольшего БЧ
    Big_Number minuend = *this;     //переопределяем для ясности
    cout << "minuend1 = " << minuend << endl;
    Big_Number subtrahend;
    subtrahend = BN;
    Big_Number difference(2, max_size);     // БЧ под ответ
    for(int i = minuend.taken_coefficient - 1, j = subtrahend.taken_coefficient - 1; i >=0; i--, j--){
        int first = minuend.integers[i], second = 0;
        cout << "minuend2 = " << minuend << endl;

        if(j >= 0) second = subtrahend.integers[j];
        if(first < second) {        //если прийдется занять из след. разряда
            for (int k = i - 1, j = 0 ; k >= 0; k--) {
                cout << "minuend3 = " << minuend << endl;

                int next = minuend.integers[k]; // число, изначально на 1 разряд выше
                if (next == 0) j = k;
                if (next > 0) {     //если не 0, то занимаем
                    minuend.integers[k] -= 1;
                    first += pow(2,Base_size * 8);
                    cout << "minuend4 = " << minuend << endl;

                    for(int t = k-1; t >= j; t--){
                        minuend.integers[t] = pow(2, Base_size * 8) - 1; // если занимаем у 0 - присваеваем ему значение (основание - 1) и занимаем у след. разряда
                        cout << "minuend5 = " << minuend << endl;
                    }
                    cout << "minuend6 = " << minuend << endl;

                }
            }
        }
        difference.integers[i] = first - second;    //подсчет разности
    }
    cout <<"all = " << difference.all_coefficient << endl << "take = " << difference.taken_coefficient << endl;
    cout <<" - " << difference << endl;
    return difference;
    }

Big_Number Big_Number::operator*(int n) {
    int res = 0;        //переменная для промежуточного результата
    int term = 0;   // то, что перенесем в следующий разряд
    Big_Number Composition(2, taken_coefficient + 1);
    for(int i = taken_coefficient - 1; i >= 0; i--){
        int factor = integers[i];
        res = factor * n + term;    ///если не полюс, то по теоремам(проще), иначе: разлагаем в ряд Лорана и находим С(-1)
        Composition.integers[i + 1] = res;  // i + 1: так как в результате произведения размер БЧ может получиться больше на 1, записываеипромежуточный результат в соотвецтвующий разряд
       // cout << "BN_coeff = " << factor << endl;
       // cout << "n = " << n << endl;
       // cout << "result = " << res << endl;
        res >>= (Base_size * 8);        // сдвиг и последующая запись в следующий разряд
        Composition.integers[i] = res;
        term = Composition.integers[i];
       // cout << "remainder = " << term << endl;

    }
    return Composition;
}


Big_Number Big_Number::operator*(const Big_Number &BN) {
    int Comp_size = taken_coefficient + BN.taken_coefficient;   // максимальный возможный размер результата
    Big_Number Composition(2, Comp_size);
    for(int j = BN.taken_coefficient - 1; j >= 0; j--){     //движемся по одному из множетелей от млажшего разряда к старшему
        Big_Number Term(2, taken_coefficient + 1);  //создаем БЧ, для записи промежуточного результата
        int factor = BN.integers[j];    // коэфф. БЧ, на который будем умножать
        Term = *this * factor;  // умножение БЧ на коэфф. и запись промежуточного результата
        Term = Term << BN.taken_coefficient - 1 - j;    //сдвиг на соотвецтвующее место (в зависимости от разряда коэфф.) (перегрузка сдвига ниже)
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
    return * this;
}


Big_Number Big_Number::operator+=(const Big_Number &BN) {
    *this = *this + BN;
    return * this;
}

Big_Number Big_Number::operator/(int n) {
    Big_Number Quotient(2, taken_coefficient);
    int remainder = 0, use_coefficient = 0;
    for(int i = 0; i < taken_coefficient; i++){
        use_coefficient = integers[i] + (remainder << Base_size * 8);
        Quotient.integers[i] = use_coefficient / n;
        remainder = use_coefficient % n;
    }
    return Quotient;
}

int Big_Number::operator%(int n) {
    Big_Number Quotient(2, taken_coefficient);
    int remainder = 0, use_coefficient = 0;
    for(int i = 0; i < taken_coefficient; i++){
        use_coefficient = integers[i] + (remainder << Base_size * 8);
        Quotient.integers[i] = use_coefficient / n;
        remainder = use_coefficient % n;
    }
    return remainder;
}

Big_Number Big_Number::operator/( Big_Number &BN) {
    Big_Number Result(2, taken_coefficient), use_coefficient(2, taken_coefficient),
        remainder(2, BN.taken_coefficient);
    for(int i = 0; i < taken_coefficient; i ++){
        while(use_coefficient < BN){
            use_coefficient.Shift(1);
            cout << "1) " <<use_coefficient << endl;
            use_coefficient.integers[taken_coefficient - 1] += integers[i];
            i++;
            cout <<"2) " << use_coefficient << endl;
        }
        cout << "4" << endl;
        while(use_coefficient > BN){
            //cout << "5" << endl;
            cout << "use_coefficient = " << use_coefficient << endl << "BN = " << BN << endl;
            cout << (use_coefficient - BN);
            use_coefficient = use_coefficient - BN;
            cout << "BN = " << BN << endl;
            cout << "diff = " << use_coefficient << endl;
            Result.integers[i] += 1;
        }
        cout << "6" << endl;
        remainder = use_coefficient;
    }cout << "7" << endl;
    cout << Result;
}

Big_Number Big_Number::Shift(int n) {
    for(int i = all_coefficient - taken_coefficient - 1; i < all_coefficient ; i++){
        integers[i - 1] = integers[i];
        integers[i] = 0;
    }
    return *this;
}

        //BCB72920
        //a2d8


