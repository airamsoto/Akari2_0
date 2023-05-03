#include "reglasJuego.h"

using namespace std;
int bombillasAlosLados(const tTablero& tab, int x, int y) {
    int bombillas = 0;
    if (esBombilla(celdaEnPos(tab, x + 1, y))) {
        bombillas += 1;
    }
    if (esBombilla(celdaEnPos(tab, x, y + 1))) {
        bombillas += 1;
    }
    if (esBombilla(celdaEnPos(tab, x - 1, y))) {
        bombillas += 1;
    }
    if (esBombilla(celdaEnPos(tab, x, y - 1))) {
        bombillas += 1;
    }
    return bombillas;
}
void direccionIluminacion(tTablero& tab, int x, int y, tDir cardinal, bool iluminar) {
    tCelda c;
    c = celdaEnPos(tab, x, y);


    int fila, col;


    if (cardinal == NORTE) {
        fila = x - 1;
        col = y;
        while (!esPared(celdaEnPos(tab, fila, col)) && fila >= 0) {
            c = celdaEnPos(tab, fila, col);
            actualizaIluminacionCelda(c, iluminar);
            ponCeldaEnPos(tab, fila, col, c);
            fila -= 1;
        }

    }
    else {
        if (cardinal == SUR) {
            fila = x + 1;
            col = y;
            while (!esPared(celdaEnPos(tab, fila, col)) && fila < getNumCols(tab)) {
                c = celdaEnPos(tab, fila, col);
                actualizaIluminacionCelda(c, iluminar);
                ponCeldaEnPos(tab, fila, col, c);
                fila += 1;
            }
        }
        else {
            if (cardinal == ESTE) {
                fila = x;
                col = y + 1;
                while (!esPared(celdaEnPos(tab, fila, col)) && col < getNumFilas(tab)) {
                    c = celdaEnPos(tab, fila, col);
                    actualizaIluminacionCelda(c, iluminar);
                    ponCeldaEnPos(tab, fila, col, c);
                    col += 1;
                }
            }
            else {
                if (cardinal == OESTE) {
                    fila = x;
                    col = y - 1;
                    while (!esPared(celdaEnPos(tab, fila, col)) && col >= 0) {
                        c = celdaEnPos(tab, fila, col);
                        actualizaIluminacionCelda(c, iluminar);
                        ponCeldaEnPos(tab, fila, col, c);
                        col -= 1;
                    }
                }
            }
        }
    }
}
void iluminaCruz(tTablero& tab, int x, int y, bool iluminar) {
    direccionIluminacion(tab, x, y, NORTE, iluminar);
    direccionIluminacion(tab, x, y, SUR, iluminar);
    direccionIluminacion(tab, x, y, ESTE, iluminar);
    direccionIluminacion(tab, x, y, OESTE, iluminar);
}



bool estaTerminado(tTablero const& tab) {
    bool ok = true;
    int filas = 0, columnas;

    while (filas < getNumFilas(tab) && ok) {
        columnas = 0;
        while (columnas < getNumCols(tab) && ok) {
            tCelda celda = celdaEnPos(tab, filas, columnas);
            if ((esParedRestringida(celda) && (numParedRestringida(celda) != bombillasAlosLados(tab, filas, columnas)))) {
                ok = false;
            }
            else if (!esPared(celda) && !estaIluminada(celda) && !esBombilla(celda)) {
                ok = false;
            }
            columnas++;
        }
        filas++;
    }
    return ok;
}

bool reset(int x, int y) {
    return (x == -1 && y == -1);
}

bool esPosQuit(int x, int y) {
    return (x == -1 && y == 0);
}

void ejecutarPos(tTablero& tab, int x, int y) {

    tCelda c = celdaEnPos(tab, x, y);
    if (esBombilla(c)) {
        apagaCelda(c);
        ponCeldaEnPos(tab, x, y, c);
        iluminaCruz(tab, x, y, false);
    }
    else {
        if (!esPared(celdaEnPos(tab, x, y)) && !estaIluminada(celdaEnPos(tab, x, y))) {
            ponBombilla(c);
            ponCeldaEnPos(tab, x, y, c);
            iluminaCruz(tab, x, y, true);
        }
    }
}



