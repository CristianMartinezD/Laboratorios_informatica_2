#include "funciones.h"



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





void registrarUsuario(Banco& cuentas){
    system("cls");

    bool validacion = validarAdmin();

    string cedula, clave; double saldo;
    if (validacion == true){
        cout <<"\nBIENVENIDO ADMIN!\n";
        cout <<"\nRegistremos el nuevo usuario.";
        cout <<"\nCual es su cedula: "; cin >> cedula;
        if (cuentas.buscarCuenta(cedula) == nullptr){
            cout <<"\nCual es su clave: "; cin >> clave;
            cout <<"\nCual es su saldo: "; cin >> saldo;
            cuentas.agregarCuenta(Cuenta(cedula,clave,saldo),true);
        }
        else{cout <<"\nEse usuario ya esta registrado.\n\n";}

    }
    else cout <<"\nCLAVE ERRADA\n\n";

    system("pause");
    system("cls");
}

bool validarAdmin(){
    string claveAdmin;
    cout <<"\nINGRESE LA CLAVE DE ADMINISTRADOR: "; cin >> claveAdmin;

    string binarioClaveEncriptada = convertirTEXTO_A_binario("sudo.txt");
    string binarioClaveDesencriptada = metodo1(binarioClaveEncriptada, 4, "decodificar");
    string claveReal;

    for (size_t i = 0; i < binarioClaveDesencriptada.size(); i += 8) {
        bitset<8> byte(binarioClaveDesencriptada.substr(i, 8));
        claveReal += (static_cast<unsigned char>(byte.to_ulong()));
    }
    if (claveAdmin == claveReal) return true;
    return false;
}

void consultarSaldo(Banco& cuentas){
    string cedula, clave;
    cout <<"\nAUTENTIFICACION.";
    cout <<"\nIngresa tu cedula: "; cin >> cedula;

    Cuenta *cuenta = cuentas.buscarCuenta(cedula);
    if(cuenta != nullptr){
        cout <<"\nIngresa tu clave: "; cin >> clave;
        if(cuenta->getContrasena() == clave){
            cout <<"\nTU SALDO ES: "<<cuenta->getSaldo()<<" COP - (1000 COP por esta consulta)"<<endl<<endl;
            double nuevoSaldo = cuenta->getSaldo() - 1000;
            cuenta->setSaldo(nuevoSaldo);
            cuentas.escribirEnlaBase();
        }
        else cout <<"\nAUTENTIFICACION FALLIDA, CLAVE INCORRECTA.\n\n";
    }
    else cout <<"\nESA CUENTA NO EXISTE EN NUESTRO SISTEMA.\n\n";

    system("pause");
    system("cls");
}

void retirarDinero(Banco& cuentas){
    string cedula, clave;
    cout <<"\nAUTENTIFICACION.";
    cout <<"\nIngresa tu cedula: "; cin >> cedula;

    Cuenta *cuenta = cuentas.buscarCuenta(cedula);
    if(cuenta != nullptr){
        cout <<"\nIngresa tu clave: "; cin >> clave;
        if(cuenta->getContrasena() == clave){
            if (cuenta->getSaldo() >= 10000){
                cout <<"\nCUANTO VAS A RETIRAR?...(su maximo retiro puede ser de "<<cuenta->getSaldo()<<" COP y su minimo 10000 COP)"<<endl;
                double monto;
                cout <<"\nDIGITA EL MONTO DE RETIRO: $ "; cin >> monto;
                if (monto <= cuenta->getSaldo() && monto >= 10000){
                    double nuevoSaldo = cuenta->getSaldo() - monto - 1000;
                    cuenta->setSaldo(nuevoSaldo);
                    cuentas.escribirEnlaBase();
                    cout <<"\n\n        RETIRO EXITOSO!\nSe ha cobrado una tarifa de 1000 COP por este retiro\n\n";
                }
                else cout <<"\nNo puedes retirar ese valor\n\n";
            }
            else cout <<"\nNo tienes suficientes fondos para retirar, debes tener minimo 10000 COP\n\n";
        }
        else cout <<"\nAUTENTIFICACION FALLIDA, CLAVE INCORRECTA.\n\n";
    }
    else cout <<"\nESA CUENTA NO EXISTE EN NUESTRO SISTEMA.\n\n";

    system("pause");
    system("cls");
}




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

