#ifndef SITUACIONPROBLEMA_ENVIO_H
#define SITUACIONPROBLEMA_ENVIO_H

#include "Cliente.h"
#include "Producto.h"
#include <string>
#include <vector>
using namespace std;

class Repartidor;

class Envio {
private:
    string id;
    string estado;
    vector<Producto> productos;
    vector<int> cantidad;
    string idRepartidor;
    Cliente cliente;
public:
    // Constructores
    Envio();
    Envio(string cId, vector<Producto> cProductos,
          vector<int> cCantidad, Repartidor& cRepartidor, Cliente cCliente);

    // Getters
    string getId();
    string getEstado();
    int getProductos();
    int getCantidad();
    Cliente getCliente();
    string getRepartidor();

    // Setters
    void setId(string cId);
    void setProductos(vector<Producto> cProducto);
    void setCantidad(vector<int> cCantidad);
    void setCliente(Cliente cCliente);
    void setRepartidor(Repartidor& cRepartidor);

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
