#include <iostream>
#include "compl.hpp"

int main() {
    complex<double> x(5, -3);
    complex<double> y = x;
    complex<double> z(x);
    x.display();
    y.display();
    z.display();

    complex<double> a(std::move(x));
    
    x.display();
    a.display();


    return 0;
}