#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player{
  private:
    int posX,posY,width,height,posXFinale,posYFinale;
    int speed,lives,score,gravity;
    bool inAir;

  public:
    Player(int x,int y,int cellSize);


    bool getInAir()const;
    void setInAir(bool b);

    void setLives();
    int getLives()const;

    void resetPlayer(int cellSize,int widthDisplay,int heightDisplay);
    bool verificaSconfitta()const;

    void fuoriMappa(int cellSize,int widthDisplay,int heightDisplay);
    void nelMuro(int cellSize,int widthDisplay,int heightDisplay,int heightMuro,int widthMuro,int yMuro,int xMuro,bool visible);


    void setGravity(int n);
    int getGravity()const;

    void setPosX(int n);
    void setPosY(int n);

    void setPosXFinale(int n);
    void setPosYFinale(int n);

    int getPosX()const;
    int getPosY()const;

    int getSpeed()const;
    void setSpeed(int n);

    int getWidth()const;
    int getHeight()const;

    void moveRight(bool collideScala);
    void moveLeft(bool collideScala);

    void moveUp();
    void moveDown();

    void setScore();
    int getScore()const;

    int getPosXFinale()const;
    int getPosYFinale()const;
};

#endif
