#include "listaPartidas.h"
void iniciaListaPartidas(tListaPartidas& listaPartidas) {
    listaPartidas.nElem = 0;
    for (int i = 0; i < MAX_PARTIDAS; i++) {
        listaPartidas.datos[i] = *new tPtrPartida; //mirar si lo del asterisco esta bien
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
    while(i < listaPartidas.nElem && !operator<(*listaPartidas.datos[i], nivel)) {
        i++;
    }
    return i;
}
tPtrPartida dameElem(const tListaPartidas& listaPartidas, int pos) {
    return listaPartidas.datos[buscaPos(listaPartidas, pos)];
}

int dameNumElem(const tListaPartidas& listaPartidas) {
    return listaPartidas.nElem;
}
void eliminarPartida(tListaPartidas& listaPartidas, const tPartida partida) {
    int i = 0;
    //while (i < listaPartidas.nElem &&  ) algo de ponerla en el contador, reducir el contador y luego volver a ordenar la lista

}
void guardarListaPartidas (ofstream& archivo, const tListaPartidas& listaPartidas) {
    archivo<< listaPartidas.nElem;
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