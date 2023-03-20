#ifndef HUESPEDE_H
#define HUESPEDE_H

#include "person.h"

class Huespede : public Persona {
public:
  string Clinica;
  string Procedencia;

  Huespede() = default;
  Huespede(int identificacion, string nombre, string sexo, string fecha_nacimiento, int puntaje, string clinica, string procedencia);
 
};

#endif
