#include"Pelicula.h"
#include <string>
#include <iostream>
//using namespace std;

Pelicula::Pelicula(const::string& titulo, const::string& fecha, float calificacion, int duracion, const::string& director): titulo(titulo), fecha(fecha), calificacion(calificacion), duracion(duracion), director(director) {}


string getTitulo(string titulo)  {
    return titulo;
}

string getFecha(string fecha) {
    return fecha;
}

int getcalificacion(int calificacion) {
    return calificacion;
}

int getduracion(int duracion){
    return duracion;
}

string getdirector(string director){
    return director;
}

//MÉTODOS PARA COMPARAR POR CALIFICACIÓN

// Sobrecarga del operador << para permitir la salida de objetos Persona a un flujo de salida
std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula) {
    os << " Titulo: " << pelicula.titulo <<", Director: " << pelicula.director <<  ", Duracion: " << pelicula.duracion << ", Fecha: " << pelicula.fecha << ", Calificacion: " << pelicula.calificacion;
    return os;
}

// Sobrecarga del operador > para comparar dos objetos Persona por calificacion
bool Pelicula::operator>(const Pelicula& otra) const {
    return calificacion > otra.calificacion;
}

// Sobrecarga del operador < para comparar dos objetos Persona por edad
bool Pelicula::operator<(const Pelicula& otra) const {
    return calificacion < otra.calificacion;
}

// Sobrecarga del operador == para comparar dos objetos Persona por edad
bool Pelicula::operator==(const Pelicula& otra) const {
    return calificacion == otra.calificacion;
}


//MÉTODOS PARA COMPARAR POR FECHA 

//Se extrae el año de creación para hacer la comparación
int Pelicula::obtenerAño(const std::string& fechaStr) const{
    std::string fechaSub= fechaStr.substr(fechaStr.length() - 4, 4);
    int año = stoi(fechaSub);
    return año;
}

//Método que retorna True si los años son iguales
bool Pelicula::fechaIgual(const Pelicula& otra) const {
    int año1 = obtenerAño(this->fecha);   
    int año2 = obtenerAño(otra.fecha);    
        
    return año1 == año2;
}

//Métodos para retornar si una fecha es mayor o menor que a otra
bool Pelicula::fechaMayor(const Pelicula& otra) const {
    int año1 = obtenerAño(this->fecha);   
    int año2 = obtenerAño(otra.fecha);    
        
    return año1 > año2;
}
bool Pelicula::fechaMenor(const Pelicula& otra) const {
    int año1 = obtenerAño(this->fecha);   
    int año2 = obtenerAño(otra.fecha);    
        
    return año1 < año2;
}