#ifndef BDATA_H
#define BDATA_H

#include <iostream>
#include "propietarios.h"
#include "huespede.h"
#include "reservas.h"
#include "evaluacion.h"
#include <vector>
#include <ctime>

using std::vector;

class Bdata {
protected:
  vector<HogarPropietario*> listPropietarios;
  vector<Huespede*> listHuespede;
  vector<Reserva*> listReservas;
  vector<Evaluacion*> listEvaluacion;
public:
  Bdata();
  ~Bdata();

  int scanfID(int id, int t);
  void propietariosInscriptos();
  void HuespedesInscriptos();
  void guardarReserva(Reserva* r);
  int eliminarReserva(Huespede* pHuespede);
  void reservasRealizadas();
  HogarPropietario* scanfPropietario(int id);
  Huespede* scanfHuespede(int id);
  HogarPropietario* crearReserva(Huespede* pHuespede, Reserva* r);
  int BuscarReserva(Huespede* pHuespede);
  void addPropietario(HogarPropietario* pHogarPropietario);
  void addHuespede(Huespede* pHuespede);
  void addPuntajeNew(HogarPropietario* ePropietario, Huespede* eHuespede, int score, int band);
  void addEvaluacion(Evaluacion* e);
  void autoEvaluacion(int& score, string& comentario);
};

#endif
