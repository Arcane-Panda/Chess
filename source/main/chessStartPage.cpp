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

int main() {


  while(startMenu){
    cout << "\e[8;24;50t"<< endl<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    //  system("clear");
    if(incorectSelect == false){
      incorect = "                                                  ";
    }else{
      incorect = " Please select a valid menu                       ";
    }

    //  cout<<"/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\/\\|/\\"<< endl;
    cout<<"                                                  "<< endl;
    cout<<"                 Welcome to Chess!                "<< endl;
    cout<<"                                                  "<< endl;
    cout<<"              Please select an option             "<< endl;
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
    cout<<incorect<< endl;
    incorectSelect = false;
    cout<<" Type the menu you wish to select: ", cin>> menuSelect, cout<< endl;
    //cout<<"\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/\\/|\\/"<< endl;


    if(menuSelect == "Start"|| menuSelect == "start"){
      cout<<"1";
    } else if(menuSelect == "Instuctions"|| menuSelect == "instuctions"){
      cout<<"2";
    } else if(menuSelect == "Modes"|| menuSelect == "modes"){
      cout<<"3";
    } else if(menuSelect == "Exit"|| menuSelect == "exit"){
      startMenu = false;
    } else {
    incorectSelect = true;
    }
  }
  return 0;
}
