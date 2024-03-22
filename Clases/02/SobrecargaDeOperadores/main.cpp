/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 22 de marzo de 2024, 02:40 PM
 */

#include <iostream>
using namespace std;

struct Punto2D
{
    int x;
    int y;
};

Punto2D operator+(const Punto2D &p1, const Punto2D &p2){
    Punto2D p3;
    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;
    return p3;
}

void operator+=(Punto2D &p1, const Punto2D &p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
} 

ostream& operator<<(ostream &out,const Punto2D &p){
    out<<p.x<<","<<p.y;
    return out;
}

istream & operator >> (istream &in, Punto2D &p){
    cin>>p.x>>p.y;
    return in;
}

int main(int n, char* args[])
{
    Punto2D p1{5,2};
    Punto2D p2;
    cout<<"Ingresar valores para p2:";
    cin>>p2;
    Punto2D p3 = p1 + p2;
    cout<<p3<<endl;
    p3 += p2;
    cout<<p3<<endl;

     //TODO: implementar los operadores >, +=, ++
    if(p1 > p2)
        cout<<"P1 es mayor\n";
    else
        cout<<"P2 es mayor\n";    
    p3 += p1;
    cout<<p3<<endl; // 7, 7
    ++p3;
    cout<<p3<<endl; // 8, 8
}
