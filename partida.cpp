#include "partida.h"


void iniciaPartida(tPartida& partida){
    iniciaListaPosiciones(partida.listaBombillas);

}
void cargarPartida(ifstream& archivo, tPartida& partida){
    tTablero tablero;
    archivo.open("partida.txt");
    if(archivo.is_open()){
        archivo >> partida.nivel;
        leerTablero(archivo, tablero);
    }
}
bool operator<(const tPartida& partida, int nivel){
    return partida.nivel < nivel;
}
bool operator<(const tPartida& partida1, const tPartida& partida2){
    return partida1.nivel < partida2.nivel;
}
bool juega(tPartida& partida, int& nIt){
    ifstream archivo;
    tTablero tablero;
    int x, y;
    bool ok = false;
    cargarPartida(archivo, partida);
    leerYColocarBombillas(archivo, tablero);
    mostrarTablero(tablero);

    while (!estaTerminado(tablero)) {
        cout << "En caso de que desee abandonar la partida introtuzca las coordenadas (-1 0)" << endl;
        cout << "INTRUZCA UNAS COORDENADAS: ";
        cin >> x >> y;
        nIt++;
        if(esPosQuit(x,y)) {
            ok = true;
            //estaTerminado(tablero) = true; da  un error al ponerlo a true no se porq
            nIt--;
        } else {
            ejecutarPos(tablero, x, y);
            mostrarTablero(tablero);
            estaTerminado(tablero);

        }
    }
    cout << "El numero de movimientos realizados es: " << nIt<< endl;
    return ok;
}
void guardarPartida (ofstream& archivo, const tPartida& partida) {
    tTablero tablero;
    archivo << partida.nivel << endl;
    archivo << getNumFilas(tablero) << " " << getNumCols(tablero) << endl;
    for (int i = 0; i < getNumFilas(tablero); i++) {
        for (int j = 0; j < getNumCols(tablero); ++j) {
            celdaToChar(celdaEnPos(tablero, i, j));
        }
    }
    guardarListaBombilla(archivo, partida.listaBombillas);
}


void destruyePartida (tPartida& partida) {
    destruyeListaPosiciones(partida.listaBombillas);
}

