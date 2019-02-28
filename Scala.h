#ifndef SCALA_H
#define SCALA_H
#include <iostream>
using namespace std;
class Scala{

   private:
     int posX,posY;
     int width,height;


   public:
      Scala(int x , int y,int cellSize);

      int getPosX()const;
      int getPosY()const;

      void setPosX(int num);
      void setPosY(int num);

      int getWidth()const;
      int getHeight()const;

};
#endif
