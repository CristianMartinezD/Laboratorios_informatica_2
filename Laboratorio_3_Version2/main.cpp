#include <iostream>
#include <bitset>
#include <fstream>
#include <limits> //Para limpiar el buffer.

using namespace std;

/* CLASES */

// Prototipo de la clase Cuenta
class Cuenta {
private:
    string cedula;
    string contrasena;
    double saldo;

public:
    // Constructor por defecto
    Cuenta();

    // Constructor
    Cuenta(string cedu, string contrasena, double saldo);

    // Métodos getters
    string getCedula() const;
    string getContrasena() const;
    double getSaldo() const;

    void setSaldo(double sald);

    // Método para mostrar la información de la cuenta
    void mostrarInfo() const;
};

// Prototipo de la clase Banco
class Banco {
private:
    Cuenta* cuentas;
    unsigned int posicion, capacidad;

    // Método privado para redimensionar el arreglo
    void redimensionar();

public:
    // Constructor
    Banco();

    // Método para agregar una cuenta al banco
    void agregarCuenta(const Cuenta &cuenta, bool escribirEnlaBase = false);

    // Método para buscar una cuenta por cédula
    Cuenta* buscarCuenta(const string &cedula);

    // Método para mostrar todas las cuentas
    void mostrarCuentas() const;

    // Método para cargar cuentas desde un string
    void cargarCuentasDesdeString(const string &datos);

    // Método para convertir las cuentas a un string
    string convertirCuentasAString() const;

    // Método para escribir en la base de datos
    void escribirEnlaBase();

    // Destructor
    ~Banco();
};



/* FUNCIONES */
string metodo1(const string&, int, string);
string invertir_bloque(const string&);
string metodo2(const string&, int, string);
string convertirTEXTO_A_binario(string nombreArchivo);
int obtenerENTEROpositivo();
void EscribirArchivoBinario(const string&, const string&);
void menuOperacionesBancarias(); void registrarUsuario(Banco&); void consultarSaldo(Banco&); void retirarDinero(Banco&);
bool validarAdmin();
/*#########################################*/




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




string metodo1(const string& binarioAprocesar, int n, string accionArealizar) {
    if (accionArealizar != "codificar" && accionArealizar != "decodificar") {
        return ""; // Validación de la acción
    }

    // Inicializamos el resultado con el primer bloque invertido
    string resultado = invertir_bloque(binarioAprocesar.substr(0, n));

    // Procesamos los bloques siguientes
    for (size_t i = n; i < binarioAprocesar.size(); i += n) {
        string bloque_previo;
        if (accionArealizar == "codificar") {
            bloque_previo = binarioAprocesar.substr(i - n, n);
        } else {
            bloque_previo = resultado.substr(i - n, n);
        }

        // Contamos los 1s y 0s en el bloque previo
        int num_1s = 0;
        int num_0s = 0;
        for (char c : bloque_previo) {
            if (c == '1') {
                num_1s++;
            } else if (c == '0') {
                num_0s++;
            }
        }

        // Tomamos el bloque actual
        string bloque_actual = binarioAprocesar.substr(i, n);

        // Aplicar las reglas según la cantidad de 1s y 0s en el bloque anterior
        if (num_1s == num_0s) {
            resultado += invertir_bloque(bloque_actual);
        } else if (num_0s > num_1s) {
            if (n >= 2) {
                for (size_t j = 1; j < bloque_actual.size(); j += 2) {
                    bloque_actual[j] = (bloque_actual[j] == '0') ? '1' : '0';
                }
            }
            resultado += bloque_actual;
        } else {
            if (n >= 3) {
                for (size_t j = 1; j < bloque_actual.size(); j += 3) {
                    bloque_actual[j] = (bloque_actual[j] == '0') ? '1' : '0';
                }
            }
            resultado += bloque_actual;
        }
    }

    return resultado;
}



string invertir_bloque(const string& bloque) {
    string bloque_invertido = bloque;
    for (char& bit : bloque_invertido) {
        bit = (bit == '0') ? '1' : '0';
    }
    return bloque_invertido;
}





/* FUNCION PARA CODIFICAR Y DECODIFICAR MEDIANTE EL METODO 2 */

string metodo2(const string& binarioAprocesar, int n, string accionArealizar) {
    // Para almacenar el resultado final
    string resultado;

    if (accionArealizar == "codificar") {
        // Codificamos cada bloque
        for (size_t i = 0; i < binarioAprocesar.size(); i += n) {
            string bloqueActual = binarioAprocesar.substr(i, n);

            // Desplazamos cada bit hacia la derecha
            if (bloqueActual.length() == static_cast<size_t>(n)) {
                char ultimoBit = bloqueActual[bloqueActual.length() - 1];
                for (int j = bloqueActual.length() - 1; j > 0; --j) {
                    bloqueActual[j] = bloqueActual[j - 1];
                }
                bloqueActual[0] = ultimoBit;
            }

            resultado += bloqueActual;
        }
    }
    else if (accionArealizar == "decodificar") {
        // Decodificamos cada bloque
        for (size_t i = 0; i < binarioAprocesar.size(); i += n) {
            string bloqueActual = binarioAprocesar.substr(i, n);

            // Desplazamos cada bit hacia la izquierda
            if (bloqueActual.length() == static_cast<size_t>(n)) {
                char primerBit = bloqueActual[0];
                for (size_t j = 0; j < bloqueActual.length() - 1; ++j) {
                    bloqueActual[j] = bloqueActual[j + 1];
                }
                bloqueActual[bloqueActual.length() - 1] = primerBit;
            }

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




// Implementación de la clase Cuenta
Cuenta::Cuenta() : cedula(""), contrasena(""), saldo(0.0) {} // Constructor por defecto

Cuenta::Cuenta(string cedu, string contrasena, double saldo) : cedula(cedu), contrasena(contrasena), saldo(saldo) {}

string Cuenta::getCedula() const {
    return cedula;
}

string Cuenta::getContrasena() const {
    return contrasena;
}

double Cuenta::getSaldo() const {
    return saldo;
}

void Cuenta::setSaldo(double sald) {
    saldo = sald;
}

void Cuenta::mostrarInfo() const {
    cout << "Cedula: " << cedula << endl;
    cout << "Contrasena: " << contrasena << endl;
    cout << "Saldo: " << saldo << endl;
}

// Implementación de la clase Banco
Banco::Banco() {
    capacidad = 100;
    cuentas = new Cuenta[capacidad];  // Asignación de memoria dinámica
    posicion = 0;
}

void Banco::redimensionar() {
    capacidad *= 2;
    Cuenta* nuevoArray = new Cuenta[capacidad]; // Creamos un nuevo arreglo con la nueva capacidad

    // Copiamos las cuentas del arreglo original al nuevo
    for (unsigned int i = 0; i < posicion; i++) {
        nuevoArray[i] = cuentas[i];
    }

    delete[] cuentas;  // Liberamos la memoria del arreglo anterior
    cuentas = nuevoArray; // Asignamos la dirección de memoria del nuevo arreglo al puntero cuentas
}

void Banco::agregarCuenta(const Cuenta &cuenta, bool escribirEnlaBase) {
    // Si ya no hay espacio en el arreglo, lo redimensionamos
    if (posicion >= capacidad) {
        redimensionar();
    }
    cuentas[posicion] = cuenta;
    posicion += 1;

    if (escribirEnlaBase) {
        Banco::escribirEnlaBase();
        cout << "\nLa cuenta ha sido agregada!\n\n";
    }
}

Cuenta* Banco::buscarCuenta(const string &cedula) {
    for (unsigned int i = 0; i < posicion; i++) {
        if (cuentas[i].getCedula() == cedula) {
            return &cuentas[i];  // Retornamos un puntero a la cuenta si la encuentra
        }
    }
    return nullptr;  // Retornamos nullptr si no se encuentra la cuenta
}

void Banco::mostrarCuentas() const {
    system("cls");
    cout << "\n\nLAS CUENTAS REGISTRADAS EN EL SISTEMA SON:\n\n";
    for (unsigned int i = 0; i < posicion; i++) {
        cuentas[i].mostrarInfo();
        cout << "--------------------------" << endl;
    }
    system("pause");
    system("cls");
}

void Banco::cargarCuentasDesdeString(const string &datos) {
    size_t inicio = 0;
    size_t fin;

    // Iteramos mientras haya líneas en el string
    while ((fin = datos.find('\n', inicio)) != string::npos) {
        string linea = datos.substr(inicio, fin - inicio);  // Extraemos una línea
        inicio = fin + 1;

        size_t pos1 = linea.find(':');
        size_t pos2 = linea.find(':', pos1 + 1);

        // Verificamos que se hayan encontrado los separadores ':'
        if (pos1 != string::npos && pos2 != string::npos) {
            string cedula = linea.substr(0, pos1);  // Cédula antes del primer ':'
            string contrasena = linea.substr(pos1 + 1, pos2 - pos1 - 1);  // Contraseña entre los dos ':'
            double saldo = stod(linea.substr(pos2 + 1));  // Convertimos el saldo después del segundo ':'

            // Agregamos la cuenta al banco
            agregarCuenta(Cuenta(cedula, contrasena, saldo));
        }
    }

    // Procesar la última línea (si no tiene un salto de línea al final)
    if (inicio < datos.size()) {
        string linea = datos.substr(inicio);
        size_t pos1 = linea.find(':');
        size_t pos2 = linea.find(':', pos1 + 1);

        if (pos1 != string::npos && pos2 != string::npos) {
            string cedula = linea.substr(0, pos1);
            string contrasena = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            double saldo = stod(linea.substr(pos2 + 1));

            agregarCuenta(Cuenta(cedula, contrasena, saldo));
        }
    }
}

string Banco::convertirCuentasAString() const {
    string resultado;

    for (size_t i = 0; i < posicion; ++i) {
        resultado += cuentas[i].getCedula() + ":" + cuentas[i].getContrasena() + ":" + to_string(cuentas[i].getSaldo());
        if (i < posicion - 1) {
            resultado += "\n";  // Agregamos un salto de línea entre cuentas, excepto para la última
        }
    }

    return resultado;
}

void Banco::escribirEnlaBase() {
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

Banco::~Banco() {
    delete[] cuentas;
}
