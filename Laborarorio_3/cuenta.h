#ifndef CUENTA_H
#define CUENTA_H
#include <iostream>
using namespace std;

class Cuenta {
    private:
        string cedula;
        string contrasena;
        double saldo;

    public:
        // Constructor
        Cuenta(string cedu, string contrasena, double saldo): cedula(cedu), contrasena(contrasena), saldo(saldo) {}

        // Métodos getters
        string getCedula() const;
        string getContrasena() const;
        double getSaldo() const;


        void setSaldo(double sald);

        // Método para mostrar la información de la cuenta
        void mostrarInfo() const;
};

#endif // CUENTA_H
