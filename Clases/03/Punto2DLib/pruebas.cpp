#include "pruebas.h"

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

istream& operator >> (istream &in, Punto2D &p){
    in >> p.x >> p.y;
    return in;
}

void operator++(Punto2D &p1){
    ++p1.x;
    ++p1.y;
}
