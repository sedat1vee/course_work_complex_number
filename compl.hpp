#include <iostream>
#include <cmath>

template <typename T>
class complex {
private:
    T real;
    T imag;

public:
    complex();                             // Конструктор за замовчуванням
    complex(const T r, const T i);        // Конструктор з параметрами
    complex(const complex& other);          // Конструктор копіювання
    complex(complex&& other);      // Конструктор переміщення
    ~complex();                             // Деструктор

    // Арифметика
    complex<T> operator=(const complex<T> other);         // Оператор =
    complex<T> operator+(const complex<T> other) const;    // Оператор +
    complex<T> operator-(const complex<T> other) const;    // Оператор -
    complex<T> operator*(const complex<T> other) const;    // Оператор *
    complex<T> operator/(const complex<T> other) const;    // Оператор /

    // Модуль
    T abs() const;

    // Вивід
    void display() const;
};


template <typename T>
complex<T>::complex() : real(0), imag(0) {} // якщо не задані значення, створиться об'єкт зі значенням 0 + 0i

template <typename T>
complex<T>::complex(const T r, const T i) : real(r), imag(i) {} // створюється об'єкт та в нього заносяться значення r та i типу T

template <typename T>
complex<T>::complex(const complex& other)
    : real(other.real), imag(other.imag) {} // створюється об'єкт та в нього заносяться значення іншого об'єкта

template <typename T>
complex<T>::complex(complex&& other)
    : real(other.real), imag(other.imag) // переміщуємо значення
{
    // Обнуляємо джерело
    other.real = 0;
    other.imag = 0;
}

template <typename T>
complex<T>::~complex() {}

template <typename T>
complex<T> complex<T>::operator=(const complex<T> other) { // перевантаження оператора =
    real = other.real; // присвоюємо значення
    imag = other.imag;
    return *this; // повертаємо об'єкт
}

template <typename T>
complex<T> complex<T>::operator+(const complex<T> other) const { // перевантаження оператора +
    return complex<T>(real + other.real, imag + other.imag); // додавання окремо дійсної та уявної частин
}

template <typename T>
complex<T> complex<T>::operator-(const complex<T> other) const { // перевантаження оператора -
    return complex<T>(real - other.real, imag - other.imag); // віднімання окремо дійсної та уявної частин
}

template <typename T>
complex<T> complex<T>::operator*(const complex<T> other) const { // перевантаження оператора *
    return complex<T>(                          // a + bi та c + di
        real * other.real - imag * other.imag,  // дійсна частина виконується по формулі a*c - b*d
        real * other.imag + imag * other.real   // уявна частина виконується по формулі a*d + b*c
    );
}

template <typename T>                                               
complex<T> complex<T>::operator/(const complex<T> other) const {   // перевантаження оператора /
    T d = other.real * other.real + other.imag * other.imag;        
    return complex<T>(
        (real * other.real + imag * other.imag) / d,
        (imag * other.real - real * other.imag) / d
    );
}
/*
a + bi та c + di

Ділення відбувається за формулами:
дійсна частина = (a*c - b*d)/(c**2 + d**2)
уявна частина = (c*b - a*d)/(c**2 +d**2)
*/


template <typename T>
T complex<T>::abs() const {                         // метод abs
    return std::sqrt(real * real + imag * imag);    // рахує модуль комплексного числа за формулою: sqrt(a**2 + b**2)
}

template <typename T>
void complex<T>::display() const {                      // метод display
    if(imag < 0)                                        // запобігає виведенню комлпексного числа виду: 5 + -4i
        std::cout << real << " - " << -imag << "i\n\n";
    else
        std::cout << real << " + " << imag << "i\n\n";
}