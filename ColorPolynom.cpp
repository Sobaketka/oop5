#include "ColorPolynom.h"
using namespace std;

string code(const string& col) {
    if (col == "cyan") {
        return "\033[0;36m";
    }
    if (col == "magenta") {
        return "\033[0;35m";
    }
    if (col == "yellow") {
        return "\033[0;33m";
    }
    if (col == "green") {
        return "\033[0;32m";
    }
    if (col == "blue") {
        return "\033[0;34m";
    }
    if (col == "red") {
        return "\033[0;31m";
    }
    return "";
}

ColorPolynom::ColorPolynom(): Polynom() {
    color = "white";
    cout<< "default CP constructor" << endl;
}

ColorPolynom::ColorPolynom(const double* coefs, int size, string c):Polynom(coefs, size) {
    color = c;
    cout<<"CP constructor" << endl;
};

ColorPolynom::ColorPolynom(const ColorPolynom& two):Polynom(two) {
    color = two.color;
    cout<<"CP copy constructor" << endl;
}

ColorPolynom::~ColorPolynom() {
    cout<<"CP destructor" << endl;
}

ColorPolynom& ColorPolynom::operator=(const ColorPolynom& two) {
    Polynom::operator=(two);
    color = two.color;
    return *this;
}

ColorPolynom ColorPolynom::operator++(int) {
    ColorPolynom old(*this);
    double *temp = new double[n+1];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i];
    }
    temp[n] = 1;
    delete[] a;
    a = temp;
    n++;
    return old;
}

ColorPolynom ColorPolynom::operator--(int) {
    ColorPolynom old(*this);
    if (n > 1) {
        double *temp = new double[n-1];
        for (int i = 0; i  < n - 1; i++) {
            temp[i] = a[i];
        }
        delete [] a;
        a = temp;
        n--;
    }

    return old;
}

double& ColorPolynom::operator[](int i) {
    return a[i];
}

ostream&operator<<(ostream& os, const ColorPolynom& p) {
    os << code(p.color) << p.a[0];
    for (int i = 1; i < p.n; i++) {
        if (p.a[i] < 0) {
            os << "-" << -p.a[i];
        }
        else {
            os << "+" << p.a[i];
        }
        os << "*x^" << i;
    }
    os << "\033[0m";
    return os;
}

void ColorPolynom::setColor(string c) {
    color = c;
}

string ColorPolynom::getColor()const {
    return color;
}

ColorPolynom ColorPolynom::copy() const {
    return ColorPolynom(*this);
}

void ColorPolynom::input() {
    Polynom::input();
    cout<<"Choose color-> cyan, magenta, yellow, green, blue, red: ";
    cin >> color;
}

void ColorPolynom::output()const {
    cout << code(color) << endl;
    Polynom::output();
    cout<< "\033[0m";
}

void ColorPolynom::print()const {
    cout << *this << endl;
}

ColorPolynom ColorPolynom::integral() const {
    double *temp = new double[n + 1];
    temp[0] = 0;
    for (int i = 0; i < n; i++) {
        temp [i + 1] = a[i] / (i + 1);
    }

    ColorPolynom res(temp, n+1, color);
    delete[] temp;
    return res;
}
