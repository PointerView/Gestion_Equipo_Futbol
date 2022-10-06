#include <iostream>
#include "puestos.hpp"

using namespace std;

Entrenador::Entrenador(string nombre, string apellido, int edad, string estrategia) : Persona(nombre, apellido, edad) {
    this->estrategia = estrategia;
    this->puesto = "Entrenador";
}


void
Entrenador::partidoFutbol(){
    cout<<"Dirige el partido de futbol\n";
}


void
Entrenador::entrenamiento(){
    cout<<"Dirige el entrenamiento\n";
}


void
Entrenador::planificarEntrenamiento(){
    cout<<"Planifica el entrenamiento\n";
}

Entrenador::~Entrenador(){}