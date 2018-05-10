#include <dirent.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctime>#include <dirent.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctime>
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
vector<int> possibleMovesPiece;
vector<int> possibleMoves1X;
vector<int> possibleMoves1Y;
vector<int> possibleMoves1Piece;
vector<int> bestMove;
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
bool modeMenu = false;
bool startSelections = false;
bool loadGames = false;
bool inputting = false;
bool whiteCastle = false;
bool blackCastle = false;
int castleRook;
bool open;
bool randomAI = true;
int randAIselect;
bool AIloop = true;
int randAIX;
int randAIY;
int randAIPiece;
int whitek;
int whitep;
int whiteh;
int whiter;
int whiteb;
int whiteq;
int blackk;
int blackp;
int blackh;
int blackr;
int blackb;
int blackq;
double evaluation;
int possibleMovesBlack;
int possibleMovesWhite;
int aiLevel = 2;
double aiEval;
int oldX1;
int oldY1;
// functions

void save(string file){
  ofstream outfile("/Users/9625014/Programming1Folder/Term3/Chess/saves/"+file);
  for(int c = 0; c < arrayLength; c++){
    outfile << pieces[c].getXpos() << pieces[c].getYpos();
  }
  outfile << whiteTurn;
  outfile.close();
}

void load(string file)
{
  ifstream infile;
  infile.open(file);

  string saveFile;
  infile >> saveFile;
  infile.close();
  BP1.setCoords(saveFile.at(0),saveFile.at(1));
  BP2.setCoords(saveFile.at(2),saveFile.at(3));
  BP3.setCoords(saveFile.at(4),saveFile.at(5));
  BP4.setCoords(saveFile.at(6),saveFile.at(7));
  BP5.setCoords(saveFile.at(8),saveFile.at(9));
  BP6.setCoords(saveFile.at(10),saveFile.at(11));
  BP7.setCoords(saveFile.at(12),saveFile.at(13));
  BP8.setCoords(saveFile.at(14),saveFile.at(15));

  BQ.setCoords(saveFile.at(16),saveFile.at(17));

  BK.setCoords(saveFile.at(18),saveFile.at(19));

  BB1.setCoords(saveFile.at(20),saveFile.at(21));
  BB2.setCoords(saveFile.at(22),saveFile.at(23));

  BR1.setCoords(saveFile.at(24),saveFile.at(25));
  BR2.setCoords(saveFile.at(26),saveFile.at(27));

  BH1.setCoords(saveFile.at(28),saveFile.at(29));
  BH2.setCoords(saveFile.at(30),saveFile.at(31));

  WP1.setCoords(saveFile.at(32),saveFile.at(33));
  WP2.setCoords(saveFile.at(34),saveFile.at(35));
  WP3.setCoords(saveFile.at(36),saveFile.at(37));
  WP4.setCoords(saveFile.at(38),saveFile.at(39));
  WP5.setCoords(saveFile.at(40),saveFile.at(41));
  WP6.setCoords(saveFile.at(42),saveFile.at(43));
  WP7.setCoords(saveFile.at(44),saveFile.at(45));
  WP8.setCoords(saveFile.at(46),saveFile.at(47));

  WQ.setCoords(saveFile.at(48),saveFile.at(49));

  WK.setCoords(saveFile.at(50),saveFile.at(51));

  WB1.setCoords(saveFile.at(52),saveFile.at(53));
  WB2.setCoords(saveFile.at(54),saveFile.at(55));

  WR1.setCoords(saveFile.at(56),saveFile.at(57));
  WR2.setCoords(saveFile.at(58),saveFile.at(59));

  WH1.setCoords(saveFile.at(60),saveFile.at(61));
  WH2.setCoords(saveFile.at(62),saveFile.at(63));

  if(saveFile.at(64) == '1')
  {
    whiteTurn = true;
  } else
  {
    whiteTurn = false;
  }
  infile.close();
}

void loadGame(){
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
    if((dir = opendir ("/Users/9625014/Programming1Folder/Term3/Chess/saves")) != NULL)
    {
      while((ent = readdir(dir)) != NULL)
      {
        printf ("%s\n", ent->d_name);
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

    char fileName[255];

    if(menuSelect == "Exit"|| menuSelect == "exit"){
      loadGames = false;
    } else if(menuSelect != "Exit" && menuSelect != "exit"){
      DIR *dir;
      struct dirent *ent;
      while ((ent = readdir(dir)) != NULL)
      {
        strncpy(fileName, ent->d_name, 254);
        fileName[254] = '\0';
        if(fileName == menuSelect)
        {
          load(menuSelect);
          loaded = true;
        } else
        {
          //cout << "Invalid entry" << endl;
        }

      }
      closedir(dir);
      //load(menuSelect);
    }else if (loaded == false)
    {
      incorectSelect = true;
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
    cout<<"                        ...                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
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
    }else {
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
    cout<<"                      Random                      "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                        AI                        "<< endl;
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
    } else if (menuSelect == "AI" || menuSelect == "ai") {
      mode = "AI";
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
      cout << "Name your file:";
      cin >> fileName;
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
      if(pieces[c].getXpos() != 9 && pieces[c].getYpos() != 9){
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
  }


  for (int c = 0; c < possibleMovesX.size(); c++){

    if(white){
      if (pieces[25].getXpos() == possibleMovesX[c] && pieces[25].getYpos() == possibleMovesY[c]){
        return true;
      }
    }else{
      if(pieces[9].getXpos() == possibleMovesX[c] && pieces[9].getYpos() == possibleMovesY[c]){
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
        if(pieces[f].getXpos() != 9 && pieces[f].getYpos() != 9){
          oldX = pieces[f].getXpos();
          oldY = pieces[f].getYpos();

          if(pieces[f].getType() == 'P'){

            for(int x = 0; x < 8; x++){
              for(int y = 0; y < 8; y++){
                if(Pawn(f, x,y,false, true)){
                  Pawn(f, x,y,true, true);
                  if(check(colorW) == false){
                    pieces[f].setCoords(oldX,oldY);
                    return false;
                  }
                  pieces[f].setCoords(oldX,oldY);
                }
              }
            }


          }else if(pieces[f].getType() == 'Q'){


            for(int x = 0; x < 8; x++){
              for(int y = 0; y < 8; y++){
                if(Queen(f, x,y,false, true)){
                  Queen(f, x,y,true, true);
                  if(check(colorW) == false){
                    pieces[f].setCoords(oldX,oldY);
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
                    return false;
                  }
                  pieces[f].setCoords(oldX,oldY);
                }
              }
            }

          }
        }
      }

    }

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

void possibleMoves(bool white){

  possibleMovesX.clear();
  possibleMovesY.clear();
  possibleMovesPiece.clear();

  for(int c = 0; c < arrayLength; c++){
    if(pieces[c].getXpos() != 9 && pieces[c].getYpos() != 9){
      if(pieces[c].getWhite() == white){

        if(pieces[c].getType() == 'P'){
          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Pawn(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }


        }else if(pieces[c].getType() == 'Q'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Queen(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }

        }else if(pieces[c].getType() == 'R'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Rook(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);

              }
            }
          }

        }else if(pieces[c].getType() == 'B'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Bishop(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }


        }else if(pieces[c].getType() == 'H'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Horse(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }


        }else if(pieces[c].getType() == 'K'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(King(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }

        }

      }
    }
  }

}

double evaluateBoard(){
  whitek =0;
  whitep =0;
  whiteh =0;
  whiter =0;
  whiteb =0;
  whiteq =0;
  blackk =0;
  blackp =0;
  blackh =0;
  blackr =0;
  blackb =0;
  blackq =0;
  evaluation = 0;
  possibleMoves(false);
  possibleMovesBlack = possibleMovesX.size();
  possibleMoves(true);
  possibleMovesWhite = possibleMovesX.size();
  for(int o = 0; o < arrayLength; o++){
    if(pieces[o].getXpos() != 9 && pieces[o].getYpos() != 9){
      if(pieces[o].getWhite()){
        switch(pieces[o].getType()) {
          case 'P' :
          whitep += 1;
          break;       // and exits the switch
          case 'K' :
          whitek += 1;
          break;
          case 'Q' :
          whiteq += 1;
          break;
          case 'R' :
          whiter += 1;
          break;
          case 'H' :
          whiteh += 1;
          break;
          case 'B' :
          whiteb += 1;
          break;
        }
      }else{
        switch(pieces[o].getType()) {
          case 'P' :
          blackp += 1;
          break;       // and exits the switch
          case 'K' :
          blackk += 1;
          break;
          case 'Q' :
          blackq += 1;
          break;
          case 'R' :
          blackr += 1;
          break;
          case 'H' :
          blackh += 1;
          break;
          case 'B' :
          blackb+= 1;
          break;
        }
      }
    }
  }
  evaluation = 200*(whitek - blackk) + 9*(whiteq-blackq) + 5*(whiter-blackr) + 3*(whiteb - blackb + whiteh - blackh) + 1*(whitep - blackp) + 0.1*(possibleMovesWhite  - possibleMovesBlack) ;


  return evaluation;
}

void AI(bool white) {
  cout<<"evaluation "<< evaluateBoard()<< endl;
  possibleMoves(false);
  if(aiLevel == 1){
    AIloop = true;
    while(AIloop){

      randAIselect = rand() % 16;
      randAIX = rand() % 8;
      randAIY = rand() % 8;

      if(pieces[randAIselect].getXpos() != 9 && pieces[randAIselect].getYpos() != 9){
        if(pieces[randAIselect].getWhite() == white){

          oldX = pieces[randAIselect].getXpos();
          oldY = pieces[randAIselect].getYpos();

          if(pieces[randAIselect].getType() == 'P'){


            if(Pawn(randAIselect, randAIX ,randAIY ,false, true)){
              Pawn(randAIselect, randAIX ,randAIY ,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }


            }


          }else if(pieces[randAIselect].getType() == 'Q'){
            if(Queen(randAIselect, randAIX,randAIY,false, true)){
              Queen(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }
            }



          }else if(pieces[randAIselect].getType() == 'R'){


            if(Rook(randAIselect, randAIX,randAIY,false, true)){
              Rook(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }
            }


          }else if(pieces[randAIselect].getType() == 'B'){


            if(Bishop(randAIselect, randAIX,randAIY,false, true)){
              Bishop(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }
            }



          }else if(pieces[randAIselect].getType() == 'H'){

            if(Horse(randAIselect, randAIX,randAIY,false, true)){
              Horse(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }

            }


          }else if(pieces[randAIselect].getType() == 'K'){


            if(King(randAIselect, randAIX,randAIY,false, true)){
              King(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }

            }

          }

        }
      }
    }




  }

  else if(aiLevel == 2){

    aiEval = 0;
    possibleMoves(false);
    possibleMoves1X = possibleMoves1X;;
    possibleMoves1Y =  possibleMovesY;
    possibleMoves1Piece = possibleMovesPiece;

    for(int z = 0; z <  possibleMoves1Piece.size() ; z++){
      if(pieces[possibleMoves1Piece[z]].getWhite() == white){
        if(pieces[possibleMoves1Piece[z]].getXpos() != 9 && pieces[f].getYpos() != 9){
          oldX1 = pieces[possibleMoves1Piece[z]].getXpos();
          oldY1 = pieces[possibleMoves1Piece[z]].getYpos();
          pieces[possibleMoves1Piece[z]].setCoords(possibleMoves1X[z],possibleMoves1Y[z]);
          if( evaluateBoard() <= aiEval ){
            aiEval = evaluateBoard;
            bestMove.push_back(z);
          }
          pieces[possibleMoves1Piece[z]].setCoords(oldX1,oldY1);
        }
      }
    }
    randAIPiece = rand() % (bestMove.size() -1);
    pieces[possibleMoves1Piece[bestMove[randAIPiece]]].setCoords(possibleMoves1X[bestMove[randAIPiece]], possibleMoves1Y[bestMove[randAIPiece]]);

  }



}

void passTurn(){

  if (whiteTurn == true){
    if(checkMate(false)){
      playing = false;
      cout<< endl << endl << endl << endl << "Check Mate. White Player wins" << endl;
    }
    else{
      if (randomAI) {
        AI(false);
        whiteTurn = true;






      }else{
        whiteTurn = false;
        cout << endl << endl << endl << endl << "\033[1;92mBlack Turn\033[0m\n" << endl;
      }

    }
  }else if (whiteTurn == false){
    if(checkMate(true)){
      playing = false;
      cout<< endl << endl << endl << endl << "Check Mate. Black Player wins" << endl;
    }else{
      whiteTurn = true;
    }
    cout << endl << endl << endl << endl << "\033[1;92mWhite Turn\033[0m\n" << endl;
  }
}

////////////////////////////////////////////////////////////////////////////////

int main(){
  srand(time(NULL));
  startPage();
  cout << "\e[8;22;50t";
  if (mode == "Random")
  {
    setRandomTypes();
    randomAI = false;
  } else if (mode == "AI") {
    randomAI = true;
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
          }else{
            passTurn();
          }

        }
      }else if (pieces[i].getType() == 'R')
      {
        // pyae sone
        if(Rook(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }

        }
      }else if (pieces[i].getType() == 'B')
      {
        // pyae sone
        if(Bishop(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }

        }
      }else if (pieces[i].getType() == 'H')
      {
        // pyae sone
        if(Horse(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          } else{
            passTurn();

          }

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
vector<int> possibleMovesPiece;
vector<int> possibleMoves1X;
vector<int> possibleMoves1Y;
vector<int> possibleMoves1Piece;
vector<int> bestMove;
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
bool modeMenu = false;
bool startSelections = false;
bool loadGames = false;
bool inputting = false;
bool whiteCastle = false;
bool blackCastle = false;
int castleRook;
bool open;
bool randomAI = true;
int randAIselect;
bool AIloop = true;
int randAIX;
int randAIY;
int randAIPiece;
int whitek;
int whitep;
int whiteh;
int whiter;
int whiteb;
int whiteq;
int blackk;
int blackp;
int blackh;
int blackr;
int blackb;
int blackq;
double evaluation;
int possibleMovesBlack;
int possibleMovesWhite;
int aiLevel = 1;
double aiEval;
int oldX1;
int oldY1;
// functions

void save(string file){
  ofstream outfile("/Users/9625014/Programming1Folder/Term3/Chess/saves/"+file);
  for(int c = 0; c < arrayLength; c++){
    outfile << pieces[c].getXpos() << pieces[c].getYpos();
  }
  outfile << whiteTurn;
  outfile.close();
}

void load(string file)
{
  ifstream infile;
  infile.open(file);

  string saveFile;
  infile >> saveFile;
  infile.close();
  BP1.setCoords(saveFile.at(0),saveFile.at(1));
  BP2.setCoords(saveFile.at(2),saveFile.at(3));
  BP3.setCoords(saveFile.at(4),saveFile.at(5));
  BP4.setCoords(saveFile.at(6),saveFile.at(7));
  BP5.setCoords(saveFile.at(8),saveFile.at(9));
  BP6.setCoords(saveFile.at(10),saveFile.at(11));
  BP7.setCoords(saveFile.at(12),saveFile.at(13));
  BP8.setCoords(saveFile.at(14),saveFile.at(15));

  BQ.setCoords(saveFile.at(16),saveFile.at(17));

  BK.setCoords(saveFile.at(18),saveFile.at(19));

  BB1.setCoords(saveFile.at(20),saveFile.at(21));
  BB2.setCoords(saveFile.at(22),saveFile.at(23));

  BR1.setCoords(saveFile.at(24),saveFile.at(25));
  BR2.setCoords(saveFile.at(26),saveFile.at(27));

  BH1.setCoords(saveFile.at(28),saveFile.at(29));
  BH2.setCoords(saveFile.at(30),saveFile.at(31));

  WP1.setCoords(saveFile.at(32),saveFile.at(33));
  WP2.setCoords(saveFile.at(34),saveFile.at(35));
  WP3.setCoords(saveFile.at(36),saveFile.at(37));
  WP4.setCoords(saveFile.at(38),saveFile.at(39));
  WP5.setCoords(saveFile.at(40),saveFile.at(41));
  WP6.setCoords(saveFile.at(42),saveFile.at(43));
  WP7.setCoords(saveFile.at(44),saveFile.at(45));
  WP8.setCoords(saveFile.at(46),saveFile.at(47));

  WQ.setCoords(saveFile.at(48),saveFile.at(49));

  WK.setCoords(saveFile.at(50),saveFile.at(51));

  WB1.setCoords(saveFile.at(52),saveFile.at(53));
  WB2.setCoords(saveFile.at(54),saveFile.at(55));

  WR1.setCoords(saveFile.at(56),saveFile.at(57));
  WR2.setCoords(saveFile.at(58),saveFile.at(59));

  WH1.setCoords(saveFile.at(60),saveFile.at(61));
  WH2.setCoords(saveFile.at(62),saveFile.at(63));

  if(saveFile.at(64) == '1')
  {
    whiteTurn = true;
  } else
  {
    whiteTurn = false;
  }
  infile.close();
}

void loadGame(){
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
    if((dir = opendir ("/Users/9625014/Programming1Folder/Term3/Chess/saves")) != NULL)
    {
      while((ent = readdir(dir)) != NULL)
      {
        printf ("%s\n", ent->d_name);
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

    char fileName[255];

    if(menuSelect == "Exit"|| menuSelect == "exit"){
      loadGames = false;
    } else if(menuSelect != "Exit" && menuSelect != "exit"){
      DIR *dir;
      struct dirent *ent;
      while ((ent = readdir(dir)) != NULL)
      {
        strncpy(fileName, ent->d_name, 254);
        fileName[254] = '\0';
        if(fileName == menuSelect)
        {
          load(menuSelect);
          loaded = true;
        } else
        {
          //cout << "Invalid entry" << endl;
        }

      }
      closedir(dir);
      //load(menuSelect);
    }else if (loaded == false)
    {
      incorectSelect = true;
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
    cout<<"                        ...                       "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                                                  "<< endl;
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
    }else {
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
    cout<<"                      Random                      "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                        AI                        "<< endl;
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
    } else if (menuSelect == "AI" || menuSelect == "ai") {
      mode = "AI";
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
      cout << "Name your file:";
      cin >> fileName;
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
      if(pieces[c].getXpos() != 9 && pieces[c].getYpos() != 9){
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
  }


  for (int c = 0; c < possibleMovesX.size(); c++){

    if(white){
      if (pieces[25].getXpos() == possibleMovesX[c] && pieces[25].getYpos() == possibleMovesY[c]){
        return true;
      }
    }else{
      if(pieces[9].getXpos() == possibleMovesX[c] && pieces[9].getYpos() == possibleMovesY[c]){
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
        if(pieces[f].getXpos() != 9 && pieces[f].getYpos() != 9){
          oldX = pieces[f].getXpos();
          oldY = pieces[f].getYpos();

          if(pieces[f].getType() == 'P'){

            for(int x = 0; x < 8; x++){
              for(int y = 0; y < 8; y++){
                if(Pawn(f, x,y,false, true)){
                  Pawn(f, x,y,true, true);
                  if(check(colorW) == false){
                    pieces[f].setCoords(oldX,oldY);
                    return false;
                  }
                  pieces[f].setCoords(oldX,oldY);
                }
              }
            }


          }else if(pieces[f].getType() == 'Q'){


            for(int x = 0; x < 8; x++){
              for(int y = 0; y < 8; y++){
                if(Queen(f, x,y,false, true)){
                  Queen(f, x,y,true, true);
                  if(check(colorW) == false){
                    pieces[f].setCoords(oldX,oldY);
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
                    return false;
                  }
                  pieces[f].setCoords(oldX,oldY);
                }
              }
            }

          }
        }
      }

    }

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

void possibleMoves(bool white){

  possibleMovesX.clear();
  possibleMovesY.clear();
  possibleMovesPiece.clear();

  for(int c = 0; c < arrayLength; c++){
    if(pieces[c].getXpos() != 9 && pieces[c].getYpos() != 9){
      if(pieces[c].getWhite() == white){

        if(pieces[c].getType() == 'P'){
          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Pawn(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }


        }else if(pieces[c].getType() == 'Q'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Queen(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }

        }else if(pieces[c].getType() == 'R'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Rook(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);

              }
            }
          }

        }else if(pieces[c].getType() == 'B'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Bishop(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }


        }else if(pieces[c].getType() == 'H'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(Horse(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }


        }else if(pieces[c].getType() == 'K'){

          for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
              if(King(c, x,y,false, true)){

                possibleMovesX.push_back(x);
                possibleMovesY.push_back(y);
                possibleMovesPiece.push_back(c);
              }
            }
          }

        }

      }
    }
  }

}

double evaluateBoard(){
  whitek =0;
  whitep =0;
  whiteh =0;
  whiter =0;
  whiteb =0;
  whiteq =0;
  blackk =0;
  blackp =0;
  blackh =0;
  blackr =0;
  blackb =0;
  blackq =0;
  evaluation = 0;
  possibleMoves(false);
  possibleMovesBlack = possibleMovesX.size();
  possibleMoves(true);
  possibleMovesWhite = possibleMovesX.size();
  for(int o = 0; o < arrayLength; o++){
    if(pieces[o].getXpos() != 9 && pieces[o].getYpos() != 9){
      if(pieces[o].getWhite()){
        switch(pieces[o].getType()) {
          case 'P' :
          whitep += 1;
          break;       // and exits the switch
          case 'K' :
          whitek += 1;
          break;
          case 'Q' :
          whiteq += 1;
          break;
          case 'R' :
          whiter += 1;
          break;
          case 'H' :
          whiteh += 1;
          break;
          case 'B' :
          whiteb += 1;
          break;
        }
      }else{
        switch(pieces[o].getType()) {
          case 'P' :
          blackp += 1;
          break;       // and exits the switch
          case 'K' :
          blackk += 1;
          break;
          case 'Q' :
          blackq += 1;
          break;
          case 'R' :
          blackr += 1;
          break;
          case 'H' :
          blackh += 1;
          break;
          case 'B' :
          blackb+= 1;
          break;
        }
      }
    }
  }
  evaluation = 200*(whitek - blackk) + 9*(whiteq-blackq) + 5*(whiter-blackr) + 3*(whiteb - blackb + whiteh - blackh) + 1*(whitep - blackp) + 0.1*(possibleMovesWhite  - possibleMovesBlack) ;


  return evaluation;
}

void AI(bool white) {
  cout<<"evaluation "<< evaluateBoard()<< endl;
  possibleMoves(false);
  if(aiLevel == 1){
    AIloop = true;
    while(AIloop){

      randAIselect = rand() % 16;
      randAIX = rand() % 8;
      randAIY = rand() % 8;

      if(pieces[randAIselect].getXpos() != 9 && pieces[randAIselect].getYpos() != 9){
        if(pieces[randAIselect].getWhite() == white){

          oldX = pieces[f].getXpos();
          oldY = pieces[f].getYpos();

          if(pieces[randAIselect].getType() == 'P'){


            if(Pawn(randAIselect, randAIX ,randAIY ,false, true)){
              Pawn(randAIselect, randAIX ,randAIY ,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }


            }


          }else if(pieces[randAIselect].getType() == 'Q'){
            if(Queen(randAIselect, randAIX,randAIY,false, true)){
              Queen(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }
            }



          }else if(pieces[randAIselect].getType() == 'R'){


            if(Rook(randAIselect, randAIX,randAIY,false, true)){
              Rook(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }
            }


          }else if(pieces[randAIselect].getType() == 'B'){


            if(Bishop(randAIselect, randAIX,randAIY,false, true)){
              Bishop(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }
            }



          }else if(pieces[randAIselect].getType() == 'H'){

            if(Horse(randAIselect, randAIX,randAIY,false, true)){
              Horse(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }

            }


          }else if(pieces[randAIselect].getType() == 'K'){


            if(King(randAIselect, randAIX,randAIY,false, true)){
              King(randAIselect, randAIX,randAIY,true, false);
              if(check(true)){
                pieces[randAIselect].setCoords(oldX,oldY);
              }else{
                AIloop = false;
              }

            }

          }

        }
      }
    }




  }

  else if(aiLevel == 2){

    aiEval = 0;
    possibleMoves(false);
    possibleMoves1X = possibleMoves1X;;
    possibleMoves1Y =  possibleMovesY;
    possibleMoves1Piece = possibleMovesPiece;

    for(int z = 0; z <  possibleMoves1Piece.size() ; z++){
      if(pieces[f].getWhite() == white){
        if(pieces[f].getXpos() != 9 && pieces[f].getYpos() != 9){
          oldX1 = pieces[possibleMoves1Piece[z]].getXpos();
          oldY1 = pieces[possibleMoves1Piece[z]].getYpos();
          pieces[possibleMoves1Piece[z]].setCoords(possibleMoves1X[z],possibleMoves1Y[z]);
          if( evaluateBoard() <= aiEval ){
            aiEval = evaluateBoard;
            bestMove.push_back(z);
          }
          pieces[possibleMoves1Piece[z]].setCoords(oldX1,oldY1);
        }
      }
    }
    randAIPiece = rand() % (bestMove.size() -1);
    pieces[possibleMoves1Piece[bestMove[randAIPiece]]].setCoords(possibleMoves1X[bestMove[randAIPiece]], possibleMoves1Y[bestMove[randAIPiece]]);

  }



}

void passTurn(){

  if (whiteTurn == true){
    if(checkMate(false)){
      playing = false;
      cout<< endl << endl << endl << endl << "Check Mate. White Player wins" << endl;
    }
    else{
      if (randomAI) {
        AI(false);
        whiteTurn = true;






      }else{
        whiteTurn = false;
        cout << endl << endl << endl << endl << "\033[1;92mBlack Turn\033[0m\n" << endl;
      }

    }
  }else if (whiteTurn == false){
    if(checkMate(true)){
      playing = false;
      cout<< endl << endl << endl << endl << "Check Mate. Black Player wins" << endl;
    }else{
      whiteTurn = true;
    }
    cout << endl << endl << endl << endl << "\033[1;92mWhite Turn\033[0m\n" << endl;
  }
}

////////////////////////////////////////////////////////////////////////////////

int main(){
  srand(time(NULL));
  startPage();
  cout << "\e[8;22;50t";
  if (mode == "Random")
  {
    setRandomTypes();
    randomAI = false;
  } else if (mode == "AI") {
    randomAI = true;
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
          }else{
            passTurn();
          }

        }
      }else if (pieces[i].getType() == 'R')
      {
        // pyae sone
        if(Rook(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }

        }
      }else if (pieces[i].getType() == 'B')
      {
        // pyae sone
        if(Bishop(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          }else{
            passTurn();
          }

        }
      }else if (pieces[i].getType() == 'H')
      {
        // pyae sone
        if(Horse(i, newArrayX, newArrayY, true, false))
        {
          if(check(true)){
            pieces[i].setCoords(oldArrayX,oldArrayY);
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You can't move into check. Try again!\033[0m\n" << endl;
          } else{
            passTurn();

          }

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
