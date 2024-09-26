# include <iostream>
# include <fstream>
#include <vector>
# include <bitset>
#include <string>
#include <algorithm> //Para usar count()

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
void menuOperacionesBancarias(); void registrarUsuario(); void consultarSaldo(); void retirarDinero();


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

            case '3': menuOperacionesBancarias(); break;

            default: {cout<<"\nNO INGRESASTE UNA OPCION VALIDA\n"; break;}
        }

        /* PAUSA Y LIMPIEZA DE PANTALLA ANTES DE MOSTRAR NUEVAMENTE EL MUNU */
        cout <<endl;
        system("pause");
        system("cls");
    }

    return 0;
}



string convertirTEXTO_A_binario(string nombreArchivo){
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return "";
    }

    char caracter;
    string str_binario;

    while (archivo.get(caracter)) {
        bitset<8> binario(caracter);
        str_binario += binario.to_string();
    }

    archivo.close();
    return str_binario;
}

/* FUNCIÓN PARA CODIFICAR Y DECODIFICAR EL BINARIO */

string metodo1(const string& binarioAprocesar, int n, string accionArealizar) {
    // Dividimos el binario en bloques de tamaño n
    vector<string> bloques;
    for (size_t i = 0; i < binarioAprocesar.size(); i += n) {
        bloques.push_back(binarioAprocesar.substr(i, n));
    }

    // Aplicamos la primera regla: invertir el primer bloque completamente
    vector<string> bloques_procesados;
    bloques_procesados.push_back(invertir_bloque(bloques[0]));

    // Procesamos los bloques siguientes
    for (size_t i = 1; i < bloques.size(); ++i) {
        //i=1 para facilitar la selección del bloque_previo y el bloque_actual

        string bloque_previo;
        if (accionArealizar == "codificar") bloque_previo = bloques[i - 1];
        else if(accionArealizar == "decodificar") bloque_previo = bloques_procesados[i - 1];
        else return ""; //Porque no se envio una acción validad.

        // Contamos la cantidad de 1s y 0s en el bloque anterior
        int num_1s = count(bloque_previo.begin(), bloque_previo.end(), '1');
        int num_0s = count(bloque_previo.begin(), bloque_previo.end(), '0');

        // Aplicar las reglas según la cantidad de 1s y 0s en el bloque anterior
        string bloque_actual = bloques[i];

        if (num_1s == num_0s) {
            // Si hay igual cantidad de 1s y 0s, invertir todo el bloque
            bloques_procesados.push_back(invertir_bloque(bloque_actual));
        } else if (num_0s > num_1s) {
            // Si hay más 0s, invertir cada 2 bits, si el tamaño lo permite
            if (n >= 2) {
                for (size_t j = 1; j < bloque_actual.size(); j += 2) {
                    bloque_actual[j] = (bloque_actual[j] == '0') ? '1' : '0';
                }
            }
            bloques_procesados.push_back(bloque_actual);
        } else {
            // Si hay más 1s, invertir cada 3 bits, si el tamaño lo permite
            if (n >= 3) {
                for (size_t j = 1; j < bloque_actual.size(); j += 3) {
                    bloque_actual[j] = (bloque_actual[j] == '0') ? '1' : '0';
                }
            }
            bloques_procesados.push_back(bloque_actual);
        }
    }

    // Combinar todos los bloques codificados en un solo string
    string resultado;
    for (const string& bloque : bloques_procesados) {
        resultado += bloque;
    }

    return resultado;
}


string invertir_bloque(const string& bloque) {
    string invertido = bloque;
    for (char& bit : invertido) {
        bit = (bit == '0') ? '1' : '0';
    }
    return invertido;
}




/* FUNCION PARA CODIFICAR Y DECODIFICAR MEDIANTE EL METODO 2 */
string metodo2(const string& binarioAprocesar, int n, string accionArealizar) {
    // Dividimos el binario en bloques de tamaño n
    vector<string> bloques;
    for (size_t i = 0; i < binarioAprocesar.size(); i += n) {
        bloques.push_back(binarioAprocesar.substr(i, n));
    }

    // Para almacenar el resultado final
    string resultado;

    if (accionArealizar == "codificar") {
        // Codificamos cada bloque
        for (size_t i = 0; i < bloques.size(); ++i) {
            string bloqueActual = bloques[i];
            // Desplazamos cada bit hacia la derecha
            char ultimoBit = bloqueActual[bloqueActual.length() - 1];
            for (size_t j = bloqueActual.length() - 1; j > 0; --j) {
                bloqueActual[j] = bloqueActual[j - 1];
            }
            bloqueActual[0] = ultimoBit;
            resultado += bloqueActual;
        }
    }
    else if (accionArealizar == "decodificar") {
        // Decodificamos cada bloque
        for (size_t i = 0; i < bloques.size(); ++i) {
            string bloqueActual = bloques[i];
            // Desplazamos cada bit hacia la izquierda
            char primerBit = bloqueActual[0];
            for (size_t j = 0; j < bloqueActual.length() - 1; ++j) {
                bloqueActual[j] = bloqueActual[j + 1];
            }
            bloqueActual[bloqueActual.length() - 1] = primerBit;
            resultado += bloqueActual;
        }
    }
    else return ""; // Para el caso donde no se envió una acción válida.

    return resultado;
}



// Función para escribir la cadena de bits codificados en un archivo binario
void EscribirArchivoBinario(const string& nombreArchivo, const string& binarioCodificado) {

    ofstream archivo(nombreArchivo, ios::binary);
    for (size_t i = 0; i < binarioCodificado.size(); i += 8) {
        bitset<8> byte(binarioCodificado.substr(i, 8));
        archivo.put(static_cast<unsigned char>(byte.to_ulong()));

    }
}



void escribirArchivo(string nombreArchivo, string texto, bool limpiar=false)
{
    fstream archivo;
    if (limpiar) // Si limpiar es verdadero, se sobreescribe el archivo
    {
        archivo.open(nombreArchivo, ios::out | ios::trunc);
    }
    else // Si limpiar es falso, se agrega contenido al final del archivo
    {
        archivo.open(nombreArchivo, ios::out | ios::app);
    }

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo\n";
        return;
    }

    archivo << texto << endl;
    archivo.close();
}



string leerArchivoPorLinea(string nombreArchivo)
{
    fstream archivo(nombreArchivo, ios::in);
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo\n";
        return "";
    }

    string contenido;
    string linea;
    while (getline(archivo, linea))
    {
        contenido += linea;
    }
    archivo.close();

    return contenido;
}



string leerArchivoPorCaracter(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo\n";
        return "";
    }

    string contenido;
    char c;
    while (archivo.get(c))
    {
        contenido += c;
    }
    archivo.close();

    return contenido;
}





/* APLICACION */

void menuOperacionesBancarias(){
    system("cls"); cout <<"\n   BIENVENIDO AL BANCO.\n"; system("pause"); system("cls");

    bool salir = false;
    while (salir == false) {
        cout <<"\nMENU DE OPERACIONES BANCARIAS\n";
        char operacion;
        cout <<"\nQue operacion deseas realizar:\n";
        cout <<"1. Registrar usuarios en el sistema (solo admin)\n";
        cout <<"2. Consultar saldo\n";
        cout <<"3. Retirar dinero\n";
        cout <<"0. Volver al menu principal\n";
        cout <<"INGRESA UNA DE LAS ANTERIORES OPCIONES (1,2,3, o 0): "; cin >> operacion;

        switch (operacion) {
        case '1': registrarUsuario(); break;
        case '2': consultarSaldo(); break;
        case '3': retirarDinero(); break;
        case '0': salir = true; break;
        default:break;
        }
    }
}



void registrarUsuario(){}
void consultarSaldo(){}
void retirarDinero(){}




int obtenerENTEROpositivo(){
    string entero; bool cadenaVALIDA = false;
    cin >> entero;

    while (cadenaVALIDA == false) {
        cadenaVALIDA = true; //Asumimos que la cadena entero será valida.

        for (size_t i = 0; i < entero.length(); ++i) {
            if (entero[i] < '0' || entero[i] > '9'){
                cout <<"\nLo que ingresate no es un valor valido.\n";
                cout <<"INGRESA UN VALOR ENTERO POSITIVO: ";
                cin >> entero;
                cadenaVALIDA = false;
                break;
            }
        }
    }
    return stoi(entero); //Convertimos la cadena entero a un entero y lo retornamos.
}
int obtenerENTERO(){
    string entero; bool cadenaVALIDA = false, esNEGATIVO = false;
    cin >> entero;

    while (cadenaVALIDA == false) {
        cadenaVALIDA = true; //Asumimos que la cadena entero será valida.

        if (entero[0] == '-'){
            entero[0] = '0';
            esNEGATIVO = true;
        }

        for (size_t i = 0; i < entero.length(); ++i) {
            if (entero[i] < '0' || entero[i] > '9'){
                cout <<"\nLo que ingresate no es un valor valido.\n";
                cout <<"INGRESA UN VALOR ENTERO: ";
                cin >> entero;
                cadenaVALIDA = false;
                esNEGATIVO = false;
                break;
            }
        }
    }

    if (esNEGATIVO) return -1*stoi(entero);
    else return stoi(entero);
}
