#include "Repartidor.h"
#include "Envio.h"
#include <iostream>
#include <vector>
using namespace std;

bool Repartidor::estaDisponible(){
    return (this->listaEnvios.size() < this->limiteEnvios);
}

void Repartidor::agregarEnvio(Envio& envio){
    if (estaDisponible()) this->listaEnvios.push_back(envio);
    else cout << "Repartidor no disponible" << endl;
    
}

int Repartidor::estaEnvio(Envio& envio){
    int i = 0;
    for (auto&e : this->listaEnvios){
        if (e == envio) return i;
        else i++;
    }
    return -1;
}
void Repartidor::entregarEnvio(Envio& envio){
    if (this->listaEnvios.size() == 0){
        cout << "Error: el repartidor no tiene envios" << endl;
        return;
    }
    int indice = estaEnvio(Envio& envio);
    if (!indice == -1) {
        listaEnvios.erase(indice);
        cout << "Envio entregado" << endl;
    } else cout << "Envio no existe" << endl;
}

void imprimir(){
    cout << "--Datos del repartidor--" << endl;
    cout << "\nNombre: " << this->nombre << endl;
    cout << "Identificacion: " << this->identificacion << endl;
    cout << "Modelo de vehiculo: " << this->modeloVehiculo << endl;
    cout << "Placas de vehiculo: " << this->placaVehiculo << endl;
    cout << "Capacidad maxima de envios: " << this->limiteEnvios << " envios" << endl;
    cout << "Numero de envios: " << this->listaEnvios.size() << endl;
    cout << "\n-Lista de envios-" << endl;
    for (auto &e : this->listaEnvios) {
        e.mostrarInfo();
    }
}