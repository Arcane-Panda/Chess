        if (pieces[i].getType() == 'P')
        {
          if(Pawn(i, newArrayX, newArrayY)){
            pieces[i].setCoords(newArrayX,newArrayY);
            passTurn;
            
          }
