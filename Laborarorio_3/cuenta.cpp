#include "cuenta.h"

string Cuenta::getCedula() const {
    return cedula;
}

string Cuenta::getContrasena() const {
    return contrasena;
}

double Cuenta::getSaldo() const {
     return saldo;
}

void Cuenta::setSaldo(double sald)
{
    saldo = sald;
}

void Cuenta::mostrarInfo() const {
    cout << "Cedula: " << cedula << endl;
    cout << "Contrasena: " << contrasena << endl;
    cout << "Saldo: " << saldo << endl;
}
