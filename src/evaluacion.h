#ifndef EVALUACION_H
#define EVALUACION_H

#include<iostream>
#include<person.h>
#include<propietarios.h>
#include<huespede.h>

class Evaluacion {
private:
  string Fecha;
  Persona* remisor; //evaluador
  Persona* destinatario; //perona evaluada
  int calificacion;
  string comentarios;
public:
  Evaluacion() = default;
  Evaluacion(string Fecha, Persona* remisor, Persona* destinatario, int calificacion, string comentarios);
  ~Evaluacion();
};

#endif
