//
// Created by airam on 18/04/2023.
//

#ifndef AKARI2_0_PARTIDA_H
#define AKARI2_0_PARTIDA_H

#include "listaPosiciones.h"

typedef struct{
    tTablero tablero;
    tListaPosiciones listaBombillas;
    int nivel;
}tPartida;

void iniciaPartida(tPartida& partida);
void cargarPartida(ifstream& archivo, tPartida& partida);
bool operator<(const tPartida& partida, int nivel);
bool operator<(const tPartida& partida1, const tPartida& partida2);
bool juega(tPartida& partida, int& nIt);
void guardarPartida (ofstream& archivo, const tPartida& partida);
void destruyePartida (tPartida& partida);


#endif //AKARI2_0_PARTIDA_H
