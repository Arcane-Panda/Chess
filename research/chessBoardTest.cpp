// by zach greenberg 3/7/18
#include <iostream>
#include <string>
#include <cstdio>
#include <array>

using namespace std;

int p[5] = {0,2,7,5,3};
bool piece = true;
bool piece1 = true;

int main() {

  char name = 'h';




 for(int j=0;j < 8; j+=2){ // rows

  for( int l =0; l < 8;l+=2 ){ //Columns

     for(int i = 0; i < 5; i++){ // pieces

       if(p[i]/*.row*/ == j && p[i]/*.col*/ ==l && piece == true){

         printf("\x1b[37;40m %c \x1b[0m" ,name);//black
         piece = false;

       }
     }
     if(piece){

        printf("\x1b[37;40m   \x1b[0m" );// black

       }
    for(int i = 0; i < 5; i++){
     if(p[i]/*.row*/ == j && p[i]/*.col*/ ==l+1 && piece1 == true){

         printf("\x1b[37;42m %c \x1b[0m" , name);//green
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

     for(int i = 0; i < 5; i++){ // pieces

       if(p[i]/*.row*/ == j+1 && p[i]/*.col*/ == l && piece == true){

         printf("\x1b[37;42m %c \x1b[0m" , name);//green
         piece = false;

       }
     }

     if(piece){
       printf("\x1b[37;42m   \x1b[0m" );//green


       }

      for(int i = 0; i < 5; i++){
       if(p[i]/*.row*/ == j+1 && p[i]/*.col*/ == l+1 && piece1 == true){

         printf("\x1b[37;40m %c \x1b[0m" ,name);//black
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
