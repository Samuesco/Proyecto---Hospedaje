#include "propietarios.h"

HogarPropietario::HogarPropietario(int Identificacion, string Nombre, string Sexo, string Fecha_Nacimiento, int puntaje, string direccion, string cantCamas, int alojamientoBebes, string descripcionHogar, int disponibilidad)
    : Persona(Identificacion,Nombre, Sexo,Fecha_Nacimiento, puntaje), Direccion(direccion), CantCamas(cantCamas), AlojamientoBebes(alojamientoBebes), DescripcionHogar(descripcionHogar), Disponibilidad(disponibilidad) {}

void HogarPropietario::set_Direccion(string direccion){
  this->Direccion = direccion;
}

void HogarPropietario::set_CantCamas(string cantCamas){
  this->CantCamas = cantCamas;
}

void HogarPropietario::set_Alojamiento(int alojamientoBebes){
  this->AlojamientoBebes = alojamientoBebes;
}

void HogarPropietario::set_DescripcionHogar(string descripcionHogar){
  this->DescripcionHogar = descripcionHogar;
}

void HogarPropietario::set_Disponibilidad(int disponibilidad){
  this->Disponibilidad = disponibilidad;
}

int HogarPropietario::get_Disponibilidad(){
  return this->Disponibilidad;
}

