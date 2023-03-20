#include "huespede.h"

Huespede::Huespede(int identificacion, string nombre, string sexo, string fecha_nacimiento, int puntaje, string clinica, string procedencia) : Persona(identificacion, nombre, sexo, fecha_nacimiento,puntaje)
{
  this->Clinica = clinica;
  this->Procedencia = procedencia;
}

