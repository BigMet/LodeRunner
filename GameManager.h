#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <vector>
#include "GameField.h" // includo tutti gli altri oggetti
using namespace std;


class GameManager{

// per ora lo lascio protected
protected:
  ALLEGRO_DISPLAY* display;
  ALLEGRO_BITMAP* pgDxIdle = NULL;
  ALLEGRO_BITMAP* pgSxIdle = NULL;
  vector<ALLEGRO_BITMAP*> bitmapsPg;

  ALLEGRO_SAMPLE *Musica;
	ALLEGRO_SAMPLE_INSTANCE *MusicaMenu;

  ALLEGRO_TIMER* timer;
  ALLEGRO_TIMER* timer_time;

  ALLEGRO_MONITOR_INFO data; // RESIZE
  ALLEGRO_TRANSFORM t; // RESIZE
  ALLEGRO_KEYBOARD_STATE keystate;

  ALLEGRO_EVENT_QUEUE *event_queue ;
  ALLEGRO_FONT* fontLevel;

  GameField* field;

  int numLivello;
  int cellSize;


  const int FPS = 60;

public:
  GameManager();
  ~GameManager();


  // fnzione principale del gioco
  void Start();
  void caricaBmp();


  // Servono nella funzione di resize nel costruttore
  int monitor_w, monitor_h;
  int width, height;
  float resize_x , resize_y;


};
#endif
