#ifndef RESERVAS_H
#define RESERVAS_H

#include <iostream>
#include "propietarios.h"
#include "huespede.h"

class Reserva{
private:
  string initF;
  string endF;
  Huespede* rHuespede;
  HogarPropietario* rPropietario;
public:
  Reserva() = default;
  Reserva(string initF, string endF);
  ~Reserva();

  void set_Propietario(HogarPropietario* rPropietario);
  void set_Huespede(Huespede* rHuespede);
  int get_IdH();
  int get_IdP();
  string get_NameH();
  string get_NameP();
  string get_FechaInit();
  string get_FechaEnd();
  HogarPropietario* get_Propietario();
  Huespede* get_Huespede();
};


#endif
