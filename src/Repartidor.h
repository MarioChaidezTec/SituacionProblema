#ifndef SITUACIONPROBLEMA_REPARTIDOR_H
#define SITUACIONPROBLEMA_REPARTIDOR_H

#include <string>
#include <vector>
#include "Envio.h"
using namespace std;

class Repartidor{
private:
    string nombre;
    string identificacion;
    string modeloVehiculo;
    string placaVehiculo;
    vector <Envio> listaEnvios;
    int limiteEnvios;

    int Repartidor::estaEnvio(Envio& envio);
public:
    // Constructores
    Repartidor(); // Default
    Repartidor(string cNombre, string cIdentificacion, string cModeloVehiculo, string cPlacaVehiculo, int cLimiteEnvios); // Parametrizado

    // Getters y setters
    string getNombre();
    void setNombre(string cNombre);
    string getIdentificacion();
    void setIdentificacion(string cIdentificacion);
    string getModeloVehiculo();
    void setModeloVehiculo(string cModeloVehiculo);
    string getPlacaVehiculo();
    void setPlacaVehiculo(string cPlacaVehiculo);
    int getLimiteEnvios();
    void setLimiteEnvios(int cLimiteEnvios);
    
    void agregarEnvio(Envio& envio); // Agrega un envio al vector listaEnvios 
    void entregarEnvio(Envio& envio); // Borra el envio del vector listaEnvios
    bool estaDisponible(); // Revisa si los envios del repartidor no exceden su limite de envios
    void imprimir(); // Imprime los datos de la instancia de Repartidor

    // Destructor
    ~Repartidor();
};


#endif