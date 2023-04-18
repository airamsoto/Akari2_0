#ifndef AKARI2_0_LISTAPOSICIONES_H
#define AKARI2_0_LISTAPOSICIONES_H
#include "posicion.h"
const int DIM = 2;
tPosicion *tAyy;

typedef struct {
    int cont;
    int  size;
    tPosicion *arrayPos;
}tListaPosiciones;


void iniciaListaPosiciones (tListaPosiciones& lp);
void destruyeListaPosiciones (tListaPosiciones& lp);
void insertar (tListaPosiciones& lp, const tPosicion& pos);
int dameNumElem (const tListaPosiciones& lp);
tPosicion dameElem (const tListaPosiciones& lp, int i);
void guardarListaBombilla  (ofstream& archivo, const tListaPosiciones& lp);

#endif //AKARI2_0_LISTAPOSICIONES_H
