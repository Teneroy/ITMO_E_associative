//
// Created by alexc on 1/13/2019.
//

#include "Associative.h"
using namespace atdlist;

int main()
{
    Associative arr;
    arr.assign("A", "blabla");
    arr.assign("B", "cococo");
    arr.assign("C", "uuuuuu");
    arr.print();
    arr.assign("A", "kek");
    arr.print();
    std::cout << "compute: " << arr.compute("O", "arrrrrr") << std::endl;
    arr.print();
    std::cout << "compute: " << arr.compute("C", "arrrrrr") << std::endl;
    arr.print();
return 0;
}