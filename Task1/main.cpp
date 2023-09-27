//«адание 1.
//Ќаписать родительский класс и унаследовать от него классы от него.Ќаследники должны считать правую, 
// левую и центральную производную.
#include<iostream>
#include <functional>
#include <memory>
#include <utility>
//базовый класс
class Derivatives {
private:
public:
	double x_, x_0;
	std::function<double(double)>_f;//функци€ ,производную которой нужно вычислить
	Derivatives(double x, double x0, std::function< double(double) > f) {
		x_ = x;
		x_0 = x0;
		_f = std::move(f);

	};
	virtual double Differ() {//метод,возвращающий значение производной

		return 0;
	};

};
//класс дл€ вычислении€ левой производной 
class LeftDerivative :public Derivatives {
public:
	LeftDerivative(double x, double x0, std::function<double(double)> f) :Derivatives(x, x0, f) {};
	double Differ() override
	{
		return ((_f(x_) - _f(x_ - x_0)) / x_0);
	};
};
//класс дл€ вычислении€ правой производной 
class  RightDerivative :public Derivatives {
public:

	RightDerivative(double x, double x0, std::function<double(double)> f) : Derivatives(x, x0, f) {};

	double Differ() override {
		return ((_f(x_ + x_0) - _f(x_0)) / x_0);
	};
};
//класс дл€ вычислении€ центральной производной 
class CentralDerivative :public Derivatives {
public:
	CentralDerivative(double x, double x0, std::function<double(double)> f) :Derivatives(x, x0, f) {};
	double Differ() override {
		return ((_f(x_ + x_0) - _f(x_ - x_0)) / (2 * x_0));
	};
};


int main() {
    //задание функции,производную которой нужно вычислить
    std::function<double(double)> f = [](double x) {
        return x * x * x ;
        };
    double x = 4;
    double  x0 = 0.1;//приращение
	//создание объектов классов
    std::unique_ptr<Derivatives> calcr1 = std::make_unique<LeftDerivative>(LeftDerivative(x, x0, f));
    std::unique_ptr<Derivatives> calcr2 = std::make_unique<RightDerivative>(RightDerivative(x, x0, f));
    std::unique_ptr<Derivatives> calcr3 = std::make_unique<CentralDerivative>(CentralDerivative(x, x0, f));
	//¬ызываем метод дл€ каждого объекта класса 
    std::cout << "derivative = " << calcr1->Differ() << std::endl;
    std::cout << "derivative2 = " << calcr2->Differ() << std::endl;
    std::cout << "derivative3 = " << calcr3->Differ() << std::endl;
    return 0;

}