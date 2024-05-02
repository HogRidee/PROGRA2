/* 
 * File:   PilaConEnteros.h
 * Author: Ivan
 *
 * Created on 2 de mayo de 2024, 10:16
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

#include "FlotaGenerica.h"

void *leenumero(ifstream &);
int calculanumero(void *);
void imprimenumero(void *);
int cmpnumero(const void *, const void *);

#endif /* PILACONENTEROS_H */

