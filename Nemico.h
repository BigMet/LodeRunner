#ifndef NEMICO_H
#define NEMICO_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "GenericObject.h"
#include "Scala.h"
#include <vector>
using namespace std;

class Nemico : public GenericObject{

  private:
    int posXFinale,posYFinale;
    bool inAir,destra;

  public:
    Nemico(int x, int y,int cellSize);

    void setPosXFinale(int n);
    void setPosYFinale(int n);

    int getPosXFinale()const;
    int getPosYFinale()const;

    bool getInAir()const;
    void setInAir(bool b);

    void moveRight();
    void moveLeft();


    void moveUp();
    void moveDown();

    // bool getCollideLadder()const;
    // void setCollideLadder(bool b);
    //
    // bool getCollideWall()const;
    void setCollideWall(bool b);

    bool getDirezione()const;


    // void checkCollisionLadder(const vector<Scala*> & ladder);

    virtual void move(int cellSize,int widthDisplay, int heightDisplay,int xPlayer,int yPlayer);


};

#endif
