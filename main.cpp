#include <iostream>
#include "listaPartidas.h"

int main() {
    int n, cont = 0;
    ifstream archivo;
    ofstream archivoEscr;
    tListaPartidas listaPartidas;
    tPartida partida;
    iniciaListaPartidas(listaPartidas);
    archivo.open("partidas.txt");
    if (archivo.is_open()) {
        cargarListaPartidas(archivo, listaPartidas);
        cout << "INTRODUCE EL NIVEL DE LA PARTIDA QUE QUIERAS JUGAR: ";
        cin >> n;
        if (buscaPos(listaPartidas, n) != -1) {
            partida = *dameElem(listaPartidas, buscaPos(listaPartidas, n));
        }
        else if(buscaPos(listaPartidas, n) == -1) {
            if ( operator<(*dameElem(listaPartidas, dameNumElem(listaPartidas)),  n)) {
                partida = *dameElem(listaPartidas, dameNumElem(listaPartidas) - 1);
            } else {
                int i = n;
                int aux = -2;
                while (i < dameNumElem(listaPartidas) && aux == -2) { //falta mirar si se carga la partida con el -2
                    if (buscaPos(listaPartidas, n) != -1) {
                        aux = i;
                    } else  {
                        i++;
                    }
                }
                partida = *dameElem(listaPartidas, buscaPos(listaPartidas, aux));
            }



        } /*else if ( operator<(*dameElem(listaPartidas, dameNumElem(listaPartidas)),  n)) {
            partida = *dameElem(listaPartidas, dameNumElem(listaPartidas));
        }*/
        if (juega(partida, cont)) {
            eliminarPartida(listaPartidas, partida);
            archivoEscr.open("partidasNew.txt");
            if (archivoEscr.is_open()) {
                guardarListaPartidas(archivoEscr, listaPartidas);
                //no guarda las bombillas
                destruyePartida(partida); //no se si hay que usar destruye listapartidas
            }
            archivoEscr.close();

        }
    }

    return 0;
}
