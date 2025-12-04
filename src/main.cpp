#include <iostream>
#include "Repartidor.h"
#include "Envio.h"
#include <vector>
#include <string>
#include "Cliente.h"
#include "Producto.h"
using namespace std;

Repartidor repartidor1("Victor Arevalo", "VA8382", "NP300", "BAV323", 1);
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
    cout << "Ingrese una id: "<< endl;
    getline(cin, id);

    string nombreCliente;
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nombreCliente);
    string direccionCliente;
    cout << "Ingrese la direccion del cliente: ";
    getline(cin, direccionCliente);
    string telefonoCliente;
    cout << "Ingrese el telefono del cliente: ";
    getline(cin, telefonoCliente);

    Cliente cliente(nombreCliente,direccionCliente,telefonoCliente);
    Envio envio(id, {}, {}," ", cliente);
    envios.push_back(envio);
    cout << "Envio creado" << endl;
}

void agregarProducto() {
    int i = 1;
    for (auto& envio : envios) {
        cout << "Envio: " << i << " ID: " << envio.getId() << endl;
        i++;
    }
    string id;
    cout << "Escribe el id del envio: " << endl;
    getline(cin, id);

    bool envioEncontrado = false;
    for (auto& envio : envios) {
        if (envio.getId() == id) {
            envioEncontrado = true;
            string fichero;
            cout << "Ingrese el fichero con los productos: " << endl;
            getline(cin, fichero);
            if(envio.leerFichero(fichero) != -1){
                cout << "Productos agregados" << endl;
            }

        }
    }
    if (!envioEncontrado) cout << "Envio no encontrado" << endl;
}

void eliminarProducto() {
    int i = 1;
    for (auto& envio : envios) {
        cout << "Envio: " << i << " ID: " << envio.getId() << endl;
        i++;
    }
    string id;
    cout << "Escribe el id del envio: " << endl;
    getline(cin, id);

    bool envioEncontrado = false; 
    for (auto& envio : envios) {
        if (envio.getId() == id) {
             envioEncontrado = true;
            int i = 1;
            for (auto& producto : envio.getProductos()) {
                cout << i << "." << producto.getNombre() << endl;
                i++;
            }
            string nombre;
            cout << "Ingrese el nombre del producto a eliminar " << endl;
            getline(cin, nombre);

            bool productoEncontrado = false; 
            for (auto& producto : envio.getProductos()) {
                if (producto.getNombre() == nombre) {
                     productoEncontrado = true;
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
    int i = 1;
    for (auto& envio : envios) {
        cout << "Envio: " << i << " ID: " << envio.getId() << endl;
        i++;
    }
    string id;
    cout << "Escribe el id del envio: " << endl;
    getline(cin, id);

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
    cout << "Seleccione la ID de un repartidor" << endl;
    for (auto& repartidor: repartidores){
        cout << repartidor.getNombre() << " ID: " << repartidor.getIdentificacion() << endl;
    }
    string id;
    getline(cin, id);

    bool repartidorEncontrado = false;
    for(auto& repartidor: repartidores){
        if (repartidor.getIdentificacion() == id){
            repartidorEncontrado = true;
            cout << "Envios asignados al repartidor" << endl;
            int i = 1;
            for (auto& envio :repartidor.getListaEnvios()) {
                cout << "Envio: " << i << " ID: " << envio.getId() << endl;
                i++;
            }
            string idEnvio;
            cout << "Seleccione el ID del envio a entregar: " << endl;
            getline(cin, idEnvio);

            bool envioEncontrado = false;
            for (auto& envio : envios){
                if (idEnvio == envio.getId()){
                    envioEncontrado = true;
                    repartidor.entregarEnvio(idEnvio);
                    envio.cambiarEstado("Entregado");
                }
            }
            if (!envioEncontrado) cout << "Envio no encontrado" << endl;
        }  
    }
    if (!repartidorEncontrado) cout << "Repartidor no encontrado" << endl;
}

void asignarRepartidor() {
    int i = 1;
    for (auto& envio : envios) {
        cout << "Envio: " << i << " ID: " << envio.getId() << endl;
        i++;
    }
    string id;
    cout << "Escribe el id del envio: " << endl;
    getline(cin, id);
    int a = 0;
    for (auto& envio : envios) {
        if (envio.getId() == id) {
            int i = 0;
            for (auto& repartidor :repartidores) {
                cout << i + 1 << "." << repartidores[i].getNombre() << " : " << repartidores[i].getIdentificacion() << endl;
                i++;
            }
            string identificacion;
            cout << "Ingrese el id del repartidor: " << endl;
            getline(cin, identificacion);
            for (auto &repartidor :repartidores) {
                if (repartidor.getIdentificacion() == identificacion) {
                    if (repartidor.estaDisponible()) {
                        repartidor.agregarEnvio(envios[a]);
                        envio.setRepartidor(repartidor);
                        cout << "Envio asignado" << endl;
                    }else cout << "Repartidor no disponible, envio no asignado." << endl;
                    } else {
                        cout << "Repartidor no encontrado." << endl;
                        return;
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
        cin.ignore();
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
            case 7: return 0;
            default: cout << "Opcion invalida" << endl;
        }
    }


    return 0;
}