//Lucas Zagal
#include <iostream>
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

int Piece::setCoords(int newX, int newY)
{
//  x = newX;
//  y = newY;
  xpos = newX;
  ypos = newY;

}


Piece pieces[20];

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

}
