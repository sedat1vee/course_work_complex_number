#include <iostream>
#include "compl.hpp"

int main() {
    complex<double> x(7, 12);
    complex<double> y(-3, 5);
    complex<double> z;
    complex<double> a;
    complex<double> b;
    complex<double> c;
    double e;

    z = x + y;
    a = x - y;
    b = a * z;
    c = b / y;
    e = c.abs();

    x.display();
    y.display();
    z.display();
    a.display();
    b.display();
    c.display();
    std::cout << e;

    return 0;
}
