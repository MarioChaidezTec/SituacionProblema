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
    int cantidad; // Atributo cantidad
public:
    // Constructores
    Producto();
    Producto(string cNombre, float cPrecio, int cCantidad);

    // Getters
    string getNombre();
    float getPrecio();
    int getCantidad();

    // Setters
    void setPrecio(float cPrecio);
    void setNombre(string cNombre);
    void setCantidad(int cCantidad);

    // Destructor
    ~Producto();

};


#endif //SITUACIONPROBLEMA_PRODUCTO_H
