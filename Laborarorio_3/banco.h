#ifndef BANCO_H
#define BANCO_H
#include <iostream>
#include <vector>
#include <string>

#include "cuenta.h"

using namespace std;


// Clase que representa un banco que administra múltiples cuentas
class Banco {
private:
    vector<Cuenta> cuentas;

public:
    // Método para agregar una cuenta al banco. Esta funcion me sirve para cargar las cuentas en un vector de cuentas, y tambien me sirve para escribir una nueva cuenta en el archivo de la base de datos*/
    void agregarCuenta(const Cuenta& cuenta, bool escribirEnlaBase = false);
    // Método para buscar una cuenta por cédula
    Cuenta* buscarCuenta(const string& cedula);

    // Método para mostrar todas las cuentas
    void mostrarCuentas() const;

    // Método para cargar cuentas desde un string
    void cargarCuentasDesdeString(const string& datos);
    string convertirCuentasAString() const;

    void escribirEnlaBase();
};


#endif // BANCO_H
