#ifndef START_H
#define START_H
#include <unistd.h>

#include <iostream>
#include <string>

#include "loop.cpp"
#include "noBattleClass.cpp"
using namespace std;
class start : public loop {
 private:
  int check = -1;

 public:
  string message1 = "Hello. Welcome to Pokemon, get ready to battle.";
  string message2 = "Enter 1 to start a new game or enter 2 to load a game.";
  int choice = 0;
  int set_check(int CHECK) {
    check = CHECK;
    return 0;
  }
  int get_check() { return check; }
  virtual void selection() {  // added virtual
    while (choice != 1 && choice != 2) {
      looper();
      cin >> choice;
    }
    if (choice == 1) {
      system("clear");
      check = main_game();
    } else if (choice == 2) {
      system("clear");
      cout << "loading game function called" << endl;
    }
  }
  void looper() {  // rm virtual
    cout << message1;
    cout.flush();
    sleep(3);
    cout << "\r";
    cout << message2;
    cout.flush();
    sleep(5);
    cout << "\r";
    cout << "                                                                  "
            "                            ";
    cout << "\r";
  }
};
#endif