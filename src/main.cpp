#include <iostream>
#include "Repartidor.h"
#include "Envio.h"
#include <vector>
#include <string>
#include "Cliente.h"
using namespace std;

Repartidor repartidor1;
vector<Envio> envios;
vector<Repartidor> repartidores;

void mostrarMenu() { //muestra el menu de gestion
    cout << "********** MENU DE GESTION DE ENVIOS **********" << endl;
    cout << "1. Crear envio" << endl;
    cout << "2. Agregar producto" << endl;
    cout << "3. Elmininar producto" << endl;
    cout << "4. Mostrar informacion" << endl;
    cout << "5. Cambiar el estado" << endl;
    cout << "6. Asignar repartidor a un envio" << endl;
    cout << "7. Salir" << endl;
}

void crearEnvio() { //funcion para crear envio
    string id;
    cout << "Ingrese una id: ";
    cin >> id;
    string estado;
    estado = "No completado";

    string nombreCliente;
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombreCliente;
    string direccionCliente;
    cout << "Ingrese la direccion del cliente: ";
    cin >> direccionCliente;
    string telefonoCliente;
    cout << "Ingrese el telefono del cliente: ";
    cin >> telefonoCliente;

    Cliente cliente(nombreCliente,direccionCliente,telefonoCliente);
    Envio envio(id,estado, {}, {},repartidor1, cliente);
    envios.push_back(envio);
}

void agregarProducto() {
    for (auto& envio : envios) {
        int i = 1;
        cout << "Envio: " << i << " ID: " << envio.getId() << endl;
        i++;
    }
    string id;
    cout << "Escribe el id del envio: " << endl;
    cin >> id;
    for (auto& envio : envios) {
        if (envio.getId() == id) {
            string fichero;
            cout << "Ingrese el fichero con los productos: " << endl;
            cin >> fichero;
            envio.leerFichero(fichero);
            cout << "Productos agregados" << endl;
        }
        else cout << "No se encuentra el ID del envio" << endl;
    }
}

void mostrarInfo() {
    for (auto& envio : envios) {
        int i = 1;
        cout << "Envio: " << i << " ID: " << envio.getId() << endl;
        i++;
    }
    string id;
    cout << "Escribe el id del envio: " << endl;
    cin >> id;
    for (auto& envio : envios) {
        if (envio.getId() == id) {
            envio.mostrarinfo();
        }
        else cout << "No se encuentra el ID del envio" << endl;
    }
}

void cambiarEstado(){
    for (auto& repartidor: repartidores){
        cout << "Seleccione la ID de un repartidor" << endl;
        cout << repartidor.getNombre() << " ID: " << repartidor.getIdentificacion();
    }
    string id;
    cin >> id;
    for(auto& repartidor: repartidores){
        if (repartidor.getIdentificacion() == id){
            cout << "Envios asignados al repartidor" << endl;
            for (auto& envio :repartidor.getListaEnvios()) {
                int i = 1;
                cout << "Envio: " << i << " ID: " << envio.getId() << endl;
            }
            string idEnvio;
            cout << "Seleccione el envio a entregar: " << endl; cin >> idEnvio;
            for (auto& envio : repartidor.getListaEnvios()){
                if (idEnvio == envio.getId()){
                    repartidor.entregarEnvio(idEnvio);
                } else cout << "Envio no encontrado" << endl;
            }
        } else cout << "Repartidor no encontrado" << endl;
    }
}

int main(){

    int opcion = 0;

    while (opcion != 7) {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1: crearEnvio();
                break;
            case 2: agregarProducto();
                break;
            case 4: mostrarInfo();
                break;
            default: cout << "Opcion invalida" << endl;
        }
    }


    return 0;
}