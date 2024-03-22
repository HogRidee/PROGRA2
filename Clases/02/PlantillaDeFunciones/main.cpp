/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 22 de marzo de 2024, 02:31 PM
 */

#include <iostream>
#include "maximos.hpp"
using namespace std;

int main()
{
    std::cout<<maximo<int>(23, 12)<<std::endl;
    float* arr = nullptr;
    arr = new float[4]{15.4, 15.8, 8.5, 2};
    std::cout<<maximo<float>(arr, 4)<<std::endl;
    return 0;
}

