#include "GameField.h"

GameField::GameField(int cellSize,int numLivello){
  vittoria = false;
    Mappa = new int* [righe];
    for(int i=0;i<righe;i++)
      Mappa[i] = new int [colonne];

      leggiGameField(numLivello);


      aggiungiElemento(cellSize,numLivello);

}

bool GameField::getVittoria()const{
  if(player->getScore()/100 == coins.size()){
    return true;
  }
  return false;
}


// CERCO LA COLLISIONE CON TUTTI I TIPI DI NEMICI
bool GameField::checkCollisionWithEnemy(int cellSize,int widthDisplay,int heightDisplay){

  // NEMICO BARILE / FIAMMA
  for(int i = 0;i<barili.size();i++){
    if(barili[i]->getVisible()/*==true*/){
      if(player->getPosX() + player->getWidth()+ 30 >= barili[i]->getPosX() && barili[i]->getPosX() + barili[i]->getWidth()+30 >= player->getPosX()
          && player->getPosY()
          + player->getHeight() >= barili[i]->getPosY() && barili[i]->getPosY() + barili[i]->getHeight() >= player->getPosY()){

            player->resetPlayer(cellSize,widthDisplay,heightDisplay);

            player->setLives();
          return true;
        }

      }
  }

// NEMICO NORMALE
  for(int i = 0;i<enemy.size();i++){
      if(player->getPosX() + player->getWidth() >= enemy[i]->getPosX() && enemy[i]->getPosX() + enemy[i]->getWidth()+30 >= player->getPosX()
          && player->getPosY()
          + player->getHeight() >= enemy[i]->getPosY() && enemy[i]->getPosY() + enemy[i]->getHeight() >= player->getPosY()){

            player->resetPlayer(cellSize,widthDisplay,heightDisplay);

            player->setLives();

          return true;
        }
  }
  return false;
}

// VEDO SE COLLIDO CON LE MONETE E IN TAL CASO LE PRENDO INCREMENTO IL PUNTEGGIO E LE TOLGO
// NELCASO DEI MURI VEDO SE POSSO SPOSTARMI
bool GameField::checkCollision(bool premutoA, bool premutoD){

  // ********** COLLISIONE CON COIN ****************//
  for(int i=0;i<coins.size();i++){
    if(player->getPosX() + player->getWidth() >= coins[i]->getPosX() && coins[i]->getPosX() + coins[i]->getWidth() >= player->getPosX()
        && player->getPosY()
        + player->getHeight() >= coins[i]->getPosY()+10 && coins[i]->getPosY() + coins[i]->getHeight()+10 >= player->getPosY() ){ // +10 perchè compenso quanto ho tolto da cellSize

          if(coins[i]->getVisible()!=false){
            coins[i]->setVisibleFalse();
            player->setScore();

          }

      }
  }
  // **********  FINE COLLISIONE CON COIN ****************//




  // ********** COLLISIONE CON WALLS ****************//
bool collide = false;
  for(int i = 0;i<walls.size();i++){
    if(player->getPosXFinale() + player->getWidth() >= walls[i]->getPosX() && walls[i]->getPosX() + walls[i]->getWidth() >= player->getPosXFinale()
        && player->getPosYFinale()
        + player->getHeight() >= walls[i]->getPosY() && walls[i]->getPosY() + walls[i]->getHeight() >= player->getPosYFinale()){
          // SE IL MURO È VISIBILE COLLIDO E IN TAL CASO SE PREMO A O D POSSO ROMPERLO
          if(walls[i]->getVisible()){
            collide = true;
            player->setInAir(false);

            player->setPosYFinale(player->getPosY());
            player->setPosXFinale(player->getPosX());
        }

        // VEDO SE POSSO SPACCARE IL MURO A SINISTRA
        if(premutoA){
          walls[i-1]->setVisible(false);
        }

        // VEDO SE POSSO SPACCARE IL MURO A DESTRA
        if(premutoD){
          walls[i+1]->setVisible(false);
        }


    } // fine if collisione

  } // fine for

  if(!collide){
    player->setInAir(true);
    player->setPosX(player->getPosXFinale());
    player->setPosY(player->getPosYFinale());
  }

return collide;

} // fine funzione checkCollision


// VEDO SE COLLIDO CON LA SCALA
bool GameField::checkCollisionLadder(){
  for(int i =0; i<ladder.size();i++){

    if(player->getPosX() + player->getWidth() >= ladder[i]->getPosX() && ladder[i]->getPosX() + ladder[i]->getWidth() >= player->getPosX()
        && player->getPosY()
        + player->getHeight() >= ladder[i]->getPosY() && ladder[i]->getPosY() + ladder[i]->getHeight() >= player->getPosY()){

        return true;
      }
  }
  return false;
}


bool GameField::canMoveOnLadder(){
  for(int i =0; i<ladder.size();i++){

    if(player->getPosX() + player->getWidth() >= ladder[i]->getPosX() && ladder[i]->getPosX() + ladder[i]->getWidth() >= player->getPosX()
        && player->getPosY()
        + player->getHeight() >= ladder[i]->getPosY() && ladder[i]->getPosY() + ladder[i]->getHeight() >= player->getPosY()){

        if(player->getPosX()>=ladder[i]->getPosX() &&  player->getPosX()+player->getWidth()<=ladder[i]->getPosX()+ladder[i]->getWidth())

        return true;

      }
    }
  return false;
  }


// FUNZIONE DI UTILITY PER STAMPARE ILCONENTUNO DEGLI ARRAY ECC
// void GameField::stampaArray()const{
//
// }


// RIEMPIE GLI ARRAY IN BASSE ALLA MAPPA LETTA NELLA FUNZIONE leggiGameField();
void GameField::aggiungiElemento(int cellSize,int numLivello){
  int conta1 = 0;

  // AGGIUNGO I BARILI
  if(numLivello==1){
      barili.push_back(new Barile(cellSize));
      barili.push_back(new Barile(cellSize));
      barili.push_back(new Barile(cellSize));
      barili.push_back(new Barile(cellSize));
      barili.push_back(new Barile(cellSize));
      barili.push_back(new Barile(cellSize));
  }

    for(int i =0;i<righe;i++){
      for(int j =0;j<colonne;j++){

        if(Mappa[i][j]==1 && conta1==0){ // player
          player = new Player(i*cellSize-10,j*cellSize-10,cellSize-30);
          conta1++;
        }

        if(Mappa[i][j] == 2) // nemico
          enemy.push_back(new Nemico(i*cellSize,j*cellSize,cellSize-30));

        if(Mappa[i][j] == 4) // scala
          ladder.push_back(new Scala(i*cellSize,j*cellSize,cellSize));

        if(Mappa[i][j]==6) // muro
          walls.push_back(new Muro(i*cellSize,j*cellSize,cellSize));

        if(Mappa[i][j]==7) // aggiungo i coins
          coins.push_back(new Coin(i*cellSize,j*cellSize,cellSize-30));

    }
  }
}




// LEGGE IL LIVELLO E CREA GLI OGGETTI DEL GIOCO NEGLI ARRAY
void GameField::leggiGameField(int numLivello){
if(numLivello==0){
  ifstream apriFile("livello1.txt");
    while(!apriFile.eof()){
      for(int riga=0;riga<righe;riga++){
        for(int colonna=0;colonna<colonne;colonna++){
          apriFile >> Mappa[riga][colonna];

        }
      }
    }
    apriFile.close();
  }
  else{
    ifstream apriFile("levelBarile.txt");
      while(!apriFile.eof()){
        for(int riga=0;riga<righe;riga++){
          for(int colonna=0;colonna<colonne;colonna++){
            apriFile >> Mappa[riga][colonna];

          }
        }
      }
      apriFile.close();
  }
}


// ***********  FUNZIONI GET ************//

Player* GameField::getPlayer(){
  return player;
}

Muro* GameField::getMuro(int i){
  return walls[i];
}

vector<Muro*> GameField::getVectorMuro(){
  return walls;
}

Scala* GameField::getScala(int i){
  return ladder[i];
}
vector<Scala*> GameField::getVectorScala(){
  return ladder;
}


Coin* GameField::getCoin(int i){
  return coins[i];
}
vector<Coin*> GameField::getVectorCoin(){
  return coins;
}


Barile* GameField::getBarile(int i){
  return barili[i];
}
vector<Barile*>GameField::getVectorBarile(){
  return barili;
}


Nemico* GameField::getEnemy(int i){
  return enemy[i];
}
vector<Nemico*>GameField::getVectorEnemy(){
  return enemy;
}

// ************* FINE FUNZIONI GET *************//


GameField::~GameField(){
  for(int i =0;i<righe;i++)
    delete [] Mappa[i];
  delete [] Mappa;

    delete player;

  for(int i =0;i<enemy.size();i++)
    delete enemy [i];

  for(int i =0;i<walls.size();i++)
    delete walls [i];

  for(int i =0;i<ladder.size();i++)
    delete ladder[i];

  for(int i =0;i<coins.size();i++)
    delete coins[i];

  for(int i =0;i<barili.size();i++)
    delete barili[i];

}

void GameField::aggiungiBarile(int cellSize){
  barili.push_back(new Barile(cellSize));
}


void GameField::stampaGameField()const{
  for(int i =0;i<righe;i++){
    for(int j=0;j<colonne;j++){
      cout<<Mappa[i][j]<<" ";
    }
    cout<<endl;
  }
}
