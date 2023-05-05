#include "partida.h"
void reset (tTablero& tablero) {
    for (int i = 0; i < getNumFilas(tablero); i++) {
        for (int j = 0; j < getNumCols(tablero); j++) {
            if (estaIluminada(celdaEnPos(tablero, i, j)) || esBombilla(celdaEnPos(tablero, i, j))) {
                ejecutarPos(tablero, i, j);
            }
        }

    }

}

void almacenaBombillas (tPartida& partida) {
    for (int i = 0; i < getNumFilas(partida.tablero);i++) {
        for (int j = 0; j < getNumCols(partida.tablero); j++) {
            if (esBombilla(celdaEnPos(partida.tablero, i, j))) {
                tPosicion posicion;
                iniciaPosicion(posicion, i, j);
                insertar(partida.listaBombillas,  posicion);
            }
        }
    }
}

void guardaBombilla (tPartida& partida, int x, int y) {
    tPosicion posicion;
    iniciaPosicion(posicion, x, y);
    if (estaApagada(celdaEnPos(partida.tablero, x, y))) {
        insertar(partida.listaBombillas, posicion);
    }

}

void iniciaPartida(tPartida& partida){
    iniciaListaPosiciones(partida.listaBombillas);
    iniciaTablero(partida.tablero);
}

void cargarPartida(ifstream& archivo, tPartida& partida){
    iniciaPartida(partida);
    string basura;
    archivo >> basura;
    archivo >> partida.nivel;
    cargarTablero(partida.tablero, archivo);
    leerYColocarBombillas(archivo, partida.tablero);
    almacenaBombillas(partida);
}

bool operator<(const tPartida& partida, int nivel){
    return partida.nivel < nivel;
}

bool operator<(const tPartida& partida1, const tPartida& partida2){
    return partida1.nivel < partida2.nivel;
}

bool juega(tPartida& partida, int& nIt){
    ifstream archivo;
    ofstream archivo2;
    int x, y;
    leerYColocarBombillas(archivo, partida.tablero);
    mostrarTablero(partida.tablero);
    bool termina = estaTerminado(partida.tablero);
    bool acaba = false;

    while (!termina) {
        cout << "En caso de que desee abandonar la partida introtuzca las coordenadas (-1 0)" << endl;
        cout << "INTRODUZCA UNAS COORDENADAS: ";
        cin >> x >> y;
        nIt++;
        if (esBombilla(celdaEnPos(partida.tablero, x,y))) {
            tPosicion posicion;
            iniciaPosicion(posicion, x, y);
            eliminar(partida.listaBombillas, posicion);

        } else {
            guardaBombilla(partida,x,y);
        }
        if(esPosQuit(x,y)) {
            acaba = true;
            termina = true;
            nIt--;
        } else {
            if (reset(x, y)) {
                reset(partida.tablero);
                mostrarTablero(partida.tablero);
                destruyeListaPosiciones(partida.listaBombillas);
            }else {
                ejecutarPos(partida.tablero, x, y);
                mostrarTablero(partida.tablero);
                termina = estaTerminado(partida.tablero);

            }
        }
    }
    cout << "El numero de movimientos realizados es: " << nIt<< endl;
    return acaba;
}

void guardarPartida (ofstream& archivo, const tPartida& partida) {
    archivo <<"LEVEL " << partida.nivel << endl;
    archivo << getNumFilas(partida.tablero) << " " << getNumCols(partida.tablero) << endl;
    for (int i = 0; i < getNumFilas(partida.tablero); i++) {
        for (int j = 0; j < getNumCols(partida.tablero); ++j) {
            archivo << celdaToCharArchivo(celdaEnPos(partida.tablero, i, j));
        }
        archivo << endl;
    }

    guardarListaBombilla(archivo, partida.listaBombillas);
}

void destruyePartida (tPartida& partida) {
    destruyeListaPosiciones(partida.listaBombillas);
    destruyeTablero(partida.tablero);
}

