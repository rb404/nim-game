/*
INFO:

To Run:
g++ nim.cpp -o nim
./nim

Rules:
Pick any positive integer to be the total number of tiles.  
Pick either 1,2 or 3 tiles to subtract from the total tile 
count. On the Computer's turn, the program will decide how
many tiles to remove next. The player to remove the last tile
loses.

Strategy:
The second player has the winning strategy if n = 4j + 1 and
the first player has a winning strategy otherwise. Essentially,
to win against the program, your first move must employ the 
winning strategy; otherwise, the program will employ it first
and and have a guaranteed win. To put simply, on the player's 
turn, one should aim the subtacted total to be a multiple of 
4 plus 1 i.e. 5, 9, 13, 17, etc...
*/

#include <iostream>

using namespace std;

//Get Random int from min to max inclusive
int getRand(int min, int max) { return rand() % max + min; }

//Read user input
int getIn() {
  int choice;
  cout << "Enter 1,2, or 3: ";
  cin >> choice;
  while (choice < 1 || choice > 3) {
    cout << "Incorrect. Enter 1,2, or 3: ";
    cin >> choice;
  }
  return choice;
}

//Recursive game logic function
int nim(int tot) {
  if (tot <= 0) {
    cout << "You Win!\n";
    return 0;
  }

  cout << tot << " is new number of tiles.\n";
  tot -= getIn();

  if (tot <= 0) {
    cout << "You Lose!\n";
    return 0;
  }

  cout << tot << " is new number of tiles.\n";
  int a = (tot - 1) % 4;
  int b = getRand(1, 3);
  if (a == 0) {
    cout << b << " is Computer's choice.\n";
    return nim(tot -= b);
  } else {
    cout << a << " is Computer's choice.\n";
    return nim(tot -= a);
  }
}

//Driver
int main() {
  int num;
  cout << "Enter a starting tile count: ";
  cin >> num;
  nim(num);


  /*
  First version of game without recursion

  int num, choice;
  cout << "Enter a starting number: ";
  cin >> num;
  while (num > 0) {
    cout << "Enter 1,2, or 3: ";
    cin >> choice;
    while (choice < 1 || choice > 3) {
      cout << "Enter 1,2, or 3: ";
      cin >> choice;
    }
    num -= choice;
    cout << num << " is new num.\n";
    int x = (num - 1) % 4;
    if (x == 0) {
      cout << (num - 1) / 4 << " is Computer's choice.\n";
      num -= (num - 1) / 4;
    } else {
      cout << (num - 1) % 4 << " is Computer's choice.\n";
      num -= x;
    }
    cout << num << " is new num.\n";
  }
  */
}