#include "reservas.h"

Reserva::Reserva(string initF, string endF): initF(initF), endF(endF) {}

Reserva::~Reserva(){
  delete rPropietario;
  delete rHuespede;
}

void Reserva::set_Propietario(HogarPropietario* rPropietario){
  this->rPropietario = rPropietario;
}

void Reserva::set_Huespede(Huespede* rHuespede){
  this->rHuespede = rHuespede;
}

int Reserva::get_IdH(){
  return this->rHuespede->get_Id();
}

int Reserva::get_IdP(){
  return this->rPropietario->get_Id();
}
string Reserva::get_NameH(){
  return this->rHuespede->get_Nombre();
}
string Reserva::get_NameP(){
  return this->rPropietario->get_Nombre();
}
string Reserva::get_FechaInit(){
  return this->initF;
}
string Reserva::get_FechaEnd(){
  return this->endF;
}

HogarPropietario* Reserva::get_Propietario(){
  return this->rPropietario;
}

Huespede* Reserva::get_Huespede(){
  return this->rHuespede;
}

