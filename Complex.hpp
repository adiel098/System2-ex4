#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the equality operator
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Overload the not equal operator
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Overload the stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << "+" << c.imag << "i";
        return os;
    }
};

#endif // COMPLEX
