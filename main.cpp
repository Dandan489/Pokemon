#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Pokemon.h"

using namespace std;

int main()
{
    start:
    srand(time(NULL));
    pokemon user = {"", 10, 10, 50, 50, 0, 1, attribute::fire};
    pokemon gym = {"Dragon", 150, 130, 300, 300, 0, 100, attribute::fire};
    string choose;
    string name;
    char movement='1';

    cout << "\n";
    cout << "Welcome to Mypokemon" << endl;
    cout << "Your goal is to defeat the gym master" << endl;
    cout << "And win the championship" << endl;
    cout << "Good luck! \n" << endl;
    cout << "First, please name your pokemon" << endl;
    nm:
    line();
    cout << "Name:" ;
    getline(cin, name);
    if (name != ""){
        user.name = name;
    }
    else{
        cout << "The name cannot be blank" << endl;
        goto nm;
    }
    line();
    cout << "Second, please give it an attribute" << endl;
    cout << "1:fire 2:grass 3:water" << endl;
    att:
    line();
    cout << "Attribute:" ;
    cin >> choose;
    if (choose == "1"){
        user.attribute = attribute::fire;
    }
    else if (choose == "2"){
        user.attribute = attribute::grass;
    }
    else if (choose == "3"){
        user.attribute = attribute::water;
    }
    else {
        cout << "Wrong number, please enter again" << endl;
        goto att;
    }
    line();
    cout << "Nice! You created your pokemon" << endl;
    cout << "The stats are shown below" << endl;
    cout << "\n" <<user << "\n";
    cout << "Now start your life as a pokemon trainer!" << endl;

    while (true){
        line();
        cout << "The actions are shown below" << endl;
        cout << "I: See the information of your pokemon" << endl;
        cout << "H: Go to the hospital and heal the life of your pokemon" << endl;
        cout << "T: Train your pokemon by wild pokemon" << endl;
        cout << "G: Go to the gym and try to get a championship" << endl;
        cout << "0: Close the game" << endl;
        cout << "Please enter your action" << endl;
        action:
        line();
        cin >> movement;
        movement = toupper(movement);
        if (movement == 'I'){
            cout << user;
            continue;
        }
        else if (movement == 'H'){
            user.nowLife = user.maxLife;
            cout << "Your pokemon have restored to full health: " << user.nowLife << endl;
            continue;
        }
        else if (movement == 'T'){
            pokemon wildf = {"wild pokemon", 8, 8, 40, 40, 0, 1};
            if (rand()%3 == 0){
                wildf.attribute = attribute::fire;
            }
             else if (rand()%3 == 1){
                wildf.attribute = attribute::grass;
            }
            else {
                wildf.attribute = attribute::water;
            }
            for (int i=0; i<(user.level-1); i++){
                levelup(wildf);
            }
            cout << wildf ;
            line();
            fight(user, wildf);
            continue;
        }
        else if (movement == 'G'){
            fight(user, gym);
            if (gym.nowLife <= 0){
                cout << endl;
                cout << "Congratulations! You win the championship!" << endl;
                cout << "WIN \n" << endl;
                cout << "Enter C to close the game" << endl;
                cout << "Or R to restart" << endl;
                engm:
                cin >> movement;
                movement = toupper(movement);
                if (movement == 'R'){
                    goto start;
                }
                else if (movement == 'C'){
                    cout << "Closing game now..." << endl;
                    break;
                }
                 else {
                    cout << "wrong command, please enter again" << endl;
                    goto engm;
                 }
            }
            continue;
        }
        else if (movement == '0'){
            cout << "Closing game now..." << endl;
            break;
        }
        // secret command
        else if (movement == 'E'){
            for (int i=0; i<100; i++){
                levelup(user);
            }
            continue;
        }
        else {
            cout << "wrong command, please enter again" << endl;
            goto action;
        }
    }
    return 0;
}
