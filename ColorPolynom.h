#ifndef OOP5_COLORPOLYNOM_H
#define OOP5_COLORPOLYNOM_H

#include "Polynom.h"
#include <string>
#include <iostream>

class ColorPolynom: public Polynom {
std::string color;

public:
    ColorPolynom();
    ColorPolynom(const double* coefs, int size, std::string c);
    ColorPolynom(const ColorPolynom& two);
    ~ColorPolynom();
    ColorPolynom& operator=(const ColorPolynom& two);
    ColorPolynom operator++(int);
    ColorPolynom operator--(int);
    double& operator[](int i);
    friend std::ostream& operator<<(std::ostream& os, const ColorPolynom& p);
    void setColor(std::string c);
    std::string getColor() const;
    ColorPolynom copy() const;
    void input();
    void output()const;
    void print()const;
    ColorPolynom integral() const;

};


#endif //OOP5_COLORPOLYNOM_H
