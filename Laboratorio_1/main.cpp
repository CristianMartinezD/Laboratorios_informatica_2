#include <iostream>
#include <cstdlib>

using namespace std;

        /* DECLARACIÓN DE LAS FUNCIONES: EJERCICIOS */
void ejercicio_1(); void ejercicio_2(); void ejercicio_3();
void ejercicio_4(); void ejercicio_5(); void ejercicio_6();
void ejercicio_7(); void ejercicio_8(); void ejercicio_9();
void ejercicio_10(); void ejercicio_11(); void ejercicio_12();
void ejercicio_13(); void ejercicio_14(); void ejercicio_15();
void ejercicio_16(); void ejercicio_17(); void ejercicio_18();
void ejercicio_19(); void ejercicio_20(); void ejercicio_21();
void ejercicio_22(); void ejercicio_23(); void ejercicio_24();
void ejercicio_25(); void ejercicio_26();void ejercicio_27();
void ejercicio_28(); void ejercicio_29(); void ejercicio_30();


        /* DECLARACIÓN DE LAS FUNCIONES: PROBLEMAS */
void problema_1(); void problema_2(); void problema_3();
void problema_4(); void problema_5(); void problema_6();
void problema_7(); void problema_8(); void problema_9();
void problema_10(); void problema_11(); void problema_12();
void problema_13(); void problema_14(); void problema_15();
void problema_16(); void problema_17();

        /*DECLARACIÓN DE OTRAS FUNCIONES*/
int verificar_entero(string); /* Esta función verifica si un string
                            puede servir como un numero entero */
int mayor_a_0 (int);




int main()
{
    int OPCION = 100;
    while (OPCION != 0) {
        string opcion;
        cout<<"\nDeseas probar un EJERCICIO o un PROBLEMA?\n1. Ejercicio\n2. Problema\n0. Salir";
        cout<<"\nINGRESA UNA OPCION (1,2 o 0): "; cin>>opcion;
        OPCION = verificar_entero(opcion);
        while (OPCION != 1 && OPCION != 2 && OPCION != 0) {
            OPCION = verificar_entero("NO VALIDO");
        }

        if (OPCION == 1){
            string ejercicio; int EJERCICIO;
            cout<<"\nCual ejercicio deseas probar (del 1 al 30): "; cin>>ejercicio;
            EJERCICIO = verificar_entero(ejercicio);
            while (EJERCICIO < 1 || EJERCICIO > 30) {
                cout<<"Valor NO valido"<<endl;
                EJERCICIO = verificar_entero("Valor NO valido");
            }
            switch (EJERCICIO) {
            case 1: ejercicio_1();break;
            case 2: ejercicio_2();break;
            case 3: ejercicio_3();break;
            case 4: ejercicio_4();break;
            case 5: ejercicio_5();break;
            case 6: ejercicio_6();break;
            case 7: ejercicio_7();break;
            case 8: ejercicio_8();break;
            case 9: ejercicio_9();break;
            case 10: ejercicio_10();break;
            case 11: ejercicio_11();break;
            case 12: ejercicio_12();break;
            case 13: ejercicio_13();break;
            case 14: ejercicio_14();break;
            case 15: ejercicio_15();break;
            case 16: ejercicio_16();break;
            case 17: ejercicio_17();break;
            case 18: ejercicio_18();break;
            case 19: ejercicio_19();break;
            case 20: ejercicio_20();break;
            case 21: ejercicio_21();break;
            case 22: ejercicio_22();break;
            case 23: ejercicio_23();break;
            case 24: ejercicio_24();break;
            case 25: ejercicio_25();break;
            case 26: ejercicio_26();break;
            case 27: ejercicio_27();break;
            case 28: ejercicio_28();break;
            case 29: ejercicio_29();break;
            case 30: ejercicio_30();break;
            }
        }

        else if(OPCION == 2){
            string problema; int PROBLEMA;
            cout<<"\nCual problema deseas probar (del 1 al 17): "; cin>>problema;
            PROBLEMA = verificar_entero(problema);
            while (PROBLEMA < 1 || PROBLEMA > 17) {
                cout<<"Valor NO valido"<<endl;
                PROBLEMA = verificar_entero("Valor NO valido");
            }

            switch (PROBLEMA) {
                case 1: problema_1(); break;
                case 2: problema_2(); break;
                case 3: problema_3(); break;
                case 4: problema_4(); break;
                case 5: problema_5(); break;
                case 6: problema_6(); break;
                case 7: problema_7(); break;
                case 8: problema_8(); break;
                case 9: problema_9(); break;
                case 10: problema_10(); break;
                case 11: problema_11(); break;
                case 12: problema_12(); break;
                case 13: problema_13(); break;
                case 14: problema_14(); break;
                case 15: problema_15(); break;
                case 16: problema_16(); break;
                case 17: problema_17(); break;
            }
        }

        else OPCION = 0;

    }


    return 0;
}





/*
    EJECICIO No. 1
*/
void ejercicio_1(){
    string A,B;

    cout<<"\nEscribe un numero entero: "; cin>>A;
    int a = verificar_entero(A);
    cout<<"\nEscribe otro numero entero: "; cin>>B;
    int b = verificar_entero(B);

    cout<<"\nEl residuo de la division "<<a<<"/"<<b<<" es: "<<a%b<<endl<<endl;
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 2
*/
void ejercicio_2(){
    string n; int N;
    cout<<"\nEscribe un numero entero y te dire si es par o impar: "; cin>>n;

    N = verificar_entero(n); //Aquí verifico si ese string n puede servir como un entero.

    if (N%2 == 0) {cout<<endl<<N<<" Es par\n\n";}
    else {cout<<endl<<endl<<N<<" Es impar\n\n";}
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 3
*/
void ejercicio_3(){
    int A,B,Mayor; string a,b;
    cout<<"\nEscribe dos numeros y te digo cual es mayor.\n";
    cout<<"\nEscribe el primer numero entero: "; cin>>a;
    A = verificar_entero(a);
    cout<<"\nEscribe el segundo numero entero: "; cin>>b;
    B = verificar_entero(b);
    Mayor = (A > B) ? A:B;
    cout<<"\nEl mayor es "<<Mayor<<endl<<endl;
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 4
*/
void ejercicio_4(){
    int A,B,menor; string a,b;
    cout<<"\nEscribe dos numeros y te digo cual es menor.\n";
    cout<<"\nEscribe el primer numero entero: "; cin>>a;
    A = verificar_entero(a);
    cout<<"\nEscribe el segundo numero entero: "; cin>>b;
    B = verificar_entero(b);
    menor = (A < B) ? A:B;
    cout<<"\n\nEl menor es "<<menor<<endl<<endl;
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 5
*/
void ejercicio_5(){
    int A,B; string a,b;
    cout<<"\n     REDONDEO DE A/B\n";
    cout<<"\nEscribe un numero entero: "; cin>>a;
    A = verificar_entero(a);
    cout<<"\nEscribe otro numero entero: "; cin>>b;
    B = verificar_entero(b);

    if (B<0) {B = -1*B; A = -1*A;}

    float residuo = A%B;

    if (residuo > 0) {
        if (residuo/B >= 0.5){cout<<endl<<A<<"/"<<B<<" = "<<(A/B)+1<<endl<<endl;}
        else {cout<<endl<<A<<"/"<<B<<" = "<<A/B<<endl<<endl;}
        system("pause");
        system("cls");
    }

    else {
        residuo = -1*residuo;
        if (residuo/B >= 0.5){cout<<endl<<A<<"/"<<B<<" = "<<(A/B)-1<<endl<<endl;}
        else {cout<<endl<<A<<"/"<<B<<" = "<<A/B<<endl<<endl;}
        system("pause");
        system("cls");
    }
}
/*##########FIN##########*/


/*
    EJECICIO No. 6
*/
void ejercicio_6(){
    int A,B; string a,b;
    cout<<"\n     POTENCIA DE A^B\n";
    cout<<"\nEscribe un numero entero: "; cin>>a;
    A = verificar_entero(a);
    cout<<"\nEscribe otro numero entero: "; cin>>b;
    B = verificar_entero(b);

    bool B_es_negativo = false;
    if (B < 0){ B = B*(-1); B_es_negativo = true;}

    if (B == 0) {cout<<endl<<A<<"^"<<B<<" = "<<1;}
    else{
        long long int resultado = A;
        for (int var = 1; var < B; ++var) {
            resultado *= A;
        }
        if(B_es_negativo == false)cout<<endl<<A<<"^"<<B<<" = "<<resultado<<endl<<endl;
        else {float resul = 1.0/resultado; cout<<endl<<A<<"^-"<<B<<" = "<<resul<<endl<<endl;}
    }
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 7
*/
void ejercicio_7(){
    int N; string n;
    cout<<"\nEscribe un numero entero N y te doy la sumatoria de 0 hasta N: "; cin>>n;

    N = verificar_entero(n);
    bool A_es_negativo = false;
    if (N < 0) {A_es_negativo = true; N = -1*N;}

    int suma = 0;
    for (int var = 1; var <= N; ++var) {
        suma += var;
    }
    if (A_es_negativo == true) {cout<<"\nLa sumatoria desde 0 hasta -"<<N<<" es -"<<suma<<endl<<endl;}
    else cout<<"\nLa sumatoria desde 0 hasta "<<N<<" es "<<suma<<endl<<endl;
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 8
*/
void ejercicio_8(){
    int N; string n;
    cout<<"\n     HALLEMOS N!\n";
    cout<<"\nEscribe un numero entero positivo: "; cin>>n;
    N = verificar_entero(n);
    while (N < 0) {cout<<"El numero debe ser positivo.\n"; N = verificar_entero("NO VALIDO");}

    int long long resultado = 1;
    for (int var = 1; var <= N; ++var) {
        resultado *= var;
    }
    cout<<"\n"<<N<<"!: "<<resultado<<endl<<endl;
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 9
*/
void ejercicio_9(){
    int R; float pi = 3.1416; string r;
    cout<<"\n     HALLAR PERIMETRO Y AREA.\n";
    cout<<"\nEscribe un numero entero positivo: "; cin>>r;
    R = verificar_entero(r);
    while (R < 0) {cout<<"El numero debe ser positivo.\n"; R = verificar_entero("NO VALIDO");}
    cout<<"\n\nPerimetro: "<<2*pi*R<<endl;
    cout<<"\nArea: "<<pi*R*R<<endl<<endl;
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 10
*/
void ejercicio_10(){
    int N; string n;
    cout<<"\n     MULTIPLOS DE N MENORES A 100\n";
    cout<<"\nEscribe un numero mayor que 0: "; cin>>n;
    N = verificar_entero(n);
    while (N < 0) {cout<<"El numero debe ser positivo.\n"; N = verificar_entero("NO VALIDO");}

    cout<<"\nMultiplos de "<<N<<" menores que 100:\n";

    int i = 1;
    while (N*i < 100) {
        cout<<N*i<<endl;
        i++;
    }
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 11
*/
void ejercicio_11(){
    string n; int N;
    cout<<"\nLA TABLA DE MULTIPLICAR DE N\n";
    cout<<"\nEscribe un numero entero N y te muestro su tabla hasta 10xN: \n"; cin>>n;
    N = verificar_entero(n);

    for (int i = 1; i <= 10; i++) cout<<i<<"x"<<N<<"="<<i*N<<endl;

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 12
*/
void ejercicio_12(){
    int N; string n;
    cout<<"\n   POTENCIAS DESDE N^1 HASTA N^5\n";
    cout<<"Escribe un numero entero: "; cin>>n;
    N = verificar_entero(n);
    int potencia = N;
    cout<<N<<"^"<<1<<"="<<potencia<<endl;
    for (int i = 2; i <= 5; i++){
        for (int j = 2; j <= i; j++){
            potencia *= N;
        }
        cout<<N<<"^"<<i<<"="<<potencia<<endl;
        potencia = N;
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 13
*/
void ejercicio_13(){
    int N; string n;
    cout<<"\n   LOS DIVISORES DE N\n";
    cout<<"Escribe un numero entero: "; cin>>n;
    N = verificar_entero(n);

    if (N == 0) cout<<"\nLos divisores del 0 son todos los reales."<<endl;
    else {cout<<"\nLos divisores de "<<N<<" son:"<<endl;
        if (N < 0) N = -1*N;
        for (int i = 1; i <= N; i++){
            if (N%i == 0) cout<<i<<endl;
        }
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 14
*/
void ejercicio_14(){
    cout<<"\n   IMPRIMIR DOS COLUMNAS (1-50 | 50-1)\n";

    for (int i = 1; i <= 50; i++){
        cout<<i<<"      "<<51-i<<endl;
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 15
*/
void ejercicio_15(){
    string n; int N, suma = 0; bool cero = false, primera_vez =true;

    cout<<"\n   SUMAR HASTA QUE SE INGRESE 0\n";
    while (cero != true) {
        if (primera_vez == true){
            cout<<"Ingresa un numero entero: "; cin>>n;
            N = verificar_entero(n);
            suma += N;
            primera_vez = false;
        }
        else{
            cout<<"Ingresa otro numero entero: "; cin>>n;
            N = verificar_entero(n);
            suma += N;
        }
        if (N == 0) {
            cero = true;
            cout<<"\nEl resultado de la sumatoria es: "<<suma<<endl<<endl;
        }

    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 16
*/
void ejercicio_16(){
    cout<<"\n   CALCULAR EL PROMEDIO DE LOS N NUMEROS INGRESADOS HASTA QUE SE INGRESE 0\n";

    string n; int N,contador = 0; float suma = 0; bool cero = false, primera_vez =true;

    while (cero != true) {
        if (primera_vez == true){
            cout<<"Ingresa un numero entero: "; cin>>n;
            N = verificar_entero(n);
            suma += N;
            primera_vez = false;
            contador += 1;
        }
        else if(primera_vez == false){
            cout<<"Ingresa otro numero entero: "; cin>>n;
            N = verificar_entero(n);
            suma += N;
            contador += 1;
        }
        if (N == 0) {
            if (contador != 1) contador -= 1;
            cero = true;
            cout<<"\nEl promedio es: "<<suma/contador<<endl<<endl;
        }

    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 17
*/
void ejercicio_17(){
    cout<<"\n   CALCULAR EL MAYOR NUMERO INGRESADO\n";

    string n; int N; int Mayor = 0; bool cero = false, primera_vez =true;

    while (cero != true) {
        if (primera_vez == true){
            cout<<"Ingresa un numero entero: "; cin>>n;
            N = verificar_entero(n);
            Mayor = N;
            primera_vez = false;
            if (N == 0) {cout<<"\nNo ingresaste nada, chao!\n"; break;}
        }
        else if(primera_vez == false){
            cout<<"Ingresa otro numero entero: "; cin>>n;
            N = verificar_entero(n);
            if (Mayor < N) Mayor = N;
        }
        if (N == 0) {
            cout<<"\nEl Mayor numero ingresado fue: "<<Mayor<<endl<<endl;
            cero = true;
        }

    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 18
*/
void ejercicio_18(){
    cout<<"\n   VERIFICAR SI ES UN CUADRADO PERFECTO\n";

    string n; int N; bool si_es = false;
    cout<<"Ingresa un numero entero: "; cin>>n;
    N = verificar_entero(n);
    if (N < 0) cout<<endl<<N<<" NO es un cuadrado perfecto\n\n";
    for (int numerito = 0; numerito <= N; ++numerito) {
        if (numerito*numerito == N) {
            cout<<endl<<N<<" Es un cuadrado perfecto\n\n"; si_es = true; break;}
    }
    if (si_es == false && N >= 0) cout<<endl<<N<<" NO es un cuadrado perfecto\n\n";
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 19
*/
void ejercicio_19(){
    cout<<"\n   NUMEROS PRIMOS\n";

    int N; string n; bool primo = true;
    cout<<"Escribe un numero entero: "; cin>>n;

    N = verificar_entero(n);

    if (N <= 1) {cout<<endl<<N<<" NO es un numero primo\n";}
    else{
        for (int i = 2; i <= N/2; ++i) {
            if (N%i == 0){primo = false;}
        }
        if(primo == true) cout<<endl<<N<<" es un numero primo\n";
        else cout<<endl<<N<<" NO es un numero primo\n";
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 20
*/
void ejercicio_20(){
    cout<<"\n   NUMEROS PALINDROMOS\n";

    int N; string n; bool negativo = false;
    cout<<"Escribe un numero entero: "; cin>>n;

    N = verificar_entero(n);
    int original = N;

    if (N < 0) {N = -1*N; negativo = true;}

    int digito;
    int alreves = 0;
    while (N > 0) {
        digito = N%10;

        alreves = alreves*10 + digito;
        N = N/10;

    }
    if (negativo == true) alreves = -1*alreves;
    if(alreves == original) cout<<endl<<original<<" es un numero palindromo.\n";
    else cout<<endl<<original<<" NO es un numero palindromo.\n";

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 21
*/
void ejercicio_21(){
    cout<<"\n   CONVERTIR MINUSCULA A MAYUSCULA Y VICEVERSA\n";
    char letra; string Mayusculas = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ", minusculas = "abcdefghijklmnñopqrstuvwxyz";
    cout<<"\nIngresa una letra: "; cin>> letra;

    bool aceptable = false;
    while (aceptable == false) {
        if(Mayusculas.find(letra) != string::npos){ /* Si el indice que devuelve find al buscar a letra en Mayusculas, es diferente de un valor fuera de rango */
            letra = minusculas[Mayusculas.find(letra)];
            aceptable = true;
        }
        else if(minusculas.find(letra) != string::npos){ /* Si el indice que devuelve find al buscar a letra en minusculas, es diferente de un valor fuera de rango */
            letra = Mayusculas[minusculas.find(letra)];
            aceptable = true;
        }
        else {
            cout<<"\nEl caracter que ingresaste NO es valido, ingresa una letra: ";
            cin>>letra;
        }

    }
    cout<<endl<<"Letra convertida: "<<letra<<endl;

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 21
*/
void ejercicio_22(){
    cout<<"\n   CONVERTIR SEGUNDOS A H:M:S\n";

    int segundos, horas, minutos; float h, m, s; string segundosTEXTOS;
    cout<<"\nIngresaa la cantidad de segundos: ";cin>>segundosTEXTOS;
    segundos = verificar_entero(segundosTEXTOS);
    while (segundos < 0) {
        cout<<"HAS INGRESADO UN VALOR NO VALIDO.\n";
        segundos = verificar_entero("NO VALIDO");
    }
    h = segundos/3600.0;
    horas = h;
    m = h - horas;
    m = m*60;
    minutos = m;
    s = m - minutos;
    segundos = s*60;
    cout<<"\nLa conversion a h:m:s es: "<<horas<<":"<<minutos<<":"<<segundos<<endl;
    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 23
*/
void ejercicio_23(){
    cout<<"\n   EL MINIMO COMUN MULTIPLO DE N1 y N2\n";

    string A,B; int N1,N2; bool N1EsNegativo = false, N2EsNegativo = false;
    cout<<"\nIngresa un numero entero: ";cin>>A;
    N1 = verificar_entero(A);
    cout<<"\nIngresa otro numero entero: ";cin>>B;
    N2 = verificar_entero(B);
    if (N1 < 0) {N1 = -1*N1; N1EsNegativo = true;}
    if (N1 < 0) {N2 = -1*N2; N2EsNegativo = true;}

    if (N1 == 0 || N2 == 0) cout<<"\nPara esos dos numeros NO esta definido el m.c.m\n\n";
    else {
        int mayor = (N1 > N2) ? N1:N2;
        int menor = (N1 < N2) ? N1:N2;
        int i = 1;
        int control = 0;
        int MCM;
        while (control == 0) {
            if((mayor*i)%menor == 0){MCM = mayor*i; control = 1;}
            i += 1;
        }
        if(N1EsNegativo) N1 = -1*N1;
        if(N2EsNegativo) N2 = -1*N2;
        cout<<"\nEl M.C.M entre |"<<N1<<"| y |"<<N2<<"| es "<<MCM<<endl<<endl;
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 24
*/
void ejercicio_24(){
    cout<<"\n   CONSTRUIR UN CUADRADO CON N\n";

    string l; int lado;
    cout<<"\nIngresa un numero entero positivo(lado): ";cin>>l;
    lado = verificar_entero(l);
    lado = mayor_a_0(lado);

    for (int i = 1; i <= lado; ++i) {
        if(i == 1 || i == lado){
            for (int j = 1; j <= lado; ++j) {cout<<"+";}
            cout<<endl;
        }
        else {
            cout<<"+";
            for (int k = 2; k <= lado-1; ++k) {cout<<" ";}
            cout<<"+";
            cout<<endl;
        }
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 25
*/
void ejercicio_25(){
    cout<<"\n   CUANTOS DIGITOS TIENE  N\n";

    string n; int N;
    cout<<"\nIngresa un numero entero: "; cin>>n;
    N = verificar_entero(n);

    int copia_N = N; if(copia_N < 0) copia_N = -1*copia_N;
    int contador = 0;
    while (copia_N > 0) {
        copia_N = copia_N/10;
        contador += 1;
    }
    cout<<endl<<N<<" tiene "<<contador<<" digitos\n\n";

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 26
*/
void ejercicio_26(){
    cout<<"\n   QUE TRIANGULO SE FORMA CON A,B,C?\n";

    string a,b,c; int A,B,C;
    cout<<"\nIngresa un numero (a) entero mayor a 0: "; cin>>a;
    A = verificar_entero(a);
    A = mayor_a_0(A);
    cout<<"\nIngresa otro numero (b) entero mayor a 0: "; cin>>b;
    B = verificar_entero(b);
    B = mayor_a_0(B);
    cout<<"\nIngresa otro numero (c) entero mayor a 0: "; cin>>c;
    C = verificar_entero(c);
    C = mayor_a_0(C);

    if(A+B <= C) cout<<"\nLas longitudes "<<A<<","<<B<<" y "<<C<<" NO forman un triangulo\n\n";
    else {
        if (A == B && C != A) cout<<"\nSe forma un triangulo Isosceles\n\n";
        else if (A == B && C == A) cout<<"\nSe forma un triangulo Equilatero\n\n";
        else cout<<"\nSe forma un triangulo Escaleno\n\n";
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 27
*/
void ejercicio_27(){
    cout<<"\n   CALCULADORA\n";
    string a,b; char operador; float A,B;

    cout<<"Ingresa un numero: ";cin>>a;
    A = verificar_entero(a);
    cout<<"Ingresa otro numero: ";cin>>b;
    B = verificar_entero(b);
    cout<<"\nQue operacion quieres realiza?\nESCRIBE (+), (-), (x) o (/): ";
    cin>>operador;
    while (operador != '+' && operador != '-' && operador != 'x' && operador != '/') {
        cout<<"\nOperador invalido, ingresa (+), (-), (x) o (/): "; cin>>operador;
    }

    switch (operador) {
    case '+':
        cout<<A<<"+"<<B<<"="<<A+B<<endl; break;
    case '-':
        cout<<A<<"-"<<B<<"="<<A-B<<endl; break;
    case 'x':
        cout<<A<<"x"<<B<<"="<<A*B<<endl; break;
    case '/':
        cout<<A<<"/"<<B<<"="<<(A/B)<<endl; break;
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 28
*/
void ejercicio_28(){
    cout<<"\n   APROXIMACION DE PI\n";

    int N; string n;
    cout << "Ingrese el numero de elementos usados en la aproximacion: "; cin >> n;
    N = verificar_entero(n);
    N = mayor_a_0(N);

    double pi = 0.0;
    for (int i = 0; i < N; i++) {
        // Alterna entre sumar y restar términos
        if (i % 2 == 0) {
            pi += 1.0 / (2 * i + 1);
        } else {
            pi -= 1.0 / (2 * i + 1);
        }
    }

    pi *= 4; // Multiplica el resultado final por 4

    cout << "\npi es aproximadamente: " << pi <<endl<<endl;

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 29
*/
void ejercicio_29(){
    cout<<"\n   ADIVINAR NUMERO A (entre 0 y 100)\n";

    char opcion = 'i';
    int superior = 100;
    int inferior = 0;
    int medio = (superior + inferior)/2;
    while (opcion != '=') {
        cout<<"\nEl numero que estas pensando es el "<<medio<<"?\n";
        cout<<"Si adivine escribe '='o de lo contrario escribe '<' o '>' segun corresponda: ";
        cin>>opcion;
        if (opcion == '<'){
            superior = medio;
            medio = (superior + inferior)/2;
        }
        else if(opcion == '>'){
            inferior = medio;
            medio = (superior + inferior)/2;
        }
        else if(opcion == '=') cout<<"\nNUMERO ADIVINADO\n\n";
        else cout<<"\nOpcion NO valida\n";
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


/*
    EJECICIO No. 30
*/
void ejercicio_30(){
    cout<<"\n   ADIVINAR NUMERO\n";
    srand(time(0)); /* Esto es para que rand() me genere valores dsitintos en cada ejecucion*/
    int numero = rand() & 100;
    int entrada; string texto;
    cout<<"\nEscribe el numero que estoy pensando: "; cin>>texto;
    entrada = verificar_entero(texto);

    bool acertado = false;
    while (acertado == false) {
        if (numero == entrada) {cout<<"\n\nADIVINASTE!\n"; acertado = true;}
        else if (entrada < numero) {
            cout<<"\nEl numero es mas grande, intentalo de nuevo: "; cin>>texto;
            entrada = verificar_entero(texto);
        }
        else if (entrada > numero) {
            cout<<"\nEl numero es mas pequeno, intentalo de nuevo: "; cin>>texto;
            entrada = verificar_entero(texto);
        }
        else {cout<<"\nNO ingresaste una opcion valida, intentalo de nuevo: "; cin>>texto;
            entrada = verificar_entero(texto);
        }
    }

    system("pause");
    system("cls");
}
/*##########FIN##########*/


void problema_1(){
    cout<<"\n         IDENTIFICAR SI ES CONSONANTE, VOCAL O NINGUNA.\n";

    char caracter; string vocales = "aeiouAEIOU"; string consonantes = "bcdfghjklmnñpqrstvwxyzBCDFGHJKLMNÑPQRSTVWXYZ";

    cout<<"\nIngresa un caracter: "; cin>>caracter;

    if(consonantes.find(caracter) != string::npos){
        cout<<"\n\nEl caracter " <<caracter<<" es una consonante\n\n";
    }
    else if(vocales.find(caracter) != string::npos){
        cout<<"\n\nEl caracter " <<caracter<<" es una vocal\n\n";
    }
    else cout<<"\n\nEl caracter " <<caracter<<" NO es una letra\n\n";

    system("pause");
    system("cls");
}


void problema_2(){
    cout<<"\n   DETERMINAR LA MINIMA COMBINACION DE BILLETES Y MONEDAS PARA UNA CANTIDAD DE DINERO DETERMINADA\n\n";

    string entrada; int ENTRADA;
    cout<<"Ingresa una cantidad(entera) de dinero: "; cin>>entrada;
    ENTRADA = verificar_entero(entrada);

    while (ENTRADA < 0) {
        cout<<"VALOR NO VALIDO"; ENTRADA = verificar_entero("VALOR NO VALIDO");
    }

    int vector[11] = {50000,20000,10000,5000,2000,1000,500,200,100,50,1};

    for (int i = 0; i < 11; ++i) {
        if(i==10) cout<<"Faltante: "<<ENTRADA/vector[i]<<endl;
        else cout<<vector[i]<<": "<<ENTRADA/vector[i]<<endl;
        ENTRADA = ENTRADA%vector[i];

    }

    system("pause");
    system("cls");
}



void problema_3(){
    cout<<"\n     EVALUAR FECHA.\n";

    string dia, mes; int DIA, MES;

    cout<<"\nIngresa el DIA: "; cin>>dia;
    DIA = verificar_entero(dia);
    DIA = mayor_a_0(DIA);
    cout<<"\nIngresa el MES: "; cin>>mes;
    MES = verificar_entero(mes);
    MES = mayor_a_0(MES);

    /* TRES CASOS TRIVIALES */
    if (MES > 12) {cout<<MES<<" es un mes invalido.\n\n"; system("pause"); system("cls"); return;}
    if (DIA > 31) {cout<<DIA<<" es un dia invalido.\n\n"; system("pause"); system("cls"); return;}
    if (MES == 2 && DIA == 29) {cout<<"29/2 es valida en bisiesto.\n\n"; system("pause"); system("cls"); return;}


    /* MESES DE 31 DIA */
    if (MES == 1 || MES == 3 || MES == 5 || MES == 7 || MES == 8 || MES == 10 || MES == 12){
        cout<<DIA<<"/"<<MES<<" es una fecha valida.\n\n";
        system("pause");system("cls"); return;
    }

    /* MESES DE MENOS DE 31 DIA */
    else{
        if (DIA == 31) cout<<DIA<<"/"<<MES<<" es una fecha invalida.\n\n";
        else if (DIA == 30 && MES == 2) cout<<DIA<<"/"<<MES<<" es una fecha invalida.\n\n";
        else cout<<DIA<<"/"<<MES<<" es una fecha valida.\n\n";
        system("pause");system("cls"); return;
    }
}



void problema_4(){
    string hora, adicion; int HORA, ADICION;
    cout<<"\nIngresa la hora en este formato: 1245 (doce y cuarenta y cinco): "; cin>>hora;
    HORA = verificar_entero(hora);

    while (HORA < 0 || HORA > 2359 || HORA%100 > 59) {
        cout<<HORA<<" ES UNA HORA INVALIDA, VUELVE A INGREASARLA: "; cin>>hora;
        HORA = verificar_entero(hora);
    }


    cout<<"\nCuanto tiempo le quieres adicionar, ej: 345 (tres horas y cuarenta y cinco minutos): "; cin>>adicion;
    ADICION = verificar_entero(adicion);
    while (ADICION < 0 || ADICION > 2359 || ADICION%100 > 59) {
        cout<<ADICION<<" ES UN TIEMPO INVALIDO, VUELVE A INTENTARLO: "; cin>>adicion;
        ADICION = verificar_entero(adicion);
    }

    if (HORA + ADICION > 2359){
        HORA = HORA+ADICION-2360;
    }

    else{
        if ((HORA+ADICION)%100 > 59){
            HORA = HORA + ADICION + 100 - 60;
        }
        else{
            HORA = HORA + ADICION;
        }
    }

    cout<<"\nLa hora resultante es: "<<HORA<<endl<<endl;
    system("pause");
    system("cls");
}


void problema_5(){
    int base;
    cout<<"\nIngresa la base del triangulo: "; cin>>base;
    int altura = (base + 1)/2;

    for (int i = 1; i <= altura; ++i) {
        for (int j = 0; j < altura - i; ++j) {
            cout<<" ";
        }
        for (int k = 0; k < 2*i-1; ++k) {
            cout<<"*";
        }
        cout<<endl;
    }


    for (int i = altura-1; i >= 1; --i) {
        for (int j = 0; j < altura - i; ++j) {
            cout<<" ";
        }
        for (int k = 0; k < 2*i-1; ++k) {
            cout<<"*";
        }
        cout<<endl;
    }

    system("pause");
    system("cls");
}


void problema_6(){
    string numero; int NUMERO;
    cout<<"\nIngrese el numero de elementos a usar en la aproximacion: "; cin>>numero;
    NUMERO = verificar_entero(numero);
    while (NUMERO <= 0) {
        cout<<"\nEL NUMERO DE ELEMENTOS DEBE SER MAYOR A 0.\n"; NUMERO = verificar_entero("INVALIDO");
    }

    float aproximacion = 0;
    for (int i = 0; i <= NUMERO-1; ++i) {
        float e = 1;
        for (int j = 1; j <= i; ++j) {
            e = j*e;
        }
        aproximacion += 1/e;
    }
    cout<<"\ne es aproximadamante: "<<aproximacion<<endl<<endl;
    system("pause");
    system("cls");
}



void problema_7(){
    int NUMERO, suma = 0; string numero;
    cout<<"\n      SERIE DE FIBONACCI\n";
    cout<<"\nIngresa un numero entero positivo: "; cin>>numero;
    NUMERO = verificar_entero(numero);
    NUMERO = mayor_a_0(NUMERO);


    if (NUMERO <= 2) suma = 0;
    else{
        int anterior = 1, reAnterior = 1, Fibonacci = 0;
        while (Fibonacci < NUMERO) {
            Fibonacci = anterior + reAnterior;
            reAnterior = anterior;
            anterior = Fibonacci;
            if(Fibonacci%2 == 0) suma += Fibonacci;
        }
    }
    cout<<"\nEl resultado de la suma es: "<<suma<<endl<<endl;
    system("pause");
    system("cls");
}



void problema_8(){
    int A,B,C,suma_multiplos_A = 0,suma_multiplos_B = 0; string a,b,c;
    cout<<"\n      SUMA DE MULTIPLOS\n";
    cout<<"\nIngresa un numero entero mayor a 0: "; cin>>a;
    A = verificar_entero(a);
    A = mayor_a_0(A);
    cout<<"\nIngresa OTRO numero entero mayor a 0: "; cin>>b;
    B = verificar_entero(b);
    B = mayor_a_0(B);
    cout<<"\nIngresa un numero entero mayor a 0: "; cin>>c;
    C = verificar_entero(c);
    C = mayor_a_0(C);

    cout<<endl;
    int i = 1;
    while (A*i < C) {
        suma_multiplos_A += A*i;
        cout<<A*i<<"+";
        i += 1;
    }

    bool signo = false;
    i = 1;
    while (B*i < C) {

        if ((B*i)%A != 0){
            suma_multiplos_B += B*i;
            if (signo == true)cout<<"+";
            cout<<B*i;
            signo = true;
        }
        i += 1;
    }
    cout<<"=";
    cout<<suma_multiplos_A+suma_multiplos_B<<endl<<endl;
    system("pause");
    system("cls");
}


void problema_9(){
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

    cout<<"\n\nEl resultado de la suma es: "<<suma<<"\n\n";
    system("pause");
    system("cls");
}



void problema_10(){
    cout<<"\n       EL N-ESIMO PRIMO\n\n";

    string n; int N;
    cout<<"Escribe un numero:"; cin>>n;
    N = verificar_entero(n);
    N = mayor_a_0(N);

    int contador = 1; // Contar numero de primos.
    int num = 1;

    while (contador <= N) {
        num++;
        bool esPrimo = true; // Asumir que num sera primo.

        if (num < 2) {
            esPrimo = false; // Si num < 2 entonces num NO ES PRIMO.
        } else {
            for (int i = 2; i*i <= num; i++) { // Tambien podríamos iterar hasta i <= num/2
                if (num % i == 0) {
                    esPrimo = false;
                    break;
                }
            }
        }

        if (esPrimo) {
            contador++;
        }
    }

    cout << "El primo numero " << N << " es: " << num << endl;
    system("pause");
    system("cls");
}


void problema_11(){
    cout<<"\n       MCM DE TODOS LOS NUMEROS ENTRE 1 Y N\n\n";

    string n; int N;
    cout<<"Escribe un numero:"; cin>>n;
    N = verificar_entero(n);
    N = mayor_a_0(N);

    int mcm = 1;

    for (int i = 2; i <= N; i++) {
        int a = mcm;
        int b = i;

        // Calcular el MCD (Máximo Común Divisor) de a y b usando el algoritmo de Euclides
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        int mcd = a;

        // Calcular el MCM usando la relación MCM(a, b) = (a * b) / MCD(a, b)
        mcm = (mcm * i) / mcd;
    }

    cout << "El minimo comun multiplo es: " << mcm << endl <<endl;
    system("pause");
    system("cls");
}


void problema_12(){
    cout<<"\n       MAXIMO FACTOR PRIMO DE N\n\n";

    string n; int N;
    cout<<"Escribe un numero:"; cin>>n;
    N = verificar_entero(n);
    N = mayor_a_0(N);

    int mita = N/2;
    int maximo = 1;
    bool esPrimo = true;

    for (int i = 2; i*i <= N; i++) { // Tambien podríamos iterar hasta i <= num/2
        if (N % i == 0) {
            esPrimo = false;
            break;
        }
    }

    if (esPrimo) maximo = N;
    else{
        for (int i = mita; i >= 1; --i){
            if (N%i == 0){
                esPrimo = true;
                for (int j = 2; j*j <= i; j++) { // Tambien podríamos iterar hasta i <= num/2
                    if (i % j == 0) {
                        esPrimo = false;
                        break;
                    }
                }
                if (esPrimo) {maximo = i; break;}
            }
        }
    }
    cout<<"\nEl mayor factor primo de "<<N<<" es: "<<maximo<<endl<<endl;
    system("pause");
    system("cls");
}


void problema_13(){} void problema_14(){} void problema_15(){}
void problema_16(){} void problema_17(){}






int verificar_entero(string numero_en_texto){ /* Esta función verifica si un string
                                            puede servir como un numero entero */

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



int mayor_a_0 (int N){
    while (N <= 0) {
        cout<<"\nNumero invalido, engresa un numero mayor a 0.\n";
        N = verificar_entero("No");
    }
    return N;
}
