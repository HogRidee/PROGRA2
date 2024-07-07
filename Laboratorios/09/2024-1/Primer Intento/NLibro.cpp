/* 
 * File:   NLibro.cpp
 * Author: Ivan
 * 
 * Created on 7 de julio de 2024, 13:19
 */

#include "NLibro.h"

NLibro::NLibro() {
    plibro = nullptr;
}

NLibro::~NLibro() {
    delete plibro;
}

