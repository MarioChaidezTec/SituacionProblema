#include <iostream>
#include "Repartidor.h"
#include "Envio.h"
#include <vector>
#include <string>
#include "Cliente.h"
#include "Producto.h"
using namespace std;

Repartidor repartidor1("Victor Arevalo", "VA8382", "NP300", "BAV323", 20);
Repartidor repartidor2("Fercho", "FE2322", "Peugeot", "BAM32313", 25);
Repartidor repartidor3("Gabriel Zebo", "GBO2342", "Lancha", "BWR23423", 10);
vector<Envio> envios;
vector<Repartidor> repartidores {repartidor1, repartidor2, repartidor3};

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
    Envio envio(id, {}, {},repartidor1, cliente);
    envios.push_back(envio);
}

void agregarProducto() {
    int i = 1;
    for (auto& envio : envios) {
        cout << "Envio: " << i << " ID: " << envio.getId() << endl;
        i++;
    }
    string id;
    cout << "Escribe el id del envio: " << endl;
    cin >> id;

    bool envioEncontrado = false;
    for (auto& envio : envios) {
        if (envio.getId() == id) {
            envioEncontrado = true;
            string fichero;
            cout << "Ingrese el fichero con los productos: " << endl;
            cin >> fichero;
            envio.leerFichero(fichero);
            cout << "Productos agregados" << endl;
        }
    }
    if (!envioEncontrado) cout << "Envio no encontrado" << endl;
}

void eliminarProducto() {
    for (auto& envio : envios) {
        int i = 1;
        cout << "Envio: " << i << " ID: " << envio.getId() << endl;
        i++;
    }
    string id;
    cout << "Escribe el id del envio: " << endl;
    cin >> id;

    bool envioEncontrado = false; 
    for (auto& envio : envios) {
        if (envio.getId() == id) {
            bool envioEncontrado = true;
            int i = 1;
            for (auto& producto : envio.getProductos()) {
                cout << i << "." << producto.getNombre() << endl;
                i++;
            }
            string nombre;
            cout << "Ingrese el numero del producto a eliminar " << endl;
            cin >> nombre;

            bool productoEncontrado = false; 
            for (auto& producto : envio.getProductos()) {
                if (producto.getNombre() == nombre) {
                    bool productoEncontrado = true;
                    envio.eliminarProducto(nombre);
                    cout << "Producto eliminado" << endl;
                }
            }
            if (!productoEncontrado) cout << "Producto no encontrado" << endl;
        }
    }
    if (!envioEncontrado) cout << "Envio no encontrado" << endl; 
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

    bool envioEncontrado = false;
    for (auto& envio : envios) {
        if (envio.getId() == id) {
            envioEncontrado = true;
            envio.mostrarinfo();
        }
    }
    if (!envioEncontrado) cout << "Envio no encontrado" << endl;
}

void cambiarEstado(){
    for (auto& repartidor: repartidores){
        cout << "Seleccione la ID de un repartidor" << endl;
        cout << repartidor.getNombre() << " ID: " << repartidor.getIdentificacion();
    }
    string id;
    cin >> id;

    bool repartidorEncontrado = false;
    for(auto& repartidor: repartidores){
        if (repartidor.getIdentificacion() == id){
            repartidorEncontrado = true;
            cout << "Envios asignados al repartidor" << endl;
            for (auto& envio :repartidor.getListaEnvios()) {
                int i = 1;
                cout << "Envio: " << i << " ID: " << envio.getId() << endl;
            }
            string idEnvio;
            cout << "Seleccione el envio a entregar: " << endl; cin >> idEnvio;

            bool envioEncontrado = false;
            for (auto& envio : repartidor.getListaEnvios()){
                if (idEnvio == envio.getId()){
                    envioEncontrado = true;
                    repartidor.entregarEnvio(idEnvio);
                    cout << "Envio entregado" << endl;
                } 
            }
            if (!envioEncontrado) cout << "Envio no encontrado" << endl;
        }  
    }
    if (!repartidorEncontrado) cout << "Repartidor no encontrado" << endl;
}

void asignarRepartidor() {
    for (auto& envio : envios) {
        int i = 1;
        cout << "Envio: " << i << " ID: " << envio.getId() << endl;
        i++;
    }
    string id;
    cout << "Escribe el id del envio: " << endl;
    cin >> id;
    int a = 0;
    for (auto& envio : envios) {
        if (envio.getId() == id) {
            int i = 0;
            for (auto& repartidor :repartidores) {
                cout << i + 1 << "." << repartidores[i].getNombre() << " : " << repartidores[i].getIdentificacion() << endl;
                i++;
            }
            string identificacion;
            cout << "Ingrese el id del repartidor: " << endl; cin >> identificacion;
            for (auto &repartidor :repartidores) {
                if (repartidor.getIdentificacion() == identificacion) {
                    repartidor.agregarEnvio(envios[a]);
                    envio.setRepartidor(repartidor);
                    cout << "Envio asignado" << endl;
                    }
                }
        }
        a++;
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
            case 3: eliminarProducto();
                break;
            case 4: mostrarInfo();
                break;
            case 5: cambiarEstado();
                break;
            case 6: asignarRepartidor();
                break;
            default: cout << "Opcion invalida" << endl;
        }
    }


    return 0;
}