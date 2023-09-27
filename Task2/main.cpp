//������� ����� ����������� �����.
//�������� ������ ��������, ���������, �������, ���������, ������� � ���������� �����
// � ��������� ����� �����.
#include<iostream>
#include<string>
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
        cout << numer << '/' << denom << endl;
    }

    // ������� ����� � �������
    void read() {
        string str;
        getline(cin, str);
        int sep = str.find('/');
        this->set(stoi(str.substr(0, sep)), stoi(str.substr(sep + 1)));
    }


    // ������� ���������� �����
    void reducing() {
        for (int i = 1; i <= min(abs(numer), abs(denom)); ++i) {
            if (numer % i == 0 && denom % i == 0) {
                numer /= i;
                denom /= i;
            }
        }
    }
    
    // ������� �������� ������������ ����� � ���������� �����
    float toDecimal() {
        cout << "������� � ���������� �����" << endl;
        float tmp = float(numer) / float(denom);
        return tmp;
    }

    // ������� ��������� ����� �����
    Calc wholePart() {
        cout << "��������� ����� �����" << endl;
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
        cout << "��������" << endl;
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
        cout << "���������" << endl;
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
        cout << "���������" << endl;
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
        cout << "�������" << endl;
        Calc tmp = *this / r;
        return tmp;
    }

private:
    int wholepart;
    int numer;
    int denom;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Calc x, y;
    cout << "������� ������ �����: ";
    x.read();
    cout << "������� ������ �����: ";
    y.read();
    cout << endl;
    Calc z = x.add(y);
    z.print();
    z.wholePart().print();
    cout << z.toDecimal() << endl;;
    x.subtract(y).print();
    x.multiply(y).print();
    x.divide(y).print();
    return 0;
}
