#include <iostream>
#include <string>

using namespace std;


class Fraction {
private:
    int numerator; 
    int denominator;

public:
    Fraction(int n, int d) : numerator(n), denominator(d) {
        if(d == 0)
            throw "Деление на нуль невозможно!";
    }
    
   static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }


    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction operator+(const Fraction& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        int c = gcd(newNumerator, newDenominator);
        newNumerator = newNumerator / c;
        newDenominator = newDenominator / c;

        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        int c = gcd(newNumerator, newDenominator);
        newNumerator = newNumerator / c;
        newDenominator = newDenominator / c;

        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        int c = gcd(newNumerator, newDenominator);
        newNumerator = newNumerator / c;
        newDenominator = newDenominator / c;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction& other) const {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        int c = gcd(newNumerator, newDenominator);
        newNumerator = newNumerator / c;
        newDenominator = newDenominator / c;
        return Fraction(newNumerator, newDenominator);
    }



    double Decimal() const {
        return static_cast<double>(numerator) / static_cast<double>(denominator);
    }

    Fraction inverse() const {
        return Fraction(denominator, numerator);
    }
};
    
 int main()
{
     try {
         
         setlocale(LC_ALL, "Rus");
         int a;
         int b;
         int c;
         int d;
         char operation;
         std::string reply1;
         std::cout << "Введите числитель первой дроби" << std::endl;
         std::cin >> a;
         std::cout << "Введите знаменатель первой дроби" << std::endl;
         std::cin >> b;
         std::cout << "Вам нужна вторая дробь? Введите 'Yes' или 'No'" << std::endl;
         std::cin >> reply1;
         if (reply1 == "Yes")
         {
             std::cout << "Введите числитель второй дроби" << std::endl;
             std::cin >> c;
             std::cout << "Введите знаменатель второй дроби" << std::endl;
             std::cin >> d;
             cout << "Введите операцию (+, -, *, /) " << std::endl;
             cin >> operation;
             Fraction r1(a, b);
             Fraction r2(c, d);
             Fraction f3(c, d);
             switch (operation) {
             case '+':
                 f3 = r1 + r2;
                 std::cout << "Результат: " << f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
                 break;
             case '-':
                 f3 = r1 - r2;
                 std::cout << "Результат: " << f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
                 break;
             case '*':
                 f3 = r1 * r2;
                 std::cout << "Результат: " << f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
                 break;
             case '/':
                 f3 = r1 / r2;
                 std::cout << "Результат: " << f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
                 break;
             default:
                 cout << "Неверная операция." << endl;
             }
         }
         else
         {
             cout << "Введите операцию (#-Десятичная дробь,-1-Обратная дробь): " << std::endl;
             cin >> operation;
             Fraction r1(a, b);
             double f3;
             switch (operation) {
             case '#':
                 f3 = r1.Decimal();
                 std::cout << "Результат: " << f3 << std::endl;
                 break;

             case '-1':
                 r1 = r1.inverse();
                 std::cout << "Результат: " << r1.getNumerator() << "/" << r1.getDenominator() << std::endl;
                 break;
             default:
                 cout << "Неверная операция." << endl;
             }
         }
     }

     catch (const char* error_message)
     {
         std::cout << error_message << std::endl;
     }
    
}
