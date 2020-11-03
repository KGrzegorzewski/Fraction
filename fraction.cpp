#include <iostream>
#include "fraction.h"

Fraction::Fraction()
{
    nominator = 1;
    denominator = 1;
}

Fraction::Fraction(int nominator, int denominator)
{
    if (denominator == 0)
    {
        throw std::overflow_error("Divide by zero exception");
    }
    else
    {   
        if (denominator < 0)
        {
            nominator *= -1;
            denominator *= -1;
        }
        this -> nominator = nominator;
        this -> denominator = denominator;
    }  
}
Fraction::Fraction(const Fraction& source)
{
    this -> nominator = source.nominator; //lub nominator = source.nominator;
    this -> denominator = source.denominator; //j.w.
}

Fraction& Fraction::operator=(const Fraction& source)
{
    if(this != &source)
    {
        nominator = source.nominator;
        denominator = source.denominator;
    }
    return *this;
}

bool Fraction::operator==(const Fraction& other) const
{
    return (nominator * other.denominator == denominator * other.nominator);
}

bool Fraction::operator!=(const Fraction& other) const
{
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const
{
    return (nominator * other.denominator < denominator * other.nominator);
}

bool Fraction::operator>=(const Fraction& other) const
{
    return !(*this < other);
}

bool Fraction::operator>(const Fraction& other) const
{
    return (nominator * other.denominator > denominator * other.nominator);
}

bool Fraction::operator<=(const Fraction& other) const
{
    return !(*this > other);
}

//Funkcje arytmetyczne zwracające obiekt Fraction
Fraction Fraction::operator+(const Fraction& other)
{
    int new_nom = nominator * other.denominator + other.nominator * denominator;
    int new_den = denominator * other.denominator;

    return Fraction(new_nom / GCD(new_nom, new_den), new_den / GCD(new_nom, new_den));
}

Fraction Fraction::operator-(const Fraction& other)
{
    int new_nom = nominator * other.denominator - other.nominator * denominator;
    int new_den = denominator * other.denominator;

    return Fraction(new_nom / GCD(new_nom, new_den), new_den / GCD(new_nom, new_den));
}

Fraction Fraction::operator*(const Fraction& other)
{
    int new_nom = nominator * other.nominator;
    int new_den = denominator * other.denominator;

    return Fraction(new_nom / GCD(new_nom, new_den), new_den / GCD(new_nom, new_den));
}

Fraction Fraction::operator/(const Fraction& other)
{
    int new_nom = nominator * other.denominator;
    int new_den = denominator * other.nominator;

    return Fraction(new_nom / GCD(new_nom, new_den), new_den / GCD(new_nom, new_den));
}

//Inkrementacja zrealizowana za pomocą inkrementacji wartości licznik danego ułamka

Fraction& Fraction::operator++()
{
    nominator++;
    return *this;
}

Fraction& Fraction::operator--()
{
    nominator--;
    return *this;
}


//Gettery i settery
int Fraction::get_nominator() const
{
    return nominator;
}

int Fraction::get_denominator() const
{
    return denominator;
}

void Fraction::set_nominator(int nominator)
{
    this -> nominator = nominator;
}

void Fraction::set_denominator(int denominator)
{
    if (denominator == 0)
    {
        throw std::overflow_error("Divide by zero exception");
    }
    else 
    {
        this -> denominator = denominator;
    }
}

//Do skrocenia ulamkow, algorytm Euklidesa
int Fraction::GCD(int nom, int den)
{
    if (nom == 0)
        return den;
    return GCD(den % nom, nom);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
    //os << fraction.nominator << "/" << fraction.denominator;  hmm funkcja zaprzyjazniona nie moze korzystac z prywatnych pol klasy ??
    os << fraction.get_nominator() << "/" << fraction.get_denominator();
    return os;
}