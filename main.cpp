#include <iostream>
#include "ColorPolynom.h"
using namespace std;

int main() {
    double c[] = {2, 3, 5};
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
    cout << "a = " << a << endl;

    cout << "Postfics" << endl;
    ColorPolynom p1;
    cout << "p = " << p << endl;
    cout << "p1 = " << p1 << endl;
    p1 = p++;
    cout << "p = " << p << endl;
    cout << "p1 = " << p1 << endl;

    ColorPolynom p2;
    cout << "p = " << original << endl;
    cout << "p2= " << p2 << endl;
    p2 = p--;
    cout << "p = " << original << endl;
    cout << "p2 = " << p2 << endl;

    cout << "Prefics" << endl;
    ColorPolynom p3;
    cout << "p = " << original << endl;
    cout << "p3 = " << p3 << endl;
    p3 = ++original;
    cout << "p = " << original << endl;
    cout << "p3 = " << p3 << endl;

    ColorPolynom p4;
    cout << "p = " << original << endl;
    cout << "p4 = " << p4 << endl;
    p4 = --original;
    cout << "p = " << original << endl;
    cout << "p4 = " << p4 << endl;


    p[0] = 7;
    cout << "p[0] = " << p[0] << endl;
    cout << "p = " << p << endl;

    ColorPolynom integr = a.integral();
    cout << "integral = " << integr << endl;

    ColorPolynom p5;
    p5.input();
    p5.output();
    cout << "p5[1] =" << p5[1] << endl;

    cout << "p = " << original << endl;
    double y = original.value();
    cout << "p(y) = " << y << endl;

    ColorPolynom p6;
    p6.output();




    return 0;
}