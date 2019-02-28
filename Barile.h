#ifndef BARILE_H
#define BARILE_H
#include "GenericObject.h"
class Barile : public GenericObject{

  private:
    bool visible,scendo;
    int posyTemp; // tengo traccia dell'ultimaY prima di scendere e incrementare la posY
    int id;


  public:
    Barile(int widthDisplay);


    bool getVisible()const;
    void setVisibleFalse();
    void setVisibleTrue();

    bool getDestra()const;
    bool getScendo()const;

    virtual void move(int cellSize,int widthDisplay, int heightDisplay);


};
#endif
