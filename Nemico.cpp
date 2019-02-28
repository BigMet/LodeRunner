#include "Nemico.h"

  Nemico::Nemico(int x, int y,int cellSize){
    posX = y;
    posY = x-1;
    width = cellSize;
    height = cellSize+20;
    posXFinale=posX;
    posYFinale=posY;
    inAir = false;
    destra = false;
    // srand(time(NULL)); // avvio srand
  }




  // destra 0 , sinistra 1, sopra 2 , sotto 3
  // i due valori bool non mi dovrebbero servire perchè li ho come campi privati
  void Nemico::move(int cellSize,int widthDisplay, int heightDisplay,int xPlayer,int yPlayer){


      if(destra ){
        moveRight();
      }

      else if(!destra){
        moveLeft();
      }


        // se arrivo al margine destro || il player si trova più a sinistra deln
      if(posX+width+speed-1>=widthDisplay || ( xPlayer<= posX && (posY >= yPlayer-10 && posY <=yPlayer+cellSize))){
        destra = false;
      }

      else if(posX-speed+1<=0 || ( xPlayer>= posX && (posY >= yPlayer-10 && posY <=yPlayer+cellSize))){
        destra = true;
      }

  }




  bool Nemico::getDirezione()const{
    return destra;
  }

  void Nemico::moveRight(){
    posX = posX+speed-1;

  }
  void Nemico::moveLeft(){
    posX = posX-speed+1;
  }

  void Nemico::moveUp(){
    posYFinale = posY - speed;
  }
  void Nemico::moveDown(){
    posYFinale = posY + speed;
  }


  bool Nemico::getInAir()const{
    return inAir;
  }
  void Nemico::setInAir(bool b){
    inAir = b;
  }

  int Nemico::getPosXFinale()const{
    return posXFinale;
  }

  int Nemico::getPosYFinale()const{
    return posYFinale;
  }


  void Nemico::setPosXFinale(int n){
    posXFinale = n;
  }
  void Nemico::setPosYFinale(int n){
    posYFinale = n;
  }
