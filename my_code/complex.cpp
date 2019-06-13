#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
	return (c1.get_real() == c2.get_real()) && (c1.get_imag() == c2.get_imag());
	//return (abs(c1.get_real() - c2.get_real()) < 0.001) && (abs(c1.get_imag() - c2.get_imag()) < 0.001);  // temp!
}

bool operator!= (const Complex& c1, const Complex& c2) {
	return c1.get_real() == c2.get_real() && c1.get_imag() == c2.get_imag();  // temp!
}


Complex::Complex(double real, double imag) : real(real), imag(imag) {}

ostream& operator<< (ostream& os, const Complex& c) {
	/*
	 * Outputting a `Complex` instance, while illustrating some of the
	 * capabilities of I/O streams: `setprecision` gives us a fixed
	 * number of decimal places, while `showpos` turns on the plus
	 * sign for positive numbers.
	 * */
	os << c.real;
	if (c.imag >= 0) os << '+';
	os << c.imag << 'i';
	return os;
}

/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
	cin >> c.real >> c.imag;
	return is;
}


Complex::operator bool() const {
	return(real != 0);
}

Complex& Complex::operator++() {
	++real;
	return (*this);
}

Complex Complex::operator++(int dummy) {
	Complex original(*this);
	++real;
	return original;
}

Complex& Complex::operator--() {
	--real;
	return (*this);
}

Complex Complex::operator--(int dummy) {
	Complex original(*this);
	--real;
	return original;
}

Complex Complex::operator-=(const Complex& c) {
	real -= c.get_real();
	imag -= c.get_imag();
	return *this;
}

Complex operator+(const Complex& c1, const Complex& c2) {
	Complex result(c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag());
	return result;
}

Complex operator-(const Complex& c1, const Complex& c2) {
	Complex result(c1.get_real() - c2.get_real(), c1.get_imag() - c2.get_imag());
	return result;
}


double Complex::get_real() const {
	return real;
}

double Complex::get_imag() const {
	return imag;
}

Complex Complex::operator*(const int i) {
	Complex prod(real * i, imag * i);
	return prod;
}