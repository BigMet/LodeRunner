#include "Barile.h"


  Barile::Barile(int cellSize){
    posX = 40;
    posY = 168;
    speed = 3;
    visible = false;
    width = cellSize-30; 
    height = cellSize;
    destra = true;
    scendo = false;
    posyTemp = 0;

  }


  bool Barile::getDestra()const{
    return destra;
  }
  bool Barile::getScendo()const{
    return scendo;
  }


  bool Barile::getVisible()const{
    return visible;
  }
  void Barile::setVisibleFalse(){
    visible = false;
  }

  void Barile::setVisibleTrue(){
    visible = true;
    posX = 40;
    posY = 168;
  }

  // ridefinisco la funzione virtual
  void Barile::move(int cellSize,int widthDisplay, int heightDisplay){
    if(posX>=widthDisplay/2 && posY>=heightDisplay-(cellSize*3+height)){
      setVisibleFalse();
    }

    // arrivo al limite destro
    if(posX+speed>=widthDisplay-(width+20)){
     destra=false;
      scendo= true;
    }

    // arrivo al limite sinistro
    if(posX-speed<=0){
        destra=true;
        scendo= true;
    }

    // scendo
    if(scendo){
      if(posY<posyTemp+(cellSize*3)){
          posY+=speed;
        }
        else
        scendo=false;
    }

    // vado a destra
    if(posX+speed<widthDisplay-(width+20) && destra && !scendo){
      posX += speed;
      posyTemp = posY;
    }

      // vado a sinistra
      else if(posX-speed>=0 && !destra && !scendo){
          posX -= speed;
          posyTemp = posY;
        }

  }
