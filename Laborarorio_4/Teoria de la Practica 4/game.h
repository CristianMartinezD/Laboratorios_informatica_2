#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

class game
{
    string equipo1;
    string equipo2;
    int goles1;
    int goles2;

public:
    game(string, string);
    void partido();
    string ganador();
};

#endif // GAME_H


