#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include "nodo.h"

class ListaLigada {
public:
    void agregar(const Pelicula& pelicula);
    void imprimir() const;
    // Constructor que inicializa la lista vacía
    ListaLigada();
    // Destructor que libera la memoria de todos los nodos
    ~ListaLigada();
    // Método para intercambiar dos nodos si el primero es mayor que el segundo
    void intercambiar(Nodo* nodo1, Nodo* nodo2);

    // ORDENAMIENTO POR CALIFICACIÓN
    // Método para ordenar la lista usando el método MergeSort
    void mergeSort();
    // Método para ordenar la lista usando el método BubbleSort
    void ordenarBurbuja();
    // Método para ordenar la lista usando el método de QuickSort
    void quickSort();

    // ORDENAMIENTO POR FECHA
    // Método para ordenar la lista usando el método MergeSort
    void mergeSortFecha();
    // Método para ordenar la lista usando el método BubbleSort
    void ordenarBurbujaFecha();
    // Método para ordenar la lista usando el método de QuickSort
    void quickSortFecha();
    


private:
    Nodo* cabeza = nullptr;
    //Se utiliza para fecha y para calificación
    Nodo* obtenerMedio(Nodo* head);
    Nodo* obtenerUltimo(Nodo* cabeza);

    //ORDENAMIENTO CALIFICACIÓN
   
    // Método auxiliar para realizar el MergeSort de manera recursiva
    Nodo* mergeSortRec(Nodo* head);
    Nodo* merge(Nodo* izquierda, Nodo* derecha);
  
    // Método auxiliar para realizar el QuickSort de manera recursiva
    void quickSortRec(Nodo** cabezaRef);
    // Método auxiliar para dividir la lista en dos partes según el pivote
    Nodo* dividir( Nodo* cabeza, Nodo* cola, Nodo** nuevoCabeza, Nodo** nuevoFin);
    

    //ORDENAMIENTO FECHA

    // Método auxiliar para realizar el MergeSort de manera recursiva
    Nodo* mergeSortRecFecha(Nodo* head);
    Nodo* mergeFecha(Nodo* izquierda, Nodo* derecha);

    // Método auxiliar para realizar el QuickSort de manera recursiva
    void quickSortRecFecha(Nodo** cabezaRef);
    // Método auxiliar para dividir la lista en dos partes según el pivote
    Nodo* dividirFecha( Nodo* cabeza, Nodo* cola, Nodo** nuevoCabeza, Nodo** nuevoFin);


};

#endif // LISTALIGADA_H