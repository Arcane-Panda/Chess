//Lucas Zagal
#include <iostream>
#include <cstdio>
using namespace std;

class Piece{
public:
  Piece(){};
  Piece(char typ, int x, int y, bool isWhite) ;
  char getType(void);
  int getXpos(void);
  int getYpos(void);
  bool getWhite(void);
  int setCoords(int newX, int newY);
private:
  int xpos, ypos;
  char type;
  bool white;

};

Piece::Piece(char typ, int x, int y, bool isWhite)
{
  type = typ;
  xpos = x;
  ypos = y;
  white = isWhite;
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

int Piece::setCoords(int newX, int newY){

  xpos = newX;
  ypos = newY;

}


Piece pieces[20];



bool piece = true;
bool piece1 = true;



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



 int main()
{

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




//by zach greenberg

int arrayLength = sizeof(pieces)/sizeof(*pieces);


cout<< endl << endl<< "    A  B  C  D  E  F  G  H " << endl;
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

//system("clear"); to clear the screen

return 0;
}
