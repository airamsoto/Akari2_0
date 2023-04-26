#include "listaPartidas.h"
void iniciaListaPartidas(tListaPartidas& listaPartidas) {
    listaPartidas.nElem = 0;
    for (int i = 0; i < MAX_PARTIDAS; i++) {
        listaPartidas.datos[i] = new tPartida;
    }
}
void cargarListaPartidas(ifstream& archivo, tListaPartidas& listaPartidas) {
        archivo >> listaPartidas.nElem;
        for (int i = 0; i < listaPartidas.nElem; ++i) {
            cargarPartida(archivo, *listaPartidas.datos[i]);
        }
}

void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida) {
   int i = listaPartidas.nElem;
   tPtrPartida punteroPartida = listaPartidas.datos[listaPartidas.nElem];
   *punteroPartida = partida;
   while (operator<(*listaPartidas.datos[i - 1], partida) && i > 0) {
       listaPartidas.datos[i] = listaPartidas.datos[i-1];
       i--;
   }
   listaPartidas.datos[i] = punteroPartida;
}

int buscaPos(const tListaPartidas& listaPartidas, int nivel) {
    int i = 0;
    int pos = -1;
    while(i < listaPartidas.nElem && pos == -1) {
        if (!operator<(*listaPartidas.datos[i], nivel)) {
            pos = i;
        } else {
            i++;
        }
    }
    return pos;
}
tPtrPartida dameElem(const tListaPartidas& listaPartidas, int pos) {
    return listaPartidas.datos[pos];
}

int dameNumElem(const tListaPartidas& listaPartidas) {
    return listaPartidas.nElem;
}

void eliminarPartida(tListaPartidas& listaPartidas, const tPartida partida) {
    int pos = buscaPos(listaPartidas, partida.nivel);
    for (int i = pos; i < listaPartidas.nElem; i++) {
        listaPartidas.datos[i] = listaPartidas.datos[i+1];
    }
    listaPartidas.nElem--;
}

void guardarListaPartidas (ofstream& archivo, const tListaPartidas& listaPartidas) {
    archivo << listaPartidas.nElem << endl;
    for (int i = 0; i < listaPartidas.nElem; ++i) {
        guardarPartida(archivo, *listaPartidas.datos[i]);
    }

}

void destruyeListaPartidas(tListaPartidas& listaPartidas) {
    listaPartidas.nElem = 0;
    for (int i = 0; i < MAX_PARTIDAS; i++) {
        delete listaPartidas.datos[i];
        listaPartidas.datos[i] = nullptr;
    }
}