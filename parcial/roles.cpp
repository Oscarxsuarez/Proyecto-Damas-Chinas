#include "estructuras.h"
#include <iostream>

// Inicializa un rol con sus habilidades específicas
void inicializarRol(Rol* rol, TipoRol tipo) {
    rol->tipo = tipo;
    
    switch(tipo) {
        case ROL_REY:
            rol->nombre = "Rey";
            rol->descripcion = "Poder absoluto - Control total del juego";
            rol->icono = "[REY]";
            
            rol->habilidades[0].nombre = "Turno Doble";
            rol->habilidades[0].descripcion = "Jugar dos turnos seguidos";
            rol->habilidades[0].usosRestantes = 1;
            rol->habilidades[0].cooldownActual = 0;
            rol->habilidades[0].cooldownMaximo = 0;
            rol->habilidades[0].esUsoUnico = true;
            
            rol->habilidades[1].nombre = "Revivir Pieza";
            rol->habilidades[1].descripcion = "Recuperar una pieza capturada";
            rol->habilidades[1].usosRestantes = 1;
            rol->habilidades[1].cooldownActual = 0;
            rol->habilidades[1].cooldownMaximo = 0;
            rol->habilidades[1].esUsoUnico = true;
            
            rol->habilidades[2].nombre = "Decreto Real";
            rol->habilidades[2].descripcion = "Ver todos los movimientos validos del rival";
            rol->habilidades[2].usosRestantes = 999;
            rol->habilidades[2].cooldownActual = 0;
            rol->habilidades[2].cooldownMaximo = 5;
            rol->habilidades[2].esUsoUnico = false;
            break;
            
        case ROL_GUERRERO:
            rol->nombre = "Guerrero";
            rol->descripcion = "Maestro del combate - Especialista en capturas";
            rol->icono = "[GUERRERO]";
            
            rol->habilidades[0].nombre = "Furia de Batalla";
            rol->habilidades[0].descripcion = "Proxima captura cuenta doble (elimina 2 piezas)";
            rol->habilidades[0].usosRestantes = 2;
            rol->habilidades[0].cooldownActual = 0;
            rol->habilidades[0].cooldownMaximo = 0;
            rol->habilidades[0].esUsoUnico = false;
            
            rol->habilidades[1].nombre = "Sacrificio Tactico";
            rol->habilidades[1].descripcion = "Sacrifica 1 pieza para mover otra 2 veces";
            rol->habilidades[1].usosRestantes = 999;
            rol->habilidades[1].cooldownActual = 0;
            rol->habilidades[1].cooldownMaximo = 7;
            rol->habilidades[1].esUsoUnico = false;
            
            rol->habilidades[2].nombre = "Sed de Sangre";
            rol->habilidades[2].descripcion = "Capturas obligatorias para ambos por 3 turnos";
            rol->habilidades[2].usosRestantes = 1;
            rol->habilidades[2].cooldownActual = 0;
            rol->habilidades[2].cooldownMaximo = 0;
            rol->habilidades[2].esUsoUnico = true;
            break;
            
        case ROL_MAGO:
            rol->nombre = "Mago";
            rol->descripcion = "Maestro de lo arcano - Manipula el tablero";
            rol->icono = "[MAGO]";
            
            rol->habilidades[0].nombre = "Teletransporte";
            rol->habilidades[0].descripcion = "Mueve una pieza a cualquier casilla vacia";
            rol->habilidades[0].usosRestantes = 1;
            rol->habilidades[0].cooldownActual = 0;
            rol->habilidades[0].cooldownMaximo = 0;
            rol->habilidades[0].esUsoUnico = true;
            
            rol->habilidades[1].nombre = "Coronacion Magica";
            rol->habilidades[1].descripcion = "Convierte un peon en dama instantaneamente";
            rol->habilidades[1].usosRestantes = 999;
            rol->habilidades[1].cooldownActual = 0;
            rol->habilidades[1].cooldownMaximo = 8;
            rol->habilidades[1].esUsoUnico = false;
            
            rol->habilidades[2].nombre = "Congelar";
            rol->habilidades[2].descripcion = "Congela una pieza enemiga por 2 turnos";
            rol->habilidades[2].usosRestantes = 2;
            rol->habilidades[2].cooldownActual = 0;
            rol->habilidades[2].cooldownMaximo = 0;
            rol->habilidades[2].esUsoUnico = false;
            break;
            
        default:
            rol->nombre = "Sin Rol";
            rol->descripcion = "Modo clasico sin habilidades";
            rol->icono = "[CLASICO]";
            break;
    }
}

void mostrarRolesDisponibles() {
    std::cout << "\n*********************************************\n";
    std::cout << "           ROLES DISPONIBLES                  \n";
    std::cout << "***********************************************\n\n";
    
    std::cout << "[REY] 1. REY - Poder Absoluto\n";
    std::cout << "    Turno Doble (1 uso)\n";
    std::cout << "    Revivir Pieza (1 uso)\n";
    std::cout << "    Decreto Real (cooldown 5 turnos)\n";
    std::cout << "   Estilo: Control y dominio del juego\n\n";
    
    std::cout << "[GUERRERO] 2. GUERRERO - Maestro del Combate\n";
    std::cout << "   Furia de Batalla (2 usos)\n";
    std::cout << "   Sacrificio Tactico (cooldown 7 turnos)\n";
    std::cout << "   Sed de Sangre (1 uso)\n";
    std::cout << "   Estilo: Agresivo y ofensivo\n\n";
    
    std::cout << "[MAGO] 3. MAGO - Maestro Arcano\n";
    std::cout << "   Teletransporte (1 uso)\n";
    std::cout << "   Coronacion Magica (cooldown 8 turnos)\n";
    std::cout << "   Congelar (2 usos)\n";
    std::cout << "   Estilo: Tactico y estrategico\n\n";
    
    std::cout << "[CLASICO] 4. SIN ROL - Modo Clasico\n";
    std::cout << "   Sin habilidades especiales\n\n";
}

TipoRol seleccionarRol(const std::string& nombreJugador) {
    mostrarRolesDisponibles();
    
    int opcion;
    std::cout << nombreJugador << ", selecciona tu rol (1-4): ";
    std::cin >> opcion;
    
    switch(opcion) {
        case 1: return ROL_REY;
        case 2: return ROL_GUERRERO;
        case 3: return ROL_MAGO;
        case 4: return ROL_NINGUNO;
        default:
            std::cout << "Opcion invalida. Asignando ROL_NINGUNO.\n";
            return ROL_NINGUNO;
    }
}

void mostrarHabilidadesRol(const Rol* rol) {
    if (rol->tipo == ROL_NINGUNO) {
        std::cout << "\nNo tienes habilidades (modo clasico).\n";
        return;
    }
    
    std::cout << "\n************************************\n";
    std::cout <<  rol->icono << " HABILIDADES DE " << rol->nombre << "\n";
    std::cout << "**************************************\n";
    
    for (int i = 0; i < 3; i++) {
        std::cout << "\n[" << (i + 1) << "] " << rol->habilidades[i].nombre << "\n";
        std::cout << "    " << rol->habilidades[i].descripcion << "\n";
        
        if (rol->habilidades[i].cooldownActual > 0) {
            std::cout << "    [COOLDOWN: " << rol->habilidades[i].cooldownActual << " turnos]\n";
        } else if (rol->habilidades[i].usosRestantes == 0) {
            std::cout << "    [SIN USOS]\n";
        } else if (rol->habilidades[i].esUsoUnico) {
            std::cout << "    [DISPONIBLE - " << rol->habilidades[i].usosRestantes << " uso]\n";
        } else if (rol->habilidades[i].usosRestantes < 999) {
            std::cout << "    [DISPONIBLE - " << rol->habilidades[i].usosRestantes << " usos]\n";
        } else {
            std::cout << "    [DISPONIBLE]\n";
        }
    }
    std::cout << "\n";
}

void mostrarDetalleRol(TipoRol tipo) {
    Rol rol;
    inicializarRol(&rol, tipo);
    
    std::cout << "\n******************************************\n";
    std::cout << rol.icono << " " << rol.nombre << "\n";
    std::cout << "********************************************\n";
    std::cout << rol.descripcion << "\n";
    
    mostrarHabilidadesRol(&rol);
}

void actualizarCooldowns(Rol* rol) {
    for (int i = 0; i < 3; i++) {
        if (rol->habilidades[i].cooldownActual > 0) {
            rol->habilidades[i].cooldownActual--;
        }
    }
}

bool puedeUsarHabilidad(const Rol* rol, int indiceHabilidad) {
    if (indiceHabilidad < 0 || indiceHabilidad >= 3) {
        return false;
    }
    
    const Habilidad& hab = rol->habilidades[indiceHabilidad];
    
    if (hab.cooldownActual > 0) {
        return false;
    }
    
    if (hab.usosRestantes <= 0) {
        return false;
    }
    
    return true;
}

void usarHabilidad(Rol* rol, int indiceHabilidad) {
    if (indiceHabilidad < 0 || indiceHabilidad >= 3) {
        return;
    }
    
    Habilidad& hab = rol->habilidades[indiceHabilidad];
    
    if (hab.usosRestantes < 999) {
        hab.usosRestantes--;
    }
    
    hab.cooldownActual = hab.cooldownMaximo;
    
    std::cout << "\n ¡Habilidad '" << hab.nombre << "' activada!\n";
}

std::string obtenerNombreRol(TipoRol tipo) {
    switch(tipo) {
        case ROL_REY: return "Rey";
        case ROL_GUERRERO: return "Guerrero";
        case ROL_MAGO: return "Mago";
        default: return "Sin Rol";
    }
}