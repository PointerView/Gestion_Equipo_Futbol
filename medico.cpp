#include <iostream>
#include "puestos.hpp"

using namespace std;

Medico::Medico(string nombre, string apellido, int edad, string titulacion, int experiencia) : Persona(nombre, apellido, edad) {
    this->titulacion = titulacion;
    this->experiencia = experiencia;
    this->puesto = "Medico";
}


void
Medico::partidoFutbol(){
    cout<<"Da asistencia en el partido de futbol\n";
}


void
Medico::entrenamiento(){
    cout<<"Da asistencia en el entrenamiento\n";
}


void
Medico::curarLesion(){
    cout<<"Cura lesiones a los jugadores\n";
}