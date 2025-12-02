//
// Created by gusco on 12/1/2025.
//

#ifndef SITUACIONPROBLEMA_ENVIO_H
#define SITUACIONPROBLEMA_ENVIO_H

#include "Cliente.h"
#include "Producto.h"
#include "Repartidor.h"
#include <string>
#include <vector>
using namespace std;

class Envio {
private:
    string idEnvio;
    string estado;
    vector<Producto> productos;
    vector<int> cantidad;
    Repartidor repartidor;
    Cliente cliente;
public:
    // Constructores
    Envio();
    Envio(string cIdEnvio, vector<Producto> cProductos,
          vector<int> cCantidad, Repartidor cRepartidor, Cliente cCliente);

    // Getters
    string getIdEnvio();
    string getEstado();
    vector<Producto> getProductos();
    vector<int> getCantidad();
    Cliente getCliente();
    Repartidor getRepartidor();

    // Setters
    void setIdEnvio(string cIdEnvio);
    void setProductos(vector<Producto> cProducto);
    void setCantidad(vector<int> cCantidad);
    void setCliente(Cliente cCliente);
    void setRepartidor(Repartidor cRepartidor);

    // Metodos
    void agregarProducto(string nombre, float precio, int cCantidad);
    int estaProducto(Producto& producto);
    void eliminarProducto(string nombre);
    double calculartotal();
    void cambiarEstado(string cEstado);
    int leerFichero(string fichero);
    void mostrarinfo();

    // Destructor
    ~Envio();
};


#endif //SITUACIONPROBLEMA_ENVIO_H
