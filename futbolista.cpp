#include <iostream>
#include "puestos.hpp"

using namespace std;

Futbolista::Futbolista(string nombre, string apellido, int edad, int dorsal, string posicion) : Persona(nombre, apellido, edad) {
    this->dorsal = dorsal;
    this->posicion = posicion;
    this->puesto = "Futbolista";
}

void
Futbolista::partidoFutbol(){
    cout<<"Juega el partido de futbol\n";
}

void
Futbolista::entrenamiento(){
    cout<<"Entrena\n";
}


void
Futbolista::entrevista(){
    cout<<"Recibe una entrevista\n";
}


Futbolista::~Futbolista(){}