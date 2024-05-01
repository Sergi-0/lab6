#include <iostream>
using namespace std;

class exeption : public invalid_argument {

public:
    int t;

    exeption(const char* er,int j): invalid_argument(er)
    {
        t = j;
    }

    void print() {
    cout << t;
    }
};

class pr_ch {
public:
    int a;
    pr_ch();
    pr_ch(int b);
    void print();
};

pr_ch::pr_ch() {
    a = 0;
}

pr_ch::pr_ch(int b) {
    int k = 0;
    for (int i = 2; i<= floor(sqrt(b)); ++i) if (b % i == 0) ++k;
    if (k > 0) throw exeption("Ошибка",b);
    a = b;
}

void pr_ch::print() {
    cout << a;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    try{
        pr_ch obj(14);
        obj.print();
    }
    
    catch (exeption& e) {
        e.print();
        cout << endl;
        cout << e.what();
    }
}
