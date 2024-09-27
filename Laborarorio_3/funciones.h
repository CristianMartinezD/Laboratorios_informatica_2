#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include "banco.h"
using namespace std;

string convertirTEXTO_A_binario(string);
void escribirArchivo(string, string, bool);
string invertir_bloque(const string&);
string metodo1(const string&, int, string); //Recibe el binario que voy a procesar, n, y la acción que voy a realizar, ya sea codificar o decodificar.
string metodo2(const string&, int, string);
void EscribirArchivoBinario(const string&, const string&);
//string leerArchivoPorCaracter(string);
string leerArchivoPorLinea(string);
int obtenerENTEROpositivo();
int obtenerENTERO();
void menuOperacionesBancarias(); void registrarUsuario(Banco&); void consultarSaldo(Banco&); void retirarDinero(Banco&);

#endif // FUNCIONES_H
