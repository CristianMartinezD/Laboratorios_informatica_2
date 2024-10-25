#include <iostream>
#include "game.h"
#include <vector>
#include <list>
#include <map>


#include <stdlib.h>
#include <time.h>

game::game(string e1, string e2)
{
    equipo1=e1;
    equipo2=e2;
}

void game::partido(){
    srand(time(NULL));
    goles1=rand()%21;

    goles2=rand()%21;
}

string game::ganador()
{
    string empate="empate";
    if (goles1>goles2) return equipo1;
    else if (goles1==goles2) return empate;
    else return equipo2;
}

using namespace std;


//Mapas
/*
int main(){
  map<string,unsigned> map_mes_idx;
  map_mes_idx["enero"] = 1;
  map_mes_idx["febrero"] = 1;

  map<string,unsigned>::const_iterator
    mit (map_mes_idx.begin()),
    mend(map_mes_idx.end());

  for(;mit!=mend;++mit) cout << mit->first << '\t' << mit->second << endl;
  return 0;
}
*/


/*
 * Buscar en la STL el template set, y el metodo insert
*/



//Lista de pairs
/*
int main(){

  //Creo los pair
  pair<int,string> p1 = make_pair(5,"pouet5");
  pair<int,string> p2 = make_pair(4,"pouet4");
  pair<int,string> p3 = make_pair(2,"pouet2");

  //creo la lista
  list<pair<int,string>> ma_lista;

  //agregar pair a lista
  ma_lista.push_back(p1);
  ma_lista.push_back(p2);
  ma_lista.push_back(p3);


  list<pair<int,string>>::const_iterator //iterador de la lista
    lit (ma_lista.begin()),
    lend(ma_lista.end());

  //imprimier elementos
  for(;lit!=lend;++lit) cout << lit->first << ' '<< lit->second<< ' ';
  cout << endl;
  return 0;
}

*/

//Ejemplo vectores
/*
int main(){
    vector<int> v1;

    cout<<"tamano vector: "<<v1.size()<<endl;

    for (int i=0;i<5; i++){
        v1.push_back(i);
    }

    cout<<"tamano vector: "<<v1.size()<<endl;

    cout<<"pos 3: "<<v1[3]<<endl;

    //Primera forma de iterar
    vector<int>::iterator v = v1.begin(); //Crea un iterador (puntero) al primer elemento del vector

    while( v != v1.end()) {
       cout << "value of v = " << *v << endl;
       v++;
    }

    //Segunda forma de iterar
    for (auto i = v1.begin(); i != v1.end(); ++i)
        cout << *i << " "<<endl;
}
*/


//Paritido futbol clase

int main(){

    game juego("Chapecoense", "Bayern");
    juego.partido();
    string ganador= juego.ganador();
    cout<<ganador<<endl;
    return 0;

}








