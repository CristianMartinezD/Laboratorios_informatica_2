
#include <iostream>
#include "funciones.h"
#include <map>
#include <vector>
#include <string>
#include <ctime> // Para time()
#include <cstdlib> // Para rand() y srand()
#include <algorithm>

using namespace std;

int menuDeLaRed(map<string, map<string, map<string, int>>>& Redes, map <string, vector<string>>& routerNames);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    map <string, vector<string>> routerNames;
    map<string, map<string, map<string, int>>> Redes;

    cargarTopoligiaDesdeUnTxt("topologia.txt", Redes["Red1"], routerNames["Red1"]);

    cargarTopoligiaPorDefecto(Redes["Red2"], routerNames["Red2"]);

    AgregarRedAleatoria(Redes["Red3"], routerNames["Red3"]);

    int opcion;
    do {
        system("cls");
        cout<<"\nEN EL SISTEMA HAY "<<Redes.size()<<" REDES DISPONIBLES:\n";
        for (const auto& nombreRed : Redes) {
            cout<<nombreRed.first<<endl;
        }
        cout<<"1. Quieres entrar a una de esas redes";
        cout<<"\n2. Quieres eliminar una de esas redes";
        cout<<"\n3. Quieres agregar otra Red aleatoria al sistema";
        cout<<"\n0. SALIR";
        cout<<"\nINGREA UNA OPCION (1, 2, 3. 0): "; cin >> opcion;

        switch (opcion) {
        case 1: {opcion = menuDeLaRed(Redes, routerNames); break;}
        case 2: {eliminarRed(Redes, routerNames); break;}
        case 3: {
            string nuevoNombre = "Red"+to_string(Redes.size()+1);
            AgregarRedAleatoria(Redes[nuevoNombre], routerNames[nuevoNombre]);
            cout <<"\nHA SIDO AGREGADA UNA "<<nuevoNombre<<" AL SISTEMA!\n\n"; system("pause");
            break;
        }

        case 0: break;
        default:
            cout << "\nHAS INGRESADO UNA OPCION INVALIDA, INTENTALO DE NUEVO!\n\n"; system("pause");
            break;
        }

    } while (opcion != 0);

    cout <<"\n\nEL PROGRAMA HA FINALIZADO!\n\n";

    return 0;
}





int menuDeLaRed(map<string, map<string, map<string, int>>>& Redes, map <string, vector<string>>& routerNames){
    string nombreRed;
    cout<<"\nA CUAL DE LAS ANTERIORES REDES QUIERES ENTRAR? ESCRIBE EL NOMBRE: "; cin >> nombreRed;

    if (Redes.find(nombreRed) != Redes.end()){
        int opcion;
        do {
            system("cls");
            cout<<"\nMENU DE LA "<<nombreRed;
            cout<<"\nQue quieres realizar:";
            cout<<"\n1. Ver la matriz de adyacencia de esta red\n2. Imprimir la tabla de enrutamiento de un Enrutador";
            cout <<"\n3. Obtener la ruta mas corta entre dos enrutadores\n4. Agregar Enrutador\n5. Eliminar Enrutador";
            cout<<"\n6. Cambiar peso de las conexiones\n9. Volver al menu principal\n0. SALIR";
            cout<<"\nINGRESA UNA DE LAS ANTERIORES OPCIONES: "; cin >> opcion;

            switch (opcion) {
            case 1: {imprimirMatrizAdyacencia(Redes[nombreRed], routerNames[nombreRed]); system("pause"); break;}
            case 2: {ImprimirTablaDeEnrutamient(Redes[nombreRed], routerNames[nombreRed]); break;}
            case 3: {
                string origen, destino;
                cout << "Cual es el Enrutador Origen: "; cin >> origen;
                cout << "Cual es el Enrutador Destino: "; cin >> destino;

                if (find(routerNames[nombreRed].begin(), routerNames[nombreRed].end(), origen) != routerNames[nombreRed].end() &&
                    find(routerNames[nombreRed].begin(), routerNames[nombreRed].end(), destino) != routerNames[nombreRed].end()) {

                    encontrarRutaMasCorta(Redes[nombreRed], origen, destino, routerNames[nombreRed]);
                }
                else {cout <<"\nAlguno de los Enrutadores que ingresaste no existe en esta red\n\n";}
                system("pause");
                break;
            }
            case 4: {
                AgregarEnrutador(Redes[nombreRed], routerNames[nombreRed]); //Debo terminar esta parte
                break;
            }
            case 5: {
                EliminarEnrutador(Redes[nombreRed], routerNames[nombreRed]);
                break;
            }
            case 6: {
                cambiarPeso(Redes[nombreRed], routerNames[nombreRed]);
                break;
            }
            case 9: {return 9;}
            case 0: {return 0;}

            default:
                break;
            }
        } while (opcion != 9 && opcion != 0);

    }
    else {cout <<"\nESA RED QUE INGRESASTE NO EXISTE\n\n"; system("pause");}

    return 9;
}
