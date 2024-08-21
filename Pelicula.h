#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <iostream>
using namespace std;

class Pelicula {
private:
    string fecha;
    string titulo;
    float calificacion;
    int duracion;
    string director;

public:
    Pelicula(const string& titulo, const string& fecha, float calificacion,
             int duracion, const string& director);

    void setTitulo(const string& titulo);
    void setFecha(const string& fecha);
    void setCalificacion(float calificacion);
    void setDuracion(int duracion);
    void setDirector(const string& director);

    const string& getTitulo() const;
    const string& getFecha() const;
    float getCalificacion() const;
    int getDuracion() const;
    const string& getDirector() const;

    friend std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula);

    //Comparar por calificación
    bool operator>(const Pelicula& otra) const;
    bool operator<(const Pelicula& otra) const;
    bool operator==(const Pelicula& otra) const;

    //Comparar por año de estreno
    int obtenerAño(const std::string& fecha) const;
    bool fechaIgual(const Pelicula& otra) const;
    bool fechaMayor(const Pelicula& otra) const;
    bool fechaMenor(const Pelicula& otra) const;
};

#endif // PELICULA_H
