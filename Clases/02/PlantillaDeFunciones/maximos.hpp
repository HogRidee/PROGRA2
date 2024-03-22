/* 
 * File  :   maximos.hpp
 * Autor :   Ivan Alexander Araoz Andrade
 * Codigo:   20201216
 *
 * Creado el 22 de marzo de 2024, 02:32 PM
 */

#ifndef MAXIMOS_HPP
#define MAXIMOS_HPP

#include <iostream>

template<typename T> 
T maximo(T a, T b)
{
    T mayor = a;
    if(b > mayor) mayor = b;
    return mayor;
}

template<typename T> 
T maximo(T a, T b, T c)
{
    T mayor = a;
    if(b > mayor) mayor = b;
    if(c > mayor) mayor = c;    
    return mayor;
}

template<typename T>
T maximo(T* arr, int n)
{
    T mayor = arr[0];
    for(int i=1; i<n; ++i){
        if(arr[i] > mayor)
            mayor = arr[i];
    }
    return mayor;
}

#endif /* MAXIMOS_HPP */

