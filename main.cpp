#include "iostream"
#include <stdio.h>
#include "fraction.h"


int main()
{
    Fraction f1(-2,2), f3(-2,-3);
    Fraction x(1,1);

    std::cout << "Testy wypisania oraz geterow " << std::endl;
    std::cout << "f1: " << f1 << std::endl << "f3: " << f3 << std::endl;
    std::cout << "Ulamek f1: " << f1.get_nominator() << "/" << f1.get_denominator() << std::endl;
    std::cout << "Ulamek f3: " << f3.get_nominator() << "/" << f3.get_denominator() << std::endl;
    
    std::cout << "Testy kontruktora (wszystkie mozliwosci) glownie sprawdzenie jesli mianownik < 0 " << std::endl;
    Fraction t1(-1,7), t2(-1,-8), t3(2,9), t4(4,-9);
    std::cout << t1 << std::endl << t2 << std::endl << t3 << std::endl << t4 << std::endl;

    std::cout<< "Funkcje arytmetyczne" << std::endl;
    std::cout << f1 << " + " << f3 << " = " << f1 + f3 << std::endl;
    std::cout << f1 << " - " << f3 << " = " << f1 - f3 << std::endl;
    std::cout << f1 << " * " << f3 << " = " << f1 * f3 << std::endl;
    std::cout << f1 << " / " << f3 << " = " << f1 / f3 << std::endl;
    
    std::cout << "Porównywanie 1 - True, 0 - False" << std::endl;
    std::cout << "Ulamek przed przypisaniem innych wartosci " << x << std::endl;
    x = f1; 
    std::cout << "Po przypisaniu " << x << std::endl;
    std::cout << f1 << " == " << f3 << " : " << (f1 == f3) << std::endl;
    std::cout << f1 << " < " << f3 << " : " << (f1 < f3) << std::endl;
    std::cout << f1 << " >= " << f3 << " : " << (f1 >= f3) << std::endl;
    std::cout << f1 << " > " << f3 << " : " << (f1 > f3) << std::endl;
    std::cout << f1 << " <= " << f3 << " : " << (f1 <= f3) << std::endl;

    std::cout << "Inkrementacja, dekrementacja" << std::endl;
    std::cout << "Ulamek przez inkrementacją " << f1 << std::endl;
    //blad f1++;
    std::cout << "Ulamek po inkrementacji " << f1 << std::endl; 
    std::cout << "Ulamek przez dekrementacją " << f1 << std::endl;
    //blad f1--;
    std::cout << "Ulamek po dekrementacji " << f1 << std::endl; 

    return 0;
}