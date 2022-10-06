#include <iostream>
#include <stdio_ext.h>
#include <string>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "puestos.hpp"
#include "general.hpp"

using namespace std;

constexpr char *const normal = "\033[0m";
constexpr char *const guapo = "\033[4;40;32m";

void
wait(){
    cout<<"\n\nPulse una tecla para continuar...";
    __fpurge(stdin);
    getchar();
    system("clear");
}


void
title(){
    system("clear");
    system("toilet -Fborder -fpagga --metal 'MENU DE INICIO'");
    cout<<endl;
}


enum TOption
opciones(){
    int opcion;


    for(short i=0; opt[i]!=nullptr; i++)
        cout<<i+1<<". "<<opt[i]<<"\n";
    cout<<guapo<<"Seleccione una opcion: "<<normal;
    cin>>opcion;
    cout<<'\n';
    return (enum TOption)(opcion);
}


void
viajarEquipo(Persona *equipo[]){
    for(short i=0; i<npersonal; i++){
        cout<<equipo[i]->getNombre()<<" "<<equipo[i]->getApellido()<<" -- "<<equipo[i]->getPuesto()<<" -> ";
        equipo[i]->viajar();
    }
    wait();
}


void
entrenamientoEquipo(Persona *equipo[]){
    for(short i=0; i<npersonal; i++){
        cout<<equipo[i]->getNombre()<<" "<<equipo[i]->getApellido()<<" -- "<<equipo[i]->getPuesto()<<" -> ";
        equipo[i]->entrenamiento();
    }
    wait();
}


void
partidoEquipo(Persona *equipo[]){
    for(short i=0; i<npersonal; i++){
        cout<<equipo[i]->getNombre()<<" "<<equipo[i]->getApellido()<<" -- "<<equipo[i]->getPuesto()<<" -> ";
        equipo[i]->partidoFutbol();
    }
    wait();
}


void
planificarEntrenamiento(Persona *equipo[]){
    for(int i=0; i<npersonal; i++){
        if(equipo[i]->getPuesto() == "Entrenador"){
            cout<<equipo[i]->getNombre()<<" "<<equipo[i]->getApellido()<<" -- "<<equipo[i]->getPuesto()<<" -> ";
            static_cast<Entrenador*>(equipo[i])->planificarEntrenamiento();    //DownCasting Puntero Entrenador apunta al valor de equipo[i]
        }
    } 
    wait();
}


void
entrevistaEquipo(Persona *equipo[]){
    for(int i=0; i<npersonal; i++){
        if(equipo[i]->getPuesto() == "Futbolista"){
            cout<<equipo[i]->getNombre()<<" "<<equipo[i]->getApellido()<<" -- "<<equipo[i]->getPuesto()<<" -> ";
            static_cast<Futbolista*>(equipo[i])->entrevista();
        }
    }
    wait();     
}


void
curarEquipo(Persona *equipo[]){
    for(int i=0; i<npersonal; i++){
        if(equipo[i]->getPuesto() == "Medico"){
            cout<<equipo[i]->getNombre()<<" "<<equipo[i]->getApellido()<<" -- "<<equipo[i]->getPuesto()<<" -> ";
            static_cast<Medico*>(equipo[i])->curarLesion();
        }
    }
    wait();    
}


void
agregarJugador(Persona **&equipo){  //  Recibo un puntero que apunta a punteros que apunta a las direcciones de los valores de los objetos
    string nombre, apellido, posicion;
    int edad, dorsal;

    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Edad: "; cin>>edad;
    cout<<"Dorsal: "; cin>>dorsal;
    cout<<"Posicion: "; cin>>posicion;

    equipo = (Persona**)realloc(equipo, sizeof(Persona*)*npersonal);
    *(*&(equipo)+npersonal++) = new Futbolista(nombre, apellido, edad, dorsal, posicion);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    system("clear");
}


void
agregarMedico(Persona **&equipo){  //  Recibo un puntero que apunta a punteros que apunta a las direcciones de los valores de los objetos
    string nombre, apellido, titulacion;
    int edad, experiencia;

    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Edad: "; cin>>edad;
    __fpurge(stdin);
    cout<<"Titulacion: "; getline(cin, titulacion);
    cout<<"Experiencia: "; cin>>experiencia;
  
  
    equipo = (Persona**)realloc(equipo, sizeof(Persona*)*npersonal);
    *(*&(equipo)+npersonal++) = new Medico(nombre, apellido, edad, titulacion, experiencia);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    system("clear");
}


void
agregarEntrenador(Persona **&equipo){  //  Recibo un puntero que apunta a punteros que apunta a las direcciones de los valores de los objetos
    string nombre, apellido, estrategia;
    int edad;

    cout<<"Nombre: "; cin>>nombre;
    cout<<"Apellido: "; cin>>apellido;
    cout<<"Edad: "; cin>>edad;
    __fpurge(stdin);
    cout<<"Estrategia: "; getline(cin, estrategia);
    
    equipo = (Persona**)realloc(equipo, sizeof(Persona*)*npersonal);
    *(*&(equipo)+npersonal++) = new Entrenador(nombre, apellido, edad, estrategia); 
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    system("clear");
}




//////////////////////////////////////////////////
//      PUNTERO A FUNCIONES DEL SEGUNDO MENU     //
//////////////////////////////////////////////////


void (*agregar[])(Persona **&equipo) = {&agregarJugador, &agregarMedico, &agregarEntrenador};

void
recursosHumanos(Persona **equipo){
    int opcion;
    system("clear");

    title();

    cout<<"1. Agregar un nuevo jugador.\n";
    cout<<"2. Agregar un nuevo medico.\n";
    cout<<"3. Agregar un nuevo entrenador.\n\n";

    cout<<"Opcion: ";
    cin>>opcion;

    (*agregar[opcion-1])(equipo);   //  Paso el valor de equipo

}


//////////////////////////////////////////////////
//      PUNTERO A FUNCIONES DEL PRIMER MENU     //
//////////////////////////////////////////////////

void (*clase[])(Persona *equipo[]) = { &viajarEquipo, &entrenamientoEquipo, &partidoEquipo, &planificarEntrenamiento, &entrevistaEquipo, &curarEquipo, &recursosHumanos};


void
menu(Persona *equipo[], Persona **equipoRef){
    int opcion;
    do{
        title();
        opcion = opciones(); 
        if(opcion > 0 && opcion < 7)
            (*clase[opcion-1])(equipo);
        else if(opcion == 7)
            recursosHumanos(equipo);
    }while(opcion!=8); 
}


int
main(int argc, char *argv[]){

    setlocale(LC_ALL, "es_ES.UTF-8");   //  Indicar la posibilidad de encontrar caracteres UTF-8
    system("clear");
    Persona **equipo = (Persona**) malloc (cantpersonal*sizeof(Persona*));

    *(equipo+npersonal++) = new Futbolista("Gonzalo", "Higuain", 30, 9, "Delantero");
    *(equipo+npersonal++) = new Futbolista("Paulo", "Dybala", 24, 10, "Delantero");
    *(equipo+npersonal++) = new Entrenador("Massimiliano", "Allegri", 50, "Defensiva");
    *(equipo+npersonal++) = new Medico("Alex", "Marroni", 59, "Fisioterapeuta", 20);
    
    cantpersonal++;

    menu(equipo, equipo);

    return EXIT_SUCCESS;
}
