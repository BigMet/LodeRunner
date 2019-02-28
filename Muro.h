#ifndef MURO_H
#define MURO_H
#include<iostream>
using namespace std;
class Muro{

   private:
     int posX,posY;
     int width,height;
     bool visible;
     int time; // questo lo prendo da time di GameManager e lo uso in setVisibleTrue

   public:
      Muro(int x , int y,int cellSize);

      int getPosX()const;
      int getPosY()const;

      bool getVisible()const;
      void setVisible(bool b);
      void setVisibleTrue(int t);

      void setPosX(int num);
      void setPosY(int num);

      int getWidth()const;
      int getHeight()const;

};
#endif
