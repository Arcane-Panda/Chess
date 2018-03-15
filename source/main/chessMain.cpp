//Lucas Zagal
// combined piece class and board renderer
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






Piece pieces[20];



bool piece = true;
bool piece1 = true;






 int main()
{
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


  pieces[0] = BP1;
  pieces[1] = BP2;
  pieces[2] = BP3;
  pieces[3] = BP4;
  pieces[4] = BP5;
  pieces[5] = BP6;
  pieces[6] = BP7;
  pieces[7] = BP8;

  pieces[8] = BQ;
  pieces[9] = BK;

  pieces[10] = WP1;
  pieces[11] = WP2;
  pieces[12] = WP3;
  pieces[13] = WP4;
  pieces[14] = WP5;
  pieces[15] = WP6;
  pieces[16] = WP7;
  pieces[17] = WP8;

  pieces[18] = WQ;
  pieces[19] = WK;
  string selection = "";
  char selectConfirm;
int pieceConfirm;

string selConfOne;
string selConfTwo;
int arrayX;
int arrayY;
int arrayLength = sizeof(pieces)/sizeof(*pieces);
  while(1==1)
  {
  //by zach greenberg
  //system("clear");



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

//pyae sone


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
          arrayX = 0;
        } else if (selConfOne == "B" || selConfOne == "b") {
          arrayX = 1;
        } else if (selConfOne == "C" || selConfOne == "c") {
          arrayX = 2;
        } else if (selConfOne == "D" || selConfOne == "d") {
          arrayX = 3;
        } else if (selConfOne == "E" || selConfOne == "e") {
          arrayX = 4;
        } else if (selConfOne == "F" || selConfOne == "f") {
          arrayX = 5;
        } else if (selConfOne == "G" || selConfOne == "g") {
          arrayX = 6;
        } else if (selConfOne == "H" || selConfOne == "h") {
          arrayX = 7;
        }
        if (selConfTwo == "1") {
          arrayY = 7;
        } else if (selConfTwo == "2") {
          arrayY = 6;
        } else if (selConfTwo == "3") {
          arrayY = 5;
        } else if (selConfTwo == "4") {
          arrayY = 4;
        } else if (selConfTwo == "5") {
          arrayY = 3;
        } else if (selConfTwo == "6") {
          arrayY = 2;
        } else if (selConfTwo == "7") {
          arrayY = 1;
        } else if (selConfTwo == "8") {
          arrayY = 0;
        }

    } else
    {
      cout << "\033[1;31mInvalid input. Try again!\033[0m\n" << endl;
    }


    for (int i = 0; i < arrayLength; i++)
    {
      if (pieces[i].getYpos() == arrayY && pieces[i].getXpos() == arrayX)
      {
        cout << "Select the space to where you wish to move your selection" << endl;
        cin >> selection;
        selConfOne = selection.substr(0,1);
        selConfTwo = selection.substr(1,1);
      //  cout << "You wanna move it to " << selConfOne << selConfTwo << endl;
        if (selConfOne == "A" || selConfOne == "a") {
          arrayX = 0;
        } else if (selConfOne == "B" || selConfOne == "b") {
          arrayX = 1;
        } else if (selConfOne == "C" || selConfOne == "c") {
          arrayX = 2;
        } else if (selConfOne == "D" || selConfOne == "d") {
          arrayX = 3;
        } else if (selConfOne == "E" || selConfOne == "e") {
          arrayX = 4;
        } else if (selConfOne == "F" || selConfOne == "f") {
          arrayX = 5;
        } else if (selConfOne == "G" || selConfOne == "g") {
          arrayX = 6;
        } else if (selConfOne == "H" || selConfOne == "h") {
          arrayX = 7;
        }
        if (selConfTwo == "1") {
          arrayY = 7;
        } else if (selConfTwo == "2") {
          arrayY = 6;
        } else if (selConfTwo == "3") {
          arrayY = 5;
        } else if (selConfTwo == "4") {
          arrayY = 4;
        } else if (selConfTwo == "5") {
          arrayY = 3;
        } else if (selConfTwo == "6") {
          arrayY = 2;
        } else if (selConfTwo == "7") {
          arrayY = 1;
        } else if (selConfTwo == "8") {
          arrayY = 0;
        }
        //lucas zagal
        //Check moves here//
        if (pieces[i].getType() == 'P')
        {
          if(pieces[i].getWhite() == true)
          {

            if(arrayY - pieces[i].getYpos() == -2 && pieces[i].getFirst() == true && arrayX == pieces[i].getXpos())
            {
              pieces[i].setCoords(arrayX,arrayY);
            } else if(arrayY - pieces[i].getYpos() == -1 && arrayX == pieces[i].getXpos())
            {
              pieces[i].setCoords(arrayX,arrayY);
            } else
            {
              cout << endl << endl << endl << endl<< endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
            }
          } else
          {
            if(arrayY - pieces[i].getYpos() == 2 && pieces[i].getFirst() == true && arrayX == pieces[i].getXpos())
            {
              pieces[i].setCoords(arrayX,arrayY);
            } else if(arrayY - pieces[i].getYpos() == 1 && arrayX == pieces[i].getXpos())
            {
              pieces[i].setCoords(arrayX,arrayY);
            } else
            {
              cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
            }
          }
        } else if(pieces[i].getType() == 'Q')
        {
          pieces[i].setCoords(arrayX,arrayY);
        } else if(pieces[i].getType() == 'K')
        {

          if(arrayY- pieces[i].getYpos() == -1 && arrayX == pieces[i].getXpos())
          {
            //move up
            pieces[i].setCoords(arrayX,arrayY);
          } else if(arrayY- pieces[i].getYpos() == -1 && arrayX - pieces[i].getXpos() == 1)
          {
            //move right up
            pieces[i].setCoords(arrayX,arrayY);
          } else if(arrayY- pieces[i].getYpos() == -1 && arrayX - pieces[i].getXpos() == -1)
          {
            //move left up
            pieces[i].setCoords(arrayX,arrayY);
          } else if(arrayY == pieces[i].getYpos()  && arrayX - pieces[i].getXpos() == -1)
          {
            //move left
            pieces[i].setCoords(arrayX,arrayY);
          }else if(arrayY == pieces[i].getYpos()  && arrayX - pieces[i].getXpos() == 1)
          {
            //move right
            pieces[i].setCoords(arrayX,arrayY);
          } else if(arrayY - pieces[i].getYpos() == 1 && arrayX - pieces[i].getXpos() == -1)
          {
            //move down left
            pieces[i].setCoords(arrayX,arrayY);
          } else if(arrayY - pieces[i].getYpos() == 1 && arrayX - pieces[i].getXpos() == 1)
          {
            //move down right
            pieces[i].setCoords(arrayX,arrayY);
          } else if(arrayY - pieces[i].getYpos() == 1 && arrayX == pieces[i].getXpos())
          {
            //move down
            pieces[i].setCoords(arrayX,arrayY);
          } else
          {
            cout << endl << endl << endl << endl << "\033[1;31mInvalid move. Try again!\033[0m\n" << endl;
          }
          }
        }
      }
    }

return 0;
}
