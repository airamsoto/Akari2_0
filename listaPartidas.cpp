#include "listaPartidas.h"

void iniciaListaPartidas(tListaPartidas& listaPartidas) {
    listaPartidas.nElem = 0;
    for (int i = 0; i < MAX_PARTIDAS; i++) {
        listaPartidas.datos[i] = new tPartida;
    }
}
void ordenaPartidas (tListaPartidas& listaPartidas) {
    for (int i = 1; i < listaPartidas.nElem; i++) {
        tPtrPartida aux = listaPartidas.datos[i];
        int j = i;
        while ( j > 0 && operator<(*aux , *listaPartidas.datos[j-1])) {
            listaPartidas.datos[j] = listaPartidas.datos[j-1];
            j--;
        }
        listaPartidas.datos[j] = aux;
    }
}
void cargarListaPartidas(ifstream& archivo, tListaPartidas& listaPartidas) {
        archivo >> listaPartidas.nElem;
        for (int i = 0; i < listaPartidas.nElem; ++i) {
            cargarPartida(archivo, *listaPartidas.datos[i]);
        }
    ordenaPartidas(listaPartidas);
}


void insertarOrd(tListaPartidas& listaPartidas, const tPartida& partida) {
    int i= 0;
    bool esMenor= true;
    while (i < listaPartidas.nElem && esMenor){
        esMenor = operator<(*listaPartidas.datos[i], partida);
        if (!esMenor){
            *listaPartidas.datos[i]= partida;
        } else{
            i++;
        }
    }
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
    for (int i = 0; i < listaPartidas.nElem;i++) {
        destruyePartida(*listaPartidas.datos[i]);
    }
}