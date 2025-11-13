¿Para qué se implementó?
El sistema de roles se implementó para:
Crear rejugabilidad infinita: Cada combinación de roles genera una experiencia de juego completamente diferente
Añadir profundidad estratégica: Los jugadores deben adaptar sus estrategias según el rol propio y del oponente
Diferenciar el proyecto: Ningún otro proyecto de Damas tendrá un sistema similar
Balancear habilidad y suerte: Las habilidades especiales permiten jugadas tácticas que pueden cambiar el curso de la partida
Aumentar el engagement: Los jugadores querrán probar todas las combinaciones de roles

¿Por qué se consideró necesario?
Razones técnicas:

Demuestra dominio de estructuras de datos complejas
Requiere manejo de estados temporales y cooldowns
Implementa lógica condicional avanzada
Gestiona efectos que persisten entre turnos

Razones de diseño:

Las Damas clásicas tienen jugabilidad predecible
Los jugadores experimentados pueden estancarse en rutinas y monotonia
El sistema de roles agrega un "meta-juego" de elección de personajes
Permite que jugadores de diferentes niveles compitan de forma más equilibrada

 ¿Cómo se llevó a cabo su implementación?
 Fase 1: Diseño de la Arquitectura
Estructuras de datos creadas:
cpp// Enumeración de tipos de roles
enum TipoRol {
    ROL_NINGUNO,    // Modo clásico sin habilidades
    ROL_REY,        // Control y dominio
    ROL_GUERRERO,   // Agresión y capturas
    ROL_MAGO        // Manipulación táctica
};

// Estructura de habilidad individual
struct Habilidad {
    std::string nombre;           // Nombre descriptivo
    std::string descripcion;      // Explicación de la habilidad
    int usosRestantes;            // Contador de usos disponibles
    int cooldownActual;           // Turnos hasta poder usarla de nuevo
    int cooldownMaximo;           // Turnos de cooldown base
    bool esUsoUnico;              // Si solo se puede usar una vez
};

// Estructura de rol completo
struct Rol {
    TipoRol tipo;                 // Tipo de rol
    std::string nombre;           // Nombre del rol
    std::string descripcion;      // Descripción del estilo
    std::string icono;            // Identificador visual [REY], [MAGO], etc.
    Habilidad habilidades[3];     // Array de 3 habilidades
};

// Estructura de efectos activos
struct EfectoActivo {
    std::string nombre;           // Nombre del efecto
    int turnosRestantes;          // Duración restante
    bool afectaAmbosJugadores;    // Si afecta a ambos jugadores
    char jugadorAfectado;         // 'B', 'N', o 'X' (ambos)
};
Modificaciones a estructuras existentes:
cppstruct Jugador {
    // ... campos existentes
    Rol rol;                      // Rol seleccionado
    int turnosJugados;            // Contador de turnos
    bool tieneTurnoExtra;         // Flag para turno doble (Rey)
    bool furiaActiva;             // Flag para furia (Guerrero)
};

struct Pieza {
    // ... campos existentes
    bool congelada;               // Si está congelada (Mago)
    int turnosCongelada;          // Turnos de congelación restantes
};

struct Juego {
    // ... campos existentes
    EfectoActivo efectosActivos[5]; // Array de efectos activos
    int numEfectosActivos;          // Contador de efectos
    bool modoRoles;                 // Si el juego usa roles
};
Fase 2: Implementación de los 3 Roles
ROL: REY - Maestro del Control
Filosofía de diseño: Control absoluto del juego mediante manipulación de turnos y recursos.
Habilidades implementadas:
#NombreTipoImplementación1Turno DobleUso únicoActiva flag tieneTurnoExtra que previene el cambio de turno2Revivir PiezaUso únicoBusca pieza inactiva, solicita posición, reactiva pieza3Decreto RealCooldown 5Escanea tablero, muestra piezas enemigas con movimientos
Código clave (Turno Doble):
cppbool habilidadRey_TurnoDoble(Juego* juego) {
    Jugador* jugador = obtenerJugadorActual(juego);
    jugador->tieneTurnoExtra = true;
    std::cout << "\n[REY] Turno doble activado!\n";
    return true;
}

// En cambiarTurno():
void cambiarTurno(Juego* juego) {
    if (obtenerJugadorActual(juego)->tieneTurnoExtra) {
        std::cout << "\n[REY] Tienes un turno extra!\n";
        obtenerJugadorActual(juego)->tieneTurnoExtra = false;
        return; // NO cambiar turno
    }
    // ... cambiar turno normal
}

 ROL: GUERRERO - Maestro del Combate
Filosofía de diseño: Agresión pura mediante bonificaciones en capturas.
Habilidades implementadas:
#NombreTipoImplementación1Furia de Batalla2 usosActiva flag, próxima captura elimina 2 piezas2Sacrificio TácticoCooldown 7Elimina 1 pieza propia, permite 2 movimientos con otra3Sed de SangreUso únicoAgrega efecto global: capturas obligatorias por 3 turnos
Código clave (Furia de Batalla):
cppbool habilidadGuerrero_FuriaBatalla(Juego* juego) {
    Jugador* jugador = obtenerJugadorActual(juego);
    jugador->furiaActiva = true;
    return true;
}

// En ejecutarMovimiento() después de captura:
if (obtenerJugadorActual(juego)->furiaActiva) {
    // Buscar pieza enemiga cercana adicional
    for (int i = destinoF-2; i <= destinoF+2; i++) {
        for (int j = destinoC-2; j <= destinoC+2; j++) {
            Pieza* p = obtenerPiezaEn(&juego->tablero, i, j);
            if (p != nullptr && p->color == colorEnemigo) {
                eliminarPiezaEn(&juego->tablero, i, j);
                break; // Solo eliminar 1 pieza adicional
            }
        }
    }
    jugador->furiaActiva = false;
}

ROL: MAGO - Maestro de lo Arcano
Filosofía de diseño: Manipulación táctica del tablero mediante efectos especiales.
Habilidades implementadas:
#NombreTipoImplementación1TeletransporteUso únicoMueve pieza a cualquier casilla vacía2Coronación MágicaCooldown 8Convierte peón en dama instantáneamente3Congelar2 usosInmoviliza pieza enemiga por 2 turnos
Código clave (Congelar):
cppbool habilidadMago_Congelar(Juego* juego) {
    // ... validaciones y selección de pieza
    pieza->congelada = true;
    pieza->turnosCongelada = 2;
    return true;
}

// En ejecutarMovimiento() antes de mover:
if (pieza->congelada) {
    std::cout << "Error: Esta pieza esta congelada por " 
              << pieza->turnosCongelada << " turnos.\n";
    return false;
}

// En cambiarTurno():
void actualizarEfectosActivos(Juego* juego) {
    for (int i = 0; i < juego->numPiezas; i++) {
        if (juego->piezas[i].congelada) {
            juego->piezas[i].turnosCongelada--;
            if (juego->piezas[i].turnosCongelada <= 0) {
                juego->piezas[i].congelada = false;
            }
        }
    }
}

Fase 3: Sistema de Gestión
Funciones de gestión de roles:
cpp// Inicialización
void inicializarRol(Rol* rol, TipoRol tipo);

// Selección
TipoRol seleccionarRol(const std::string& nombreJugador);

// Visualización
void mostrarRolesDisponibles();
void mostrarHabilidadesRol(const Rol* rol);

// Cooldowns
void actualizarCooldowns(Rol* rol);
bool puedeUsarHabilidad(const Rol* rol, int indice);
void usarHabilidad(Rol* rol, int indice);
Sistema de efectos activos:
cppvoid agregarEfecto(Juego* juego, const char* nombre, int turnos, 
                   bool ambos, char jugador);
void actualizarEfectosActivos(Juego* juego);
bool tieneEfectoActivo(Juego* juego, const char* nombre);

Fase 4: Integración con el Juego Base
Modificaciones en el flujo del juego:

Inicio del juego:

cpp   void configurarModoJuego(Juego* juego) {
       // Pregunta: ¿Modo con Roles o Clásico?
       juego->modoRoles = (opcion == 1);
   }
   
   void configurarJugadores(Juego* juego) {
       // Si modoRoles == true:
       TipoRol rol = seleccionarRol(jugador->nombre);
       inicializarRol(&jugador->rol, rol);
   }

Durante el turno:

cpp   void jugarTurno(Juego* juego) {
       // Mostrar habilidades disponibles
       // Opción -2 -2 -2 -2 para usar habilidad
       if (origenF == -2 && juego->modoRoles) {
           mostrarMenuHabilidades(juego);
           ejecutarHabilidad(juego, numHabilidad);
       }
   }

Al cambiar turno:

cpp   void cambiarTurno(Juego* juego) {
       // Actualizar cooldowns
       actualizarCooldowns(&jugadorActual->rol);
       // Actualizar efectos activos
       actualizarEfectosActivos(juego);
       // Cambiar turno (a menos que tenga turno extra)
   }

Balance de Roles
Tabla Comparativa
Aspecto                  Rey           Guerrero          Mago        
Dificultad               Media            Fácil            Alta
Estilo                   Control         Agresivo        Táctico
Ventaja Temprana         Baja             Alta           Media
Ventaja Tardía           Alta             Media            Alta
Curva de Aprendizaje     Moderada          Baja            Alta
Habilidades de Uso Único   2               1                 1
Cooldowns                  1               1                  1
Estrategias Recomendadas
 Rey:

Guardar "Turno Doble" para momentos críticos
Usar "Decreto Real" frecuentemente para anticipar
"Revivir Pieza" es más efectivo en etapa final

 Guerrero:

Activar "Furia" antes de capturas importantes
"Sed de Sangre" cuando tengas ventaja posicional
Juego agresivo desde el inicio

 Mago:

"Teletransporte" para salvar piezas o preparar ataques
"Coronación Mágica" crea ventaja rápidamente
"Congelar" piezas clave del oponente

