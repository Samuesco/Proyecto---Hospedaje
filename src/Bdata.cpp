#include "Bdata.h"
using std::vector;
using std::endl;
using std::cout;

Bdata::Bdata() : listPropietarios(), listHuespede(), listReservas(), listEvaluacion() {}

Bdata::~Bdata() {
  for(vector<HogarPropietario*>::iterator it = listPropietarios.begin(); it != listPropietarios.end(); ++it){
      delete *it;
    }
  for(vector<Huespede*>::iterator it = listHuespede.begin(); it != listHuespede.end(); ++it){
      delete *it;
    }
  for(vector<Reserva*>::iterator it = listReservas.begin(); it != listReservas.end(); ++it){
      delete *it;
    }
   for(vector<Evaluacion*>::iterator it = listEvaluacion.begin(); it != listEvaluacion.end(); ++it){
      delete *it;
    }
}

void Bdata::addPropietario(HogarPropietario* pHogarPropietario) {
      this->listPropietarios.push_back(pHogarPropietario);
}

void Bdata::addHuespede(Huespede* pHuespede) {
      this->listHuespede.push_back(pHuespede);
}


int Bdata::scanfID(int id, int t) {
  if (t==1) {
    for(vector<HogarPropietario*>::iterator it = listPropietarios.begin(); it != listPropietarios.end(); ++it){
        if((*it)->get_Id() == id) return 1;
      }
  }
  else {
    for(vector<Huespede*>::iterator it = listHuespede.begin(); it != listHuespede.end(); ++it){
        if((*it)->get_Id() == id) return 1;
      }
  }
  return 0;
}

void Bdata::propietariosInscriptos(){
  if (listPropietarios.size() > 0){
   for(vector<HogarPropietario*>::iterator it = listPropietarios.begin(); it != listPropietarios.end(); ++it){
        printf("---------------------------------\n");
        cout << "[*]ID: " << (*it)->get_Id() << endl; 
        cout << "[*]Nombre: " <<(*it)->get_Nombre() << endl;
        cout << "[*]Sexo: " << (*it)->get_Sexo() << endl;
        cout << "[*]Fecha de nacimiento: " << (*it)->get_FechaNacimiento() << endl;
        cout << "[*]Puntaje: " << (*it)->get_puntaje() << endl;
    }
  }else{
    printf("No hay propietarios escriptos\n");
   }
}

void Bdata::HuespedesInscriptos(){
  if (listHuespede.size() > 0){
    for(vector<Huespede*>::iterator it = listHuespede.begin(); it != listHuespede.end(); ++it){
        printf("---------------------------------\n");
        cout << "[*]ID: " << (*it)->get_Id() << endl; 
        cout << "[*]Nombre: " << (*it)->get_Nombre() << endl;
        cout << "[*]Sexo: " << (*it)->get_Sexo() << endl;
        cout << "[*]Fecha de nacimiento: " << (*it)->get_FechaNacimiento() << endl;
        cout << "[*]Puntaje: " << (*it)->get_puntaje() << endl;
     }
  }else{
    printf("No hay huespedes escriptos\n");
  }
}

void Bdata::guardarReserva(Reserva* r){
  this->listReservas.push_back(r);
}



int Bdata::BuscarReserva(Huespede *pHuespede){
    for(vector<Reserva*>::iterator it = listReservas.begin(); it != listReservas.end(); ++it){
        if ((*it)->get_Huespede()->get_Id() == pHuespede->get_Id()){
            return 1;
        }
    }
    return 0;
}

void Bdata::reservasRealizadas(){
  if (listReservas.size() > 0) {
    for(vector<Reserva*>::iterator it = listReservas.begin(); it != listReservas.end(); ++it){
      printf("----------------------------------\n"); 
      cout << "[*]Nombre Propietario: " << (*it)->get_NameP() << endl;
      cout << "[*]ID Propietario: " << (*it)->get_IdP() << endl;
      cout << "[*]Nombre Huespede: " << (*it)->get_NameH() << endl;
      cout << "[*]ID Huespede: " << (*it)->get_IdH() << endl;
      cout << "[*]Fecha de inicio: " << (*it)->get_FechaInit() << endl;
      cout << "[*]Fecha final: " << (*it)->get_FechaEnd() << endl;    
   }
  }else{
    printf("No hay reservas realizadas\n");
  }  
 }

Huespede* Bdata::scanfHuespede(int id){
for(vector<Huespede*>::iterator it = listHuespede.begin(); it != listHuespede.end(); ++it){
    if((*it)->get_Id() == id){
        return (*it);
    }
  }
  return nullptr;
}

HogarPropietario* Bdata::crearReserva(Huespede* pHuespede, Reserva* r){
  for(vector<HogarPropietario*>::iterator it = listPropietarios.begin(); it != listPropietarios.end(); ++it){
      if ((*it)->get_Disponibilidad() == 1){
        r->set_Huespede(pHuespede);
        r->set_Propietario(*it);
        (*it)->set_Disponibilidad(0);
        return (*it);
      }
  }
  return nullptr;
}

void Bdata::addPuntajeNew(HogarPropietario* ePropietario, Huespede* eHuespede, int score, int band){
  int punt;
  if (band == 1){
      cout << ePropietario->get_puntaje();
      punt = (ePropietario->get_puntaje() + score)/2;
      ePropietario->set_puntaje(punt);
  }else if(band == 0){
      cout << ePropietario->get_puntaje();
      punt = (eHuespede->get_puntaje() + score)/2;
      eHuespede->set_puntaje(punt);
  }
}

void Bdata::addEvaluacion(Evaluacion* e){
  listEvaluacion.push_back(e);
}

HogarPropietario* Bdata::scanfPropietario(int id){
    for(vector<Reserva*>::iterator it = listReservas.begin(); it != listReservas.end(); ++it){
        if((*it)->get_Huespede()->get_Id() == id){
            HogarPropietario* rPropietario = (*it)->get_Propietario();
            return rPropietario;
        }
    }
    return nullptr;
}

void Bdata::autoEvaluacion(int& score, string& comentario){
  srand(time(0));
  score =  1 + rand() % (6 - 1);
  switch(score){
    case 1: comentario = "Muy mal huespede"; break;
    case 2: comentario = "Pesimo huespede"; break;
    case 3: comentario = "Huespede regular"; break;
    case 4: comentario = "Buen huespede"; break;
    case 5: comentario = "Muy buen huespede"; break;
  }
}
int Bdata::eliminarReserva(Huespede* pHuespede){
    for(vector<Reserva*>::iterator it = listReservas.begin(); it != listReservas.end();++it){
        if ((*it)->get_IdH() == pHuespede->get_Id()){
            this->listReservas.erase(it);
            return 0;
        }
    }
    return 1;
}


