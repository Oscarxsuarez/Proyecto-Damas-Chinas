#include "pieza.h"
#include "tablero.h"
#include <iostream>

using namespace std;


void inicializarTablero(Tablero* tablero) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tablero->casillas[i][j] = nullptr;
        }
    }
}


void limpiarTablero(Tablero* tablero) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tablero->casillas[i][j] = nullptr;
        }
    }
}

#include <iostream>
#include <string>
using namespace std;

#define RESET   "\033[0m"
#define NEGRO   "\033[30m"
#define BLANCO  "\033[97m"
#define FONDO_OSCURO "\033[48;5;236m"   // gris oscuro
#define FONDO_CLARO "\033[48;5;250m"    // gris claro
#define FONDO_PIEZA "\033[48;5;28m"     // blanco para piezas activas

void mostrarTablero(const Tablero* tablero) {
    cout << "\n     ";
    for (int j = 0; j < 10; j++) cout << j << "   ";
    cout << "\n   +" << string(10 * 4, '-') << "+\n";

    for (int i = 0; i < 10; i++) {
        cout << " " << i << " |";
        for (int j = 0; j < 10; j++) {
            Pieza* pieza = tablero->casillas[i][j];
            bool oscura = esCasillaOscura(i, j);

         
            string fondo = oscura ? FONDO_OSCURO : FONDO_CLARO;

            if (pieza != nullptr && estaActivaPieza(pieza)) {
                char simbolo = obtenerSimbolo(pieza);
                cout << fondo << " " << BLANCO << simbolo << " " << RESET << "|";
            } else {
                cout << fondo << "   " << RESET << "|";
            }
        }
        cout << " " << i << "\n   +" << string(10 * 4, '-') << "+\n";
    }

    cout << "     ";
    for (int j = 0; j < 10; j++) cout << j << "   ";
    cout << "\n\n" << RESET;
    cout << "Leyenda: b=peon blanco, B=DAMA blanca, n=peon negro, N=DAMA negra\n\n";
}


bool esCasillaOscura(int fila, int col) {
    return (fila + col) % 2 == 1;
}


bool esDentroDelTablero(int fila, int col) {
    return fila >= 0 && fila < 10 && col >= 0 && col < 10;
}

bool estaVaciaCasilla(const Tablero* tablero, int fila, int col) {
    if (!esDentroDelTablero(fila, col)) {
        return false;
    }
    Pieza* pieza = tablero->casillas[fila][col];
    return pieza == nullptr || !estaActivaPieza(pieza);
}


Pieza* obtenerPiezaEn(const Tablero* tablero, int fila, int col) {
    if (!esDentroDelTablero(fila, col)) {
        return nullptr;
    }
    Pieza* pieza = tablero->casillas[fila][col];
    if (pieza != nullptr && estaActivaPieza(pieza)) {
        return pieza;
    }
    return nullptr;
}


void colocarPiezaEn(Tablero* tablero, Pieza* pieza, int fila, int col) {
    if (esDentroDelTablero(fila, col)) {
        tablero->casillas[fila][col] = pieza;
        if (pieza != nullptr) {
            pieza->fila = fila;
            pieza->columna = col;
        }
    }
}


void eliminarPiezaEn(Tablero* tablero, int fila, int col) {
    if (esDentroDelTablero(fila, col)) {
        Pieza* pieza = tablero->casillas[fila][col];
        if (pieza != nullptr) {
            desactivarPieza(pieza);
            tablero->casillas[fila][col] = nullptr;
        }
    }
}


void moverPiezaEn(Tablero* tablero, int origenF, int origenC, int destinoF, int destinoC) {
    if (esDentroDelTablero(origenF, origenC) && esDentroDelTablero(destinoF, destinoC)) {
        Pieza* pieza = tablero->casillas[origenF][origenC];
        if (pieza != nullptr && estaActivaPieza(pieza)) {
            tablero->casillas[destinoF][destinoC] = pieza;
            tablero->casillas[origenF][origenC] = nullptr;
            pieza->fila = destinoF;
            pieza->columna = destinoC;
        }
    }
}


int contarPiezasColor(const Tablero* tablero, char color) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Pieza* pieza = tablero->casillas[i][j];
            if (pieza != nullptr && estaActivaPieza(pieza) && 
                obtenerColorPieza(pieza) == color) {
                count++;
            }
        }
    }
    return count;
}
