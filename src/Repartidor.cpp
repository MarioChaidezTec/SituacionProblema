#include "Repartidor.h"
#include "Envio.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Repartidor::estaDisponible(){
    return (this->listaEnvios.size() < this->limiteEnvios);
}

void Repartidor::agregarEnvio(Envio& envio){
    if (estaDisponible()) this->listaEnvios.push_back(envio);
    else cout << "Repartidor no disponible" << endl;
    
}

int Repartidor::estaEnvio(string id){
    int i = 0;
    for (auto&e : this->listaEnvios){
        if (e.getId() == id) return i;
        else i++;
    }
    return -1;
}

void Repartidor::entregarEnvio(string id){
    if (this->listaEnvios.size() == 0){
        cout << "Error: el repartidor no tiene envios" << endl;
        return;
    }
    int indice = estaEnvio(id);
    if (!indice == -1) {
        listaEnvios.erase(listaEnvios.begin() + indice);
        cout << "Envio entregado" << endl;
    } else cout << "Envio no existe" << endl;
}

void Repartidor::imprimir(){
    cout << "--Datos del repartidor--" << endl;
    cout << "\nNombre: " << this->nombre << endl;
    cout << "Identificacion: " << this->identificacion << endl;
    cout << "Modelo de vehiculo: " << this->modeloVehiculo << endl;
    cout << "Placas de vehiculo: " << this->placaVehiculo << endl;
    cout << "Capacidad maxima de envios: " << this->limiteEnvios << " envios" << endl;
    cout << "Numero de envios: " << this->listaEnvios.size() << endl;
    cout << "\n-Lista de envios-" << endl;
    for (auto &e : this->listaEnvios) {
        e.mostrarinfo();
    }
}

Repartidor::Repartidor() {
    this->nombre = "";
    this->identificacion = "";
    this->modeloVehiculo = "";
    this->placaVehiculo = "";
    this->listaEnvios;
    this->limiteEnvios = 0;
}
Repartidor::Repartidor(string cNombre, string cIdentificacion, string cModeloVehiculo, string cPlacaVehiculo, int cLimiteEnvios) {
    this->nombre = cNombre;
    this->identificacion = cIdentificacion;
    this->modeloVehiculo = cModeloVehiculo;
    this->placaVehiculo = cPlacaVehiculo;
    this->listaEnvios;
    this->limiteEnvios = cLimiteEnvios;
}

string Repartidor::getNombre() {
    return this->nombre;
}
void Repartidor::setNombre(string cNombre) {
    this->nombre = cNombre;
}

string Repartidor::getIdentificacion() {
    return this->identificacion;
}
void Repartidor::setIdentificacion(string cIdentificacion) {
    this->identificacion = cIdentificacion;
}

string Repartidor::getModeloVehiculo() {
    return this->modeloVehiculo;
}
void Repartidor::setModeloVehiculo(string cModeloVehiculo) {
    this->modeloVehiculo = cModeloVehiculo;
}

string Repartidor::getPlacaVehiculo() {
    return this->placaVehiculo;
}
void Repartidor::setPlacaVehiculo(string cPlacaVehiculo) {
    this->placaVehiculo = cPlacaVehiculo;
}

int Repartidor::getLimiteEnvios() {
    return this->limiteEnvios;
}
void Repartidor::setLimiteEnvios(int cLimiteEnvios) {
    this->limiteEnvios = cLimiteEnvios;
}
