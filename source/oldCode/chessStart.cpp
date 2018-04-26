// by zach greenberg

#include <iostream>
#include <string>
#include <cstdio>
#include <array>

using namespace std;

string menuSelect;
string incorect;
bool incorectSelect = false;
bool startMenu = true;
bool instructionsMenu = false;
bool modeMenu = false;
string mode;

void gameStart(){

  cout<< "started";
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
    cout<<"                                                  "<< endl;
    cout<<"                      Random                      "<< endl;
    cout<<"                                                  "<< endl;
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
    cout<<"                                                  "<< endl;
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
      gameStart();
    }else if(menuSelect == "Instructions"|| menuSelect == "instructions"){
      instructionsMenu = true;
      instructions();
    } else if(menuSelect == "Modes"|| menuSelect == "modes"){
      modeMenu = true;
      modes();
    } else if(menuSelect == "Exit"|| menuSelect == "exit"){
      startMenu = false;
    } else {
    incorectSelect = true;
    }
  }
}

int main() {

  startPage();

  return 0;
}
