#include "Muro.h"

Muro::Muro(int x , int y,int cellSize){
  posX = y;
  posY = x;
  width=cellSize;
  height = cellSize;
  visible = true;
  time = 0;
}


  int Muro::getPosX()const{
    return posX;
  }
  int Muro::getPosY()const{
    return posY;
  }

  void Muro::setPosX(int num){
    posX = num;
  }
  void Muro::setPosY(int num){
    posY = num;
  }

  int Muro::getWidth()const{
    return width;
  }
  int Muro::getHeight()const{
    return height;
  }

  bool Muro::getVisible()const{
    return visible;
  }
  void Muro::setVisible(bool b){
    visible = b;
  }

  // QUANDO VA A FALSE PRIMA DI SETTARE A TRUE LA VISIBILITÀ ASPETTA 2 SECONDI
  // MI SALVO LA IL TEMPO DI ENTRATA IN GAME MANAGER
  void Muro::setVisibleTrue(int t){
    if(visible){
      time = t;
    }

    // SETTO IL TEMPO DI RICOSTUZIONE DEL MURO DOPO ESSERE STATO ROTTO
    else  if(time - t>=4 && !visible){

        visible = true;
      }
  }
