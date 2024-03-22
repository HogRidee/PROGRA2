/* 
 * File  :  main.cpp
 * Autor :  Ivan Alexander Araoz Andrade
 * Codigo:  20201216
 *
 * Creado el 22 de marzo de 2024, 02:40 PM
 */

#include <iostream>
#include <fstream>
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

istream& operator >> (istream &in, Punto2D &p){
    in >> p.x >> p.y;
    return in;
}

void operator++(Punto2D &p1){
    ++p1.x;
    ++p1.y;
}

template <typename T>
bool leerDatos(T* &arr, int &n, const char* filename){
    ifstream file(filename); //fstream para leer y escribir
    
    if (!file.is_open()){
        cout << "El archivo no existe" << endl;
        return false;
    }
    
    arr = new T[100];
    n = 0;
    
    while (true){
        file >> arr[n];
        cout << arr[n] << endl;
        if (file.eof()) break;
        ++n;
    }
    
    file.close();
    
    return true;
}

int main()
{
    Punto2D p1{5,2};
    Punto2D p2{3,4};
    Punto2D p3 = p1 + p2;
    cout<<p3<<endl;
    p3 += p2;
    cout<<p3<<endl;

     //TODO: implementar los operadores >, +=, ++
//    if(p1 > p2)
//        cout<<"P1 es mayor\n";
//    else
//        cout<<"P2 es mayor\n";    
    p3 += p1;
    cout<<p3<<endl; // 7, 7
    ++p3;
    cout<<p3<<endl; // 8, 8
    
    Punto2D* arr = nullptr;
    int n = 0;
    leerDatos<Punto2D>(arr, n, "puntos2d.txt");
    
    return 0;
}