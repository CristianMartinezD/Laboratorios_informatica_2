#include "funciones.h"
#include <iostream>
#include <fstream>
#include <sstream> /* Para usar stringstream y convertir lineas de texto en un flujo de tokens */
#include <queue>
#include <algorithm>  // Para usar reverse y find

int cargarTopoligiaDesdeUnTxt(string nombreArchivo, map<string, map<string, int>>& topologia, vector<string>& routerNames)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string linea, nombreRouter, distancia;

    getline(archivo, linea); // Leemos la primera línea (que tiene los nombres de los enrutadores destinos)
    stringstream flujoDeTokens(linea);

    // Leer los nombres de los enrutadores
    while (flujoDeTokens >> nombreRouter) { //Mientras haya más toquen por sacar del flujoDeTokens.
        routerNames.push_back(nombreRouter);
    }

    // Leemos las siguientes líneas (matriz de distancias)
    while (getline(archivo, linea)) { //Mientras haya más lineas por sacar del archivo.
        stringstream flujoDeTok(linea);

        // Leer el nombre del enrutador actual (primera columna)
        flujoDeTok >> nombreRouter;

        // Leer las distancias hacia los otros enrutadores
        for (const auto& destino : routerNames) {
            flujoDeTok >> distancia;

            // Convertir la distancia en entero y almacenar en el mapa
            topologia[nombreRouter][destino] = stoi(distancia);
        }
    }
    return 0;
}





// Función para imprimir la matriz de adyacencia
void imprimirMatrizAdyacencia(const map<string, map<string, int>>& topologia, const vector<string>& routerNames) {
    // Imprimir encabezado de columnas (con los nombres de los enrutadores)
    cout << "  ";  // Espacio para alinear correctamente
    for (const auto& nombreRouter : routerNames) {
        cout << nombreRouter << " ";  // Encabezado de columna
    }
    cout << endl;

    // Imprimir cada fila de la matriz
    for (const auto& origen : routerNames) {
        cout << origen << " ";  // Imprimir el nombre del enrutador origen (encabezado de fila)
        for (const auto& destino : routerNames) {
            int distancia = topologia.at(origen).at(destino);
            cout << (distancia == -1 ? "-1" : to_string(distancia)) << " ";  // Mostrar "-1" si no hay conexión
        }
        cout << endl;
    }
    cout << endl;
}






/* ENCONTRAR LA RUTA MÁS CORTA */

struct NodoRuta { // Estructura para almacenar la información de las rutas y los pesos
    string nodo;
    int peso;
    // Para que la prioridad en la cola sea por el peso (distancia mínima)
    bool operator>(const NodoRuta& otro) const {
        return peso > otro.peso;
    }
};


string encontrarRutaMasCorta(const map<string, map<string, int>>& topologia, const string& origen, const string& destino, const vector<string>& routerNames, bool retornar) {
    //system("cls");

    if (!retornar){cout << "\nMatriz de adyacencia:\n";
        imprimirMatrizAdyacencia(topologia, routerNames); // Imprimir la matriz de adyacencia
    }

    // Mapa para almacenar las distancias mínimas desde el origen
    map<string, int> distancias;
    // Mapa para rastrear el predecesor de cada nodo (para reconstruir la ruta)
    map<string, string> predecesor;

    for (const auto& nodo : topologia) {
        distancias[nodo.first] = INT_MAX;  // Inicializamos todas las distancias a infinito
    }
    distancias[origen] = 0;  // La distancia del origen a sí mismo es 0

    // Cola de prioridad para seleccionar el nodo con la distancia más corta
    priority_queue<NodoRuta, vector<NodoRuta>, greater<NodoRuta>> cola;
    cola.push({origen, 0});  // Empiezamos desde el nodo origen

    while (!cola.empty()) {
        NodoRuta actual = cola.top();
        cola.pop();

        string nodoActual = actual.nodo;
        int distanciaActual = actual.peso;

        // Si llegamos al destino, nos detenemos
        if (nodoActual == destino) break;

        // Exploramos los vecinos del nodo actual
        for (const auto& vecino : topologia.at(nodoActual)) {
            string nodoVecino = vecino.first;
            int peso = vecino.second;

            // Si no hay conexión (peso -1), ignorarmos
            if (peso == -1) continue;

            // Calculamos la distancia total desde el origen para el actual vecino
            int nuevaDistancia = distanciaActual + peso;

            if (nuevaDistancia < distancias[nodoVecino]) { // Si encontramos una distancia más corta hacia este vecino
                distancias[nodoVecino] = nuevaDistancia;
                predecesor[nodoVecino] = nodoActual;  // Guardamos de dónde venimos
                cola.push({nodoVecino, nuevaDistancia});
            }
        }
    }

    // Si no encontramos una ruta hacia el destino
    if (distancias[destino] == INT_MAX) {
        cout << "No hay ruta disponible entre " << origen << " y " << destino << endl;
        return "";
    }

    // Reconstruimos la ruta desde el destino al origen usando el mapa de predecesores
    vector<string> ruta;
    string nodo = destino;
    while (nodo != origen) {
        ruta.push_back(nodo);
        nodo = predecesor[nodo];
    }
    ruta.push_back(origen);  // Añadimos el origen al final

    // Invertimos la ruta para mostrarla en el orden correcto
    reverse(ruta.begin(), ruta.end());

    if (!retornar){
        // Imprimimos la ruta y el peso total
        cout << "La ruta mas corta para ir de " << origen << " a " << destino << " es: ";
        for (size_t i = 0; i < ruta.size(); ++i) {
            cout << ruta[i];
            if (i != ruta.size() - 1) cout << "->";
        }
        cout << ", con un peso de " << distancias[destino] << " unidades." << endl << endl;
        return "";
    }
    else{
        string RutaCorta = "";
        for (size_t i = 0; i < ruta.size(); ++i) {
            RutaCorta += ruta[i];
            if (i != ruta.size() - 1) RutaCorta += "->";
        }
        if (origen.length() == 1)return "   " +destino + "    |         " + to_string( distancias[destino]) +"           |  " + RutaCorta +"\n";
        else if (origen.length() == 2)return "  " +destino + "    |         " + to_string( distancias[destino]) +"           |  " + RutaCorta +"\n";
        else if(origen.length() == 3 && distancias[destino] > 9) return " " +destino + "    |         " + to_string( distancias[destino]) +"          |  " + RutaCorta +"\n";
        else return " " +destino + "    |         " + to_string( distancias[destino]) +"           |  " + RutaCorta +"\n";
    }
}






void cargarTopoligiaPorDefecto(map<string, map<string, int> > &topologia, vector<string> &routerNames)
{
    routerNames = {"R1", "R2", "R3", "R4"};
    topologia = {
        {"R1", {{"R1", 0}, {"R2", 2}, {"R3", -1}, {"R4", 4}}},
        {"R2", {{"R1", 2}, {"R2", 0}, {"R3", 3}, {"R4", 1}}},
        {"R3", {{"R1", -1}, {"R2", 3}, {"R3", 0}, {"R4", 1}}},
        {"R4", {{"R1", 4}, {"R2", 1}, {"R3", 1}, {"R4", 0}}}
    };
}






void AgregarRedAleatoria(map<string, map<string, int> > &topologia, vector<string> &routerNames)
{
    unsigned short cantidad_router = 5 + (rand() % 6); // 5 a 10
    unsigned short numeroDelRouter = 20 + (rand() % 51); // 20 a 100

    for (int i = 0; i < cantidad_router; ++i) {
        routerNames.push_back("R"+to_string(numeroDelRouter+i));
    }

    for (auto& origen : routerNames) {
        for (auto& destino : routerNames) {
            if (origen == destino) topologia[origen][destino] = 0;
            else {
                topologia[origen][destino] = -1 + (rand() % 21); //Pesos
                if (topologia[origen][destino] == 0) topologia[origen][destino] = -1;
            }
        }
    }
}







void eliminarRed(map<string, map<string, map<string, int> > > &Redes, map<string, vector<string> > &routerNames)
{
    string nombreRed;
    cout <<"\nCUAL DE LAS ANTERIORES REDES QUIERES ELIMINAR? ESCRIBE SU NOMBRE: "; cin >> nombreRed;

    size_t elementosEliminados = Redes.erase(nombreRed);

    if (elementosEliminados == 0) { // Verificamos si se eliminó algún elemento
        cout << "\nEsa Red no existía en el sistema, nada fue eliminado!" <<endl;
    }
    else {
        cout << "\nLA "<<nombreRed<<" HA SIDO ELIMINADA!\n\n";
        routerNames.erase(nombreRed);
    }
    system ("pause");
}






void AgregarEnrutador(map<string, map<string, int> > &topologia, vector<string> &routerNames)
{
    string nuevoRouter, ModoManual;
    cout << "\nCOMO SE LLAMARA EL NUEVO ENRUTADOR?: "; cin >> nuevoRouter;
    cout << "\nQuieres asignar manualmente los pesos de viajar a otro enrutador de la red?, si o no: "; cin >> ModoManual;
    routerNames.push_back(nuevoRouter);

    topologia[nuevoRouter][nuevoRouter] = 0;
    for (auto& destino : routerNames) {
        if (nuevoRouter == destino) {topologia[nuevoRouter][destino] = 0; topologia[destino][nuevoRouter] = 0;}
        else {
            int peso;
            if (ModoManual != "si") peso = -1 + (rand() % 21); //Pesos;
            else {cout <<"\nCUAL SERA EL PESO DE LA CONEXION "<<nuevoRouter<<"-->"<<destino<<": "; cin >> peso;}
            topologia[nuevoRouter][destino] = peso;
            topologia[destino][nuevoRouter] = peso;
            if (topologia[nuevoRouter][destino] == 0) {
                topologia[nuevoRouter][destino] = -1;
                topologia[destino][nuevoRouter] = -1;
            }
        }
    }
    if (ModoManual == "no") cout <<"\n\nENRUTADOR AGREGADO! LOS PESOS FUERON ASIGNADOS ALEATORIAMENTE\n\n";
    else if (ModoManual != "si" && ModoManual != "no") cout <<"\n\nNO INGRESASTE UNA OPCION CORRECTA, POR LO TANTO SE ASIGNARON PESOS ALEATORIOS AL NUEVO ENRUTADOR AGREGADO\n\n";
    else cout <<"\n\nENRUTADOR AGREGADO EXITOSAMENTE!\n\n";
    system("pause");
}





void ImprimirTablaDeEnrutamient(map<string, map<string, int> > &topologia, vector<string> &routerNames)
{
    string origen, destino;
    cout << "\nESTOS SON LOS ENRUTADORES DE ESTA RED:\n";
    for (auto& router : routerNames){
        cout <<router<<endl;
    }

    cout << "A CUAL DE ESOS ENRUTADORES LE QUIERES VER SU TABLA DE ENRUTAMIENTO: "; cin >> origen;
    string tabla = "";
    if (find(routerNames.begin(), routerNames.end(), origen) != routerNames.end()) {
        cout <<"\nLa tabla de enrutamiento de "<<origen<<" es:\n";
        cout<<"\nDESTINO | DISTANCIA MAS CORTA | RUTA\n";
        for (auto& destino : routerNames){
            tabla += encontrarRutaMasCorta(topologia, origen, destino, routerNames,true);
        }
        cout<<tabla<<endl;
    }
    else {cout <<"\nEl Enrutador que ingresaste no existe en esta red\n\n";}
    system("pause");
}





void EliminarEnrutador(map<string, map<string, int> > &topologia, vector<string> &routerNames)
{
    string Eliminar;
    cout << "\nESTOS SON LOS ENRUTADORES DE ESTA RED:\n";
    for (auto& router : routerNames){
        cout <<router<<endl;
    }
    cout << "A CUAL DE ESOS ENRUTADORES QUIERES ELIMINAR: "; cin >> Eliminar;
    if (find(routerNames.begin(), routerNames.end(), Eliminar) != routerNames.end()) {

        for (auto& routerOrigen : routerNames){
            topologia[routerOrigen].erase(Eliminar); //Borramos la columna donde Eliminar el destino
        }
        topologia.erase(Eliminar); //Borramos la columna donde Eliminar el origen
        cout<<"\nEL ENRUTADOR "<<Eliminar<<" HA SIDO ELIMINADO DE LA RED!";
        cout<<"\nLa nueva matriz de adyacencia es:\n";
        routerNames.erase(remove(routerNames.begin(), routerNames.end(), Eliminar), routerNames.end());
        imprimirMatrizAdyacencia(topologia, routerNames);
    }
    else {cout <<"\nEl Enrutador que ingresaste no existe en esta red\n\n";}
    cout<<endl;
    system("pause");
}




void cambiarPeso(map<string, map<string, int> > &topologia, vector<string> &routerNames)
{
    string opcion;
    cout << "\nQUIERES CAMBIAR EL PESO DE CONEXION ENTRE DOS ENRUTADORES, O QUE SE CAMBIEN TODOS LOS PESOS AUTOMATICAMENTE?";
    cout << "\n\n1. CAMBIAR EL PESO ENTRE DOS ENRUTADORES";
    cout << "\n2. CAMBIAR PESO DE TODOS, AUTOMATICAMENTE";
    cout << "\n   INGRESA 1 O 2: ";  cin >> opcion;

    if (opcion == "1"){
        string enrutador1, enrutador2;
        cout <<"\nIngresa el nombre del primer enrutador: "; cin >> enrutador1;
        cout <<"\nIngresa el nombre del segundo enrutador: "; cin >> enrutador2;
        if (find(routerNames.begin(), routerNames.end(), enrutador1) != routerNames.end() &&
            find(routerNames.begin(), routerNames.end(), enrutador2) != routerNames.end()) {
            int peso;
            cout <<"\nCUAL EL ES NUEVO PESO QUE LE ASIGNARAS A LA CONEXION ENTRE ESTOS DOS ENRUTADORES: "; cin >> peso;
            topologia[enrutador1][enrutador2] = peso;
            topologia[enrutador2][enrutador1] = peso;
            cout <<"\n\nEL PESO DE LA CONEXION ENTRE ESTOS DOS ENRUTADORES HA SIDO CAMBIADO!\n\n";
        }
        else {cout <<"\nUno de los Enrutadores que ingresaste no existe en esta red\n\n";}
    }
    else{
        for (auto& origen : routerNames) {
            for (auto& destino : routerNames) {
                if (origen == destino) topologia[origen][destino] = 0;
                else {
                    topologia[origen][destino] = -1 + (rand() % 21); //Pesos
                    if (topologia[origen][destino] == 0) topologia[origen][destino] = -1;
                }
            }
        }
        cout <<"\n\nEL PESO DE LAS CONEXIONES EN TODA LA RED HA SIDO CAMBIADO!\n\n";
    }

    system("pause");
}
