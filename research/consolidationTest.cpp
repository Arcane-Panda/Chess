// combined piece class and board renderer


//Lucas Zagal

#include <iostream>
#include <cstdio>
using namespace std;

class Piece
{
public:
  Piece(){};
  Piece(char typ, int x, int y, bool isWhite) ;
  char getType(void);
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

Piece WQ('Q',4,7,true);

Piece WK('K',3,7,true);

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
      // cout << "You selected " << selConfOne << selConfTwo << endl;
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

void checkMoves()
{
  //lucas zagal
  //Check moves here//
  for (int i = 0; i < arrayLength; i ++)
  {
    if (pieces[i].getXpos() == newArrayX && pieces[i].getYpos() == newArrayY)
  if (pieces[i].getType() == 'P')
  {
    if(pieces[i].getWhite() == true)
    {

      if(newArrayY - pieces[i].getYpos() == -2 && pieces[i].getFirst() == true && newArrayX == pieces[i].getXpos())
      {
        pieces[i].setCoords(newArrayX,newArrayY);
      } else if(newArrayY - pieces[i].getYpos() == -1 && newArrayX == pieces[i].getXpos())
      {
        pieces[i].setCoords(newArrayX,newArrayY);
      } else
      {
        cout << endl << endl << endl << endl<< endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
      }
    } else
    {
      if(newArrayY - pieces[i].getYpos() == 2 && pieces[i].getFirst() == true && newArrayX == pieces[i].getXpos())
      {
        pieces[i].setCoords(newArrayX,newArrayY);
      } else if(newArrayY - pieces[i].getYpos() == 1 && newArrayX == pieces[i].getXpos())
      {
        pieces[i].setCoords(newArrayX,newArrayY);
      } else
      {
        cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
      }
    }
  } else if(pieces[i].getType() == 'Q')
  {
    pieces[i].setCoords(newArrayX,newArrayY);
  } else if(pieces[i].getType() == 'K')
  {

    if(newArrayY- pieces[i].getYpos() == -1 && newArrayX == pieces[i].getXpos())
    {
      //move up
      pieces[i].setCoords(newArrayX,newArrayY);
    } else if(newArrayY- pieces[i].getYpos() == -1 && newArrayX - pieces[i].getXpos() == 1)
    {
      //move right up
      pieces[i].setCoords(newArrayX,newArrayY);
    } else if(newArrayY- pieces[i].getYpos() == -1 && newArrayX - pieces[i].getXpos() == -1)
    {
      //move left up
      pieces[i].setCoords(newArrayX,newArrayY);
    } else if(newArrayY == pieces[i].getYpos()  && newArrayX - pieces[i].getXpos() == -1)
    {
      //move left
      pieces[i].setCoords(newArrayX,newArrayY);
    }else if(newArrayY == pieces[i].getYpos()  && newArrayX - pieces[i].getXpos() == 1)
    {
      //move right
      pieces[i].setCoords(newArrayX,newArrayY);
    } else if(newArrayY - pieces[i].getYpos() == 1 && newArrayX - pieces[i].getXpos() == -1)
    {
      //move down left
      pieces[i].setCoords(newArrayX,newArrayY);
    } else if(newArrayY - pieces[i].getYpos() == 1 && newArrayX - pieces[i].getXpos() == 1)
    {
      //move down right
      pieces[i].setCoords(newArrayX,newArrayY);
    } else if(newArrayY - pieces[i].getYpos() == 1 && newArrayX == pieces[i].getXpos())
    {
      //move down
      pieces[i].setCoords(newArrayX,newArrayY);
    } else
    {
      cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
    }
    }
  }
}

 int main()
{



  while(1==1)
  {
  //by zach greenberg
  //system("clear");
  display();

//pyae sone

  userInput();



      checkMoves();

  }
}
