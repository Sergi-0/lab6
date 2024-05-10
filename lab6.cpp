#include <iostream>
using namespace std;

class exeption : public invalid_argument { // класс исключение, потомок класса invalid_argument

public:
    int t; // число

    exeption(const char* er,int j): invalid_argument(er) // конструктор класса
    {
        t = j;
    }

    void print() { // метод вывода числа
    cout << t;
    }
};

class pr_ch { // класс простое число
public:
    int a;
    pr_ch(); // нулевой конструктор
    pr_ch(int b); // конструктор с параметрами
    void print(); // метод print
};

pr_ch::pr_ch() {
    a = 0;
}

pr_ch::pr_ch(int b) {
    int k = 0;
    for (int i = 2; i<= floor(sqrt(b)); ++i) if (b % i == 0) ++k; // подсчет количества делителей число
    if (k > 0) throw exeption("Ошибка",b); // если k > 0, то есть делителей больше двух, то создается класс исключения и ссылку на него выбрасывает throw, если throw срабатывает, программа в конструкторе дальше не идет
    a = b;
}

void pr_ch::print() {
    cout << a;
}


int main()
{
    setlocale(LC_ALL, "Rus"); // вывод в консоль на русском
    try{ // блок контроля
        pr_ch obj(14);
        obj.print();
    }
    
    catch (exeption& e) { // блок обработки исключения
        e.print();
        cout << endl;
        cout << e.what(); // what единственный метод класса invalid_argument, он служит для вывода сообщения об ошибке
    }
}
