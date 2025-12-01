//
// Created by gusco on 12/1/2025.
//

#ifndef SITUACIONPROBLEMA_PRODUCTO_H
#define SITUACIONPROBLEMA_PRODUCTO_H
#include <string>
using namespace std;

class Producto {
private:
    string nombre; // Atributo nombre
    float precio; // Atributo precio
public:
    // Constructores
    Producto();
    Producto(string cNombre, float cPrecio);

    // Getters
    string getNombre();
    float getPrecio();

    // Setters
    void setPrecio(float cPrecio);
    void setNombre(string cNombre);

    // Destructor
    ~Producto();

};


#endif //SITUACIONPROBLEMA_PRODUCTO_H
