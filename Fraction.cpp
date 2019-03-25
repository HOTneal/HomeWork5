
#include "pch.h"
#include <iostream>

using namespace std;

class Fraction
{
public:
	Fraction();
	Fraction(int, int);
	Fraction(const Fraction&);

	~Fraction() {}

	void SetFraction();
	void GetFraction() { std::cout << numerator << '/' << denominator << std::endl; }

	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	bool operator==(const Fraction&);

private:
	int numerator;
	int denominator;
};


Fraction::Fraction() :
	numerator(0), denominator(0)
{}

Fraction::Fraction(int _num, int _denom) :
	numerator(_num), denominator(_denom)
{}

Fraction::Fraction(const Fraction& rhs)
{
	this->numerator = rhs.numerator;
	this->denominator = rhs.denominator;
}

void Fraction::SetFraction()
{
	cout << "Enter numerator: ";
	cin >> numerator;

	cout << "Enter denominator: ";
	cin >> denominator;
}

Fraction Fraction::operator+(const Fraction& rhs)
{
	Fraction temp;

	temp.numerator = this->numerator + rhs.numerator;
	temp.denominator = this->denominator + rhs.denominator;

	return temp;
}

Fraction Fraction::operator-(const Fraction& rhs)
{
	Fraction temp;

	temp.numerator = this->numerator - rhs.numerator;
	temp.denominator = this->denominator - rhs.denominator;

	return temp;
}

Fraction Fraction::operator*(const Fraction& rhs)
{
	Fraction temp;

	temp.numerator = this->numerator * rhs.numerator;
	temp.denominator = this->denominator * rhs.denominator;

	return temp;
}

bool Fraction::operator==(const Fraction& rhs)
{
	return ((this->numerator + this->denominator) == (rhs.numerator + rhs.denominator)) ? true : false;
}

void Plus(Fraction Frac1, Fraction Frac2) {

	Fraction Result = Frac1 + Frac2;

	cout << "\nPlus = ";
	Result.GetFraction();
}

void Minus(Fraction Frac1, Fraction Frac2) {

	Fraction Result = Frac1 - Frac2;

	cout << "\nMinus = ";
	Result.GetFraction();
}

void Multiply(Fraction Frac1, Fraction Frac2) {

	Fraction Result = Frac1 * Frac2;

	cout << "\nMultiply = ";
	Result.GetFraction();
}

void Comparison(Fraction Frac1, Fraction Frac2) {

	bool comparison = Frac1 == Frac2;

	cout << "\nComparison = " << comparison << endl;
}

int main()
{
	Fraction Frac1;
	cout << "Fraction1 \n";
	Frac1.SetFraction();

	Fraction Frac2;
	cout << "Fraction2 \n";
	Frac2.SetFraction();

	Plus(Frac1, Frac2); //сложение
	Minus(Frac1, Frac2); //вычитание
	Multiply(Frac1, Frac2); //умножение
	Comparison(Frac1, Frac2); //сравнение
}