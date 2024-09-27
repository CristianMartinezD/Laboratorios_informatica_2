#include "banco.h"
#include <sstream>  // Para istringstream
#include <bitset>
#include "funciones.h"

void Banco::agregarCuenta(const Cuenta &cuenta, bool escribirEnlaBase) {
    cuentas.push_back(cuenta);

    if(escribirEnlaBase){
        Banco::escribirEnlaBase();
        cout<<"\nLa cuenta ha sido agregada!\n\n";
    }
}

Cuenta *Banco::buscarCuenta(const string &cedula) {
    for (auto& cuenta : cuentas) {
        if (cuenta.getCedula() == cedula) {
            return &cuenta;
        }
    }
    return nullptr; // Retorna nullptr si no se encuentra la cuenta
}

void Banco::mostrarCuentas() const {
    for (const auto& cuenta : cuentas) {
        cuenta.mostrarInfo();
        cout << "--------------------------" << endl;
    }
}

void Banco::cargarCuentasDesdeString(const string &datos) {
    istringstream stream(datos);  // Convertir el string en un stream
    string linea;

    // Leer línea por línea
    while (getline(stream, linea)) {
        istringstream lineaStream(linea);
        string cedula, contrasena;
        double saldo;

        // Dividimos la líneaStream por los ':' para obtener los valores
        if (getline(lineaStream, cedula, ':') &&
            getline(lineaStream, contrasena, ':') &&
            lineaStream >> saldo) {

            agregarCuenta(Cuenta(cedula, contrasena, saldo));// Creamos una cuenta y la agregarmos al banco
        }
    }
}



string Banco::convertirCuentasAString() const {
    ostringstream oss;

    for (size_t i = 0; i < cuentas.size(); ++i) {
        oss << cuentas[i].getCedula() <<":"<<cuentas[i].getContrasena()<<":"<<cuentas[i].getSaldo();
        if (i < cuentas.size() - 1) oss <<"\n";
    }
    return oss.str();
}

void Banco::escribirEnlaBase()
{
    string textoCuentasSinCod = convertirCuentasAString();
    string binarioSinCod;
    for (size_t i = 0; i < textoCuentasSinCod.length(); ++i) {
        char caracter = textoCuentasSinCod[i];
        bitset<8> binario(caracter);
        binarioSinCod += binario.to_string();
    }
    string binarioCod = metodo1(binarioSinCod, 4, "codificar");
    EscribirArchivoBinario("baseDeDatos.txt", binarioCod);
}
