#include "Polynom.h"
using namespace std;

int Polynom::count = 0;
double Polynom::point = 2;

Polynom::Polynom() {
    n = 1;
    a = new double[n];
    a[0] = 0;
    count++;
    cout << "Default constructor" << endl;
}

Polynom::Polynom(int size) {
    n = size;
    a = new double[n];
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
    count++;
    cout << "Size constructor" << endl;
}

Polynom::Polynom(const double* coefs, int size) {
    n = size;
    a = new double[n];
    for (int i = 0; i < n; i++) {
        a[i] = coefs[i];
    }
    count++;
    cout << "Constructor of massive" << endl;
}

Polynom::Polynom(double x, double f) {
    n = 2;
    a = new double[n];
    a[0] = x;
    a[1] = f;
    count++;
    cout << "Constructor of odn" << endl;
}

Polynom::Polynom(const Polynom& other) {
    n = other.n;
    a = new double[n];
    for (int i = 0; i < n; i++) {
        a[i] = other.a[i];
    }
    count++;
    cout << "Copy constructor" << endl;
}

Polynom::~Polynom() {
    delete[] a;
    count--;
    cout << "Destructor" << endl;
}

Polynom& Polynom::operator=(const Polynom& other) {
    cout << "Assignment operator" << endl;
    if (this != &other) {
        delete[] a;
        n = other.n;
        a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = other.a[i];
        }
    }
    return *this;
}

void Polynom::input() {
    cout << "Enter n: ";
    cin >> n;
    delete[] a;
    a = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "a" << i << " = ";
        cin >> a[i];
    }
}

void Polynom::output() const {
    cout << a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < 0) {
            cout << " - " << -a[i];
        } else {
            cout << " + " << a[i];
        }
        cout << "*x^" << i;
    }
    cout << endl;
}

int Polynom::getCount() {
    return count;
}

double Polynom::getPoint() {
    return point;
}

Polynom Polynom::copy() const {
    return Polynom(*this);
}

double Polynom::value() const {
    double sum = 0;
    double st = 1;
    for (int i = 0; i < n; i++) {
        sum = sum + a[i] * st;
        st = st * point;
    }
    return sum;
}

Polynom Polynom::derivative() const {
    if (n == 1)
        return Polynom(1);

    Polynom d(n - 1);
    for (int i = 1; i < n; i++) {
        d.a[i - 1] = i * a[i];
    }
    return d;
}

Polynom Polynom::mulXminusB(double b) const {
    Polynom t(-b, 1);
    return t * (*this);
}



Polynom Polynom::shift(double b) const {
    Polynom t(b, 1);
    return (*this)(t);
}


Polynom operator+(const Polynom& p, const Polynom& q) {
    int m = p.n;
    if (q.n > m) {
        m = q.n;
    }
    Polynom r(m);
    for (int i = 0; i < p.n; i++) {
        r.a[i] += p.a[i];
    }
    for (int i = 0; i < q.n; i++) {
        r.a[i] += q.a[i];
    }
    return r;
}

Polynom operator-(const Polynom& p, const Polynom& q) {
    int m = p.n;
    if (q.n > m) {
        m = q.n;
    }
    Polynom r(m);
    for (int i = 0; i < p.n; i++) {
        r.a[i] += p.a[i];
    }
    for (int i = 0; i < q.n; i++) {
        r.a[i] -= q.a[i];
    }
    return r;
}

Polynom Polynom::operator*(const Polynom& o) const {
    Polynom r(n + o.n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < o.n; j++) {
            r.a[i + j] += a[i] * o.a[j];
        }
    }
    return r;
}

Polynom Polynom::operator()(const Polynom& q) const {
    Polynom res(1);
    for (int i = n - 1; i >= 0; i--) {
        Polynom c(&a[i], 1);
        res = res * q + c;
    }
    return res;
}

void divide(const Polynom& p, const Polynom& d, Polynom& q, Polynom& r) {
    if (p.n < d.n) {
        q = Polynom(1);
        r = p;
        return;
    }

    Polynom t(p);
    Polynom res(p.n - d.n + 1);
    for (int k = res.n - 1; k >= 0; k--) {
        res.a[k] = t.a[k + d.n - 1] / d.a[d.n - 1];
        for (int j = 0; j < d.n; j++) {
            t.a[k + j] -= res.a[k] * d.a[j];
        }
    }
    q = res;
    r = p - res * d;
}
