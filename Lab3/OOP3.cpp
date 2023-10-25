#include<iostream>
#include"oop3.h"

int main() {

    AS::Array3d<int> array3D(3, 3, 3);

    array3D.fill_1(2);
    array3D.Print();


    array3D.setValue(2, 3, 1, 999);
    std::cout << array3D.getValue(2,3,1) << std::endl;

    array3D.ones();
    array3D.Print();

    array3D.zeroes();
    array3D.Print();
    return 0;


  
}
