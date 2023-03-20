//
// Created by Usuario on 20/03/2023.
//

#ifndef HOSPEDAJE_MAIN_H
#define HOSPEDAJE_MAIN_H
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include "person.h"
#include "propietarios.h"
#include "huespede.h"
#include "evaluacion.h"
#include "Bdata.h"
#include "reservas.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;
using std::string;
using std::endl;

void menu();
void clear();
string FechaInicio();
string FechaFinal(string initFecha);
void leerCadena(std::string& cadena);

#endif //HOSPEDAJE_MAIN_H
