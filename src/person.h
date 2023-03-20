#ifndef PERSON_H
#define PERSON_H

#include<iostream>
using std::string;

class Persona {
private:
  int Identificacion;
  string Nombre;
  string Sexo;
  string Fecha_nacimiento;
  int Puntaje;
public:
  Persona() = default;
  Persona(int identificacion, string nombre, string sexo, string fecha_nacimiento,int puntaje);

  void set_Id(int identificacion);
  void set_Nombre(string nombre);
  void set_Sexo(string sexo);
  void set_FechaNacimiento(string fecha_nacimiento);
  void set_puntaje(int puntaje);
  
  int get_Id();
  string get_Nombre();
  string get_Sexo();
  string get_FechaNacimiento();
  int get_puntaje();

};

#endif

  
