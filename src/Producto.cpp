//
// Created by gusco on 12/1/2025.
//

#include "Producto.h"
#include <string>

using namespace std;

Producto::Producto() {
    this -> nombre = " ";
    this -> precio = 0;
    this -> cantidad = 0;
}

Producto::Producto(std::string cNombre, float cPrecio, int cCantidad) {
    this -> nombre = cNombre;
    this -> precio = cPrecio;
    this -> cantidad = cCantidad;
}

string Producto::getNombre() {
    return this -> nombre;
}

float Producto::getPrecio() {
    return this -> precio;
}

int Producto::getCantidad() {
    return this -> cantidad;
}

void Producto::setNombre(string cNombre) {
    this -> nombre = cNombre;
}

void Producto::setPrecio(float cPrecio) {
    this -> precio = cPrecio;
}

void Producto::setCantidad(int cCantidad) {
    this -> cantidad = cCantidad;
}

Producto::~Producto() {}