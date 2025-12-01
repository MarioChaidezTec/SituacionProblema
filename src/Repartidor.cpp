//
// Created by luis1 on 01/12/2025.
//

#include "Repartidor.h"
#include "Envio.h"
#include <string>
#include <iostream>
using namespace std;

//constructores
Repartidor::Repartidor() {
    this->nombre = "";
    this->identificacion = "";
    this->modeloVehiculo = "";
    this->placaVehiculo = "";
    this->listaEnvios;
    this->limiteEnvios = 0;
}
Repartidor::Repartidor(string cNombre, string cIdentificacion, string cModeloVehiculo, string cPlacaVehiculo, vector<Envio> cListaEnvios, int cLimiteEnvios) {
    this->nombre = cNombre;
    this->identificacion = cIdentificacion;
    this->modeloVehiculo = cModeloVehiculo;
    this->placaVehiculo = cPlacaVehiculo;
    this->listaEnvios = cListaEnvios;
    this->limiteEnvios = cLimiteEnvios;
}

//getters y setters
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


