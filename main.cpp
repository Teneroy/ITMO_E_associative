//
// Created by alexc on 1/13/2019.
//
#include <fstream>
#include "Associative.h"
using namespace atdlist;

void readFile(Associative &arr, const char * fname)
{
    std::ifstream myReadFile;
    myReadFile.open(fname);
    char name[20], address[20];
    if (myReadFile.is_open())
    {
        while (!myReadFile.eof())
        {
            myReadFile >> name;
            myReadFile >> address;
            arr.assign(elem(name, address));
        }
        myReadFile.close();
    }
}

int main()
{
    Associative arr;
    char fname[256];
    std::cout << "File name: ";
    std::cin >> fname;
    readFile(arr, fname);
    std::cout << "-------------------------------------------------------DATA FROM FILE:-----------------------------------------------" << std::endl;
    arr.print();
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;
    std::cout << "-------------------------------------------------------REASSIGN:-----------------------------------------------------" << std::endl;
    arr.assign(elem("name2", "Reassign"));
    arr.print();
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;
    std::cout << "-------------------------------------------------------COMPUTE:------------------------------------------------------" << std::endl;
    std::cout << "COMPUTE(fff): " << arr.compute(domaintype("fff"), rangetype("Compute")) << std::endl;
    std::cout << "COMPUTE(name1): " << arr.compute(domaintype("name1"), rangetype("Compute")) << std::endl;
    arr.print();
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;
    std::cout << "-------------------------------------------------------MAKENULL:-----------------------------------------------------" << std::endl;
    arr.makenull();
    arr.print();
    std::cout << "_____________________________________________________________________________________________________________________" << std::endl;


    return 0;
}