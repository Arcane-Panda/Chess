

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
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
  firstMove = false;
  cout << "\n\n\n\n\n\n\n\n";

}

bool Piece::getFirst(void)
{
  return firstMove;
  //firstMove = false;
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
vector<int> possibleMovesX;
vector<int> possibleMovesY;
int oldX;
int oldY;
bool playing = true;
Piece pieces[20] = {BP1, BP2, BP3, BP4, BP5, BP6 ,BP7, BP8, BQ, BK, WP1, WP2, WP3, WP4, WP5, WP6, WP7, WP8, WQ, WK};


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
// functions

void display(){

  cout  << endl << endl<< "    A  B  C  D  E  F  G  H " << endl;
  for(int j=0;j < 8; j+=2){ // rows

    cout<< " " << 8-j << " ";
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

    cout<< " " << 7-j << " ";
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
  cout<< "    A  B  C  D  E  F  G  H " << endl << endl;

}

void userInput(){
  cout << "Type the location of a board piece to select it" << endl;
  cout << "i.e. A1" << endl;
  // make sure that selected space isn't empty
  cin >> selection;
  cout << "You selected " << selection << endl;
  cout << "Confirm selection? y/n" << endl;
  cin >> selectConfirm;
  if (selectConfirm == 'n') {
    cout << "Type the location of a board piece to select it" << endl;
    cout << "i.e. A1" << endl;
  } else if (selectConfirm == 'y') {
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
    }

  } else
  {
    cout << "\033[1;31mInvalid input. Try again!\033[0m\n" << endl;
  }

  for (int i = 0; i < arrayLength; i++)
  {
    if (pieces[i].getYpos() == oldArrayY && pieces[i].getXpos() == oldArrayX)
    {
      cout << "Select the space to where you wish to move your selection" << endl;
      cin >> selection;
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
      pieces[i].setCoords(newArrayX,newArrayY);
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
  }else{
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
        pieces[i].setCoords(newArrayX,newArrayY);
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
        pieces[i].setCoords(newArrayX,newArrayY);
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

  for (int i = 0; i < arrayLength; i++)
  {
    randomInt = rand();
    randomInt = rand();
    if(pieces[i].getType() != 'K')
    {
      if (randomInt <= 1073741820)
      {
        pieces[i].setType('P');
      } else
      {
        pieces[i].setType('Q');
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

        for(int x = 0; x < 9; x++){
          for(int y = 0; y < 9; y++){
            if(Queen(c, x,y,false, true)){

              possibleMovesX.push_back(x);
              possibleMovesY.push_back(y);
            }
          }
        }

      }else if(pieces[c].getType() == 'K'){

        for(int x = 0; x < 9; x++){
          for(int y = 0; y < 9; y++){
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
      if (pieces[19].getXpos() == possibleMovesX[c] && pieces[19].getYpos() == possibleMovesY[c]){
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


bool checkMate(bool white){

  if(check(white)){
    for(int f = 0; f < arrayLength; f++){
      if(pieces[f].getWhite() == white){
        oldX = pieces[f].getXpos();
        oldY = pieces[f].getYpos();

        if(pieces[f].getType() == 'P'){

          for(int x = 0; x < 9; x++){
            for(int y = 0; y < 9; y++){
              if(Pawn(f, x,y,false, true)){
                Pawn(f, x,y,true, true);
                if(check(white) == false){
                  pieces[f].setCoords(oldX,oldY);
                  return false;
                }
                pieces[f].setCoords(oldX,oldY);
              }
            }
          }


        }else if(pieces[f].getType() == 'Q'){


          for(int x = 0; x < 9; x++){
            for(int y = 0; y < 9; y++){
              if(Queen(f, x,y,false, true)){
                Queen(f, x,y,true, true);
                if(check(white) == false){
                  pieces[f].setCoords(oldX,oldY);
                  return false;
                }
                pieces[f].setCoords(oldX,oldY);
              }
            }
          }

        }else if(pieces[f].getType() == 'K'){

          for(int x = 0; x < 9; x++){
            for(int y = 0; y < 9; y++){
              if(King(f, x,y,false, true)){
                King(f, x,y,true, true);
                if(check(white) == false){
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

  if (mode == "Random")
  {
    setRandomTypes();
  }
  while(playing)
  {
    //by zach greenberg
    display();
    //pyae sone
    userInput();

    //lucas zagal
    int i;
    for (int v = 0; v < arrayLength; v ++)
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
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You cant move into check. Try again!\033[0m\n" << endl;
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
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You cant move into check. Try again!\033[0m\n" << endl;
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
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You cant move into check. Try again!\033[0m\n" << endl;
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
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You cant move into check. Try again!\033[0m\n" << endl;
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
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You cant move into check. Try again!\033[0m\n" << endl;
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
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. You cant move into check. Try again!\033[0m\n" << endl;
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

