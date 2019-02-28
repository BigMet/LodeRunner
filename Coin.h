#ifndef COIN_H
#define COIN_H

#include<iostream>
using namespace std;
class Coin{

   private:
     int posX,posY;
     int width,height;
     bool visibile; // se la prendo diventa false
     
   public:
      Coin(int x , int y,int cellSize);

      int getPosX()const;
      int getPosY()const;

      void setPosX(int num);
      void setPosY(int num);

      int getWidth()const;
      int getHeight()const;

      void setVisibleFalse();
      bool getVisible()const;

};
#endif
