#ifndef GENERICOBJECT_H
#define GENERICOBJECT_H
#include <iostream>
// #include "GameField.h"
// #include "Barile.h"
using namespace std;

class GenericObject{

protected:
  int posX,posY;
  int width,height;
  int speed;
  bool destra;

public:
   GenericObject();

   int getPosX()const;
   int getPosY()const;

   void setPosX(int num);
   void setPosY(int num);

   int getWidth()const;
   int getHeight()const;

   int getSpeed()const;
   void setSpeed(int n);

   // QUESTA FUNZIONE HA IMPLEMENTAZIONI DIVERSE IN BARILE E IN NEMICO
   virtual void move(int cellSize,int widthDisplay, int heightDisplay) {}





};
#endif
