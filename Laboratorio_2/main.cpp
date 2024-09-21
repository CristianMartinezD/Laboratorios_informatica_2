#include <iostream>
#include <algorithm> // Para usar las funciones reverse, swap, max y min
#include <vector>

// directivas de preprocesador para determinar si el codigo se esta compilando en linux o en windows.
#ifdef __linux__
#include <cstdlib> // Para system()
#elif defined(_WIN32) || defined(_WIN64)
#include <cstdlib> // Para system()
#else
#error "Sistema operativo no soportado"
#endif

using namespace std;

void problema2 (); int problema4 (); void problema6 ();
void problema8 (); void problema10 (); void problema12 (); void problema14 ();
void problema15 (); void problema16 (); void problema17 (); void problema18 ();

int recibir_entero();


int main()
{
    int opcion = 100;
    while (opcion != 0) {
        cout<<"\n             MENU\nElije un problema (del 1 al 18) o ingresa 0 para salir: ";
        opcion = recibir_entero();
        while (opcion < 0 || opcion >18) {cout<<"OPCION NO VALIDA, ELIGE DEL 1 AL 18, O 0 PARA SALIR: "; opcion = recibir_entero();}

        switch (opcion) {
        case 0: opcion = 0; break;
        case 2: problema2 (); break;
        case 4: {int entero = problema4(); cout<<"\nLa cadena '"<<entero<<"' ha sido convertida en el entero int "<<entero<<endl<<endl; break;}
        case 6: problema6 (); break;
        case 8: problema8 (); break;
        case 10: problema10 (); break;
        case 12: problema12 (); break;
        case 14: problema14 (); break;
        case 15: problema15 (); break;
        case 16: problema16 (); break;
        case 17: problema17 (); break;
        case 18: problema18 (); break;
        }


        // Limpiar la pantalla y hacer pausa según el sistema operativo
        #ifdef __linux__
                getchar();
                system("clear"); // Para Linux
        #elif defined(_WIN32) || defined(_WIN64)
                system("pause");
                system("cls");   // Para Windows
        #endif
    }


    return 0;
}


void problema2(){
    cout << "\nPROBLEMA 2.\nVERIFICAR LETRAS REPETIDAS EN ARREGLO DE LETRAS MAYUSCULAS.\n";

    string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char letrasGeneradas[26];

    char arreglo[200] = {}; // //Arreglo que contendrá las letras con sus repeticiones. Se inicializan todas las posiciones con '\0'
    int repeticiones[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    srand(time(0)); // Semilla con el tiempo actual
    for (int i = 0; i < 200; ++i) {
        int numeroAleatorio = rand() % 26; // Generamos un número aleatorio entre 0 y 25 incluyendo ambos.
        repeticiones[numeroAleatorio] += 1;
        arreglo[i] = letras[numeroAleatorio];
        int indice = letras.find(arreglo[i]);
        letrasGeneradas[indice] = arreglo[i];
    }

    //Imprimimos las letras con sus repeticiones
    for (int i = 0; i < 200; ++i) {
        cout<<arreglo[i]<<" ";
        if (i == 19 || i == 39 || i == 59 || i == 79 || i == 99 || i == 119 || i == 139 || i == 159 || i == 179 || i == 199){
            cout<<endl;
        }
    }

    //Imprimimos los pares Letra: cantidad
    for (int i = 0; i < 26; ++i) {
        if (repeticiones[i] != 0) cout<<letrasGeneradas[i]<<": "<<repeticiones[i]<<endl;
    }
}


int problema4() {
    cout << "\nPROBLEMA 4.\nCONVERTIR CADENA EN ENTERO.";
    string cadena;
    bool cadenaValida = false;  // Bandera para verificar si la cadena es válida
    int entero;

    while (!cadenaValida) {
        cout << "\nIngresa una cadena de caracteres: ";
        cin >> cadena;

        cadenaValida = true;  // Asumimos que la cadena es válida, y la invalidamos si encontramos un error

        // Verificamos cada carácter para asegurarnos de que sea un dígito
        for (int i = 0; i < cadena.length(); ++i) {
            if (cadena[i] < '0' || cadena[i] > '9') {  // Si no es un dígito
                cout << "\nError: '" << cadena[i] << "' no es un numero valido.";
                cout << "\nEsa cadena no se puede convertir en un numero entero, vuelve a intentarlo.\n";
                cadenaValida = false;
                break;
            }
        }
    }

    // Si salimos del bucle, la cadena es válida, así que la convertimos a entero
    entero = stoi(cadena);
    return entero;
}



void problema6 (){
    cout <<"\n	PROBLEMA 6.\nCAMBIAR LETRAS MAYUSCULAS POR MINUSCULAS.";
    string cadenaInicial;
    cout<<"\nIngresa la cadena de caracteres: "; cin>>cadenaInicial;
    string copia = cadenaInicial;

    string MAYUSCULAS = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    string minusculas = "abcdefghijklmnñopqrstuvwxyz";
    for (int i = 0; i < cadenaInicial.length(); ++i) {
        if (minusculas.find(cadenaInicial[i]) != std::string::npos) {
            int indice = minusculas.find(cadenaInicial[i]);
            cadenaInicial[i] = MAYUSCULAS [indice];
        }
    }
    cout<<"\nORIGINAL: "<<copia<<". En mayusculas: "<<cadenaInicial<<"."<<endl<<endl;
}



void problema8 (){
    cout <<"\n	PROBLEMA 8.\nSEPARAR NUMEROS DE LETRAS.";
    string cadenaOrifinal;
    cout<<"\nIngresa la cadena de caracteres: "; cin>>cadenaOrifinal;

    string textoDElaCadena = "", numerosDElaCadena = "";
    for (int i = 0; i < cadenaOrifinal.length(); ++i) {
        if (cadenaOrifinal[i] >= 48 && cadenaOrifinal[i] <= 57) numerosDElaCadena += cadenaOrifinal[i];
        else textoDElaCadena += cadenaOrifinal[i];
    }

    cout <<"\nOriginal: "<<cadenaOrifinal<<endl;
    cout <<"\nTexto: "<<textoDElaCadena<<". Numero: "<<numerosDElaCadena<<endl<<endl;
}



void problema10 (){
    cout <<"\n	PROBLEMA 10.\nCONVERTIR ROMANO A ARABIGO.";
    string ROMANOS = "MDCLXVI", romano;
    cout<<"\nIngresa el numero romano: "; cin>>romano;

    // Verificamos que los caracteres del numero romano ingresado sean todos validos.
    bool ROMANOVALIDO = false;
    while (ROMANOVALIDO == false){
        for (int i = 0; i < romano.size(); ++i) {
            if (ROMANOS.find(romano[i]) == std::string::npos){
                cout<<"\nEse no es un numero romano, ingresalo nuevamente: "; cin>>romano;
                break;
            }
            if (i == (romano.size() - 1)) ROMANOVALIDO = true;
        }
    }

    // Recorremos cada carácter del número romano
    int total = 0, anterior = 0;
    for (int i = romano.length() - 1; i >= 0; i--) {
        char actual = romano[i];
        int valor;

        // Asignamos el valor correspondiente al carácter romano
        switch (actual) {
        case 'M': valor = 1000; break;
        case 'D': valor = 500; break;
        case 'C': valor = 100; break;
        case 'L': valor = 50; break;
        case 'X': valor = 10; break;
        case 'V': valor = 5; break;
        case 'I': valor = 1; break;
        }

        // Si el valor actual es menor que el anterior, verificar si la resta es válida
        if (valor < anterior) {
            // Reglas de restas permitidas
            if ((actual == 'I' && (romano[i + 1] != 'V' && romano[i + 1] != 'X')) ||
                (actual == 'X' && (romano[i + 1] != 'L' && romano[i + 1] != 'C')) ||
                (actual == 'C' && (romano[i + 1] != 'D' && romano[i + 1] != 'M'))) {
                cout << "\nCombinacion invalida de resta en la numeracion romana.\nIntentalo de nuevo." << endl;
                problema10 ();
                ROMANOVALIDO = false;
                break;
            }
            total -= valor;
        } else {
            total += valor;
        }

        // Actualizamos el valor anterior
        anterior = valor;
    }

    // Muestramos el resultado final
    if (ROMANOVALIDO == true){
        cout << "\nEl numero ingresado fue: " << romano << endl;
        cout << "Que corresponde a: " << total << endl <<endl;
    }


}


void problema12 (){
    cout << "\nCUADRADO MAGICO.\n";
    int n;
    cout << "\nCuantas filas tendra tu matriz cuadrada?: "; n = recibir_entero();
    while (n < 2) {cout << "\nINGRESA UN NUMERO DE FILAS VALIDO: "; n = recibir_entero();}

    int matriz[n][n];
    //Obtenemos la matriz.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<"\nIngresa el valor ["<<i+1<<"]["<<j+1<<"] de tu matriz: "; matriz[i][j] = recibir_entero();
        }
    }

    //Imprimimos la matriz.
    cout<<"\nSU MATRIZ ES:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<matriz[i][j]<<" ";
            if (matriz[i][j] < 10) cout<<" ";
            if (j == n-1) cout<<endl;
        }
    }

    //Verificamos si la matriz es un cuadrado magico.
    int sumaDEfilas = 0, sumaDEcolumnas = 0, sumaDiagonal1 = 0, sumaDiagonal2 = 0, constante = 0;
    string magico = "ES UN CUADRADO MAGICO\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sumaDEfilas += matriz[i][j];
            sumaDEcolumnas += matriz[j][i];
            if (i == 0){
                sumaDiagonal1 += matriz[j][j];
                sumaDiagonal2 += matriz[j][(n-1)-j];
            }

        }
        if (i == 0 && sumaDiagonal1 == sumaDiagonal2) constante = sumaDiagonal1;
        if (sumaDEfilas != constante || sumaDEcolumnas != constante){
            magico = "NO ES UN CUADRADO MAGICO\n";
            break;
        }
        sumaDEfilas = 0;
        sumaDEcolumnas = 0;
        sumaDiagonal1 = 0;
        sumaDiagonal2 = 0;
    }
    cout<<"\nTU MATRIZ "<<magico<<endl;
}


void problema14 (){
    cout << "\nIMPRIMIR MATRIZ 5X5 ROTADA 0,90,180,270 GRADOS.\n";
    int matriz[5][5], valor = 1;
    cout<<"\nLlenamos e imprimimos la matriz Inicial:\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matriz[i][j] = valor;
            if (valor < 11) cout<<matriz[i][j]<<"  ";
            else cout<<matriz[i][j]<<" ";
            if (valor == 5 || valor == 10|| valor == 15 || valor == 20) cout<<"\n";
            ++valor;
        }
    }
    cout<<endl;
    int nuevaMatriz[5][5];
    valor = 1;
    cout<<"\nMatriz rotada 90 grados:\n";
    for (int i = 0; i <= 4; ++i) {
        for (int j = 4; j >= 0; --j) {
            if (matriz[j][i] < 10) cout<<matriz[j][i]<<"  ";
            else cout<<matriz[j][i]<<" ";
            if (valor == 5 || valor == 10|| valor == 15 || valor == 20) cout<<"\n";
            ++valor;
            nuevaMatriz[i][4-j] = matriz[j][i]; //Llenamos la matriz rotada 90 grados.
        }
    }
    cout<<endl;
    valor = 1;
    cout<<"\nMatriz rotada 180 grados:\n";
    for (int i = 0; i <= 4; ++i) {
        for (int j = 4; j >= 0; --j) {
            if (nuevaMatriz[j][i] < 10) cout<<nuevaMatriz[j][i]<<"  ";
            else cout<<nuevaMatriz[j][i]<<" ";
            if (valor == 5 || valor == 10|| valor == 15 || valor == 20) cout<<"\n";
            ++valor;
            matriz[i][4-j] = nuevaMatriz[j][i]; //Llenamos la matriz rotada 180 grados.
        }
    }
    cout<<endl;
    valor = 1;
    cout<<"\nMatriz rotada 270 grados:\n";
    for (int i = 0; i <= 4; ++i) {
        for (int j = 4; j >= 0; --j) {
            if (matriz[j][i] < 10) cout<<matriz[j][i]<<"  ";
            else cout<<matriz[j][i]<<" ";
            if (valor == 5 || valor == 10|| valor == 15 || valor == 20) cout<<"\n";
            ++valor;
            //nuevaMatriz[i][4-j] = matriz[j][i]; //Llenamos la matriz rotada 270 grados.
        }
    }
    cout<<endl<<endl;

}


void problema15 (){
    cout << "\nRECTANGULO DE INTERSECCION DE A y B.\n";

    // Capturamos las caracteristicas del rectángulo A.
    int A[4];
    cout << "\nINGRESA X1 DEL RECTANGULO A: "; A[0] = recibir_entero();
    cout << "\nINGRESA Y1 DEL RECTANGULO A: "; A[1] = recibir_entero();
    cout << "\nINGRESA EL ANCHO DEL RECTANGULO A: "; A[2] = recibir_entero();
    cout << "\nINGRESA ALTO DEL RECTANGULO A: "; A[3] = recibir_entero();

    // Capturamos las caracteristicas del rectángulo B.
    int B[4];
    cout << "\nINGRESA X1 DEL RECTANGULO B: "; B[0] = recibir_entero();
    cout << "\nINGRESA Y1 DEL RECTANGULO B: "; B[1] = recibir_entero();
    cout << "\nINGRESA EL ANCHO DEL RECTANGULO B: "; B[2] = recibir_entero();
    cout << "\nINGRESA ALTO DEL RECTANGULO B: "; B[3] = recibir_entero();

    // Calculamos las coordenadas de la esquina superior izquierda del rectángulo de intersección
    int x_interseccion = max(A[0], B[0]);
    int y_interseccion = max(A[1], B[1]);

    // Calculamos las dimensiones (ancho y alto) del rectángulo de intersección
    int ancho_interseccion = min(A[0] + A[2], B[0] + B[2]) - x_interseccion;
    int alto_interseccion = min(A[1] + A[3], B[1] + B[3]) - y_interseccion;

    // Verificamos si hay intersección
    if (ancho_interseccion > 0 && alto_interseccion > 0) {
        // Si hay intersección, imprimimos las coordenadas y dimensiones
        cout << "\nEl rectangulo de interseccion es: {";
        cout << x_interseccion << ", " << y_interseccion << ", ";
        cout << ancho_interseccion << ", " << alto_interseccion << "}\n" << endl;
    } else {
        // Si no hay intersección
        cout << "\nLos rectangulos no se intersectan.\n" << endl;
    }
}



void problema16 (){
    cout << "\nNUMERO DE CAMINOS POSIBLES PARA RECORRER MALLA NXN.\n";
    int n;

    cout << "\nIntroduce el valor n para la malla, mayor a 0: ";
    cin >> n;

    while (n <= 0) {
        cout << "\nEL VALOR DE n DEBE SER MAYOR A 0, VUELVE A INGRESAR n: ";
        cin >> n;
    }

    /*ESTE PROBLEMA SE RESUELVE USANDO CONVINATORIA, LA FORMULA ES: (2n)! / (n! * n!) */

    // Cálculamos el factorial de 2n
    unsigned long long factorial2n = 1;
    for (int i = 1; i <= 2 * n; ++i) {
        factorial2n *= i;
    }

    // Cálculamos el factorial de n
    unsigned long long factorialn = 1;
    for (int i = 1; i <= n; ++i) {
        factorialn *= i;
    }

    // El número de caminos sería: (2n)! / (n! * n!)
    unsigned long long caminos = factorial2n / (factorialn * factorialn);

    cout << "\nPara una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos.\n" << endl;

}



void problema17() {
    cout << "\nSUMA DE LOS NUMEROS AMIGABLES MENORES A N.";
    int n, suma = 0;
    vector<int> amigos;

    cout << "\nIntroduce el valor de n, mayor a 220: ";
    cin >> n;

    while (n <= 220) {
        cout << "\nEL VALOR DE n DEBE SER MAYOR A 220, VUELVE A INGRESAR n: ";
        cin >> n;
    }

    for (int posibleAmigable = 220; posibleAmigable < n; ++posibleAmigable) {
        int suma1 = 0;
        // Calcular la suma de divisores de posibleAmigable
        for (int i = 1; i <= posibleAmigable / 2; ++i) {
            if (posibleAmigable % i == 0) {
                suma1 += i;
            }
        }

        if (suma1 > posibleAmigable) {
            int suma2 = 0;
            // Calcular la suma de divisores de suma1
            for (int i = 1; i <= suma1 / 2; ++i) {
                if (suma1 % i == 0) {
                    suma2 += i;
                }
            }

            // Verificar si son números amigables
            if (suma2 == posibleAmigable) {
                // Verificar si los números ya están en la lista para evitar duplicados
                if (suma1 < n && find(amigos.begin(), amigos.end(), suma1) == amigos.end()) {
                    amigos.push_back(suma1);
                }
                if (find(amigos.begin(), amigos.end(), posibleAmigable) == amigos.end()) {
                    amigos.push_back(posibleAmigable);
                }
            }
        }
    }

    // Calcular la suma de los números amigables encontrados
    for (int i = 0; i < amigos.size(); ++i) {
        suma += amigos[i];
    }

    cout << "\nEl resultado de la suma es: " << suma << endl << endl;
}



void problema18 (){
    cout<<"\nENESIMA PERMUTACION LEXICOGRAFICA.";
    int n; bool hubosuficientespermutaciones = true;
    cout << "\nIntroduce el valor de n: "; n = recibir_entero();
    while (n <= 0) { cout << "\nEL VALOR DE n DEBE SER MAYOR A 0, VUELVE A INGRESAR n: "; n = recibir_entero();}

    string permutacion = "0123456789";

    // Aquí generamos permutaciones hasta alcanzar la enésima
    for (int contador = 1; contador < n; ++contador) {
        int i = permutacion.length() - 2;

        // Encuentramos el primer dígito que es menor que el siguiente
        while (i >= 0 && permutacion[i] >= permutacion[i + 1])
            i--;

        if (i < 0) {
            cout << "No hay suficientes permutaciones." << endl;
            hubosuficientespermutaciones = false;
            break;
        }

        // Encuentramos el número más pequeño a la derecha de permutacion[i] que sea mayor que permutacion[i]
        int j = permutacion.length() - 1;
        while (permutacion[j] <= permutacion[i])
            j--;

        // Intercambiamos permutacion[i] y permutacion[j]
        swap(permutacion[i], permutacion[j]);

        // Invertimos los dígitos a la derecha de permutacion[i] para obtener la siguiente permutación
        reverse(permutacion.begin() + i + 1, permutacion.end());
    }

    // Mostramos la permutación número n
    if (hubosuficientespermutaciones) cout << "\nLa permutacion numero " << n << " es: " << permutacion << endl <<endl;

}


int recibir_entero(){ /* Esta función verifica si un string puede servir como un numero entero */
    string numero_en_texto;
    cin >> numero_en_texto;

    bool El_numero_es_negativo = false;
    string NUMEROS = "1234567890";
    unsigned validador = 0;

    while (validador < numero_en_texto.length())
    {   if (numero_en_texto[0] == '-' && numero_en_texto.length() > 1) {numero_en_texto.erase(0,1); El_numero_es_negativo = true;}

        for (unsigned i = 0; i < numero_en_texto.length(); i++)
        {

            if (NUMEROS.find(numero_en_texto[i]) != string::npos) {
                validador += 1;
            } else{
                cout<<"Ingresa un numero valido: "; cin>>numero_en_texto;
                validador = 0;
                break;
            }
        }
        if (validador != 0) validador += 1;
    }

    if (El_numero_es_negativo) return -1*stoi(numero_en_texto);
    else return stoi(numero_en_texto);

}


