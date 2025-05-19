#include <iostream>
using namespace std;

// ======= Ієрархія БЕЗ virtual =======
class A {
public:
    int a;
};

class B : public A {
public:
    int b;
};

class C : public A {
public:
    int c;
};

class D : public B {
public:
    int d;
};

class E : public C {
public:
    int e;
};

class F : public D, public E {
public:
    int f;
};

// ======= Ієрархія З virtual =======
class AV {
public:
    int a;
};

class BV : virtual public AV {
public:
    int b;
};

class CV : virtual public AV {
public:
    int c;
};

class DV : public BV {
public:
    int d;
};

class EV : public CV {
public:
    int e;
};

class FV : public DV, public EV {
public:
    int f;
};

int main() {
    F obj1;
    FV obj2;

    cout << "Ієрархія БЕЗ virtual:" << endl;
    cout << "Розмір об'єкта F: " << sizeof(F) << " байт" << endl;

    cout << "\nІєрархія З virtual:" << endl;
    cout << "Розмір об'єкта FV: " << sizeof(FV) << " байт" << endl;

    return 0;
}
