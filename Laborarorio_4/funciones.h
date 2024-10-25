#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include <map>
#include <vector>
using namespace std;

int cargarTopoligiaDesdeUnTxt(string nombreArchivo, map<string, map<string, int>>& topologia, vector<string>& routerNames);

void imprimirMatrizAdyacencia(const map<string, map<string, int>>& topologia, const vector<string>& routerNames);

void encontrarRutaMasCorta(const map<string, map<string, int>>& topologia, const string& origen, const string& destino, const vector<string> &routerNames);

void cargarTopoligiaPorDefecto(map<string, map<string, int>>& topologia, vector<string>& routerNames);

void AgregarRedAleatoria(map<string, map<string, int>>& topologia, vector<string>& routerNames);

void eliminarRed(map<string, map<string, map<string, int>>>& Redes, map <string, vector<string>>& routerNames);

void AgregarEnrutador(map<string, map<string, int>>& topologia, vector<string>& routerNames);


#endif // FUNCIONES_H
