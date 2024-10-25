#include <iostream>

#include <vector> // Para uso de vectores

using namespace std;

/*
Similar a un array dinámico, permite acceso rápido a los elementos por índice.
Permite añadir y eliminar elementos al final con eficiencia.
Ventajas: Acceso aleatorio rápido (O(1)), redimensionamiento dinámico.
Usos: Cuando se requiere un tamaño variable y acceso rápido por índice.
*/

void print_vector(vector<int> array) {
    int n = array.size(); // Longitud del vector
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << "," ;
    }
    cout << endl;
    
}

int main() {
    int num,num2;
    vector<int> v = {1,2,4};
    vector<int> v2 = {5,6,7};

    for (int i=0; i < v2.size();i++){
        v.push_back(v2[i]);
    }
    print_vector(v);
    
    try
    {
        cout << "Ingresar valor a agregar: ";
        cin >> num ;
        v.push_back(num); // Aghregando valor de num al final del vector
        print_vector(v);
        v.pop_back();
        print_vector(v);
        cout << "El tercer elemento es: " << v[2]<< endl ;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    

    return 0;
    
}
