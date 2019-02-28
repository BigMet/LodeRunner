#include "Scala.h"

Scala::Scala(int x , int y,int cellSize){
  posX = y;
  posY = x-3;
  width=cellSize;
  height = cellSize;
}


  int Scala::getPosX()const{
    return posX;
  }
  int Scala::getPosY()const{
    return posY;
  }

  void Scala::setPosX(int num){
    posX = num;
  }
  void Scala::setPosY(int num){
    posY = num;
  }

  int Scala::getWidth()const{
    return width;
  }
  int Scala::getHeight()const{
    return height;
  }
