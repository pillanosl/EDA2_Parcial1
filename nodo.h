#ifndef NODO_H
#define NODO_H

#include "Pelicula.h"

class Nodo {
public:
    Pelicula data;
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(const Pelicula& data);
};

#endif // NODO_H