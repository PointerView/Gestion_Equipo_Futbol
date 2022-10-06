#pragma once
#ifndef GENERAL_HPP
#define GENERAL_HPP

enum TOption {VIAJE=1, ENTRENAR, PARTIDO, PLANENTRENAMIENTO, ENTREVISTA, CURARLESION, RRHH, SALIR};


const char *opt[] = {
    "Viaje en equipo",
    "Entrenamiento",
    "Partido de futbol",
    "Planificar entrenamiento",
    "Entrevista",
    "Curar lesiones",
    "Recursos Humanos",
    "Salir\n",
    nullptr
};


int npersonal = 0;
int cantpersonal = 4;



#endif
