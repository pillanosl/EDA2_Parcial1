# Parcial Estructura de Datos y Algoritmos

### Introducción
Este proyecto contiene la implementación de tres algoritmos de ordenamiento en C++ para el caso de un catálogo de películas:
- Burbuja.
- QuickSort.
- MergeSort.

### Integrantes

- Isabella Camacho Mosalve.
- Sofía Isaareth Flores Suarez.
- Paula Inés Llanos López.
- Luis Ángel Neiro Pereira.

### Contenido

- `Parcial1_Datos`: Carpeta que contiene los archivos del código fuente con las implementaciones de los algoritmos de ordenamiento.
- `README.md`: Este archivo con instrucciones para compilar y ejecutar el programa.

#### Clases y Funciones Principales
- `archivo.cpp` : Leer desde archivo, imprimir items, generar items aleatorios, generar fecha aleatoria, número tipo entero y float.
- `Pelicula.cpp` : Constructor del objeto, métodos para comparar fechas, getters y setters, sobrecarga de operadores `<, > o ==`.
- `nodo.cpp` : Constructor.
- `main.cpp`: Método para leer desde los archivos `.txt` y guardar su contenido en los generadores, métodos para generar todos los títulos de películas de forma aleatoria, creación de la lista y ordenamiento con obtención de tiempo de ordenamiento.
- `listaligada.cpp` : Métodos mergeSort, quickSort, ordenarBurbuja con sus respectivos métodos auxiliares para implementarse de forma recursiva.

### Instrucciones de Compilación y Ejecución

### Requisitos

Asegúrate de tener instalado un compilador de C++ como `g++`.

### Compilación

Para compilar el programa, abre una terminal en VSC y navega al directorio que contiene la carpeta Parcial1_Datos. 
Ejecuta en este orden los siguientes comando en la terminal:

```sh
g++ -c main.cpp nodo.cpp listaligada.cpp archivo.cpp Pelicula.cpp

g++ main.cpp -o mi_programa nodo.o listaligada.o archivo.o Pelicula.o

./mi_programa

