#include "Player.h"

Player::Player(int x, int y, int cellSize){
  posX = y;
  posY = x-1; // altrimenti viene schiacchiato fino al pavimento
  speed = 5;
  width = cellSize+10; // 40
  height = cellSize+30; // 60
  lives = 3; // numero di vite
  score = 0;
  gravity = 5-1;
  posXFinale=posX;
  posYFinale=posY;
  inAir = false;
}

void Player::fuoriMappa(int cellSize,int widthDisplay,int heightDisplay){
  if(posY>=1090){
    resetPlayer(cellSize,widthDisplay,heightDisplay);
    setLives();
  }
}

void Player::nelMuro(int cellSize,int widthDisplay,int heightDisplay,int heightMuro,int widthMuro,int yMuro,int xMuro,bool visible){
  if(visible){
    if(posX>=xMuro+2 && posX<xMuro+widthMuro)
    if((posY+height>=yMuro+2 && posY+height<=yMuro+heightMuro) || (posY>=yMuro+2 && posY<=yMuro+heightMuro) ){
      resetPlayer(cellSize,widthDisplay,heightDisplay);
      setLives();
    }
  }
}

bool Player::getInAir()const{
  return inAir;
}
void Player::setInAir(bool b){
  inAir = b;
}

void Player::setPosXFinale(int n){
  posXFinale = n;
}
void Player::setPosYFinale(int n){
  posYFinale = n;
}

void Player::setLives(){
  // cout<<"tolgo una vita"<<endl;
  lives --;
}

bool Player::verificaSconfitta()const{
  if(lives<=0)
    return true;
  return false;
}

int Player::getLives()const{
  return lives;
}

// RESETTO IL PLAYER NELLA POSIZIONE CHE VGLIO IO
void Player::resetPlayer(int cellSize,int widthDisplay,int heightDisplay){
  posX = widthDisplay-cellSize;
  posY = heightDisplay-cellSize*3-11;
  posXFinale = widthDisplay - cellSize;
  posYFinale = heightDisplay-cellSize*3-11;

}
void Player::setPosX(int n){
  posX = n;
}

void Player::setPosY(int n){
  posY = n;
}

void Player::setGravity(int n){
  gravity = n;
}

int Player::getGravity()const{
  return gravity;
}

int Player::getPosX()const{
  return posX;
}

int Player::getPosY()const{
  return posY;
}

int Player::getSpeed()const{
  return speed;
}

void Player::setSpeed(int n){
  speed = n;
}


// MI MUOVO A DESTRA DI UNA CERTA VELOCITÀ
// LA VELOCITÀ DIMINUISCE SE MI TROVO SU UNA SCALA
// PERCHÈ NON ESSENDOCI GRAVITÀ NON C'È ATTRITO
void Player::moveRight(bool collideScala){
  if(!collideScala)
    posXFinale = posX+speed+2;
  else
    posXFinale = posX+speed;
}

// MI MUOVO A DESTRA DI UNA CERTA VELOCITÀ
// LA VELOCITÀ DIMINUISCE SE MI TROVO SU UNA SCALA
// PERCHÈ NON ESSENDOCI GRAVITÀ NON C'È ATTRITO
void Player::moveLeft(bool collideScala){
  if(!collideScala)
    posXFinale = posX-speed-2;
  else
    posXFinale = posX-speed;
}

void Player::moveUp(){
  posYFinale = posY - speed;
}
void Player::moveDown(){
  posYFinale = posY + speed;
}

int Player::getWidth()const{
  return width;
}

int Player::getHeight()const{
  return height;
}


void Player::setScore(){
  score += 100;
}

int Player::getScore()const{
  return score;
}

int Player::getPosXFinale()const{
  return posXFinale;
}

int Player::getPosYFinale()const{
  return posYFinale;
}
