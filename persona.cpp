#include "puestos.hpp"
#include <iostream>

using namespace std;

Persona::Persona(string nombre, string apellido, int edad){
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
}

void
Persona::viajar(){
    cout<<"Viajar\n";
}


const string&
Persona::getNombre(){
    return this->nombre;
}


const string&
Persona::getApellido(){
    return this->apellido;
}


const int&
Persona::getEdad(){
    return this->edad;
}


const string&
Persona::getPuesto(){
    return this->puesto;
}


void
Persona::setPuesto(string puesto){
    this->puesto = puesto;
}

Persona::~Persona(){}