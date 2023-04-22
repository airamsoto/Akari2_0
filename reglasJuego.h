
#ifndef AKARI2_0_REGLASJUEGO_H
#define AKARI2_0_REGLASJUEGO_H
#include "tablero.h"
//funciones privadas deje comentado lo que deberiamos de quitar
bool estaTerminado(tTablero const& tab);
//int bombillasAlosLados(const tTablero& tab, int x, int y);
bool esPosQuit(int x, int y);
void ejecutarPos(tTablero& tab, int x, int y);
//void iluminaCruz(tTablero& tab, int x, int y, bool iluminar);
//void direccionIluminacion(tTablero& tab, int x, int y, tDir dir, bool iluminar);

#endif //AKARI2_0_REGLASJUEGO_H
