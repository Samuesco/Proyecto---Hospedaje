#include "main.h"

using namespace std;
using std::string;


int main(){
    menu();
    return 0;
}

void clear() {
    std::system(CLEAR);
}

void menu()
{
    int opt, id, opt1,opt2,opt3, opt4,opt5;
//Datos personas
    int Identificacion;
    string Nombre;
    string Sexo;
    string Fecha_nacimiento;
    int Puntaje;
//Datos huespede persona
    string clinica;
    string procedencia;
//Datos propietario
    string Direccion;
    string CantCamas;
    int AlojamientoBebes;
    string descripcionHogar;
    int Disponibilidad;
//reserva
    string initFecha;
    string endFecha;
//evaluacion
    int score;
    string comentario;
    //_______________:

    char band;
    //objetos de clases

    HogarPropietario* propietario;
    HogarPropietario* rPropietario = nullptr;
    Huespede* huespede;
    Huespede* rHuespede = nullptr;
    Bdata* data = new Bdata();
    Reserva* reserva;
    Evaluacion* evaluacion;
    Evaluacion* evaluacionA;

    do{ //primer do principal
        printf("\tWelcome to Airbnb\n");
        printf("[1] Iniciar secion\n");
        printf("[2] Registrarse\n");
        printf("[0] Salir\n");
        printf("[*] Seleccione la opcion:"); cin>>opt; fflush(stdin);
        printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

        if(opt == 1) {
            do{ //segundo do
                printf("[1] Propietario\n");
                printf("[2] Huespede\n");
                printf("[3] Lista de resevas\n");
                printf("[0] Salir \n");
                printf("[*] Seleccione la opcion: "); cin>>opt1; fflush(stdin);
                printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

                switch(opt1){
                    case 1:
                        do{ // tercero propietario verifica id
                            band = 'V';
                            printf("ID: "); cin>>id;
                            printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

                            if(data->scanfID(id,1)==1) {
                                do{ //cuarto do dentro de propietario

                                    printf("[1] Agregar informacion del hogar\n");
                                    printf("[2] Personas inscritas\n");
                                    printf("[0] Salir\n");
                                    printf("[*] Seleccione la opcion: "); cin>>opt2;

                                    printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

                                    switch(opt2) {
                                        case 1:

                                            printf("[1] Direccion\n");
                                            printf("[2] Cantidad de camas\n");
                                            printf("[3] Alojamiento de bebes\n");
                                            printf("[4] Descripcion del hogar\n");
                                            printf("[5] Disponiblilidad\n");
                                            printf("[*] Seleccione la opcion: "); cin>>opt3;
                                            printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

                                            switch (opt3) {
                                                case 1:  printf("[*] Direccion: "); leerCadena(Direccion);  printf("\n--Presione enter para continuar ---\n");  cin.ignore(); cin.get(); clear(); break;
                                                case 2:  printf("[*] Cantidad de camas: "); leerCadena(CantCamas); cin.ignore(); cin.get();  printf("\n--Presione enter para continuar ---\n");  clear(); break;
                                                case 3:  printf("[*] Alojamiento de Bebes\n");
                                                    printf("[0] No\n");
                                                    printf("[1] Si\n");
                                                    printf("[*] Seleccione la opcion: "); cin>>AlojamientoBebes;  printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear(); break;
                                                case 4:  printf("[*] Descripcion del Hogar: "); leerCadena(descripcionHogar);  printf("\n--Presione enter para continuar ---\n");  cin.ignore(); cin.get(); clear(); break;
                                                case 5:  printf("[*] Disponibilidad\n");
                                                    printf("[0] No\n");
                                                    printf("[1] Si\n");
                                                    printf("[*] Seleccione la opcion: "); cin>>Disponibilidad;  printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear(); break;

                                                default: break;
                                            }

                                            break;
                                        case 2:
                                            do{ //quinto do
                                                printf("[1] Propietarios\n");
                                                printf("[2] Huespedes\n");
                                                printf("[0] Salir\n");
                                                printf("[*] Seleccione la opcion: "); cin>>opt4;
                                                printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

                                                if (opt4 == 1) {
                                                    printf("\tListado de propietarios\n");
                                                    data->propietariosInscriptos();
                                                }
                                                else if(opt4==2) {
                                                    printf("\tListado de huespedes\n");
                                                    data->HuespedesInscriptos();
                                                }
                                                printf("\n--Presione enter para continuar ---\n");  cin.ignore(); cin.get();clear();
                                            }while(opt4!=0); //quinto
                                            break;
                                        default: break;
                                    }
                                    fflush(stdin);
                                }while(opt2!=0); //cuarto do
                            }
                            else {
                                band = 'F';
                                printf("ID invalido, Intentelo nuevamente o registrese\n");
                            }
                            printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();
                        }while(band!='F'); //termina do propietario verifica id
                        break;
                    case 2:
                        do{ //segundo do linea principal
                            band = 'V';
                            printf("ID: "); cin>>id;  fflush(stdin);
                            printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

                            if(data->scanfID(id,0)==1) {
                                rHuespede = data->scanfHuespede(id);
                                do{ //tercer do
                                    printf("[1] Crear reserva\n");
                                    printf("[2] Liberar reserva\n");
                                    printf("[0] Salir\n");
                                    printf("[*] Seleccione la opcion: "); cin>>opt5;
                                    printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

                                    if(opt5 == 1){
                                        initFecha = FechaInicio();
                                        endFecha = FechaFinal(initFecha);
                                        reserva = new Reserva(initFecha, endFecha);
                                        rPropietario = data->crearReserva(rHuespede,reserva);
                                        if(rPropietario != nullptr){

                                            data->guardarReserva(reserva);

                                            cout << "[*] Propietario: " << rPropietario->get_Nombre() << endl;
                                            cout << "[*] ID Propietario: " << rPropietario->get_Id() << endl;
                                            cout << "[*] Huespede: " << rHuespede->get_Nombre() << endl;
                                            cout << "[*] ID Huespede: " << rHuespede->get_Id() << endl;
                                            cout << "[*] Inicio: " << initFecha << endl;
                                            cout << "[*] Fin: " << endFecha << endl;
                                            cout << "[*] Reseva creada" << endl;

                                        }
                                        else{
                                            printf("No hay viviendas disponibles\n");
                                        }
                                    }
                                    else if(opt5 ==2) {
                                        if(data->BuscarReserva(rHuespede) == 1){
                                            rPropietario = data->scanfPropietario(rHuespede->get_Id());
                                            printf("\tEvaluacion\n");
                                            printf("[*]Puntaje: "); cin>>score;
                                            printf("[*]Comentarios: "); leerCadena(comentario);

                                            evaluacion = new Evaluacion(initFecha,rHuespede,rPropietario,score,comentario);
                                            data->addEvaluacion(evaluacion);
                                            data->addPuntajeNew(rPropietario,rHuespede,score,1);
                                            //evaluacion hecha por el propietario
                                            data->autoEvaluacion(score,comentario);
                                            evaluacionA = new Evaluacion(initFecha,rPropietario,rHuespede,score,comentario);
                                            data->addEvaluacion(evaluacionA);
                                            data->addPuntajeNew(rPropietario,rHuespede,score,0);
                                            rPropietario->set_Disponibilidad(1);
                                            if (data->eliminarReserva(rHuespede)) cout << "Reserva eliminada"  << endl;
                                            else cout << "Reserva eliminada"  << endl;


                                        }
                                    }
                                    else{
                                        printf("[*] La reserva no existe\n");
                                    }
                                    printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();
                                }while(opt5!=0);
                            }else {
                                band = 'F';
                                printf("ID invalido, Intentelo nuevamente o registrese\n");
                            }
                            printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();  fflush(stdin);

                        }while(band!='F' && opt5!=0); //segundo do
                        break;
                    case 3:
                        printf("\tReservas\n");
                        data->reservasRealizadas();
                        printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

                        break;
                    default: break;
                }
                fflush(stdin);
            }while(opt1!=0);//segundo dO
        }
//Registro
        else if(opt==2) {
            printf("[1]Propietario\n");
            printf("[2]Huespede\n");
            printf("[*]Seleccione la opcion: "); cin>>opt;
            printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();

            printf("[*] Identificacion: "); cin>>Identificacion;
            printf("[*] Nombre: "); leerCadena(Nombre);
            printf("[*] Sexo: "); leerCadena(Sexo);
            printf("[*] Fecha de nacimiento: "); leerCadena(Fecha_nacimiento);
            fflush(stdin);

            if(opt==1) {
                printf("[*] Direccion: "); leerCadena(Direccion); fflush(stdin);
                printf("[*] Cantidad de camas: "); leerCadena(CantCamas);
                printf("[*] Alojamiento de Bebes\n");
                printf("[0] No\n");
                printf("[1] Si\n"); fflush(stdin);
                printf("[*] Seleccione la opcion: "); cin>>AlojamientoBebes;
                printf("[*] Descripcion del hogar: "); leerCadena(descripcionHogar);
                printf("[*] Disponibilidad\n"); fflush(stdin);
                printf("[0] No\n");
                printf("[1] Si\n");
                printf("[*] Seleccione la opcion: "); cin>>Disponibilidad; fflush(stdin);

                propietario = new HogarPropietario(Identificacion,Nombre,Sexo,Fecha_nacimiento,0, Direccion, CantCamas, AlojamientoBebes, descripcionHogar, Disponibilidad);
                data->addPropietario(propietario);
            }
            else if(opt==2){
                printf("[*] Clinica: "); leerCadena(clinica);
                printf("[*] Procedencia: "); leerCadena(procedencia);
                huespede = new Huespede(Identificacion,Nombre,Sexo,Fecha_nacimiento,0,clinica,procedencia);
                data->addHuespede(huespede);
            }
            printf("\n--Presione enter para continuar ---\n"); cin.ignore(); cin.get(); clear();
        }
        fflush(stdin);

    }while(opt!=0); //do principal
}

string FechaInicio()
{
    srand(time(0));

    int year = rand() % 24 + 2000;
    int month = rand() % 12 + 1;
    int day = rand() % (31 - 1 + 1) + 1;
    if (month == 2){
        day = rand() % (28 - 1 + 1) + 1;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11){
        day = rand() % (30 - 1 + 1) + 1;
    }
    string fechaInicio = to_string(day) + "/" + to_string(month) + "/" + to_string(year);

    return fechaInicio;
}

string FechaFinal(string fechaInicio)
{
    int year = stoi(fechaInicio.substr(6, 4));
    int month = stoi(fechaInicio.substr(3, 2));
    int day = stoi(fechaInicio.substr(0, 2));

    int finalMonth = month;
    int finalDay = day;
    if (month == 2) {
        finalDay = rand() % (28 - 1 + 1) + 1;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11){
        finalDay = rand() % (30 - 1 + 1) + 1;
    }
    string fechaFinal = to_string(finalDay) + "/" + to_string(finalMonth) + "/" + to_string(year);

    return fechaFinal;
}

void leerCadena(std::string& cadena) {
    //std::getline(std::cin, cadena);
    // cadena.erase(cadena.find('\n'));
    cin.ignore();
    getline(std::cin, cadena, '\n');
    fflush(stdin);
}

