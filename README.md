# Proyecto-Damas-Chinas

Integrantes del grupo Oscar Suarez Cañon | Nicolas Perez 

Curso: Pensamiento Algoritmico

Fecha: 13 de Noviembre del 2025

Guías de compilación

Guía para Windows (con MinGW o g++)

1.Abre el Bloc de notas (o cualquier editor como Notepad++).

Copia el código del repositorio y guárdalo como este con .cpp en tu escritorio.
Al guardar, selecciona: a. Tipo de archivo: "Todos los archivos" b. Nombre: (como este en el repositorio).cpp  y (como este en el repositorio).h c. Codificación: UTF-8

Abre el Explorador de Archivos y busca la carpeta donde guardaste (como lo guardaste).cpp. Ejemplo: C:\Users\TuUsuario\Documents\cpp\

4.Copia la ruta de la carpeta (arriba en la barra de dirección).

5.Abre la terminal de Windows (CMD o PowerShell).

Ve a la carpeta donde está tu archivo que copiaste con el comando cd: Ejemplo: cd C:\Users\TuUsuario\Documents\cpp
7.Compila el programa con: g++ (como lo guardaste).cpp  (como lo guardaste).h y los que sean necesarios -o (como lo guardaste).exe

8 .Ejecuta el programa con: (como lo guardaste).exe

Guía para Linux (Ubuntu/Debian/otros)

1.Abre tu editor de texto favorito (nano, gedit, vim).

2.Ve a la carpeta donde está el archivo (como lo guardaste).cpp. Ejemplo, si está en Documentos/cpp: cd ~/Documentos/cpp

Compila el archivo con g++:

g++ (como lo guardaste).cpp  (como lo guardaste).h y los que sean necesarios-o (como lo guardaste) 4.Ejecuta el programa con: ./(como lo guardaste)

Guía para MacOS

1.Abre la aplicación Terminal (búscala en Spotlight con Cmd + Espacio → "Terminal").

2.Ve a la carpeta donde está el archivo (como lo guardaste).cpp.

3.Ve a la carpeta donde está el archivo (como lo guardaste).cpp. Ejemplo, si está en Documents/cpp:

Compila el archivo con g++: g++ (como lo guardaste).cpp   (como lo guardaste).h y los que sean necesarios -o (como lo guardaste)

Ejecuta el programa: ./(como lo guardaste)
Instrucciones de ejecución 1.Seguir los pasos de como compilar y ejecutar segun el sistema operativo

2.Entrar a la carpeta del archivo. 3.Compilar el archivo correspondiente con g++. 4.Ejecutar el programa generado .


Repositorio: taller/

├── README.md

├── parcial/ │ ├──estructuras.h

│ ├── habilidades.cpp

│ ├── habilidades.h

│ ├── juego.cpp

│ ├── juego.h

│ └── jugador.cpp

│ └── jugador.h

│ └── main.cpp

│ └── menu.cpp

│ └── menu.h

│ └── pieza.cpp

│ └── pieza.h

│ └── roles.cpp

│ └── roles.h

│ └── tablero.cpp

│ └── tablero.h
# Compilar
g++ -std=c++17  main.cpp pieza.cpp tablero.cpp jugador.cpp roles.cpp habilidades.cpp juego.cpp menu.cpp -o damas.exe

# Ejecutar
./damas.exe
Innovacion:
Nuevo modo de juego de damas internacionales, incluyendo un modo el cual es el de roles, que tiene tres: rey, guerrero y mago, el cual cada uno tiene sus habilidades y ventajas sobre el otro, esto tiene potencial ya que cambia la forma de jugarlo sin quitarle la esencia al juego de damas chinas, que hace que no sea monotoma la jugabilidad, y sean infinitas las posibilidades de jugar este
