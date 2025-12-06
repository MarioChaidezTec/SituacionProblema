#include "Envio.h"
#include <string>
#include <vector>
#include "Cliente.h"
#include "Producto.h"
#include "Repartidor.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Envio::Envio() {
    this->id = "";
    this->estado = "No entregado";
    this->idRepartidor = "";
    // productos y cliente se inicializan automáticamente con sus constructores por defecto
}

// Constructor simplificado
Envio::Envio(string cId, Cliente cCliente) {
    this->id = cId;
    this->estado = "No entregado";
    this->cliente = cCliente;
    this->idRepartidor = "";
}

// Constructor completo
Envio::Envio(string cId, vector<Producto> cProductos,
             string cIdRepartidor, Cliente cCliente) {
    this->id = cId;
    this->estado = "No entregado";
    this->productos = cProductos;
    this->idRepartidor = cIdRepartidor;
    this->cliente = cCliente;
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


string Envio::getRepartidor() {
    return this -> idRepartidor;
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


void Envio::setRepartidor(Repartidor& cRepartidor) {
    this -> idRepartidor = cRepartidor.getIdentificacion();
}

void Envio::setCliente(Cliente cCliente) {
    this -> cliente = cCliente;
}

void Envio::agregarProducto(string nombre, float precio, int cantidad) {
    productos.emplace_back(nombre, precio, cantidad);
}

void Envio::eliminarProducto(string nombre) {
    for (int i = 0; i < productos.size(); i++){
        if (productos[i].getNombre() == nombre){
            productos.erase(productos.begin() + i);
        }
    }
}

double Envio::calculartotal() {
    double total = 0;
    for (int i = 0; i < productos.size(); i++){
        total += productos[i].getPrecio() * productos[i].getCantidad();
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
    string linea;
    while (getline(archivo, linea)){
        stringstream ss(linea);
        string nombre;
        string strPrecio;
        string strCantidad;

        getline(ss, nombre, ',');
        getline(ss, strPrecio, ',');
        getline(ss, strCantidad);

        productos.emplace_back(nombre, stof(strPrecio), stoi(strCantidad));
    }
    archivo.close();
    return 1;
}

void Envio::mostrarinfo() {
    cout << "El ID del envio es : " << this -> id << endl;
    cout << "El estado de este envio es: " << this -> estado << endl;
    cout << "Productos" << endl;
    cout << "---------------" << endl;
    for (int i = 0; i < productos.size(); i++){
        cout << productos[i].getNombre() << endl;
        cout << "Precio unitario: " << productos[i].getPrecio() << endl;
        cout << "Existen " << productos[i].getCantidad() << " unidades de este producto" << endl;
        cout << "----------------" << endl;
    }
    cout << "El costo total del envio es: " << calculartotal() << endl;
    cout << "El repartidor encargado de este envio es: " << this->idRepartidor << endl;
    cout << "El cliente asociado con este envio es: " << cliente.getNombre() << endl;
}

Envio::~Envio() {}
