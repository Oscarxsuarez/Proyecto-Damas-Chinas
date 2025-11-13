#include "pieza.h"

void inicializarPieza(Pieza* pieza, int fila, int col, char color) {
    pieza->fila = fila;
    pieza->columna = col;
    pieza->color = color;
    pieza->esDama = false;
    pieza->activa = true;
}

// Obtiene el símbolo para mostrar en el tablero
char obtenerSimbolo(const Pieza* pieza) {
    if (pieza->color == 'B') {
        return pieza->esDama ? 'B' : 'b';
    } else {
        return pieza->esDama ? 'N' : 'n';
    }
}
void coronarPieza(Pieza* pieza) {
    pieza->esDama = true;
}
bool esDamaPieza(const Pieza* pieza) {
    return pieza->esDama;
}
char obtenerColorPieza(const Pieza* pieza) {
    return pieza->color;
}
bool estaActivaPieza(const Pieza* pieza) {
    return pieza->activa;
}
void desactivarPieza(Pieza* pieza) {
    pieza->activa = false;
}