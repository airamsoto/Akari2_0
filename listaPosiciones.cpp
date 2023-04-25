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

void insertar (tListaPosiciones& lp, const tPosicion& pos) {
    /*if (lp.cont == lp.size) {
        lp.size *= 2;
    }
    lp.arrayPos[lp.cont] = pos;*/
    if (lp.cont < lp.size) {
        lp.arrayPos[lp.cont] = pos;
    } else {
        lp.size *= 2;
    }

}

int dameNumElem (const tListaPosiciones& lp) {
    return lp.cont;
}
tPosicion dameElem (const tListaPosiciones& lp, int i) {
    return lp.arrayPos[i];
}

void guardarListaBombilla  (ofstream& archivo, const tListaPosiciones& lp) {
    for (int i = 0; i < lp.cont; i++) {
        archivo << dameX(lp.arrayPos[i]) << " " << dameY(lp.arrayPos[i]) << endl;
    }
}

void eliminar (tListaPosiciones& lp, const tPosicion& pos) { //CAMBIAR MIRAR BUSCAPOS
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
        lp.arrayPos[aux] = lp.arrayPos[aux+1];
    }
    lp.cont--;
}