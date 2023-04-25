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
        int pos = buscaPos(listaPartidas, n);
        if (buscaPos(listaPartidas, n) != -1) {
            partida = *dameElem(listaPartidas, n);
        }
        else if(buscaPos(listaPartidas, n) == -1) {
            int i = 0;
            int aux = -2;
            while (i < dameNumElem(listaPartidas) && aux == -2) { //falta mirar si se carga la partida con el -2
                if (buscaPos(listaPartidas, n) != -1) {
                    aux = i;
                } else  {
                    i++;
                }
            }
            partida = *dameElem(listaPartidas, aux);
            //cargarPartida(archivo, *dameElem(listaPartidas, aux));

        } else if ( operator<(*dameElem(listaPartidas, dameNumElem(listaPartidas)),  n)) {
            //cargarPartida(archivo, *dameElem(listaPartidas, dameNumElem(listaPartidas)));
            partida = *dameElem(listaPartidas, dameNumElem(listaPartidas));
        }
        cargarPartida(archivo, partida);
        juega(partida, cont);
        if (juega(partida, cont)) {
            eliminarPartida(listaPartidas, partida);
            guardarListaPartidas(archivoEscr, listaPartidas);
            destruyeListaPartidas(listaPartidas);
        }
    }

    return 0;
}
