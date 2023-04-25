#include "tablero.h"
#include "reglasJuego.h"
#include <fstream>
using namespace std;

int getNumFilas(const tTablero& tab) {
    return tab.nFils;
}

int getNumCols(const tTablero& tab) {
    return tab.nCols;
}

tCelda celdaEnPos(const tTablero& tab, int x, int y) {
    return tab.tablero[x][y];
}

void ponCeldaEnPos(tTablero& tab, int x, int y, const tCelda& c) {
    tab.tablero[x][y] = c;
}

bool leerTablero(ifstream& archivo, tTablero& tab) {
    bool abre = false;
    char c;
    int numero_bombillas, x, y;
    archivo.open("tablero.txt");
    if (archivo.is_open()) {
        abre = true;
        archivo >> tab.nFils >> tab.nCols;
        for (int filas = 0; filas < getNumFilas(tab); filas++) {
            for (int columnas = 0; columnas < getNumCols(tab); columnas++) {
                archivo >> c;
                ponCeldaEnPos(tab, filas, columnas, charToCelda(c));
            }
        }

    }

    return abre;
}
void leerYColocarBombillas(ifstream& archivo, tTablero& tab) {
    int numero_bombillas, x, y;

    archivo >> numero_bombillas;
    for (int b = 0; b < numero_bombillas; b++) {
        archivo >> x >> y;
        ejecutarPos(tab, x, y);
    }
    archivo.close();
}

void mostrarTablero(const tTablero& tab) {
    tCelda c;
    for (int i = 0; i < tab.nCols; i++) {
        cout << BLUE << "   " << i << RESET;
    }
    cout << endl;
    for (int filas = 0; filas < getNumFilas(tab); filas++) {

        cout << "-+---+---+---+---+---+" << endl;
        cout << BLUE << filas << RESET;
        for (int columnas = 0; columnas < getNumCols(tab); columnas++) {

            if (esPared(celdaEnPos(tab, filas, columnas))) {
                cout << "| " << BG_BLACK << celdaToChar(celdaEnPos(tab, filas, columnas)) << RESET << " ";
            }
            else {
                if (esBombilla(celdaEnPos(tab, filas, columnas)) || estaIluminada(celdaEnPos(tab, filas, columnas))) {
                    cout << "| " << BG_YELLOW << celdaToChar(celdaEnPos(tab, filas, columnas)) << RESET << " ";
                }
                else {
                    cout << "| " << BG_WHITE << celdaToChar(celdaEnPos(tab, filas, columnas)) << RESET << " ";
                }
            }

        }
        cout << "|" << endl;
    }
}
void iniciaTablero (tTablero& tablero) {
    tablero.nFils = 0;
    tablero.nCols = 0;
}

void destruyeTablero (tTablero& tablero) {
    tablero.nFils = 0;
    tablero.nCols = 0;
}
void cargarTablero (tTablero& tab, ifstream& archivo) {
    char c;
    for (int filas = 0; filas < getNumFilas(tab); filas++) {
        for (int columnas = 0; columnas < getNumCols(tab); columnas++) {
            archivo >> c;
            ponCeldaEnPos(tab, filas, columnas, charToCelda(c));
        }
    }
}