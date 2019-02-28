#include "Coin.h"

Coin::Coin(int x , int y,int cellSize){
  posX = y;
  posY = x;
  width=cellSize;
  height = cellSize;
  visibile = true;

}


  int Coin::getPosX()const{
    return posX;
  }
  int Coin::getPosY()const{
    return posY;
  }

  void Coin::setPosX(int num){
    posX = num;
  }
  void Coin::setPosY(int num){
    posY = num;
  }

  int Coin::getWidth()const{
    return width;
  }
  int Coin::getHeight()const{
    return height;
  }


  void Coin::setVisibleFalse(){
    visibile = false;
  }

  bool Coin::getVisible()const{
    return visibile;
  }
