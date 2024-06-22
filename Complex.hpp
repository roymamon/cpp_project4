#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>
#include <cmath>

//email: mamon8521@gmail.com
//ID: 322623323

class Complex {
private:
    double real;
    double imag;

public:
    // constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // getters
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // operations
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    
    bool operator==(const Complex& other) const {
        return std::abs(real - other.real) < 1e-9 && std::abs(imag - other.imag) < 1e-9;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // tostring
    std::string toString() const {
        std::ostringstream oss;
        oss << real;
        if (imag >= 0) oss << "+";
        oss << imag << "i";
        return oss.str();
    }

    // stream <<
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.toString();
        return os;
    }
};

#endif 
