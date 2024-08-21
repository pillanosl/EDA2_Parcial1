#include <iostream>
#include <chrono>
#include "Pelicula.h"
#include "listaligada.h"
#include "archivo.h"
#include "nodo.h"

Archivo generador;
Archivo generador2;
Archivo generador3;

void cargarDatos(Archivo &gener, const std::string& file) {
    gener.leerDesdeArchivo(file);
}

std::string SimularTituloPelicula() {
    return generador.obtenerItemAleatorio() + " " + generador2.obtenerItemAleatorio();
}

std::string SimularFecha() {
    return generador.fechaAleatoria(1950, 2024);
}

float SimularCalificacion() {
    return generador.generarNumeroFloat(1.5, 5.0);
}

int SimularDuracion() {
    return generador.generarNumeroEntero(0, 200);
}

std::string SimularDirector() {
    return generador3.obtenerItemAleatorio();
}

int main() {
    ListaLigada lista, lista2;

    cargarDatos(generador, "parte1.txt");
    cargarDatos(generador2, "parte2.txt");
    cargarDatos(generador3, "nombresDirectores.txt");

    for (int i = 0; i < 10; i++) {
        lista.agregar(Pelicula(SimularTituloPelicula(), SimularFecha(), SimularCalificacion(), SimularDuracion(), SimularDirector()));
    }

    std::cout << "Lista de peliculas:" << std::endl;
    lista.imprimir();

    lista2 = lista;
    auto inicio = std::chrono::high_resolution_clock::now();

    //MÉTODOS DE ORDENAMIENTO

    lista2.mergeSort();  
    //lista2.quickSort(); 
    //lista2.ordenarBurbuja(); 

    //lista2.mergeSortFecha();
    //lista2.ordenarBurbujaFecha(); 
    //lista2.quickSortFecha(); 

    auto fin = std::chrono::high_resolution_clock::now();

    //Imprimir lista después de ordenar
    std::cout << "Lista despues de ordenar:" << std::endl;
    lista2.imprimir();
    
    //Imprimir tiempos de ordenamiento
    cout << "Inicio: " << inicio.time_since_epoch().count() << endl;
    cout << "Fin: " << fin.time_since_epoch().count() << endl;
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo de ordenamiento: " << duracion.count() << " s" << std::endl;

    lista.~ListaLigada();
    
    return 0;
}