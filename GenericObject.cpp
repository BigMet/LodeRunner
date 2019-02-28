#include "GenericObject.h"

GenericObject::GenericObject(){
  posX = 0;
  posY = 0;
  width=0;
  height = 0;
  speed = 3;
  destra = false;
}


  int GenericObject::getPosX()const{
    return posX;
  }
  int GenericObject::getPosY()const{
    return posY;
  }

  void GenericObject::setPosX(int num){
    posX = num;
  }
  void GenericObject::setPosY(int num){
    posY = num;
  }

  int GenericObject::getWidth()const{
    return width;
  }
  int GenericObject::getHeight()const{
    return height;
  }

  int GenericObject::getSpeed()const{
    return speed;
  }
  void GenericObject::setSpeed(int n){
    speed = n;
  }
