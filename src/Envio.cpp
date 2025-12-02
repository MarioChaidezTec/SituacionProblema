#include "Envio.h"
#include <string>
#include <vector>
#include "Cliente.h"
#include "Producto.h"
#include "Repartidor.h"
#include <iostream>
#include <fstream>

using namespace std;

Envio::Envio() {
    this -> id = " ";
    this -> estado = " ";
    this -> productos;
    this -> cantidad;
    this -> repartidor;
    this -> cliente;
}

Envio::Envio(string cId, string cEstado, vector<Producto> cProductos, vector<int> cCantidad,
             Repartidor cRepartidor, Cliente cCliente) {
    this -> id = cId;
    this -> estado = cEstado;
    this -> productos  = cProductos;
    this -> cantidad = cCantidad;
    this -> repartidor = cRepartidor;
    this -> cliente = cCliente;
}

string Envio::getId() {
    return this -> id;
}

string Envio::getEstado() {
    return this -> estado;
}

vector<Producto> Envio::getProductos() {
    return this -> productos;
}

vector<int> Envio::getCantidad() {
    return this -> cantidad;
}

Repartidor Envio::getRepartidor() {
    return this -> repartidor;
}

Cliente Envio::getCliente() {
    return this -> cliente;
}

void Envio::setId(string cId) {
    this -> id = cId;
}

void Envio::setProductos(vector<Producto> cProducto) {
    this -> productos = cProducto;
}

void Envio::setCantidad(vector<int> cCantidad) {
    this -> cantidad = cCantidad;
}

void Envio::setRepartidor(Repartidor cRepartidor) {
    this -> repartidor = cRepartidor;
}

void Envio::setCliente(Cliente cCliente) {
    this -> cliente = cCliente;
}

void Envio::agregarProducto(string nombre, float precio, int cCantidad) {
    productos.emplace_back(nombre, precio);
    cantidad.push_back(cCantidad);
}

void Envio::eliminarProducto(string nombre) {
    for (int i = 0; i < productos.size(); i++){
        if (productos[i].getNombre() == nombre){
            productos.erase(productos.begin() + i);
            cantidad.erase(cantidad.begin() + i);
        }
    }
}

double Envio::calculartotal() {
    double total = 0;
    for (int i = 0; i < productos.size(); i++){
        total += productos[i].getPrecio() * cantidad[i];
    }
    return total;
}

void Envio::cambiarEstado(string cEstado) {
    this -> estado = cEstado;
}

int Envio::leerFichero(string fichero) {
    ifstream archivo(fichero);
    if (!archivo.is_open()){
        cout << "El archivo no se pudo abrir, porfavor utilize un archivo valido" << endl;
        return -1;
    }
    string nombre;
    float precio;
    int cantidad1;

    while (archivo >> nombre >> precio >> cantidad1){
        productos.emplace_back(nombre, precio);
        cantidad.push_back(cantidad1);
    }
    return 1;
}

void Envio::mostrarinfo() {
    cout << "El ID del envio es : " << this -> id << endl;
    cout << "El estado de este envio es: " << this -> estado << endl;

    for (int i = 0; i < productos.size(); i++){
        cout << productos[i].getNombre() << "," << productos[i].getPrecio() << endl;
        cout << "Existen" << cantidad[i] << " unidades de este producto" << endl;
    }
    cout << "El repartidor encargado de este envio es: " << repartidor.getNombre() << endl;
    cout << "El cliente asociado con este envio es: " << cliente.getNombre() << endl;
}

Envio::~Envio() {}
