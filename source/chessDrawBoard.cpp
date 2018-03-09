// by zach greenberg 3/7/18
#include <iostream>
#include <string>//is this needed
#include <cstdio>
#include <array>//is this needed

using namespace std;

bool piece = true;
bool piece1 = true;
int arrayLength = sizeof(pieces)/sizeof(*pieces);








int main() {

  for(int j=0;j < 8; j+=2){ // rows

   for( int l =0; l < 8;l+=2 ){ //Columns

      for(int i = 0; i < arrayLength; i++){ // pieces

        if(pieces[i].getYpos() == j && pieces[i].getXpos() ==l && piece == true){

          printf("\x1b[37;40m %c \x1b[0m" ,pieces[i].getType());//black
          piece = false;

        }
      }
      if(piece){

         printf("\x1b[37;40m   \x1b[0m" );// black

        }
     for(int i = 0; i < arrayLength; i++){
      if(pieces[i].getYpos() == j && pieces[i].getXpos() ==l+1 && piece1 == true){

          printf("\x1b[37;42m %c \x1b[0m" , pieces[i].getType());//green
          piece1 = false;
       }
     }

     if(piece1){
         printf("\x1b[37;42m   \x1b[0m" );//green
     }
     piece = true;
     piece1 = true;
   }
   printf("\n");

   for( int l = 0; l < 8;l+=2 ){ // Columns

      for(int i = 0; i < arrayLength; i++){ // pieces

        if(pieces[i].getYpos() == j+1 && pieces[i].getXpos() == l && piece == true){

          printf("\x1b[37;42m %c \x1b[0m" , pieces[i].getType());//green
          piece = false;

        }
      }

      if(piece){
        printf("\x1b[37;42m   \x1b[0m" );//green


        }

       for(int i = 0; i < arrayLength; i++){
        if(pieces[i].getYpos() == j+1 && pieces[i].getXpos() == l+1 && piece1 == true){

          printf("\x1b[37;40m %c \x1b[0m" , pieces[i].getType());//black
          piece1 = false;
       }
      }

     if(piece1){


       printf("\x1b[37;40m   \x1b[0m" );// black
     }
     piece = true;
     piece1 = true;
   }
   printf("\n");
  }



  return 0;
}
