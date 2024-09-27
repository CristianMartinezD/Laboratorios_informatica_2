#include <iostream>
#include <limits> //Para limpiar el buffer.
#include <string>
#include "banco.h"
#include "funciones.h"

using namespace std;



int main()
{
    size_t n, metodo_codificacion; string nombreArchivoFuente, nombreArchivoSalida; bool salir = false; char opcion;

    while (salir == false) {
        cout<<"\nMENU PRINCIPAL";
        cout<<"\nQue operacion deseas realizar?\n1. Codificar\n2. Decodificar\n3. Operaciones bancarias\n0. Salir\nELIGE UNA OPCION (1, 2, 3 o 0): ";cin>>opcion;
        if (opcion == '1' || opcion == '2') {cout<<"\nCOMO SE LLAMA EL ARCHIVO FUENTE: "; cin >> nombreArchivoFuente;}

        switch (opcion) {

            case '0': {return 1;}

            case '1':{ /* CODIFICAR */
                string binario = convertirTEXTO_A_binario(nombreArchivoFuente); if(binario == "") {cout<<"\nArchivo NO encontrado\n";return 1;}
                cout<<"\nCual es la semilla n para la codificacion: "; n = obtenerENTEROpositivo();
                while (n < 1 || n > binario.length()) {
                    cout<<"\nLa semilla n debe ser mayor que 0 y menor que "<<binario.length() +1<<", ingresala de nuevo: ";n = obtenerENTEROpositivo();
                }

                cout<<"\nQue metodo de codificacion quieres usar, 1 o 2: "; metodo_codificacion = obtenerENTEROpositivo();
                while (metodo_codificacion < 1 || metodo_codificacion > 2) {
                    cout<<"\nINGRESA UN VALOR VALIDO, 1 o 2: "; metodo_codificacion = obtenerENTEROpositivo();
                }

                cout <<"\nQue nombre le quieres poner al archivo de salida: "; cin >>nombreArchivoSalida;
                cout << "\n\nContenido del archivo original en BINARIO:\n\n" << binario << endl;

                /* AQUÍ EMPEZAMOS CON LA CODIFICACIÓN */
                if (metodo_codificacion == 1){
                string binario_codificado = metodo1(binario, n, "codificar");
                cout << "\nEl binario codificado es:\n\n" << binario_codificado << endl;

                EscribirArchivoBinario(nombreArchivoSalida, binario_codificado);
                cout << "\nEL TEXTO CODIFICADO SE GUARDO EN UN ARCHIVO LLAMADO: " << nombreArchivoSalida << endl <<endl;

                }
                else{
                    string binario_codificado = metodo2(binario, n, "codificar");
                    cout << "\nEl binario codificado es:\n\n" << binario_codificado << endl;

                    EscribirArchivoBinario(nombreArchivoSalida, binario_codificado);
                    cout << "\nEL TEXTO CODIFICADO SE GUARDO EN UN ARCHIVO LLAMADO: " << nombreArchivoSalida << endl <<endl;

                }
                break;
            }

            case '2':{ /* DECODIFICAR */
                string binario_codificado = convertirTEXTO_A_binario(nombreArchivoFuente);
                if(binario_codificado == "") {cout<<"\nArchivo NO encontrado\n";return 1;}

                cout<<"\nCual es la semilla n para la decodificacion: "; n = obtenerENTEROpositivo();
                while (n < 1 || n > binario_codificado.length()) {
                    cout<<"\nLa semilla n debe ser mayor que 0 y menor que "<<binario_codificado.length() +1<<", ingresala de nuevo: ";n = obtenerENTEROpositivo();
                }
                cout<<"\nQue metodo de codificacion se uso para codificar el contenido del archivo que vamos a decodificar, 1 o 2: "; metodo_codificacion = obtenerENTEROpositivo();
                while (metodo_codificacion < 1 || metodo_codificacion > 2) {
                    cout<<"\nINGRESA UN VALOR VALIDO, 1 o 2: "; metodo_codificacion = obtenerENTEROpositivo();
                }

                cout <<"\nQue nombre le quieres poner al archivo de texto de salida: "; cin >>nombreArchivoSalida;
                if (metodo_codificacion == 1){
                    string binario_decodificado = metodo1(binario_codificado, n, "decodificar");
                    cout << "\nEl binario decodificado es:\n\n" << binario_decodificado << endl;

                    EscribirArchivoBinario(nombreArchivoSalida, binario_decodificado);
                    cout << "\nEL TEXTO DECODIFICADO SE GUARDO EN UN ARCHIVO LLAMADO: " << nombreArchivoSalida << endl <<endl;
                }
                else {
                    string binario_decodificado = metodo2(binario_codificado, n, "decodificar");
                    cout << "\nEl binario decodificado es:\n\n" << binario_decodificado << endl;

                    EscribirArchivoBinario(nombreArchivoSalida, binario_decodificado);
                    cout << "\nEL TEXTO DECODIFICADO SE GUARDO EN UN ARCHIVO LLAMADO: " << nombreArchivoSalida << endl <<endl;
                }
                break;
            }

            case '3': {menuOperacionesBancarias(); break;}

            default: cout<<"\nNO INGRESASTE UNA OPCION VALIDA\n"; cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
        }

        /* PAUSA Y LIMPIEZA DE PANTALLA ANTES DE MOSTRAR NUEVAMENTE EL MUNU */
        cout <<endl;
        system("pause");
        system("cls");
    }

    return 0;
}






/* APLICACION */

void menuOperacionesBancarias(){
    system("cls");

    /* CARGAMOS LA BASE DE DATOS EN MEMORIA */

    string binarioCod = convertirTEXTO_A_binario("baseDeDatos.txt");
    string binarioDec = metodo1(binarioCod, 4, "decodificar");
    string str_cuentas;
    for (size_t i = 0; i < binarioDec.size(); i += 8) {
        bitset<8> byte(binarioDec.substr(i, 8));
        str_cuentas += (static_cast<unsigned char>(byte.to_ulong()));
    }

    Banco cuentas;
    cuentas.cargarCuentasDesdeString(str_cuentas);
    /* ------------------------------------------ */

    bool salir = false;
    while (salir == false) {
        cout <<"\nMENU DE OPERACIONES BANCARIAS\n";
        char operacion;
        cout <<"\nQue operacion deseas realizar:\n";
        cout <<"1. Registrar usuarios en el sistema (solo admin)\n";
        cout <<"2. Ver cuentas registras en el sistema (solo admin)\n";
        cout <<"3. Consultar saldo\n";
        cout <<"4. Retirar dinero\n";
        cout <<"0. Volver al menu principal\n";
        cout <<"INGRESA UNA DE LAS ANTERIORES OPCIONES (1,2,3,4 o 0): "; cin >> operacion;

        switch (operacion) {
        case '1': registrarUsuario(cuentas); break;
        case '2': {bool validacion = validarAdmin(); if (validacion == true){cuentas.mostrarCuentas();} break;}
        case '3': consultarSaldo(cuentas); break;
        case '4': retirarDinero(cuentas); break;
        case '0': salir = true; break;
        default: cout <<"\nNO INGRESASTE UNA OPCION VALIDA\n"; cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
        }
    }
}
