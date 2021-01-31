#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Pokemon.h"

using namespace std;

int randnum (float Max, float Min)
{
    return (Max-Min+1)*rand()/RAND_MAX+Min;
}

void line()
{
    cout << "--------------------------------" <<endl;
}

void levelup (pokemon& p)
{
    p.maxLife += randnum(10, 12);
    p.attack += randnum(400, 600)/100;
    p.defense += randnum(400, 600)/100;
    p.level += 1;
    p.experience = p.experience -100;
    p.nowLife = p.maxLife;
}

void fight (pokemon& x, pokemon& y)
{
    while (true){
        x-y;
        if (y.nowLife <= 0){
            cout << endl;
            cout << y.name << " can't fight anymore!" << endl;
            cout << x.name << " still have " << x.nowLife << " HP" << endl;
            cout << x.name << " gain 30 exp" << endl;
            x.experience += 30;
            break;
        }
        y-x;
        if (x.nowLife <= 0){
            cout << endl;
            cout << x.name << " can't fight anymore!" << endl;
            cout << y.name << " still have " << y.nowLife << " HP" << endl;
            cout << y.name << " gain 30 exp" << endl;
            y.experience += 30;
            break;
        }
    }
    if (x.experience >= 100){
        cout << x.name << " level up!" << endl;
        levelup(x);
    }
    else if (y.experience >= 100){
        cout << y.name << " level up!" << endl;
        levelup(y);
    }
}


ostream& operator<< (ostream& os, pokemon i){
    cout << "name: " << i.name << endl;
    cout << "attack: " << i.attack << endl;
    cout << "defense: " << i.defense << endl;
    cout << "maxLife: " << i.maxLife << endl;
    cout << "nowLife: " << i.nowLife << endl;
    cout << "experience: " << i.experience << endl;
    cout << "level: " << i.level << endl;
    cout << "attribute: ";
    if (i.attribute == attribute::fire){
        cout << "fire" << endl;
    }
    else if (i.attribute == attribute::grass){
        cout << "grass" << endl;
    }
    else if (i.attribute == attribute::water){
        cout << "water" << endl;
    }
    return os;
}

void operator- (pokemon& a, pokemon& b){
    float weight;
    if (a.attribute == b.attribute){
        weight = (float)randnum(800, 1200)/1000.0;
    }
    else if ((int)a.attribute == (int)b.attribute-1){
        weight = (float)randnum(900, 1300)/1000.0;
    }
    else if ((int)a.attribute == (int)b.attribute+1){
        weight = (float)randnum(700, 1100)/1000.0;
    }
    int damage = weight*a.attack-b.defense;
    if (damage>0){
        b.nowLife = b.nowLife - damage;
        cout << a.name << " dealt " << damage << " damage!" << endl;
    }
    else{
        cout << a.name << " dealt 0 damage!" << endl;
    }
}
