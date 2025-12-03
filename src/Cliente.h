//
// Created by luis1 on 01/12/2025.
//

#ifndef SITUACIONPROBLEMAD_CLIENTE_H
#define SITUACIONPROBLEMAD_CLIENTE_H
#include <string>
using namespace std;


class Cliente {
    //attributes
private:
    string nombre;
    string direccion;
    string telefono;

    //methods
public:
    //constructors
    Cliente();
    Cliente(string cNombre, string cDireccion, string cTelefono);

    //getters and setters
    string getNombre();
    void setNombre(string cNombre);

    string getDireccion();
    void setDireccion (string cDireccion);

    string getTelefono();
    void setTelefeno(string cTelefono);

    //destructor
    ~Cliente();
};


#endif //SITUACIONPROBLEMAD_CLIENTE_H