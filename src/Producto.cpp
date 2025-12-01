//
// Created by gusco on 12/1/2025.
//

#include "Producto.h"
#include <string>

using namespace std;

Producto::Producto() {
    this -> nombre = " ";
    this -> precio = 0;
}

Producto::Producto(string cNombre, float cPrecio) {
    this -> nombre = cNombre;
    this -> precio = cPrecio;
}

string Producto::getNombre() {
    return this -> nombre;
}

float Producto::getPrecio() {
    return this -> precio;
}

void Producto::setNombre(string cNombre) {
    this -> nombre = cNombre;
}

void Producto::setPrecio(float cPrecio) {
    this -> precio = cPrecio;
}

Producto::~Producto() {}