//������� 1.
//�������� ������������ ����� � ������������ �� ���� ������ �� ����.���������� ������ ������� ������, 
// ����� � ����������� �����������.
#include<iostream>
#include <functional>
#include <memory>
#include <utility>
//������� �����
class Derivatives {
private:
public:
	double x_, x_0;
	std::function<double(double)>_f;//������� ,����������� ������� ����� ���������
	Derivatives(double x, double x0, std::function< double(double) > f) {
		x_ = x;
		x_0 = x0;
		_f = std::move(f);

	};
	virtual double Differ() {//�����,������������ �������� �����������

		return 0;
	};

};
//����� ��� ����������� ����� ����������� 
class LeftDerivative :public Derivatives {
public:
	LeftDerivative(double x, double x0, std::function<double(double)> f) :Derivatives(x, x0, f) {};
	double Differ() override
	{
		return ((_f(x_) - _f(x_ - x_0)) / x_0);
	};
};
//����� ��� ����������� ������ ����������� 
class  RightDerivative :public Derivatives {
public:

	RightDerivative(double x, double x0, std::function<double(double)> f) : Derivatives(x, x0, f) {};

	double Differ() override {
		return ((_f(x_ + x_0) - _f(x_0)) / x_0);
	};
};
//����� ��� ����������� ����������� ����������� 
class CentralDerivative :public Derivatives {
public:
	CentralDerivative(double x, double x0, std::function<double(double)> f) :Derivatives(x, x0, f) {};
	double Differ() override {
		return ((_f(x_ + x_0) - _f(x_ - x_0)) / (2 * x_0));
	};
};


int main() {
    //������� �������,����������� ������� ����� ���������
    std::function<double(double)> f = [](double x) {
        return x * x * x ;
        };
    double x = 4;
    double  x0 = 0.1;//����������
	//�������� �������� �������
    std::unique_ptr<Derivatives> calcr1 = std::make_unique<LeftDerivative>(LeftDerivative(x, x0, f));
    std::unique_ptr<Derivatives> calcr2 = std::make_unique<RightDerivative>(RightDerivative(x, x0, f));
    std::unique_ptr<Derivatives> calcr3 = std::make_unique<CentralDerivative>(CentralDerivative(x, x0, f));
	//�������� ����� ��� ������� ������� ������ 
    std::cout << "derivative = " << calcr1->Differ() << std::endl;
    std::cout << "derivative2 = " << calcr2->Differ() << std::endl;
    std::cout << "derivative3 = " << calcr3->Differ() << std::endl;
    return 0;

}