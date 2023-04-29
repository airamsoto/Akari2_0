#include <iostream>
#include "listaPartidas.h"

int main() {
    int n, cont = 0;
    ifstream archivo;
    ofstream archivoEscr;
    string archivoNuevo;
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
        }
        if (!juega(partida, cont)) {
            eliminarPartida(listaPartidas, partida);
        } else {
            insertarOrd(listaPartidas, partida);
            }
        cout << "Seleccione el archivo donde desea guardar la lista de partidas: ";
        cin >> archivoNuevo;
        archivoEscr.open(archivoNuevo);
        if (archivoEscr.is_open()) {
            guardarListaPartidas(archivoEscr, listaPartidas);
            destruyeListaPartidas(listaPartidas);
        }
        archivoEscr.close();
    }

    return 0;
}
