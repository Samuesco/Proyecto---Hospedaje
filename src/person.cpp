#include "person.h"

Persona::Persona(int identificacion, string nombre, string sexo, string fecha_nacimiento, int puntaje)
  : Identificacion(identificacion), Nombre(nombre), Sexo(sexo), Fecha_nacimiento(fecha_nacimiento), Puntaje(puntaje) {}

void Persona::set_Id(int identificacion){
  this->Identificacion = identificacion;
}

void Persona::set_Nombre(string nombre){
  this->Nombre = nombre;
}

void Persona::set_Sexo(string sexo){
  this->Sexo = sexo;
}

void Persona::set_FechaNacimiento(string fecha_nacimiento){
  this->Fecha_nacimiento = fecha_nacimiento;
}

void Persona::set_puntaje(int puntaje){
  this->Puntaje = puntaje;
}

int Persona::get_Id(){
  return this->Identificacion;
}

string Persona::get_Nombre(){
  return this->Nombre;
}

string Persona::get_Sexo(){
  return this->Sexo;
}

string Persona::get_FechaNacimiento(){
  return this->Fecha_nacimiento;
}

int Persona::get_puntaje(){
  return this->Puntaje;
}


