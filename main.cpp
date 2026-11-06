#include <iostream>
#include "ColorPolynom.h"
using namespace std;

int main() {
    double c[] = {1, 2, 3};
    ColorPolynom p(c, 3, "blue");
    ColorPolynom original = p.copy();
    p.print();

    cout << "setting color" << endl;
    p.setColor("cyan");
    string color = p.getColor();
    cout << "color = " << color << endl;
    p.output();

    cout << "copy->" << endl;
    ColorPolynom a = p.copy();
    a.setColor("red");
    cout << "p = " << p << endl;
    cout << "a = " << a << endl;

    p++;
    cout << "p++ = " << p << endl;

    p--;
    cout << "p-- = " << p << endl;
    p--;
    cout << "p-- = " << p << endl;

    p[0] = 7;
    cout << "p[0] = " << p[0] << endl;
    cout << "p = " << p << endl;

    ColorPolynom integr = a.integral();
    cout << "integral = " << integr << endl;

    ColorPolynom p2;
    p2.input();
    p2.output();

    cout << "p = " << original << endl;
    double y = original.value();
    cout << "p(y) = " << y << endl;

    return 0;
}