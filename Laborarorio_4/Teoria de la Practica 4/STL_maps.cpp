#include <iostream>

#include <map>

using namespace std;


//Mapas

int main(){
  map<string,unsigned> map_mes_idx;
  map_mes_idx["enero"] = 1;
  map_mes_idx["febrero"] = 2;

  map<string,unsigned>::const_iterator
    mit (map_mes_idx.begin()),
    mend(map_mes_idx.end());

  for(;mit!=mend;++mit) cout << mit->first << '\t' << mit->second << endl;
  return 0;
}


