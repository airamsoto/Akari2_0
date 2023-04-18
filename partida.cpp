#include "partida.h"


void iniciaPartida(tPartida& partida){
    iniciaListaPosiciones(partida.listaBombillas);

}
void cargarPartida(ifstream& archivo, tPartida& partida){
    archivo.open("partida.txt");
    if(archivo.is_open()){
        archivo >> partida.tablero.
        for (int i = 0; i < partida.tablero.; i++){

        }
    }
}
bool operator<(const tPartida& partida, int nivel){
    return partida.nivel < nivel;
}
bool operator<(const tPartida& partida1, const tPartida& partida2){
    return partida1.nivel < partida2.nivel;
}
bool juega(tPartida& partida, int& nIt){

}
void guardarPartida (ofstream& archivo, const tPartida& partida);
void destruyePartida (tPartida& partida);

