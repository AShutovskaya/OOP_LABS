//������� ����� ����������� �����.
//�������� ������ ��������, ���������, �������, ���������, ������� � ���������� �����
// � ��������� ����� �����.
#include<iostream>
#include<string>
#include "main.h"
using namespace std;

class Calc
{
public:
	Calc() {
		numer = 0;// ���������
		denom = 0;//�����������
		wholepart = 0;//��� ��������� ����� �����
	}

	Calc(int n, int d) {
		numer = n;
		denom = d;
		wholepart = 0;
	}
	//��������� �������� ��������� ��������� � �����������
	int getNumer() const { return numer; }
	int getDenom() const { return denom; }
	//����������� ��������
	void set(int n, int d) {
		numer = n;
		denom = d;
	}

	// ������� ������ � �������
	void print() {
		if (wholepart != 0)
			cout << wholepart << "+";
		cout << numer <<'/' << denom <<endl;
	}

	// ������� ����� � �������
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
			cout << "������! ������� ����� �����." << endl;
			return 0;
		}
		if (dem == 0) {
			cout <<" ������!����������� �� ����� ���� ����� ����." << endl;
			return 0;
		}
		this->set(num, dem);
		return 1;
	}
		
	
	


	// ������� ���������� �����
	void reducing() {
		int gcd_value = gcd(numer, denom);
		numer /= gcd_value;
		denom /= gcd_value;
	}



	// ������� �������� ������������ ����� � ���������� �����
	float toDecimal() {
		cout << "������� � ���������� �����:" << endl;
		float tmp = float(numer) / float(denom);
		return tmp;
	}

	// ������� ��������� ����� �����
	Calc wholePart() {
		cout << "��������� ����� �����:" <<endl;
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

	//���������� ���������� � ������, ����������� �� ����������
	void operator=(const Calc& r) {
		numer = r.getNumer();
		denom = r.getDenom();
	}
	//��������
	Calc operator+(const Calc& r) {
		Calc tmp;
		tmp.numer = numer * r.getDenom() + denom * r.getNumer();
		tmp.denom = denom * r.getDenom();
		tmp.reducing();
		return tmp;
	}

	Calc add(const Calc& r) {
		cout<< "��������:" <<endl;
		Calc tmp = *this + r;
		return tmp;
	}
	//���������
	Calc operator-(const Calc& r) {
		Calc tmp;
		tmp.numer = numer * r.getDenom() - denom * r.getNumer();
		tmp.denom = denom * r.getDenom();
		tmp.reducing();
		return tmp;
	}

	Calc subtract(const Calc& r) {
		cout << "���������:" << endl;
		Calc tmp = *this - r;
		return tmp;
	}
	//������������
	Calc operator*(const Calc& r) {
		Calc tmp;
		tmp.numer = numer * r.getNumer();
		tmp.denom = denom * r.getDenom();
		tmp.reducing();
		return tmp;
	}

	Calc multiply(const Calc& r) {
		cout<< "���������:" << endl;
		Calc tmp = *this * r;
		return tmp;
	}
	//�������
	Calc operator/(const Calc& r) {
		Calc tmp;
		tmp.numer = numer * r.getDenom();
		tmp.denom = denom * r.getNumer();
		tmp.reducing();
		return tmp;
	}

	Calc divide(const Calc& r) {
		cout<< "�������:" <<endl;
		Calc tmp = *this / r;
		return tmp;
	}
	

private:
	int wholepart;
	int numer;
	int denom;
	

	//���������� ����� ��������
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
	cout << "������� ������ �����(��������� � ����������� ����� /): ";
	x.read();
	cout << "������� ������ �����(��������� � ����������� ����� /): ";
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
