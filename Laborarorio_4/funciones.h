#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include <map>
#include <vector>
using namespace std;

int cargarTopoligiaDesdeUnTxt(string nombreArchivo, map<string, map<string, int>>& topologia, vector<string>& routerNames);

void imprimirMatrizAdyacencia(const map<string, map<string, int>>& topologia, const vector<string>& routerNames);

string encontrarRutaMasCorta(const map<string, map<string, int>>& topologia, const string& origen, const string& destino, const vector<string> &routerNames, bool retornar = false);

void cargarTopoligiaPorDefecto(map<string, map<string, int>>& topologia, vector<string>& routerNames);

void AgregarRedAleatoria(map<string, map<string, int>>& topologia, vector<string>& routerNames);

void eliminarRed(map<string, map<string, map<string, int>>>& Redes, map <string, vector<string>>& routerNames);

void AgregarEnrutador(map<string, map<string, int>>& topologia, vector<string>& routerNames);

void EliminarEnrutador(map<string, map<string, int>>& topologia, vector<string>& routerNames);

void cambiarPeso(map<string, map<string, int>>& topologia, vector<string>& routerNames);

void ImprimirTablaDeEnrutamient(map<string, map<string, int>>& topologia, vector<string>& routerNames);


#endif // FUNCIONES_H
