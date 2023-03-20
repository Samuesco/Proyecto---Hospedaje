#ifndef PROPIETARIOS_H
#define PROPIETARIOS_H

#include "person.h"

class HogarPropietario : public Persona {
private:
  string Direccion;
  string CantCamas;
  int AlojamientoBebes;
  string DescripcionHogar;
  int Disponibilidad;
public:
  HogarPropietario() = default;
  HogarPropietario(int Identificacion, string Nombre, string Sexo, string Fecha_Nacimiento, int puntaje, string direccion, string cantCamas, int alojamientoBebes, string descripcionHogar, int disponibilidad);

  void set_Direccion(string direccion);
  void set_CantCamas(string cantCamas);
  void set_Alojamiento(int alojamientoBebes);
  void set_DescripcionHogar(string descripcionHogar);
  void set_Disponibilidad(int disponibilidad);
  int get_Disponibilidad();
};

#endif
