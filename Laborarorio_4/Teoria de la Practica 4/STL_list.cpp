#include <iostream>
#include <list>

/*
Lista doblemente enlazada, donde cada elemento apunta al siguiente y al anterior.
Ventajas: Inserciones y eliminaciones rápidas en cualquier parte de la lista (O(1)).
Usos: Cuando la frecuencia de inserciones y eliminaciones es alta y el acceso por índice no es necesario.
*/


using namespace std;

void print_list(list<int> l) {
    for (int x : l) cout << x << ' '; // Imprimir todos los elementos
    
    cout << endl;
}


int main() {
    list<int> l={1,2,3};
    cout << "Lista Inicial: ";
    print_list(l);
    l.push_back(4); // añadir elemento al final
    cout << "Lista Luego de agregar un 4 al final: ";
    print_list(l);
    l.push_front(0); // añadir elemento al inicio de la lista
    cout << "Lista Luego de agregar un 0 al inicio: ";
    print_list(l);

    // Obtener un valor de la lista:
    // Crear un iterador para la lista
    list<int>::iterator it = l.begin();
    
    // Avanzar el iterador para acceder al tercer elemento
    advance(it, 2); // Mueve el iterador 2 posiciones (0-based index)
    // Imprimir el valor del tercer elemento
    cout << "El tercer elemento de la lista es: " << *it << endl;
    return 0;
}