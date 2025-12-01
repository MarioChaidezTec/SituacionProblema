//
// Created by luis1 on 01/12/2025.
//

#include "Cliente.h"
#include <string>
using namespace std;

//constructors
Cliente::Cliente() {
    this->nombre = "";
    this->direccion = "";
    this->telefono = "";
}
Cliente::Cliente(string cNombre, string cDireccion, string cTelefono) {
    this->nombre = cNombre;
    this->direccion = cDireccion;
    this->telefono = cTelefono;
}

//getters and setters
string Cliente::getNombre() {
    return this->nombre;
}
void Cliente::setNombre(string cNombre) {
    this->nombre = cNombre;
}

string Cliente::getDireccion() {
    return this->direccion;
}
void Cliente::setDireccion(string cDireccion) {
    this->direccion = cDireccion;
}

string Cliente::getTelefono() {
    return this->telefono;
}
void Cliente::setTelefeno(string cTelefono) {
    this->telefono = cTelefono;
}

Cliente::~Cliente() {}



