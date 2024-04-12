/* 
 * File:   main.cpp
 * Author: ivana
 *
 * Created on 12 de abril de 2024, 04:21 PM
 */

#include <iostream>

using namespace std;

void test1(){
    int val = 10;
    int *ptrInt = &val;
    void *vInt = &val;
    cout << val << endl;
    cout << *ptrInt << endl;
    cout << *(int*)vInt << endl;
}

void test2(){
    int val = 10;
    int *ptrVal = &val;
    void *ptrvoid = &val;
    *ptrVal = 20;
    cout << val << endl;
    *(int*)ptrvoid = 30;
    cout << val << endl;
}

void test3(){
    void *ptrv[2];
    ptrv[0] = new int;
    ptrv[1] = new float;
    *(int*)ptrv[0] = 22;
    *(float*)ptrv[1] = 1.85;
    cout << *(int*)ptrv[0] << endl;
    cout << *(float*)ptrv[1] << endl;
}

void* pedirDatos(){
    void ** datos = new void*[2];
    cout << "Ingrese edad: ";
    datos[0] = new int;
    cin >> *(int*)datos[0];
    cout << "Ingrese talla: ";
    datos[1] = new float;
    cin >> *(float*)datos[1];
    void *result = datos;
    return result;
}

void mostrarDatos(void *result){
    void **datos = (void**) result;
    cout << "Edad: " << *(int*)datos[0] << endl;
    cout << "Talla: " << *(float*)datos[1] << endl;
}

int main(int argc, char** argv) {
    
    void *datos = pedirDatos();
    mostrarDatos(datos);
    
    return 0;
}

