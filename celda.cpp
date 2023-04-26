#include "celda.h"

char celdaToChar(const tCelda& celda) {
    char aux = ' ';

    if (celda.tipo == BOMBILLA) {
        aux = '*';
    }
    else if (celda.tipo == PARED) {
        if (celda.numBombillas == 4) {
            aux = '4';
        }
        else if (celda.numBombillas == 3) {
            aux = '3';
        }
        else if (celda.numBombillas == 2) {
            aux = '2';
        }
        else if (celda.numBombillas == 1) {
            aux = '1';
        }
        else if (celda.numBombillas == 0) {
            aux = '0';
        }
        else if (celda.numBombillas == -1) {
            aux = ' ';
        }

    }
    return aux;

}

tCelda charToCelda(char c) {
    tCelda celda;
    if (c == 'X') {
        celda.tipo = PARED;
        celda.numBombillas = -1;
    }
    else if (c == '.') {
        celda.tipo = LIBRE;
        celda.numBombillas = 0;
    }
    else if (c == '*') {
        celda.tipo = BOMBILLA;
        celda.numBombillas = 1;
    }
    else if (c == '0') {
        celda.tipo = PARED;
        celda.numBombillas = 0;
    }
    else if (c == '1') {
        celda.tipo = PARED;
        celda.numBombillas = 1;
    }
    else if (c == '2') {
        celda.tipo = PARED;
        celda.numBombillas = 2;
    }
    else if (c == '3') {
        celda.tipo = PARED;
        celda.numBombillas = 3;
    }
    else if (c == '4') {
        celda.tipo = PARED;
        celda.numBombillas = 4;
    }
    else if (c == ' ') {
        celda.tipo = PARED;
        celda.numBombillas = -1;
    }
    return celda;
}

bool esPared(const tCelda& c) {
    return c.tipo == PARED;
}
bool esParedRestringida(const tCelda& c) {
    bool ok = false;
    if (c.tipo == PARED && (c.numBombillas <= 4 && c.numBombillas >= 0)) {
        ok = true;
    }
    return ok;
}

int numParedRestringida(const tCelda& c) {
    return c.numBombillas;
}

bool esBombilla(const tCelda& c) {
    return c.tipo == BOMBILLA;
}

bool estaApagada(const tCelda& c) {
    return c.tipo == LIBRE && c.numBombillas == 0;
}
bool estaIluminada(const tCelda& c) {
    return c.tipo == LIBRE && c.numBombillas > 0;
}
void apagaCelda(tCelda& c) {
    c.tipo = LIBRE;
    c.numBombillas = 0;
}

void actualizaIluminacionCelda(tCelda& c, bool iluminar) {
    if (iluminar) {
        c.numBombillas++;
    }
    else {
        c.numBombillas--;
    }
}
void ponBombilla(tCelda& c) {
    c.tipo = BOMBILLA;
}

char celdaToCharArchivo(const tCelda& celda) {
    char aux = '.';

    if (celda.tipo == BOMBILLA) { //esto?
        aux = '.';
    }
    else if (celda.tipo == PARED) {
        if (celda.numBombillas == 4) {
            aux = '4';
        }
        else if (celda.numBombillas == 3) {
            aux = '3';
        }
        else if (celda.numBombillas == 2) {
            aux = '2';
        }
        else if (celda.numBombillas == 1) {
            aux = '1';
        }
        else if (celda.numBombillas == 0) {
            aux = '0';
        }
        else if (celda.numBombillas == -1) {
            aux = ' ';
        }

    }
    return aux;

}