#include <iostream>
#include "compl.hpp"

int main() {
    complex<double> x(1, 2);    // 1 + 2i
    x.display();

    complex<double> y(3, 4);    // 3 + 4i
    y.display();

    complex<double> z = x + y;  // 4 + 6i
    z.display();

    complex<double> a = y - x;  // 2 + 2i
    a.display();

    complex<double> b = x * y;  // -5 + 10i
    b.display();

    complex<double> d = y / x;  // 2.2 - 0.4i
    d.display();

    complex<double> e;

    return 0;
}
