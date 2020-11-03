#include <ostream>

class Fraction
{
    private:
        int nominator = 1;
        int denominator = 1;

    public:
        Fraction(); //domyslny konstruktor
        Fraction(int nominator, int denominator); //konstruktor argumentowy
        Fraction(const Fraction& source); //konstruktor kopiujacy

        Fraction& operator++();
        Fraction& operator--();

        //Dlaczego dajemy const na końcu? hmm i tak samo const Fraction& other - zapobiegnie to zmianie wartosci dla podanego Fraction?
        Fraction& operator=(const Fraction& source);
        bool operator==(const Fraction& other) const; //a w boolach?
        bool operator!=(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;

        Fraction operator+(const Fraction& other);
        Fraction operator-(const Fraction & other);
        Fraction operator*(const Fraction & other);
        Fraction operator/(const Fraction& other);


        //Greatest Common Divider - najwiekszy wsp dzielnik
        int GCD(int nom, int den);
        int get_nominator() const;
        int get_denominator() const;
        void set_nominator(int nominator);
        void set_denominator(int denominator);

        //friendly function
        friend std::ostream& operator<<(std::iostream& os, const Fraction& fraction);
};

std::ostream& operator<<(std::ostream& os, const Fraction& fraction);