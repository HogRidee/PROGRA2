/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PilaConRegistros.h
 * Author: RODRIGO
 *
 * Created on 30 de abril de 2024, 23:37
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H


void* leeregistro(ifstream& arch);
double calcularegistro(void* pilacamion,void* dato,double pesomaximo,int &actual);
char* leerCadenaExacta(ifstream& arch,char c);
void imprimeregistro(ofstream& arch,void* dato,int i);

#endif /* PILACONREGISTROS_H */
