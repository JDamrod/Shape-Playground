#include <iostream>

using namespace std;

class Rectangle {
private:
    int a, b;
public:
    Rectangle(int a_, int b_) : a(a_), b(b_) {}
    ~Rectangle() {}
    void rysowac()
    {
          for (int i = 0; i < b; ++i)
          {
              for (int j = 0; j < a; ++j)
              {
                  cout << "*";
              }
              cout << endl;
          }
    }
     Rectangle operator+(const Rectangle& other) {
        return Rectangle(this->a + other.a, this->b + other.b);
    }
};

class Square : public Rectangle {
public:
    Square(int strona) : Rectangle(strona, strona) {}
};

class Ksiazka {
private:
    int *przypisy;
    char *autor;
    char *tytul;
    int cena;
    int rokWyd;
public:
    Ksizka() {przypisy=new int[10]; autor = new char [255]; tytul = new char [256]; cena=55; rokWyd=2017; }
    ~Ksiazka() { delete[] przypisy; delete[] autor; delete[] tytul; }
};

class A {
protected:
    int* px, *pz;
public:
    A (int x) {px=new int; *px=x; pz = new int[3];
    for (int i = 0; i < 3; ++i)
        {
            pz[i] = x-i;
        }
    }
    ~A() { delete px; delete[] pz;}

     A(const A& other) {
        px = new int(*other.px);
        pz = new int[3];
        for (int i = 0; i < 3; ++i) {
            pz[i] = other.pz[i];
        }
    }

     A& operator=(const A& other) {
        if (this != &other) {
            delete px;
            delete[] pz;

            px = new int(*other.px);
            pz = new int[3];
            for (int i = 0; i < 3; ++i) {
                pz[i] = other.pz[i];
            }
        }
        return *this;
    }

    void pokaz() {
        cout << "px = " << *px << endl;
        cout << "pz = ";
        for (int i = 0; i < 3; ++i) {
            cout << pz[i] << " ";
        }
        cout << endl << endl;
    }
};

class B : public A {
public:
    B(int x) : A(x) {
        for (int i = 0; i < 3; ++i) {
            set_pz(i, x + 5 + i);
        }
    }

    void set_pz(int indeks, int wartosc);
};

void B::set_pz(int indeks, int wartosc) {
    if (indeks >= 0 && indeks < 3) {
        pz[indeks] = wartosc;
    }
}

int main()
{

    Rectangle prostokat1(2, 4);
    Rectangle prostokat2(4, 2);

    Rectangle* p1 = new Rectangle(3, 6);
    Rectangle* p2 = new Rectangle(5, 2);

    cout << "ZADANIE 1:" << endl << endl;
    cout << "P1" << endl;
    p1->rysowac();

    cout << "__________________________" << endl << endl;

    cout << "P2:" << endl;
    p2->rysowac();

    cout << "__________________________" << endl << endl;

    cout << "Prostokat1:" << endl;
    prostokat1.rysowac();

    cout << "__________________________" << endl << endl;

    cout << "Prostokat2:" << endl;
    prostokat2.rysowac();


    cout << "__________________________" << endl << endl;

    Rectangle p3 = *p1 + *p2;

    cout << "R3 = R1 + R2:" << endl;
    p3.rysowac();

    cout << "__________________________" << endl << endl;

    Square pr(4);
    cout << "Square:" << endl << endl;
    pr.rysowac();
    cout << "__________________________" << endl << endl;

    delete p1;
    delete p2;


    cout << "ZADANIE 3:" << endl << endl;
    A a1(20);
    A a2 = a1;

    A a3(4);
    a3 = a1;

    cout << "a1:" << endl << endl;
    a1.pokaz();
    cout << "---------" << endl << endl;

    cout << "a2 (z konstruktor kopiujacy):" << endl << endl;
    a2.pokaz();
    cout << "---------" << endl << endl;

    cout << "a3 (operator przypisania):" << endl << endl;
    a3.pokaz();

    cout << "---------" << endl << endl;

    cout << "ZADANIE 4: " << endl << endl;

    B b1(10);
    cout << "b1:" << endl;
    b1.pokaz();

    return 0;
}
