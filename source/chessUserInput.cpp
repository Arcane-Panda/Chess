#include <iostream>
using namespace std;

// Pyae Sone's Contribution

char board[8][8] = { {'p','p',' ',' ',' ',' ','p','p'}, {'p','p',' ',' ',' ',' ','p','p'},
  {'p','p',' ',' ',' ',' ','p','p'}, {'K','p',' ',' ',' ',' ','p','Q'},
  {'Q','p',' ',' ',' ',' ','p','K'}, {'p','p',' ',' ',' ',' ','p','p'},
  {'p','p',' ',' ',' ',' ','p','p'}, {'p','p',' ',' ',' ',' ','p','p'},};

string selection = "";
int selectConfirm;
int pieceConfirm;
string piece;
string selConfOne;
string selConfTwo;
int arrayX;
int arrayY;
bool confirm = false;


int main() {
  cout << "Type the location of a board piece to select it" << endl;
  cout << "i.e. A1" << endl;
  do {
    cin >> selection;
    cout << "You selected " << selection << endl;
    cout << "Confirm selection? Type 1 for yes or 0 for no" << endl;
    cin >> selectConfirm;
    if (selectConfirm == 0) {
      cout << "Type the location of a board piece to select it" << endl;
      cout << "i.e. A1" << endl;
    } else if (selectConfirm == 1) {
       selConfOne = selection.substr(0,1);
       selConfTwo = selection.substr(1,1);
       cout << "You selected " << selConfOne << selConfTwo << endl;
        if (selConfOne == "A") {
          arrayX = 0;
        } else if (selConfOne == "B") {
          arrayX = 1;
        } else if (selConfOne == "C") {
          arrayX = 2;
        } else if (selConfOne == "D") {
          arrayX = 3;
        } else if (selConfOne == "E") {
          arrayX = 4;
        } else if (selConfOne == "F") {
          arrayX = 5;
        } else if (selConfOne == "G") {
          arrayX = 6;
        } else if (selConfOne == "H") {
          arrayX = 7;
        }
        if (selConfTwo == "1") {
          arrayY = 0;
        } else if (selConfTwo == "2") {
          arrayY = 1;
        } else if (selConfTwo == "3") {
          arrayY = 2;
        } else if (selConfTwo == "4") {
          arrayY = 3;
        } else if (selConfTwo == "5") {
          arrayY = 4;
        } else if (selConfTwo == "6") {
          arrayY = 5;
        } else if (selConfTwo == "7") {
          arrayY = 6;
        } else if (selConfTwo == "8") {
          arrayY = 7;
        }
        //cout << arrayX << arrayY << endl;
    }
    cout << "You have selected" << board[arrayX][arrayY] << endl;
    cout << "Confirm selection? Type 1 for yes or 0 for no" << endl;
    piece = board[arrayX][arrayY];
    cin >> pieceConfirm;
    if (pieceConfirm == 0) {
      cout << "Type the location of a board piece to select it" << endl;
      cout << "i.e. A1" << endl;
    } else if (pieceConfirm == 1) {
      if (piece == "p") {

      } else if (piece == "K") {

      } else if (piece == "Q") {

      }
    }
  }
  while (confirm == false);
}
