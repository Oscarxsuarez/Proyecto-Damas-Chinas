#include "juego.h"
#include "menu.h"
#include <iostream>


int main() {
    bool salir = false;
    
    while (!salir) {
        int opcion = mostrarMenuPrincipal();
        
        switch (opcion) {
            case 1: {
                // Nueva partida
                Juego juego;
                inicializarJuego(&juego);
                jugar(&juego);
                
                std::cout << "\n¿Deseas jugar otra partida? (s/n): ";
                char respuesta;
                std::cin >> respuesta;
                std::cin.ignore();
                
                if (respuesta != 's' && respuesta != 'S') {
                    salir = true;
                }
                break;
            }
            case 2:
                mostrarReglas();
                break;
            case 3:
                mostrarCreditos();
                break;
            case 4:
                salir = true;
                std::cout << "\n¡Gracias por jugar!\n\n";
                break;
            default:
                std::cout << "\nOpcion invalida. Intenta nuevamente.\n";
                pausar();
                break;
        }
    }
    
    return 0;
}