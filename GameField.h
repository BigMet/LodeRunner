#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <iostream>
#include "Player.h"
#include "Nemico.h"
#include "Muro.h"
#include "Scala.h"
#include "Definizioni.h"
#include "Coin.h"
#include "GenericObject.h"
#include "Barile.h"
#include <vector>
#include <fstream> // serve per leggere la matrice da file
#include <cstdlib>

using namespace std;

class GameField{


private:
  int** Mappa;
  bool vittoria;

  Player* player;

  vector<Nemico*> enemy;
  vector<Muro*> walls;
  vector<Scala*> ladder;
  vector<Coin*> coins;
  vector<Barile*> barili;

public:
  GameField(int cellSize,int numLivello);
  ~GameField();

  Player* getPlayer();

  Muro* getMuro(int i);
  vector<Muro*> getVectorMuro();

  Scala* getScala(int i);
  vector<Scala*> getVectorScala();

  Coin* getCoin(int i);
  vector<Coin*> getVectorCoin();

  Barile* getBarile(int i);
  vector<Barile*> getVectorBarile();

  Nemico* getEnemy(int i);
  vector<Nemico*> getVectorEnemy();



  // DEL PLAYER
  bool checkCollision(bool premutoA, bool premutoD); // se collido con muri e monete
  bool checkCollisionLadder(); // se collido con scale
  bool checkCollisionWithEnemy(int cellSize,int widthDisplay,int heightDisplay); // se collido con entrambi i nemici

  void aggiungiBarile(int cellSize);

  bool canMoveOnLadder();

  void leggiGameField(int numLivello);
  void aggiungiElemento(int cellSize,int numLivello);
  void stampaGameField()const;

  bool getVittoria()const;
  int** restituisciMappa();

  // FUNZIONE DI UTILITY GENERICA
  void stampaArray()const;




};
#endif
