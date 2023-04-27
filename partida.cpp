#include "partida.h"


void iniciaPartida(tPartida& partida){
    //partida.listaBombillas = *new tListaPosiciones; revisar funcion
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
}
bool operator<(const tPartida& partida, int nivel){
    return partida.nivel < nivel;
}
bool operator<(const tPartida& partida1, const tPartida& partida2){
    return partida1.nivel < partida2.nivel;
}
bool juega(tPartida& partida, int& nIt){
    ifstream archivo;
    int x, y;
    leerYColocarBombillas(archivo, partida.tablero);
    mostrarTablero(partida.tablero);
    bool termina = estaTerminado(partida.tablero);

    while (!termina) {
        cout << "En caso de que desee abandonar la partida introtuzca las coordenadas (-1 0)" << endl;
        cout << "INTRODUZCA UNAS COORDENADAS: ";
        cin >> x >> y;
        nIt++;
        if(esPosQuit(x,y)) {
            termina = true; //doble bool mirar si con uno estaria bien
            nIt--;
        } else {
            if (reset(x, y)) { //RESET NO FUNCIONA, SE PIERDE AL VOLVER A CARGAR PARTIDA
                leerYColocarBombillas(archivo, partida.tablero);
                mostrarTablero(partida.tablero);
            } else {
                ejecutarPos(partida.tablero, x, y);
                mostrarTablero(partida.tablero);
                termina = estaTerminado(partida.tablero);
            }
        }
    }
    cout << "El numero de movimientos realizados es: " << nIt<< endl;
    return termina;
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

