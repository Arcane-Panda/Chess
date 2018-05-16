#include <dirent.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
//Lucas Zagal
class Piece
{
public:
  Piece(){};
  Piece(char typ, int x, int y, bool isWhite) ;
  char getType(void);
  void setType(char input);
  int getXpos(void);
  int getYpos(void);
  bool getWhite(void);
  void setCoords(int newX, int newY);
  bool getFirst(void);
  void setFirst(void);

private:
  int xpos, ypos;
  char type;
  bool white;
  bool firstMove;


};
Piece::Piece(char typ, int x, int y, bool isWhite)
{
  type = typ;
  xpos = x;
  ypos = y;
  white = isWhite;
  firstMove = true;
}

char Piece::getType(void)
{
  return type;
}

int Piece::getXpos(void)
{
  return xpos;
}

int Piece::getYpos(void)
{
  return ypos;
}

bool Piece::getWhite(void)
{
  return white;
}

void Piece::setCoords(int newX, int newY)
{

  xpos = newX;
  ypos = newY;
  //firstMove = false;
  cout << "\n\n\n\n\n\n\n\n";

}

bool Piece::getFirst(void)
{
  return firstMove;
  //firstMove = false;   // i think this is the problem for the castling
}

void Piece::setFirst(void)
{
  firstMove = false;
}

void Piece::setType(char input)
{
  type = input;
}


//global variables
Piece BP1('P',0,1,false);
Piece BP2('P',1,1,false);
Piece BP3('P',2,1,false);
Piece BP4('P',3,1,false);
Piece BP5('P',4,1,false);
Piece BP6('P',5,1,false);
Piece BP7('P',6,1,false);
Piece BP8('P',7,1,false);

Piece BQ('Q',3,0,false);

Piece BK('K',4,0,false);

Piece BB1('B',2,0,false);
Piece BB2('B',5,0,false);

Piece BR1('R',0,0,false);
Piece BR2('R',7,0,false);

Piece BH1('H',1,0,false);
Piece BH2('H',6,0,false);


Piece WP1('P',0,6,true);
Piece WP2('P',1,6,true);
Piece WP3('P',2,6,true);
Piece WP4('P',3,6,true);
Piece WP5('P',4,6,true);
Piece WP6('P',5,6,true);
Piece WP7('P',6,6,true);
Piece WP8('P',7,6,true);

Piece WQ('Q',3,7,true);

Piece WK('K',4,7,true);

Piece WB1('B',2,7,true);
Piece WB2('B',5,7,true);

Piece WR1('R',0,7,true);
Piece WR2('R',7,7,true);

Piece WH1('H',1,7,true);
Piece WH2('H',6,7,true);



vector<int> possibleMovesX;
vector<int> possibleMovesY;
vector<string> fileNames;
int oldX;
int oldY;
bool playing = true;
Piece pieces[32] = {BP1, BP2, BP3, BP4, BP5, BP6 ,BP7, BP8, BQ, BK, BB1, BB2, BR1, BR2, BH1, BH2, WP1, WP2, WP3, WP4, WP5, WP6, WP7, WP8, WQ, WK, WB1, WB2, WR2, WR1, WH1, WH2};
//                   0    1   2      3   4   5     6     7   8   9   10   11   12   13   14   15   16   17   18   19   20   21   22  23  24   25   26   27   28   29   30   31


bool piece = true;
bool piece1 = true;

string selection = "";
char selectConfirm;
int pieceConfirm;

string selConfOne;
string selConfTwo;
int oldArrayX;
int oldArrayY;
int newArrayX;
int newArrayY;
int arrayLength = sizeof(pieces)/sizeof(*pieces);
string mode = "Rando";
int randomInt;
bool validMove = false;
int possibleMove;
bool whiteTurn = true;

string menuSelect;
string incorect;
bool incorectSelect = false;
bool startMenu = true;
bool instructionsMenu = false;
bool howToPlay = false;
bool modeMenu = false;
bool commandsMenu = false;
bool beginnersMenu = false;
bool savingAndLoadingMenu = false;
bool startSelections = false;
bool loadGames = false;
bool inputting = false;
bool whiteCastle = false;
bool blackCastle = false;
int castleRook;
bool open;

string file_path = __FILE__;
string dir_path = file_path.substr(0, file_path.rfind("\\"));
string location = dir_path.substr(0, dir_path.size()-13);


// functions

void save(string file){
  ofstream outfile( location + "saves/"+file);
  for(int c = 0; c < arrayLength; c++){
    outfile << pieces[c].getXpos() << pieces[c].getYpos();
  }
  outfile << whiteTurn;
  outfile.close();
}

void load(string file)
{
  cout<< file<< endl;
  ifstream infile;
  infile.open(location + "saves/"+file);
  //infile.open(file);
  if (infile.is_open())
  {
    string saveFile;
    infile >> saveFile ;
    //infile.close();
    cout << saveFile << endl;
    cout << saveFile.at(0) << saveFile.at(1) << "\n\n";
    pieces[0].setCoords((int)saveFile.at(0) - '0',(int)saveFile.at(1) - '0');
    cout << pieces[0].getXpos() << pieces[0].getYpos() << endl;
    cout << saveFile.at(0) << saveFile.at(1) << "\n\n";
    pieces[1].setCoords((int)saveFile.at(2)- '0',(int)saveFile.at(3) - '0');
    pieces[2].setCoords((int)saveFile.at(4) - '0',(int)saveFile.at(5) - '0');
    pieces[3].setCoords((int)saveFile.at(6) - '0',(int)saveFile.at(7) - '0');
    pieces[4].setCoords((int)saveFile.at(8) - '0',(int)saveFile.at(9) - '0');
    pieces[5].setCoords((int)saveFile.at(10) - '0',(int)saveFile.at(11) - '0');
    pieces[6].setCoords((int)saveFile.at(12) - '0',(int)saveFile.at(13) - '0');
    pieces[7].setCoords((int)saveFile.at(14)- '0',(int)saveFile.at(15) - '0');

    pieces[8].setCoords((int)saveFile.at(16) - '0',(int)saveFile.at(17) - '0');

    pieces[9].setCoords((int)saveFile.at(18) - '0',(int)saveFile.at(19) - '0');

    pieces[10].setCoords((int)saveFile.at(20) - '0',(int)saveFile.at(21) - '0');
    pieces[11].setCoords((int)saveFile.at(22) - '0',(int)saveFile.at(23) - '0');

    pieces[12].setCoords((int)saveFile.at(24) - '0',(int)saveFile.at(25) - '0');
    pieces[13].setCoords((int)saveFile.at(26) - '0',(int)saveFile.at(27) - '0');

    pieces[14].setCoords((int)saveFile.at(28) - '0',(int)saveFile.at(29) - '0');
    pieces[15].setCoords((int)saveFile.at(30) - '0',(int)saveFile.at(31) - '0');

    pieces[16].setCoords((int)saveFile.at(32) - '0',(int)saveFile.at(33) - '0');
    pieces[17].setCoords((int)saveFile.at(34) - '0',(int)saveFile.at(35) - '0');
    pieces[18].setCoords((int)saveFile.at(36) - '0',(int)saveFile.at(37) - '0');
    pieces[19].setCoords((int)saveFile.at(38) - '0',(int)saveFile.at(39) - '0');
    pieces[20].setCoords((int)saveFile.at(40) - '0',(int)saveFile.at(41) - '0');
    pieces[21].setCoords((int)saveFile.at(42) - '0',(int)saveFile.at(43) - '0');
    pieces[22].setCoords((int)saveFile.at(44) - '0',(int)saveFile.at(45) - '0');
    pieces[23].setCoords((int)saveFile.at(46) - '0',(int)saveFile.at(47) - '0');

    pieces[24].setCoords((int)saveFile.at(48) - '0',(int)saveFile.at(49) - '0');

    pieces[25].setCoords((int)saveFile.at(50) - '0',(int)saveFile.at(51) - '0');

    pieces[26].setCoords((int)saveFile.at(52) - '0',(int)saveFile.at(53) - '0');
    pieces[27].setCoords((int)saveFile.at(54) - '0',(int)saveFile.at(55) - '0');

    pieces[28].setCoords((int)saveFile.at(56) - '0',(int)saveFile.at(57) - '0');
    pieces[29].setCoords((int)saveFile.at(58) - '0',(int)saveFile.at(59) - '0');

    pieces[30].setCoords((int)saveFile.at(60) - '0',(int)saveFile.at(61) - '0');
    pieces[31].setCoords((int)saveFile.at(62) - '0',(int)saveFile.at(63) - '0');
    for (int i = 0; i < arrayLength; i++)
    {
      cout << pieces[i].getXpos() << pieces[i].getYpos() << endl;
    }
    if((int)saveFile.at(64) == '1')
    {
      whiteTurn = true;
    } else
    {
      whiteTurn = false;
    }
  } else
  {
    cout << "Error Loading File" << endl;
  }
  infile.close();
}

void loadGame()
{
  bool loaded = false;
  while(loadGames){
    loaded = false;
    cout << "\e[8;22;50t";
    system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }

    cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Welcome to Chess!                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"              Please select an option             "<< endl;
    cout<<"              -----------------------             "<< endl;
    DIR *dir;
    struct dirent *ent;

    string str = location + "saves/";
    const char * path = str.c_str();
    dir = opendir( path);
    if((dir) != NULL)
    {
      fileNames.clear();
      while((ent = readdir(dir)) != NULL)
      {
        printf ("%s\n", ent->d_name);
        fileNames.push_back(ent->d_name);
      }
      closedir(dir);
    } else
    {
      perror("");
    }
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Exit                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<incorect<< endl;
    incorectSelect = false;
    cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;
    //  load(menuSelect);
    char fileName[255];
    loaded = false;
    for(int i = 0; i < fileNames.size(); i++){
      if(fileNames[i] == menuSelect){
        loaded = true;
        load(menuSelect);
      }
    }
    if (loaded == false)
    {
      if(menuSelect == "Exit"|| menuSelect == "exit"){
        loadGames = false;
      }else{
        incorectSelect = true;
      }


    }
    else if(menuSelect != "Exit" && menuSelect != "exit"){

    }
  }
}

void gameStart(){

  while(startSelections){
    cout << "\e[8;22;50t";
    system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }

    cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Welcome to Chess!                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"              Please select an option             "<< endl;
    cout<<"              -----------------------             "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       New                        "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Load                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Exit                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<incorect<< endl;
    incorectSelect = false;
    cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;


    if( menuSelect == "new" || menuSelect == "New" ) {
      startSelections = false;
      startMenu = false;
    }else if(menuSelect == "load"|| menuSelect == "Load" ){
      loadGames = true;
      loadGame();

    } else if(menuSelect == "Exit"|| menuSelect == "exit"){
      startSelections = false;
    } else {
      incorectSelect = true;
    }
  }
}
void beginners(){
  int pageNum = 1;
  while(beginnersMenu){
    cout << "\e[8;22;50t";
    system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }
    if (pageNum == 1)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                   Introduction                   "<< endl;
      cout<<"    Chess is a strategy game played on a board    "<< endl;
      cout<<"      with 2 players, one white, one black.       "<< endl;
      cout<<"    You play by moving the pieces of your color   "<< endl;
      cout<<" around the board according to each piece's rules "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"   Pieces can't move through other pieces, nor    "<< endl;
      cout<<"           onto pieces of the same color          "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                      1 of 11                      "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 2)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"     However, you can move pieces onto pieces     "<< endl;
      cout<<"           of the opposite color, and             "<< endl;
      cout<<"            replace or 'capture' them             "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"       You win by placing your opponents king     "<< endl;
      cout<<"          in checkmate (explained on page 4)      "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                      2 of 11                      "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 3)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                How the Pieces Move               "<< endl;
      cout<<"                    The King (K)                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"        Can move one square in any direction      "<< endl;
      cout<<"        (Up, Down, Left, Right, Diagonals)        "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"      If the king can be captured by another      "<< endl;
      cout<<"               piece, he's in check               "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                      3 of 11                      "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 4)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"        The king cannot be moved into check       "<< endl;
      cout<<"      and if he's in check, he must be moved out  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"     If the king can't move out of check he is    "<< endl;
      cout<<"        in checkmate, and the game is over        "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"     Make sure to protect him, as he is your      "<< endl;
      cout<<"                most important piece              "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                      4 of 11                      "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 5)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                   The Queen (Q)                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"      The Queen is the most powerful piece.       "<< endl;
      cout<<"      She can move in a straight line as far      "<< endl;
      cout<<"           as possible in one direction           "<< endl;
      cout<<"    (forward, backwards, sideways, or diagonal)   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                      5 of 11                      "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 6)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                   The Rook (R)                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"     The rook can also move as far as he wants,   "<< endl;
      cout<<"    but only forwards, backwards, and sideways    "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"   They are quite powerful when working together  "<< endl;
      cout<<"           and protecting each other.             "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                      6 of 11                      "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 7)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                   The Bishop (B)                 "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"     The bishop can move any number of spaces,    "<< endl;
      cout<<"                   only diagonaly                 "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"      Each bishop starts on a black or white      "<< endl;
      cout<<"        square and must stick to that color       "<< endl;
      cout<<"     so bishops work well together because they   "<< endl;
      cout<<"            cover each others weaknesses          "<< endl;
      cout<<"                      7 of 11                      "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 8)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"               The Horse/Knight (H)               "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"         The horse moves unlike any other         "<< endl;
      cout<<"   piece in the game. It moves two spaces in a    "<< endl;
      cout<<" non diagonal direction, and then one more space  "<< endl;
      cout<<"      at a 90 degree angle to form an L shape     "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"      They are also the only pieces that can      "<< endl;
      cout<<"          move through other pieces               "<< endl;
      cout<<"                      8 of 11                      "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 9)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                   The Pawn (P)                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"     Pawns are unusual, because they move and     "<< endl;
      cout<<"  capture in different ways. Pawns can only move  "<< endl;
      cout<<"    one square forward at a time, except for      "<< endl;
      cout<<"   their very first move, where they can move     "<< endl;
      cout<<"   forward two squares. Pawns can only capture    "<< endl;
      cout<<"    pieces that are diagonally in front of them   "<< endl;
      cout<<"     They can never move or capture backwards.    "<< endl;
      cout<<"                     9 of 11                      "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 10)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Special Rules                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Pawn Promotion                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"   When a pawn reaches the opposite side of the   "<< endl;
      cout<<"       board, it can become any other piece.      "<< endl;
      cout<<"      A pawn is usually promoted to a queen.      "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                     10 of 11                     "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 10)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                    En Passant                    "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"  If a pawn moves two squares on its first move,  "<< endl;
      cout<<"     and by doing so lands to the side of an      "<< endl;
      cout<<"  opponent's pawn, the other pawn has the option  "<< endl;
      cout<<"    of capturing the first pawn as it passes by.  "<< endl;
      cout<<"   This must be done immediatly after the first   "<< endl;
      cout<<"       pawns moves, or the option is lost.        "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                     10 of 11                     "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<"                                                  "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    } else if (pageNum == 11)
    {
      cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                 Welcome to Chess!                "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                  Beginners Guide                 "<< endl;
      cout<<"                   ------------                   "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"                     Castling                     "<< endl;
      cout<<"                                                  "<< endl;
      cout<<"   Castling your king lets you do two important   "<< endl;
      cout<<"   things. get your king to safety, and get your  "<< endl;
      cout<<"     rook out of the corner and into the game.    "<< endl;
      cout<<"    To castle, move your king two spaces over to  "<< endl;
      cout<<"   one side, then move that side's rook to right  "<< endl;
      cout<<"  next to the king on the opposite side. It must  "<< endl;
      cout<<"   be both pieces first moves, and there can't    "<< endl;
      cout<<"         be any pieces in between them.           "<< endl;
      cout<<"                     11 of 11                     "<< endl;
      cout<<"                       Exit                       "<< endl;
      cout<<incorect<< endl;
      incorectSelect = false;
      cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    }

    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;


    if(menuSelect == "Exit"|| menuSelect == "exit"){
      beginnersMenu = false;
    } else if(menuSelect == "1")
    {
      pageNum = 1;
    }else if(menuSelect == "2")
    {
      pageNum = 2;
    } else if(menuSelect == "3")
    {
      pageNum = 3;
    } else if(menuSelect == "4")
    {
      pageNum = 4;
    } else if(menuSelect == "5")
    {
      pageNum = 5;
    } else if(menuSelect == "6")
    {
      pageNum = 6;
    } else if(menuSelect == "7")
    {
      pageNum = 7;
    } else if(menuSelect == "8")
    {
      pageNum = 8;
    } else if(menuSelect == "9")
    {
      pageNum = 9;
    } else if(menuSelect == "10")
    {
      pageNum = 10;
    } else if(menuSelect == "11")
    {
      pageNum = 11;
    }  else {
      incorectSelect = true;
    }
  }
}

void howToPlayFunc(){

  while(howToPlay){
    cout << "\e[8;22;50t";
    system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }

    cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Welcome to Chess!                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                    How To Play                   "<< endl;
    cout<<"                   ------------                   "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"             Select a piece by typing             "<< endl;
    cout<<"                  its coordinates                 "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"        Move it by typing the coordinates         "<< endl;
    cout<<"        of the space you'd like to move to        "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"           If you've never played chess:          "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                  Beginners Guide                 "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Exit                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<incorect<< endl;
    incorectSelect = false;
    cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;
    //https://www.chess.com/learn-how-to-play-chess

    if(menuSelect == "Exit"|| menuSelect == "exit"){
      howToPlay = false;
    }else if(menuSelect == "Beginners"|| menuSelect == "beginners")
    {
      beginnersMenu = true;
      beginners();
    } else {
      incorectSelect = true;
    }
  }
}
void commands(){

  while(commandsMenu){
    cout << "\e[8;22;50t";
    system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }

    cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Welcome to Chess!                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                     Commands                     "<< endl;
    cout<<"                   ------------                   "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"               Type these instead of              "<< endl;
    cout<<"                selecting a piece                 "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"            save - saves your game so it          "<< endl;
    cout<<"               can be loaded later                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"               exit - exits the game              "<< endl;
    cout<<"                   without saving                 "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Exit                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<incorect<< endl;
    incorectSelect = false;
    cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;


    if(menuSelect == "Exit"|| menuSelect == "exit"){
      commandsMenu = false;
    } else {
      incorectSelect = true;
    }
  }
}
void savingAndLoading(){

  while(savingAndLoadingMenu){
    cout << "\e[8;22;50t";
    system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }

    cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Welcome to Chess!                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Saving & Loading                 "<< endl;
    cout<<"                   ------------                   "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"            Games are saved in a folder           "<< endl;
    cout<<"          called \"saves\" and are loaded         "<< endl;
    cout<<"                 from the same one                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"          Make sure the save folder is in         "<< endl;
    cout<<"         the same place as the application        "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Exit                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<incorect<< endl;
    incorectSelect = false;
    cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;


    if(menuSelect == "Exit"|| menuSelect == "exit"){
      savingAndLoadingMenu = false;
    } else {
      incorectSelect = true;
    }
  }
}
void instructions(){

  while(instructionsMenu){
    cout << "\e[8;22;50t";
    system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }

    cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Welcome to Chess!                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                   Instructions                   "<< endl;
    cout<<"                   ------------                   "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                    How To Play                   "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                     Commands                     "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Saving & Loading                 "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Exit                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<incorect<< endl;
    incorectSelect = false;
    cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;


    if(menuSelect == "Exit"|| menuSelect == "exit"){
      instructionsMenu = false;
    }else if(menuSelect == "how"|| menuSelect == "How")
    {
      howToPlay = true;
      howToPlayFunc();
    } else if(menuSelect == "commands"|| menuSelect == "Commands")
    {
      commandsMenu = true;
      commands();
    }else if(menuSelect == "saving"|| menuSelect == "Saving")
    {
      savingAndLoadingMenu = true;
      savingAndLoading();
    } else {
      incorectSelect = true;
    }
  }
}
void modes(){

  while(modeMenu){
    cout << "\e[8;22;50t";
    system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }

    cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Welcome to Chess!                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                Please select a mode              "<< endl;
    cout<<"                --------------------              "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                      Random                      "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Exit                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<incorect<< endl;
    incorectSelect = false;
    cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;


    if(menuSelect == "Exit"|| menuSelect == "exit"){
      modeMenu = false;
    } else if(menuSelect == "Random" || menuSelect == "random") {
      mode = "Random";
    } else {
      incorectSelect = true;
    }
  }
}
void startPage(){

  while(startMenu){
    cout << "\e[8;22;50t";
    system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }

    cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Welcome to Chess!                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"              Please select an option             "<< endl;
    cout<<"              -----------------------             "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Start                      "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                   Instructions                   "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Modes                      "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                       Exit                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<incorect<< endl;
    incorectSelect = false;
    cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;


    if(menuSelect == "Start"|| menuSelect == "start"){
      startSelections = true;
      gameStart();
    }else if(menuSelect == "Instructions"|| menuSelect == "instructions"){
      instructionsMenu = true;

      instructions();
    } else if(menuSelect == "Modes"|| menuSelect == "modes"){
      modeMenu = true;
      modes();
    } else if(menuSelect == "Exit"|| menuSelect == "exit"){
      startMenu = false;
      playing = false;
      break;
    } else {
      incorectSelect = true;
    }
  }
}


void display(){
  cout << "\n\n\n\n\n\n\n\n\n";
  cout  << endl << endl<< "            A  B  C  D  E  F  G  H " << endl;
  for(int j=0;j < 8; j+=2){ // rows

    cout<< "         " << 8-j << " ";
    for( int l =0; l < 8;l+=2 ){ //Columns

      for(int i = 0; i < arrayLength; i++){ // pieces

        if(pieces[i].getYpos() == j && pieces[i].getXpos() ==l && piece == true){
          if(pieces[i].getWhite()){
            printf("\x1b[31;46m %c \x1b[0m" ,pieces[i].getType());//black
          }else{
            printf("\x1b[30;46m %c \x1b[0m" ,pieces[i].getType());//black
          }

          piece = false;

        }
      }
      if(piece){

        printf("\x1b[37;46m   \x1b[0m" );// black

      }
      for(int i = 0; i < arrayLength; i++){
        if(pieces[i].getYpos() == j && pieces[i].getXpos() ==l+1 && piece1 == true){
          if(pieces[i].getWhite()){
            printf("\x1b[31;47m %c \x1b[0m" , pieces[i].getType());//green
          }else{
            printf("\x1b[30;47m %c \x1b[0m" , pieces[i].getType());//green
          }
          piece1 = false;
        }
      }

      if(piece1){
        printf("\x1b[37;47m   \x1b[0m" );//green
      }
      piece = true;
      piece1 = true;
    }
    cout<< " " << 8-j << " ";
    printf("\n");

    cout<< "         " << 7-j << " ";
    for( int l = 0; l < 8;l+=2 ){ // Columns

      for(int i = 0; i < arrayLength; i++){ // pieces

        if(pieces[i].getYpos() == j+1 && pieces[i].getXpos() == l && piece == true){
          if(pieces[i].getWhite()){
            printf("\x1b[31;47m %c \x1b[0m" , pieces[i].getType());//green
          }else{
            printf("\x1b[30;47m %c \x1b[0m" , pieces[i].getType());//green
          }
          piece = false;

        }
      }

      if(piece){
        printf("\x1b[37;47m   \x1b[0m" );//green


      }

      for(int i = 0; i < arrayLength; i++){
        if(pieces[i].getYpos() == j+1 && pieces[i].getXpos() == l+1 && piece1 == true){
          if(pieces[i].getWhite()){
            printf("\x1b[31;46m %c \x1b[0m" , pieces[i].getType());//black
          }else{
            printf("\x1b[30;46m %c \x1b[0m" , pieces[i].getType());//black
          }
          piece1 = false;
        }
      }

      if(piece1){


        printf("\x1b[37;46m   \x1b[0m" );// black
      }
      piece = true;
      piece1 = true;
    }
    cout<< " " << 7-j << " ";
    printf("\n");
  }
  cout<< "            A  B  C  D  E  F  G  H " << endl << endl;

}

void userInput(){
  inputting = true;
  while(inputting){
    cout << "Type the location of a piece to select it, or a   command  ";
    cout << "i.e. A1, or exit" << endl;
    // make sure that selected space isn't empty
    cin >> selection;
    if (selection == "exit" || selection == "Exit" )
    {
      cout << "Are you sure you want to exit?" << endl;
      cout << "All unsaved progress will be lost" << endl;
      cout << "Are you sure? y/n" << endl;
      cin >> selectConfirm;
      if (selectConfirm == 'n') {


      } else if (selectConfirm == 'y') {
        inputting = false;
        startMenu = true;
        startPage();
        break;
      }
    }else if(selection == "save" || selection == "Save" )
    {
      string fileName;
      cout << "Name your file: ";
      cin >> fileName;
      fileName = fileName + ".txt";
      save(fileName);
    }
    else {

      cout << "You selected " << selection << endl;
      cout << "Confirm selection? y/n" << endl;
      cin >> selectConfirm;
      if (selectConfirm == 'n') {


      } else if (selectConfirm == 'y') {
        inputting = false;
        selConfOne = selection.substr(0,1);
        selConfTwo = selection.substr(1,1);
        if (selConfOne == "A" || selConfOne == "a") {
          oldArrayX = 0;
        } else if (selConfOne == "B" || selConfOne == "b") {
          oldArrayX = 1;
        } else if (selConfOne == "C" || selConfOne == "c") {
          oldArrayX = 2;
        } else if (selConfOne == "D" || selConfOne == "d") {
          oldArrayX = 3;
        } else if (selConfOne == "E" || selConfOne == "e") {
          oldArrayX = 4;
        } else if (selConfOne == "F" || selConfOne == "f") {
          oldArrayX = 5;
        } else if (selConfOne == "G" || selConfOne == "g") {
          oldArrayX = 6;
        } else if (selConfOne == "H" || selConfOne == "h") {
          oldArrayX = 7;
        } else
        {
          system("clear");
          cout << "\033[1;31mInvalid input. Try again!\033[0m\n" << endl;
          display();

        }
        if (selConfTwo == "1") {
          oldArrayY = 7;
        } else if (selConfTwo == "2") {
          oldArrayY = 6;
        } else if (selConfTwo == "3") {
          oldArrayY = 5;
        } else if (selConfTwo == "4") {
          oldArrayY = 4;
        } else if (selConfTwo == "5") {
          oldArrayY = 3;
        } else if (selConfTwo == "6") {
          oldArrayY = 2;
        } else if (selConfTwo == "7") {
          oldArrayY = 1;
        } else if (selConfTwo == "8") {
          oldArrayY = 0;
        } else
        {
          system("clear");
          cout << "\033[1;31mInvalid input. Try again!\033[0m\n" << endl;
          display();
        }

      } else
      {
        system("clear");
        cout << "\033[1;31mInvalid input. Try again!\033[0m\n" << endl;
        display();
      }
    }

  }
  inputting = true;
  for (int i = 0; i < arrayLength; i++)
  {
    if (pieces[i].getYpos() == oldArrayY && pieces[i].getXpos() == oldArrayX)
    {
      while(inputting){
        cout << "Select the space to where you wish to move your   selection" << endl;
        cin >> selection;
        cout << "You selected " << selection << endl;
        cout << "Confirm selection? y/n" << endl;
        cin >> selectConfirm;
        if (selectConfirm == 'n') {
        } else if (selectConfirm == 'y'){
          inputting = false;
          selConfOne = selection.substr(0,1);
          selConfTwo = selection.substr(1,1);
          //  cout << "You wanna move it to " << selConfOne << selConfTwo << endl;
          if (selConfOne == "A" || selConfOne == "a") {
            newArrayX = 0;
          } else if (selConfOne == "B" || selConfOne == "b") {
            newArrayX = 1;
          } else if (selConfOne == "C" || selConfOne == "c") {
            newArrayX = 2;
          } else if (selConfOne == "D" || selConfOne == "d") {
            newArrayX = 3;
          } else if (selConfOne == "E" || selConfOne == "e") {
            newArrayX = 4;
          } else if (selConfOne == "F" || selConfOne == "f") {
            newArrayX = 5;
          } else if (selConfOne == "G" || selConfOne == "g") {
            newArrayX = 6;
          } else if (selConfOne == "H" || selConfOne == "h") {
            newArrayX = 7;
          } else
          {
            system("clear");
            cout << "\033[1;31mInvalid input. Try again!\033[0m\n" << endl;
            display();
          }
          if (selConfTwo == "1") {
            newArrayY = 7;
          } else if (selConfTwo == "2") {
            newArrayY = 6;
          } else if (selConfTwo == "3") {
            newArrayY = 5;
          } else if (selConfTwo == "4") {
            newArrayY = 4;
          } else if (selConfTwo == "5") {
            newArrayY = 3;
          } else if (selConfTwo == "6") {
            newArrayY = 2;
          } else if (selConfTwo == "7") {
            newArrayY = 1;
          } else if (selConfTwo == "8") {
            newArrayY = 0;
          } else
          {
            system("clear");
            cout << "\033[1;31mInvalid input. Try again!\033[0m\n" << endl;
            display();
          }
        } else
        {
          system("clear");
          cout << "\033[1;31mInvalid input. Try again!\033[0m\n" << endl;
          display();
        }
      }
    }
  }

}



bool Pawn(int i, int newX, int newY, bool moving, bool checkM){

  validMove = false;

  if(pieces[i].getWhite() == true){

    if(newY - pieces[i].getYpos() == -2 && pieces[i].getFirst() == true && newX == pieces[i].getXpos()){
      //double move white
      validMove = true;
      for(int j = 0; j < arrayLength; j++){
        if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
          validMove = false;
        }
        if(pieces[j].getYpos() == newY + 1 && pieces[j].getXpos() == newX){
          validMove = false;
        }
      }

    }else if(newY - pieces[i].getYpos() == -1 && newX == pieces[i].getXpos()){
      //single move white
      validMove = true;
      for(int j = 0; j < arrayLength; j++){
        if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
          validMove = false;
        }
      }
    }else if(newY - pieces[i].getYpos() == -1 && (newX == pieces[i].getXpos() + 1 || newX == pieces[i].getXpos() -1 )){
      // attacking white
      validMove = false;
      for(int j = 0; j < arrayLength; j++){

        if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
          if(pieces[i].getWhite() == pieces[j].getWhite()){
            validMove = false;
          }else{
            validMove = true;
            if(moving && checkM == false){
              pieces[j].setCoords(9,9);
            }
          }
        }
      }
    }else{
      validMove = false;
    }
  }else{ // black
    if(newY - pieces[i].getYpos() == 2 && pieces[i].getFirst() == true && newX == pieces[i].getXpos())
    {
      // double move black
      validMove = true;
      for(int j = 0; j < arrayLength; j++){
        if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
          validMove = false;
        }
        if(pieces[j].getYpos() == newY - 1 && pieces[j].getXpos() == newX){
          validMove = false;
        }
      }
    } else if(newY - pieces[i].getYpos() == 1 && newX == pieces[i].getXpos()){
      //single move black
      validMove = true;
      for(int j = 0; j < arrayLength; j++){
        if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
          validMove = false;
        }
      }
    }else if(newY - pieces[i].getYpos() == 1 && (newX == pieces[i].getXpos() + 1 || newX == pieces[i].getXpos() - 1  )){
      // attack black
      validMove = false;
      for(int j = 0; j < arrayLength; j++){

        if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
          if(pieces[j].getWhite() == pieces[i].getWhite()){
            validMove = false;
          }else{
            validMove = true;
            if(moving && checkM == false){
              pieces[j].setCoords(9,9);
            }
          }
        }
      }

    }else{
      validMove = false;
    }
  }
  if(validMove){
    if(moving){
      pieces[i].setCoords(newX,newY);
      pieces[i].setFirst();
    }
    return true;

  }else{
    if(moving){
      cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
    }
    return false;
  }
}

bool King(int i, int newX, int newY, bool moving, bool checkM){

  validMove = false;
  blackCastle = false;
  whiteCastle = false;
  castleRook = 0;

  if(newY- pieces[i].getYpos() == -1 && newX == pieces[i].getXpos())
  {
    //move up
    validMove = true;
  } else if(newY- pieces[i].getYpos() == -1 && newX - pieces[i].getXpos() == 1)
  {
    //move right up
    validMove = true;
  } else if(newY- pieces[i].getYpos() == -1 && newX - pieces[i].getXpos() == -1)
  {
    //move left up
    validMove = true;
  } else if(newY == pieces[i].getYpos()  && newX - pieces[i].getXpos() == -1)
  {
    //move left
    validMove = true;
  }else if(newY == pieces[i].getYpos()  && newX - pieces[i].getXpos() == 1)
  {
    //move right
    validMove = true;
  } else if(newY - pieces[i].getYpos() == 1 && newX - pieces[i].getXpos() == -1)
  {
    //move down left
    validMove = true;
  } else if(newY - pieces[i].getYpos() == 1 && newX - pieces[i].getXpos() == 1)
  {
    //move down right
    validMove = true;
  } else if(newY - pieces[i].getYpos() == 1 && newX == pieces[i].getXpos())
  {
    //move down
    validMove = true;
  }else if(pieces[i].getWhite() == true && pieces[i].getFirst() == true && newY - pieces[i].getYpos() == 0 && newX - pieces[i].getXpos() == 2){
    if (pieces[28].getFirst())
    {

      open = true;

      for(int j = 0; j < arrayLength; j++){
        if(pieces[j].getYpos() == 7 && pieces[j].getXpos() == 5 ){
          open = false;
        }else if(pieces[j].getYpos() == 7 && pieces[j].getXpos() == 6 ){
          open = false;
        }
      }
      if(open){
        validMove = true;
        whiteCastle = true;
        castleRook = 2;
      }

    }
  }else if(pieces[i].getWhite() == true && pieces[i].getFirst() == true && newY - pieces[i].getYpos() == 0 && newX - pieces[i].getXpos() == -2){
    if (pieces[29].getFirst())
    {
      open = true;
      for(int j = 0; j < arrayLength; j++){
        if(pieces[j].getYpos() == 7 && pieces[j].getXpos() == 1 ){
          open = false;
        }else if(pieces[j].getYpos() == 7 && pieces[j].getXpos() == 2 ){
          open = false;
        }else if(pieces[j].getYpos() == 7 && pieces[j].getXpos() == 3 ){
          open = false;
        }
      }
      if(open){
        validMove = true;
        whiteCastle = true;
        castleRook = 1;
      }

    }
  }else if(pieces[i].getWhite() == false && pieces[i].getFirst() == true && newY - pieces[i].getYpos() == 0 && newX - pieces[i].getXpos() == 2){
    if (pieces[13].getFirst())
    {
      open = true;
      for(int j = 0; j < arrayLength; j++){
        if(pieces[j].getYpos() == 0 && pieces[j].getXpos() == 5 ){
          open = false;
        }else if(pieces[j].getYpos() == 0 && pieces[j].getXpos() == 6 ){
          open = false;
        }
      }
      if(open){
        validMove = true;
        blackCastle = true;
        castleRook = 2;
      }

    }
  } else if(pieces[i].getWhite() == false && pieces[i].getFirst() == true && newY - pieces[i].getYpos() == 0 && newX - pieces[i].getXpos() == -2){
    if (pieces[12].getFirst())
    {
      open = true;
      for(int j = 0; j < arrayLength; j++){
        if(pieces[j].getYpos() == 0 && pieces[j].getXpos() == 1 ){
          open = false;
        }else if(pieces[j].getYpos() == 0 && pieces[j].getXpos() == 2 ){
          open = false;
        }else if(pieces[j].getYpos() == 0 && pieces[j].getXpos() == 3 ){
          open = false;
        }
      }
      if(open){
        validMove = true;
        blackCastle = true;
        castleRook = 1;
      }

    }
  } else{
    validMove = false;
  }
  if(validMove){
    for(int j = 0; j < arrayLength; j++){
      if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
        if(pieces[j].getWhite() == pieces[i].getWhite()){
          if(moving){
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
          }
          return false;
        }
        else{
          if(moving && checkM == false){
            pieces[j].setCoords(9,9);
          }
        }
      }
    }
    if(validMove){
      if(moving){
        pieces[i].setCoords(newX,newY);
        pieces[i].setFirst();
        if (whiteCastle)
        {
          if(castleRook == 1){
            pieces[29].setCoords(3,7);
            pieces[29].setFirst();
          }else if(castleRook == 2){
            pieces[28].setCoords(5,7);
            pieces[28].setFirst();
          }

        } else if(blackCastle)
        {
          if(castleRook == 1){
            pieces[12].setCoords(3,0);
            pieces[12].setFirst();
          }else if(castleRook == 2){
            pieces[13].setCoords(5,0);
            pieces[13].setFirst();
          }

        }
      }
      return true;
    }
  }else{
    if(moving){
      cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
    }
    return false;
  }
}

bool Queen(int i, int newX, int newY, bool moving, bool checkM){
  validMove = false;

  if (newX - pieces[i].getXpos() == newY - pieces[i].getYpos()) {

    validMove = true;
    if((newX - pieces[i].getXpos()) > 0){
      for(int l = 1; l < newX  -  pieces[i].getXpos(); l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == l + pieces[i].getYpos() && pieces[j].getXpos() == l + pieces[i].getXpos()){
            validMove = false;
          }
        }
      }
    }else{
      for(int l = 1; l <  pieces[i].getXpos() - newX; l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == l + newY && pieces[j].getXpos() == l + newX){
            validMove = false;
          }
        }
      }
    }

  }else if (newX - pieces[i].getXpos() == (newY - pieces[i].getYpos())*-1) {

    validMove = true;
    if((newX - pieces[i].getXpos()) > 0){
      for(int l = 1; l < newX - pieces[i].getXpos(); l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == pieces[i].getYpos() - l && pieces[j].getXpos() == pieces[i].getXpos() + l){
            validMove = false;
          }
        }
      }
    }else{
      for(int l = 1; l <  pieces[i].getXpos() - newX; l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == newY - l && pieces[j].getXpos() == newX + l){
            validMove = false;
          }
        }
      }
    }

  }else if(newX == pieces[i].getXpos()) {

    validMove = true;
    if((newY - pieces[i].getYpos()) > 0){
      for(int l = pieces[i].getYpos()+1; l < newY; l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == l && pieces[j].getXpos() == newX){
            validMove = false;
          }
        }
      }

    }else{
      for(int l = newY +1; l <  pieces[i].getYpos(); l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == l && pieces[j].getXpos() == newX){
            validMove = false;
          }
        }
      }
    }

  }else if (newY == pieces[i].getYpos()) {

    validMove = true;
    if((newX - pieces[i].getXpos()) > 0){
      for(int l = pieces[i].getXpos()+1; l < newX; l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getXpos() == l && pieces[j].getYpos() == newY){
            validMove = false;
          }
        }
      }

    }else{
      for(int l = newX +1; l <  pieces[i].getXpos(); l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getXpos() == l && pieces[j].getYpos() == newY){
            validMove = false;
          }
        }
      }
    }

  }else{
    validMove = false;
  }
  if(validMove == true){
    for(int j = 0; j < arrayLength; j++){
      if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
        if(pieces[j].getWhite() == pieces[i].getWhite()){
          validMove = false;
          if(moving){
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
          }
          return false;
        }else{
          if(moving && checkM == false){
            pieces[j].setCoords(9,9);
          }
        }
      }
    }
    if(validMove){
      if(moving){
        pieces[i].setCoords(newX,newY);
        pieces[i].setFirst();
      }
      return true;
    }
  }else{
    if(moving){
      cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
    }
    return false;
  }
}

bool Rook(int i, int newX, int newY, bool moving, bool checkM){
  validMove = false;

  if(newX == pieces[i].getXpos()) {

    validMove = true;
    if((newY - pieces[i].getYpos()) > 0){
      for(int l = pieces[i].getYpos()+1; l < newY; l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == l && pieces[j].getXpos() == newX){
            validMove = false;
          }
        }
      }

    }else{
      for(int l = newY +1; l <  pieces[i].getYpos(); l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == l && pieces[j].getXpos() == newX){
            validMove = false;
          }
        }
      }
    }

  }else if (newY == pieces[i].getYpos()) {

    validMove = true;
    if((newX - pieces[i].getXpos()) > 0){
      for(int l = pieces[i].getXpos()+1; l < newX; l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getXpos() == l && pieces[j].getYpos() == newY){
            validMove = false;
          }
        }
      }

    }else{
      for(int l = newX +1; l <  pieces[i].getXpos(); l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getXpos() == l && pieces[j].getYpos() == newY){
            validMove = false;
          }
        }
      }
    }

  }else{
    validMove = false;
  }
  if(validMove == true){
    for(int j = 0; j < arrayLength; j++){
      if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
        if(pieces[j].getWhite() == pieces[i].getWhite()){
          validMove = false;
          if(moving){
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
          }
          return false;
        }else{
          if(moving && checkM == false){
            pieces[j].setCoords(9,9);
          }
        }
      }
    }
    if(validMove){
      if(moving){
        pieces[i].setCoords(newX,newY);
        pieces[i].setFirst();
      }
      return true;
    }
  }else{
    if(moving){
      cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
    }
    return false;
  }
}

bool Bishop(int i, int newX, int newY, bool moving, bool checkM){
  validMove = false;

  if (newX - pieces[i].getXpos() == newY - pieces[i].getYpos()) {

    validMove = true;
    if((newX - pieces[i].getXpos()) > 0){
      for(int l = 1; l < newX  -  pieces[i].getXpos(); l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == l + pieces[i].getYpos() && pieces[j].getXpos() == l + pieces[i].getXpos()){
            validMove = false;
          }
        }
      }
    }else{
      for(int l = 1; l <  pieces[i].getXpos() - newX; l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == l + newY && pieces[j].getXpos() == l + newX){
            validMove = false;
          }
        }
      }
    }

  }else if (newX - pieces[i].getXpos() == (newY - pieces[i].getYpos())*-1) {

    validMove = true;
    if((newX - pieces[i].getXpos()) > 0){
      for(int l = 1; l < newX - pieces[i].getXpos(); l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == pieces[i].getYpos() - l && pieces[j].getXpos() == pieces[i].getXpos() + l){
            validMove = false;
          }
        }
      }
    }else{
      for(int l = 1; l <  pieces[i].getXpos() - newX; l++){
        for(int j = 0; j < arrayLength; j++){
          if(pieces[j].getYpos() == newY - l && pieces[j].getXpos() == newX + l){
            validMove = false;
          }
        }
      }
    }

  }else{
    validMove = false;
  }
  if(validMove == true){
    for(int j = 0; j < arrayLength; j++){
      if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
        if(pieces[j].getWhite() == pieces[i].getWhite()){
          validMove = false;
          if(moving){
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
          }
          return false;
        }else{
          if(moving && checkM == false){
            pieces[j].setCoords(9,9);
          }
        }
      }
    }
    if(validMove){
      if(moving){
        pieces[i].setCoords(newX,newY);
        pieces[i].setFirst();
      }
      return true;
    }
  }else{
    if(moving){
      cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
    }
    return false;
  }
}

bool Horse(int i, int newX, int newY, bool moving, bool checkM){
  validMove = false;

  if (((newX == 1 + pieces[i].getXpos())||(newX == -1 + pieces[i].getXpos())) && ((newY == 2 + pieces[i].getYpos())||(newY == -2 + pieces[i].getYpos()))) {

    validMove = true;


  }else if (((newX == 2 + pieces[i].getXpos())||(newX == -2 + pieces[i].getXpos())) && ((newY == 1 + pieces[i].getYpos())||(newY == -1 + pieces[i].getYpos()))) {

    validMove = true;

  }else{
    validMove = false;
  }
  if(validMove == true){
    for(int j = 0; j < arrayLength; j++){
      if(pieces[j].getYpos() == newY && pieces[j].getXpos() == newX){
        if(pieces[j].getWhite() == pieces[i].getWhite()){
          validMove = false;
          if(moving){
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
          }
          return false;
        }else{
          if(moving && checkM == false){
            pieces[j].setCoords(9,9);
          }
        }
      }
    }
    if(validMove){
      if(moving){
        pieces[i].setCoords(newX,newY);
        pieces[i].setFirst();
      }
      return true;
    }
  }else{
    if(moving){
      cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
    }
    return false;
  }
}

void setRandomTypes(){
  srand(time(NULL));
  for (int i = 0; i < arrayLength; i++)
  {
    randomInt = rand() % 5;
    if(pieces[i].getType() != 'K')
    {
      if (randomInt == 0)
      {
        pieces[i].setType('P');
      } else if (randomInt==1)
      {
        pieces[i].setType('Q');
      }else if(randomInt==2)
      {
        pieces[i].setType('B');
      } else if(randomInt==3)
      {
        pieces[i].setType('H');
      } else if(randomInt==4)
      {
        pieces[i].setType('R');
      }
    }
  }
}

bool check(bool white){

  possibleMovesX.clear();
  possibleMovesY.clear();

  for(int c = 0; c < arrayLength; c++){

    if(pieces[c].getWhite() != white){

      if(pieces[c].getType() == 'P'){

        if(pieces[c].getWhite()){


          if(pieces[c].getXpos() > 0 && pieces[c].getXpos() < 8 && pieces[c].getYpos() < 8){

            // white pawn diagonal right
            possibleMovesX.push_back(pieces[c].getXpos() + 1);
            possibleMovesY.push_back(pieces[c].getYpos() - 1);
            //white pawn diagonal left
            possibleMovesX.push_back( pieces[c].getXpos() - 1);
            possibleMovesY.push_back( pieces[c].getYpos() - 1);

          }else if(pieces[c].getXpos() == 0 && pieces[c].getYpos() < 8){
            // white pawn diagonal right
            possibleMovesX.push_back(pieces[c].getXpos() + 1);
            possibleMovesY.push_back(pieces[c].getYpos() - 1);

          }else if(pieces[c].getXpos() == 8 && pieces[c].getYpos() < 8){
            // white pawn diagonal right
            possibleMovesX.push_back(pieces[c].getXpos() - 1);
            possibleMovesY.push_back(pieces[c].getYpos() - 1);

          }

        }else{

          if(pieces[c].getXpos() > 0 && pieces[c].getXpos() < 8 && pieces[c].getYpos() > 0){

            // white pawn diagonal right
            possibleMovesX.push_back(pieces[c].getXpos() + 1);
            possibleMovesY.push_back(pieces[c].getYpos() + 1);
            //white pawn diagonal left
            possibleMovesX.push_back( pieces[c].getXpos() - 1);
            possibleMovesY.push_back( pieces[c].getYpos() + 1);

          }else if(pieces[c].getXpos() == 0 && pieces[c].getYpos() > 0){
            // white pawn diagonal right
            possibleMovesX.push_back(pieces[c].getXpos() + 1);
            possibleMovesY.push_back(pieces[c].getYpos() + 1);

          }else if(pieces[c].getXpos() == 8 && pieces[c].getYpos() > 0){
            // white pawn diagonal right
            possibleMovesX.push_back(pieces[c].getXpos() - 1);
            possibleMovesY.push_back(pieces[c].getYpos() + 1);

          }

        }

      }else if(pieces[c].getType() == 'Q'){

        for(int x = 0; x < 8; x++){
          for(int y = 0; y < 8; y++){
            if(Queen(c, x,y,false, true)){

              possibleMovesX.push_back(x);
              possibleMovesY.push_back(y);
            }
          }
        }

      }else if(pieces[c].getType() == 'R'){

        for(int x = 0; x < 8; x++){
          for(int y = 0; y < 8; y++){
            if(Rook(c, x,y,false, true)){

              possibleMovesX.push_back(x);
              possibleMovesY.push_back(y);
            }
          }
        }

      }else if(pieces[c].getType() == 'B'){

        for(int x = 0; x < 8; x++){
          for(int y = 0; y < 8; y++){
            if(Bishop(c, x,y,false, true)){

              possibleMovesX.push_back(x);
              possibleMovesY.push_back(y);
            }
          }
        }


      }else if(pieces[c].getType() == 'H'){

        for(int x = 0; x < 8; x++){
          for(int y = 0; y < 8; y++){
            if(Horse(c, x,y,false, true)){

              possibleMovesX.push_back(x);
              possibleMovesY.push_back(y);
            }
          }
        }


      }else if(pieces[c].getType() == 'K'){

        for(int x = 0; x < 8; x++){
          for(int y = 0; y < 8; y++){
            if(King(c, x,y,false, true)){

              possibleMovesX.push_back(x);
              possibleMovesY.push_back(y);
            }
          }
        }

      }

    }

  }


  for (int c = 0; c < possibleMovesX.size(); c++){

    if(white){
      if (pieces[25].getXpos() == possibleMovesX[c] && pieces[25].getYpos() == possibleMovesY[c]){
        //cout << "Check test\n";
        return true;

      }
    }else{
      if(pieces[9].getXpos() == possibleMovesX[c] && pieces[9].getYpos() == possibleMovesY[c]){
        //cout << "Check test\n";
        return true;
      }
    }

  }
  return false;
}

bool checkMate(bool colorW){

  if(check(colorW)){
    for(int f = 0; f < arrayLength; f++){
      if(pieces[f].getWhite() == colorW){
        oldX = pieces[f].getXpos();
        oldY = pieces[f].getYpos();

        if(pieces[f].getType() == 'P'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Pawn(f, x,y,false, true)){
                Pawn(f, x,y,true, true);
                if(check(colorW) == false){
                  pieces[f].setCoords(oldX,oldY);
                  //cout << "Test\n";
                  return false;
                }
                pieces[f].setCoords(oldX,oldY);
              }
            }
          }

          //  start load puzzle1.txt exit new a1 y a8 y
        }else if(pieces[f].getType() == 'Q'){


          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Queen(f, x,y,false, true)){
                Queen(f, x,y,true, true);
                if(check(colorW) == false){
                  pieces[f].setCoords(oldX,oldY);
                  //cout << "Test\n";
                  return false;
                }
                pieces[f].setCoords(oldX,oldY);
              }
            }
          }

        }else if(pieces[f].getType() == 'R'){


          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Rook(f, x,y,false, true)){
                Rook(f, x,y,true, true);
                if(check(colorW) == false){
                  pieces[f].setCoords(oldX,oldY);
                  //  cout << "Test\n";
                  return false;
                }
                pieces[f].setCoords(oldX,oldY);
              }
            }
          }


        }else if(pieces[f].getType() == 'B'){


          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Bishop(f, x,y,false, true)){
                Bishop(f, x,y,true, true);
                if(check(colorW) == false){
                  pieces[f].setCoords(oldX,oldY);
                  //  cout << "Test\n";
                  return false;
                }
                pieces[f].setCoords(oldX,oldY);
              }
            }
          }

        }else if(pieces[f].getType() == 'H'){


          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Horse(f, x,y,false, true)){
                Horse(f, x,y,true, true);
                if(check(colorW) == false){
                  pieces[f].setCoords(oldX,oldY);
                  //cout << "Test\n";
                  return false;
                }
                pieces[f].setCoords(oldX,oldY);
              }
            }
          }

        }else if(pieces[f].getType() == 'K'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(King(f, x,y,false, true)){
                King(f, x,y,true, true);
                if(check(colorW) == false){
                  pieces[f].setCoords(oldX,oldY);
                  cout << "Test\n";
                  // cout << pieces[12].getXpos() << pieces[12].getYpos() << endl;
                  // cout << pieces[13].getXpos() << pieces[13].getYpos() << endl;
                  return false;
                }
                pieces[f].setCoords(oldX,oldY);
              }
            }
          }
          //          start load puzzle1.txt exit new a1 y a8 y

        }

      }

    }
    cout << "Test\n";
    return true;
  }
  return false;
}

void promotion(int i){
  if (pieces[i].getWhite() && pieces[i].getYpos() == 0 && pieces[i].getType() == 'P'){

    pieces[i].setType('Q');
    cout << endl << endl << endl << endl << "\033[1;92mPromotion!\033[0m\n" << endl;

  } else if(pieces[i].getYpos() == 7 && pieces[i].getWhite() == false && pieces[i].getType() == 'P')
  {
    pieces[i].setType('Q');
    cout << endl << endl << endl << endl << "\033[1;92mPromotion!\033[0m\n" << endl;
  }
}

void passTurn(){

  if (whiteTurn == true){
    if(checkMate(false)){
      playing = false;
      cout<< endl << endl << endl << endl << "Check Mate. White Player wins" << endl;
    }
    else{
      whiteTurn = false;
      cout << endl << endl << endl << endl << "\033[1;92mBlack Turn\033[0m\n" << endl;
    }
  }else if (whiteTurn == false){
    if(checkMate(true)){
      playing = false;
      cout<< endl << endl << endl << endl << "Check Mate. Black Player wins" << endl;
    }else{
      whiteTurn = true;
      cout << endl << endl << endl << endl << "\033[1;92mWhite Turn\033[0m\n" << endl;
    }
  }
}


////////////////////////////////////////////////////////////////////////////////

int main(){

  cout<< location;
  startPage();
  cout << "\e[8;22;50t";
  if (mode == "Random")
  {
    setRandomTypes();
  }
  //save("save.txt");
  //load("save.txt");
  while(playing)
  {

    //by zach greenberg
    cout << "\e[8;22;50t";
    display();
    //pyae sone
    userInput();
    if (playing == false)
    {
      break;
    }
    //lucas zagal
    int i;
    for (int v = 0; v < arrayLength; v++)
    {
      if (pieces[v].getXpos() == oldArrayX && pieces[v].getYpos() == oldArrayY)
      {
        i = v;
      }
    }
    if(pieces[i].getWhite() ==  true && whiteTurn == true)
    {
      if (pieces[i].getType() == 'P')
      {
        if(Pawn(i, newArrayX, newArrayY, true, false))
        {

          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
            promotion(i);
          }
        }
      }else if (pieces[i].getType() == 'K')
      {
        if(King(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }
        }
      } else if (pieces[i].getType() == 'Q')
      {
        // pyae sone
        if(Queen(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }
          passTurn();
        }
      }else if (pieces[i].getType() == 'R')
      {
        // pyae sone
        if(Rook(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }
          passTurn();
        }
      }else if (pieces[i].getType() == 'B')
      {
        // pyae sone
        if(Bishop(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }
          passTurn();
        }
      }else if (pieces[i].getType() == 'H')
      {
        // pyae sone
        if(Horse(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }
          passTurn();
        }
      }

    }else if (pieces[i].getWhite() == false && whiteTurn == false){

      if (pieces[i].getType() == 'P')
      {
        if(Pawn(i, newArrayX, newArrayY,true, false))
        {
          if(check(false)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
            promotion(i);
          }
        }
      } else if (pieces[i].getType() == 'K')
      {
        if(King(i, newArrayX, newArrayY,true, false))
        {
          if(check(false)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }
        }
      } else if (pieces[i].getType() == 'Q')
      {
        // pyae sone
        if(Queen(i, newArrayX, newArrayY,true, false))
        {
          if(check(false)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }
        }
      }else if (pieces[i].getType() == 'R')
      {
        // pyae sone
        if(Rook(i, newArrayX, newArrayY,true, false))
        {
          if(check(false)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }
        }
      }else if (pieces[i].getType() == 'B')
      {
        // pyae sone
        if(Bishop(i, newArrayX, newArrayY,true, false))
        {
          if(check(false)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }
        }

      }else if (pieces[i].getType() == 'H')
      {
        // pyae sone
        if(Horse(i, newArrayX, newArrayY,true, false))
        {
          if(check(false)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }
        }

      }

    }else{
      cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Not your turn!\033[0m\n" << endl;
    }
  }
}
