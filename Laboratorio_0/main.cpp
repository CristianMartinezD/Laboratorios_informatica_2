#include <iostream>

using namespace std;

            /*DECLARACIÓN DE FUNCIONES*/

int verificar_entero(string); /* Esta función verifica si un string puede servir como un numero entero */
void ejercicio0();
void ejercicio1();
void ejercicio2();


            /*FUNCION PRINCIPAL DEL PROGRAMA*/
int main()
{
    int OPCION = 7; string opcion;
    while (OPCION != 3) {

        cout<<"Cual de los ejercicios quieres probar?"
                "\n 0. El ejemplo"
                "\n 1. El primero"
                "\n 2. El segundo"
                "\n 3. Deseo salir"
                "\nIngresa una de las anteriores opciones (0-3): "; cin >> opcion;
        OPCION = verificar_entero(opcion);

        while (OPCION < 0 || OPCION > 3) {
            cout<<"\nESA OPCION NO ES VALIDA, ELIJE ENTRE 0-3\n";
            OPCION = verificar_entero("NO VALIDA");
        }

        switch (OPCION) {
        case 0: {ejercicio0(); break;}
        case 1: {ejercicio1(); break;}
        case 2: {ejercicio2(); break;}
        case 3: {OPCION = 3; break;}
        }

    }

    return 0;
}




int verificar_entero(string numero_en_texto){

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





void ejercicio0(){
    system("cls");
    cout<<"\n   HAGAMOS DOS TRIANGULOS JUNTOS.\n\n";
    cout<<"Escribe un numero entero positivo: ";
    int N; string n;
    cout<<"Escribe un numero entero positivo: "; cin>>n;

    N = verificar_entero(n);
    while (N <= 0) {cout<<"\nEse numero NO es valido.\n"; N = verificar_entero("NO VALIDO");}

    for(int fila=1; fila <= N; fila++){
        for (int asterisco=1; asterisco <= fila; asterisco++) cout<<"*"; //Este for imprime tantos asteriscos como indique el el valor de fila.
        for (int espacios=1; espacios < (N-fila)*2; espacios++) cout<<" "; // Este for imprime (n-fila)*2 espacios en cada iteración.
        for (int asterisco=1; asterisco <= fila; asterisco++){
            if(asterisco !=N) cout<<"*";
        }

        cout<<endl;
    }
    cout<<"\nEse es el resultado del ejercicio del ejemplo.\n\n";
    system("pause");
    system("cls");
}




void ejercicio1(){
    system("cls");
    cout<<"\n   HAGAMOS UNA MARIPOSA.\n\n";
    int N; string n;
    cout<<"Escribe un numero entero positivo: "; cin>>n;

    N = verificar_entero(n);
    while (N <= 0) {cout<<"\nEse numero NO es valido.\n"; N = verificar_entero("NO VALIDO");}

    for(int fila=1; fila <= N; fila++){
        for (int asterisco=1; asterisco <= fila; asterisco++) cout<<"*"; //Este for imprime tantos asteriscos como indique el el valor de fila.
        for (int espacios=1; espacios < (N-fila)*2; espacios++) cout<<" "; // Este for imprime (n-fila)*2 espacios en cada iteración.
        for (int asterisco=1; asterisco <= fila; asterisco++){
            if(asterisco !=N) cout<<"*";
        }

        cout<<endl;
    }


    for (int fila=N-1; fila>=1; fila--){
        for (int asterisco=1; asterisco <= fila; asterisco++) cout<<"*";
        for (int espacios=1; espacios < (N-fila)*2; espacios++) cout<<" ";
        for (int asterisco=1; asterisco <= fila; asterisco++) cout<<"*";

        cout<<endl;
    }
    cout<<"\nEse es el resultado del ejercicio 1.\n\n";
    system("pause");
    system("cls");
}



void ejercicio2(){
    system("cls");
    cout<<"\n   PROGRAMA QUE AL RECIBIR 231 HACE 2^2+3^3+1^1=32.\n\n";
    int N; string n;
    cout<<"Escribe un numero entero: "; cin>>n;

    N = verificar_entero(n);

    if (N < 0) N = -1*N;

    int digito;
    int suma = 0;
    int digitoCopia;
    while (N > 0) {
        digito = N%10;
        digitoCopia = digito;
        for (int i = 1; i < digitoCopia; ++i) {
            digito = digito*digitoCopia;
        }
        suma = suma+digito;
        N = N/10;

    }

    cout<<"\n\nLa suma da: "<<suma<<"\n";
    cout<<"\nEse es el resultado del ejercicio 2.\n\n";
    system("pause");
    system("cls");
}
