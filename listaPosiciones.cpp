#include "listaPosiciones.h"

void iniciaListaPosiciones (tListaPosiciones& lp) {
    lp.cont = 0;
    lp.size = DIM;
    lp.arrayPos = new tPosicion [DIM];
}

void destruyeListaPosiciones (tListaPosiciones& lp) {
    lp.cont = 0;
    lp.size = 0;
    delete [] lp.arrayPos;
    lp.arrayPos = nullptr;
}
void ampliar (tListaPosiciones& lp) {
    tPosicion* puntero = lp.arrayPos;
    lp.size*=2;
    lp.arrayPos= new tPosicion [lp.size];
    for (int i = 0; i < lp.cont;i++) {
        lp.arrayPos[i] = puntero[i];
    }
    delete[] puntero;
}
void insertar (tListaPosiciones& lp, const tPosicion& pos) {
    if (lp.cont == lp.size) {
        ampliar(lp);
    }
    lp.arrayPos[lp.cont] = pos;
    lp.cont++;
}

int dameNumElem (const tListaPosiciones& lp) {
    return lp.cont;
}
tPosicion dameElem (const tListaPosiciones& lp, int i) {
    return lp.arrayPos[i];
}

void guardarListaBombilla  (ofstream& archivo, const tListaPosiciones& lp) {
    archivo << dameNumElem(lp) << endl;
    for (int i = 0; i < lp.cont; i++) {
        if (!operator== (lp.arrayPos[i], lp.arrayPos[i+1])) {
            guardarPosicion(archivo, dameElem(lp, i));
        }

    }
}

void eliminar (tListaPosiciones& lp, const tPosicion& pos) { //en teoria no hace falta
    int i = 0;
    int aux;
    bool ya = false;
    while (i < lp.cont && !ya) {
        if (operator==(lp.arrayPos[i], pos)) {
            ya = true;
            aux = i;
        } else {
            i++;
        }
    }
    for (int j = aux; j < lp.cont; j++) {
        lp.arrayPos[j] = lp.arrayPos[j+1];
    }
    lp.cont--;
}
