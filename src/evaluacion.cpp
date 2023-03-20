#include "evaluacion.h"

Evaluacion::Evaluacion(string Fecha, Persona* remisor, Persona* destinatario, int calificacion, string comentarios) : Fecha(Fecha), remisor(remisor), destinatario(destinatario),calificacion(calificacion),comentarios(comentarios) {}

Evaluacion::~Evaluacion(){
  delete remisor;
  delete destinatario;
}

