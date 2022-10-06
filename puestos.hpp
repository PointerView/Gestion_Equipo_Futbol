#pragma once
#ifndef PUESTOS_HPP
#define PUESTOS_HPP

#include <iostream>
#include <string>

using namespace std;


/////////////////////////
//     CLASE PADRE     //
/////////////////////////


class Persona
{
    protected:
        string nombre;
        string apellido;
        int edad;
        string puesto;

    public:
        Persona(string nombre, string apellido, int edad);
        void viajar();
        const string& getNombre();
        const string& getApellido();
        const int& getEdad();
        virtual void partidoFutbol() = 0;
        virtual void entrenamiento() = 0;
        const string& getPuesto();
        void setPuesto(string);
        virtual ~Persona();
};



//////////////////////////
//     CLASES HIJAS     //
//////////////////////////



class Futbolista : public Persona
{
    private:
        int dorsal;
        string posicion;

    public:
        Futbolista(string nombre, string apellido, int edad, int dorsal, string posicion);
        virtual ~Futbolista();
        virtual void partidoFutbol();
        virtual void entrenamiento();
        void entrevista();
};


class Medico : public Persona
{
    private:
        string titulacion;
        int experiencia;

    public:
        Medico(string nombre, string apellido, int edad, string titulacion, int experiencia);
        virtual void partidoFutbol();
        virtual void entrenamiento();
        void curarLesion();
};


class Entrenador : public Persona
{
    private:
        string estrategia;

    public:
        Entrenador(string nombre, string apellido, int edad, string estrategia);
        virtual void partidoFutbol();
        virtual void entrenamiento();
        void planificarEntrenamiento();
        virtual ~Entrenador();
};

#endif
