//Создать класс натуральная дробь.
//Добавить методы сложение, вычитание, деление, умножение, перевод в десятичную дробь
// и выделение целой части.
#include<iostream>
#include<string>
#include "main.h"
using namespace std;

class Calc
{
public:
	Calc() {
		numer = 0;// числитель
		denom = 0;//знаменатель
		wholepart = 0;//для выделения целой части
	}

	Calc(int n, int d) {
		numer = n;
		denom = d;
		wholepart = 0;
	}
	//Извлекаем значения перменных числителя и знаменателя
	int getNumer() const { return numer; }
	int getDenom() const { return denom; }
	//Присваиваем значения
	void set(int n, int d) {
		numer = n;
		denom = d;
	}

	// Функция вывода в консоль
	void print() {
		if (wholepart != 0)
			cout << wholepart << "+";
		cout << numer <<'/' << denom <<endl;
	}

	// Функция ввода с консоли
	bool read() {
		string str;
		getline(cin, str);
		int sep = str.find('/');
		int num, dem;
		try {
			num = stoi(str.substr(0, sep));
			dem = stoi(str.substr(sep + 1));
		}
		catch (...) {
			cout << "Ошибка! Введите целое число." << endl;
			return 0;
		}
		if (dem == 0) {
			cout <<" Ошибка!Знаменатель не может быть равен нулю." << endl;
			return 0;
		}
		this->set(num, dem);
		return 1;
	}
		
	
	


	// Функция сокращения дроби
	void reducing() {
		int gcd_value = gcd(numer, denom);
		numer /= gcd_value;
		denom /= gcd_value;
	}



	// Функция перевода рациональной дроби в десятичную дробь
	float toDecimal() {
		cout << "Перевод в десятичную дробь:" << endl;
		float tmp = float(numer) / float(denom);
		return tmp;
	}

	// Функция выделения целой части
	Calc wholePart() {
		cout << "Выделение целой части:" <<endl;
		Calc tmp;
		if (numer < denom)
			tmp = *this;
		else {
			tmp.wholepart = numer / denom;
			tmp.numer = numer - denom * tmp.wholepart;
			tmp.denom = denom;
		}
		return tmp;
	}

	//Перегрузка операторов и методы, ссылающиеся на перегрузку
	void operator=(const Calc& r) {
		numer = r.getNumer();
		denom = r.getDenom();
	}
	//Сложение
	Calc operator+(const Calc& r) {
		Calc tmp;
		tmp.numer = numer * r.getDenom() + denom * r.getNumer();
		tmp.denom = denom * r.getDenom();
		tmp.reducing();
		return tmp;
	}

	Calc add(const Calc& r) {
		cout<< "Сложение:" <<endl;
		Calc tmp = *this + r;
		return tmp;
	}
	//Вычитание
	Calc operator-(const Calc& r) {
		Calc tmp;
		tmp.numer = numer * r.getDenom() - denom * r.getNumer();
		tmp.denom = denom * r.getDenom();
		tmp.reducing();
		return tmp;
	}

	Calc subtract(const Calc& r) {
		cout << "Вычитание:" << endl;
		Calc tmp = *this - r;
		return tmp;
	}
	//Произведение
	Calc operator*(const Calc& r) {
		Calc tmp;
		tmp.numer = numer * r.getNumer();
		tmp.denom = denom * r.getDenom();
		tmp.reducing();
		return tmp;
	}

	Calc multiply(const Calc& r) {
		cout<< "Умножение:" << endl;
		Calc tmp = *this * r;
		return tmp;
	}
	//Деление
	Calc operator/(const Calc& r) {
		Calc tmp;
		tmp.numer = numer * r.getDenom();
		tmp.denom = denom * r.getNumer();
		tmp.reducing();
		return tmp;
	}

	Calc divide(const Calc& r) {
		cout<< "Деление:" <<endl;
		Calc tmp = *this / r;
		return tmp;
	}
	

private:
	int wholepart;
	int numer;
	int denom;
	

	//Наибольший общий делитель
	int gcd(int a, int b)
	{
		if (b == 0) return a;
		return gcd(b, a % b);
	}
};

int main()

{
	setlocale(LC_ALL, "Russian");
	Calc x, y;
	cout << "Введите первую дробь(числитель и знаменатель через /): ";
	x.read();
	cout << "Введите вторую дробь(числитель и знаменатель через /): ";
	cout << endl;
	y.read();
	Calc z = x.add(y);
	z.print();
	z.wholePart().print();
	cout << z.toDecimal() << endl;
	x.subtract(y).print();
	x.multiply(y).print();
	x.divide(y).print();

	return 0;

}
