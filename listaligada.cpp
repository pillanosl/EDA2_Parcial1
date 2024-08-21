#include "listaligada.h"
#include <iostream>
#include <chrono>
// Biblioteca para medir el tiempo de ejecución

// Constructor que inicializa la lista vacía
ListaLigada::ListaLigada() : cabeza(nullptr) {}

// Destructor que libera la memoria de todos los nodos
ListaLigada::~ListaLigada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual; // Liberar la memoria del nodo actual
        actual = siguiente; // Avanzar al siguiente nodo
    }
}

// Método para imprimir la lista
void ListaLigada::imprimir() const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->data << std::endl;
        actual = actual->siguiente;
    }
}

// Método para agregar un nodo a la lista
void ListaLigada::agregar(const Pelicula& pelicula) {
    Nodo* nuevoNodo = new Nodo(pelicula);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

//ORDENAR POR CALIFICACIÓN

//ORDENAR BURBUJA
//Método para ordenar la lista usando el método de burbuja
void ListaLigada::ordenarBurbuja() {
    if (cabeza == nullptr) return; // Si la lista está vacía, no hacer nada

    bool intercambiado;
    do {
        intercambiado = false;
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            if (actual->data < actual->siguiente->data) {
                intercambiar(actual, actual->siguiente); // Intercambiar nodos si están en el orden incorrecto
                intercambiado = true;
            }
            actual = actual->siguiente; // Avanzar al siguiente nodo
        }
    } while (intercambiado); // Repetir hasta que no haya intercambios
}

// Método para intercambiar dos nodos si el primero es mayor que el segundo
void ListaLigada::intercambiar(Nodo* nodo1, Nodo* nodo2) {
    Pelicula temp = nodo1->data; // Guardar temporalmente los datos de nodo1
    nodo1->data = nodo2->data; // Copiar los datos de nodo2 a nodo1
    nodo2->data = temp; // Copiar los datos originales de nodo1 a nodo2
}


//ORDENAR MERGE SORT 
// Método para ordenar la lista usando merge sort
void ListaLigada::mergeSort() {
    cabeza = mergeSortRec(cabeza);
}

Nodo* ListaLigada::mergeSortRec(Nodo* head) {
    //Devuelve la cabeza si la lista está vacía o tiene un solo nodo
    if (head == nullptr || head->siguiente == nullptr) {
        return head;
    }

    //Se obtiene el nodo en la mitad de la lista
    Nodo* medio = obtenerMedio(head);
    //Se obtiene el nodo siguiente a medio
    Nodo* mitadSiguiente = medio->siguiente;

    medio->siguiente = nullptr;

    //Divide la lista en dos pares
    //Se llama recursivamente a la función para seguir dividiendo la lista en pares
    Nodo* izquierda = mergeSortRec(head); //Ordenar la primera mitad
    Nodo* derecha = mergeSortRec(mitadSiguiente); //Ordenar la segunda mitad

    return merge(izquierda, derecha); //Fusionar las dos mitades ordenadas
}

// Método auxiliar para fusionar dos listas ordenadas
Nodo* ListaLigada::merge(Nodo* left, Nodo* right) {
    if (left == nullptr) return right; // Si la lista izquierda está vacía, devolver la lista derecha
    if (right == nullptr) return left; // Si la lista derecha está vacía, devolver la lista izquierda

    //Ordenar de mayor a menor
    //Se compara el dato de nodo actual de la lista izquierda con el dato de nodo actual de la derecha
    if (left->data > right->data) {
        //Si el de left es mayor, se llama merge con el nodo siguiente a actual (izq) con el dato actual de derecha
        left->siguiente = merge(left->siguiente, right); // Fusionar el resto de la lista izquierda con la lista derecha
        return left;
    } else {
        //Si el de right es mayor, se llama merge con el nodo siguiente a actual (der) con el dato actual de izquierda
        right->siguiente = merge(left, right->siguiente); // Fusionar la lista izquierda con el resto de la lista derecha
        return right;
    }
}

Nodo* ListaLigada::obtenerMedio(Nodo* head) {
    if (head == nullptr) {
        return head;
    }

    Nodo* lento = head;
    Nodo* rapido = head->siguiente;

    //Por cada iteración, rápido se aleja +1 posición de lento,
    //se detiene cuando rápido se haya "salido" de la lista
    while (rapido != nullptr) {
        rapido = rapido->siguiente;
        if (rapido != nullptr) {
            lento = lento->siguiente;
            rapido = rapido->siguiente;
        }
    }
    return lento;
}

// ORDENAR QUICK SORT
// Método para ordenar la lista usando el método de QuickSort
void ListaLigada::quickSort() {
    quickSortRec(&cabeza);
}

// Método auxiliar para realizar el QuickSort de manera recursiva
void ListaLigada::quickSortRec(Nodo** cabezaRef) {
    Nodo* cabeza = *cabezaRef;
    if (cabeza == nullptr || cabeza->siguiente == nullptr) return;

    Nodo* nuevoCabeza = nullptr;
    Nodo* nuevoFin = nullptr;

    //Los inicios de estas listas están dados por nuevoCabeza y nuevoFin
    //Pivote siempre va a ser el último elemento de la lista
    //Nuevo cabeza es la cabeza de la sub lista con elementos mayoes a pivote
    //Nuevo fin es la cabeza de la sub lista con los elementos menores a pivote
    //Ambos son los mayores de su subcategoría

    Nodo* pivote = dividir(cabeza, obtenerUltimo(cabeza), &nuevoCabeza, &nuevoFin);

    if (nuevoCabeza != pivote) {
        Nodo* temp = nuevoCabeza;
        while (temp->siguiente != pivote) temp = temp->siguiente;
        temp->siguiente = nullptr;

        quickSortRec(&nuevoCabeza);

        temp = obtenerUltimo(nuevoCabeza);
        temp->siguiente = pivote;
    }

    quickSortRec(&(pivote->siguiente));
    *cabezaRef = nuevoCabeza;
}

// Método auxiliar para dividir la lista en dos partes según el pivote
Nodo* ListaLigada::dividir(Nodo* cabeza, Nodo* cola, Nodo** nuevoCabeza, Nodo** nuevoFin) {
    //Siempre va a tomar la cola de la lista como pivote
    //Pivote es el nodo a partir del cual se ordenan todos los datos
    Nodo* pivote = cola;
    Nodo* previo = nullptr, *actual = cabeza, *fin = pivote;

    //Se recorre la lista reubicando los nodos en función de si su dato es mayor o igual al de pivote
    while (actual != pivote) {
        if ((actual->data > pivote->data) || (actual->data == pivote->data)) {
            if ((*nuevoCabeza) == nullptr) (*nuevoCabeza) = actual;

            previo = actual;
            actual = actual->siguiente;
        } else {
            if (previo) previo->siguiente = actual->siguiente;

            Nodo* temp = actual->siguiente;
            actual->siguiente = nullptr;
            fin->siguiente = actual;
            fin = actual;
            actual = temp;
        }
    }

    if ((*nuevoCabeza) == nullptr) (*nuevoCabeza) = pivote;

    (*nuevoFin) = fin;

    return pivote;
}

Nodo* ListaLigada::obtenerUltimo(Nodo* cabeza) {
    while (cabeza != nullptr && cabeza->siguiente != nullptr) {
        cabeza = cabeza->siguiente;
    }
    return cabeza;
}

//ORDENAR POR FECHA

//ORDENAR BURBUJA
// Método para ordenar la lista usando el método de burbuja
void ListaLigada::ordenarBurbujaFecha() {
    if (cabeza == nullptr) return; // Si la lista está vacía, no hacer nada

    bool intercambiado;
    do {
        intercambiado = false;
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            if (actual->data.fechaMenor(actual->siguiente->data)){
                intercambiar(actual, actual->siguiente); // Intercambiar nodos si están en el orden incorrecto
                intercambiado = true;
            }
            actual = actual->siguiente; // Avanzar al siguiente nodo
        }
    } while (intercambiado); // Repetir hasta que no haya intercambios
}


//ORDENAR MERGE SORT 
// Método para ordenar la lista usando merge sort
void ListaLigada::mergeSortFecha() {
    cabeza = mergeSortRecFecha(cabeza);
}

Nodo* ListaLigada::mergeSortRecFecha(Nodo* head) {
    if (head == nullptr || head->siguiente == nullptr) {
        return head;
    }

    //Se crea lista de head en adelante
    Nodo* medio = obtenerMedio(head);
    Nodo* mitadSiguiente = medio->siguiente;

    medio->siguiente = nullptr;

    Nodo* izquierda = mergeSortRecFecha(head); //Ordenar la primera mitad
    Nodo* derecha = mergeSortRecFecha(mitadSiguiente); //Ordenar la segunda mitad

    return mergeFecha(izquierda, derecha); //Fusionar las dos mitades ordenadas
}

// Método auxiliar para fusionar dos listas ordenadas
Nodo* ListaLigada::mergeFecha(Nodo* left, Nodo* right) {
    if (left == nullptr) return right; // Si la lista izquierda está vacía, devolver la lista derecha
    if (right == nullptr) return left; // Si la lista derecha está vacía, devolver la lista izquierda

    //Ordenar de mayor a menor
    if(left->data.fechaMayor(right->data)) {
    //if (left->data > right->data) {
        left->siguiente = mergeFecha(left->siguiente, right); // Fusionar el resto de la lista izquierda con la lista derecha
        return left;
    } else {
        right->siguiente = mergeFecha(left, right->siguiente); // Fusionar la lista izquierda con el resto de la lista derecha
        return right;
    }
}


// ORDENAR QUICK SORT
// Método para ordenar la lista usando el método de QuickSort
void ListaLigada::quickSortFecha() {
    quickSortRecFecha(&cabeza);
}

// Método auxiliar para realizar el QuickSort de manera recursiva
void ListaLigada::quickSortRecFecha(Nodo** cabezaRef) {
    Nodo* cabeza = *cabezaRef;
    if (cabeza == nullptr || cabeza->siguiente == nullptr) return;

    Nodo* nuevoCabeza = nullptr;
    Nodo* nuevoFin = nullptr;

    //Divide la lista en dos pares 
    Nodo* pivote = dividirFecha(cabeza, obtenerUltimo(cabeza), &nuevoCabeza, &nuevoFin);

    if (nuevoCabeza != pivote) {
        Nodo* temp = nuevoCabeza;
        while (temp->siguiente != pivote) temp = temp->siguiente;
        temp->siguiente = nullptr;

        quickSortRecFecha(&nuevoCabeza);

        temp = obtenerUltimo(nuevoCabeza);
        temp->siguiente = pivote;
    }

    quickSortRecFecha(&(pivote->siguiente));
    *cabezaRef = nuevoCabeza;
}

// Método auxiliar para dividir la lista en dos partes según el pivote
Nodo* ListaLigada::dividirFecha(Nodo* cabeza, Nodo* cola, Nodo** nuevoCabeza, Nodo** nuevoFin) {
    Nodo* pivote = cola;
    Nodo* previo = nullptr, *actual = cabeza, *fin = pivote;

    while (actual != pivote) {
        if ((actual->data.fechaMayor(pivote->data)) || (actual->data.fechaIgual(pivote->data))) {
        //Se mantiene actual en su posición
            if ((*nuevoCabeza) == nullptr) (*nuevoCabeza) = actual;

            previo = actual;
            actual = actual->siguiente;
        } else {
            //
            if (previo) previo->siguiente = actual->siguiente;

            Nodo* temp = actual->siguiente;
            actual->siguiente = nullptr;
            fin->siguiente = actual;
            fin = actual;
            actual = temp;
        }
    }

    if ((*nuevoCabeza) == nullptr) (*nuevoCabeza) = pivote;

    (*nuevoFin) = fin;

    return pivote;
}

//OBSERVACIONES
//Se utiliza Nodo** para poder modificar los punteros pasados como argumentos,
//se pasan por referencia entonces se modifican los originales.    

//Dividir separa la lista en dos sublistas, una con los nodos menores a pivote y 
//otra con los nodos mayores a pivote.


