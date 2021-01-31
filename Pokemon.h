#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum class attribute {
    fire,
    grass,
    water
};

typedef struct {
    string name;
    int attack;
    int defense;
    int maxLife;
    int nowLife;
    int experience;
    int level;
    attribute attribute;
}pokemon;

int randnum (float, float);
void line();
void levelup (pokemon&);
void fight (pokemon&, pokemon&);

ostream& operator << (ostream&, pokemon);
void operator - (pokemon&, pokemon&);

#endif // POKEMON_H_INCLUDED
