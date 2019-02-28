#include "GameManager.h"


GameManager::GameManager(){
  al_init();
  al_init_image_addon();
  al_init_font_addon();
  al_init_ttf_addon();


  /******** resize ************/
  al_get_monitor_info(al_get_num_video_adapters() - 1, & data);
  monitor_w = data.x2 - data.x1; // 1920
  monitor_h = data.y2 - data.y1; // 1080

  width = 1920; // 32 * 40
  height = 1080; // 18 * 40
  resize_x = monitor_w / static_cast < float > (width);
  resize_y = monitor_h / static_cast < float > (height);

  al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
  display = al_create_display(monitor_w, monitor_h);
  al_identity_transform( & t);
  al_scale_transform( & t, resize_x, resize_y);
  al_use_transform( & t);
  /********fine resize********/

  // ho la dimensione della mia cella / bitmap
  cellSize = height / righe;


  numLivello = 0;



  //tastiera
  al_init_primitives_addon();
  al_install_keyboard();

  //-----audio-----------
  al_install_audio();
  al_init_acodec_addon();
  al_reserve_samples(1);
  Musica = al_load_sample("./Images/stranger8bit.wav");
  MusicaMenu = al_create_sample_instance(Musica);

  //-----mouse event---------
  al_install_mouse();

  // creo il timer
  timer = al_create_timer(1.0/FPS);

  timer_time = al_create_timer(1.0);


  fontLevel = al_load_font("pathFont/quickstyle-Regular.ttf", 30, 0);



  /****** coda di eventi e registratore di eventi *******/
  event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue,al_get_timer_event_source(timer));
  al_register_event_source(event_queue,al_get_timer_event_source(timer_time));


}




GameManager::~GameManager(){
  al_destroy_timer(timer);
  al_destroy_timer(timer_time);
  al_destroy_font(fontLevel);
  al_destroy_event_queue(event_queue);
  al_destroy_sample(Musica);
  al_destroy_sample_instance(MusicaMenu);


  al_destroy_bitmap(pgDxIdle);
  al_destroy_bitmap(pgSxIdle);
  al_destroy_display(display);
  }



// UTILE A CARICARE TUTTE LE BITMAP CHE UTILIZZO NEL GIOCO
void GameManager::caricaBmp(){
  pgDxIdle = al_load_bitmap("./Images/Resize/Dx/walkDx0.png");
  pgSxIdle = al_load_bitmap("./Images/Resize/Sx/walkSx0.png");


  for(int i =0;i<46;i++)
    bitmapsPg.push_back(NULL);

  // ******** DA 0 A 5 PLAYER A DESTRA *****************//
  bitmapsPg[0] = al_load_bitmap("./Images/Resize/Dx/walkDx1.png");
  bitmapsPg[1] = al_load_bitmap("./Images/Resize/Dx/walkDx2.png");
  bitmapsPg[2] = al_load_bitmap("./Images/Resize/Dx/walkDx3.png");
  bitmapsPg[3] = al_load_bitmap("./Images/Resize/Dx/walkDx4.png");
  bitmapsPg[4] = al_load_bitmap("./Images/Resize/Dx/walkDx5.png");
  bitmapsPg[5] = al_load_bitmap("./Images/Resize/Dx/walkDx6.png");


  // *********** DA 5 A 11 PLAYER A SINISTRA ***************//
  bitmapsPg[6] = al_load_bitmap("./Images/Resize/Sx/walkSx1.png");
  bitmapsPg[7] = al_load_bitmap("./Images/Resize/Sx/walkSx2.png");
  bitmapsPg[8] = al_load_bitmap("./Images/Resize/Sx/walkSx3.png");
  bitmapsPg[9] = al_load_bitmap("./Images/Resize/Sx/walkSx4.png");
  bitmapsPg[10] = al_load_bitmap("./Images/Resize/Sx/walkSx5.png");
  bitmapsPg[11] = al_load_bitmap("./Images/Resize/Sx/walkSx6.png");

  // *********** ALTRE IMMAGINI ***************//
  bitmapsPg[12] = al_load_bitmap("./Images/muro.png");
  bitmapsPg[13] = al_load_bitmap("./Images/scala.png");
  bitmapsPg[14] = al_load_bitmap("./Images/black_hole.png");
  bitmapsPg[15] = al_load_bitmap("./Images/coin.png");

  bitmapsPg[16] = al_load_bitmap("./Images/sfondoMenu.png");
  bitmapsPg[17] = al_load_bitmap("./Images/scrittaEnter.png");

  // ********** MOVIMENTO PLAYER SCALA  *******************//
  bitmapsPg[18] = al_load_bitmap("./Images/fermoBassoScala.png");
  bitmapsPg[19] = al_load_bitmap("./Images/fermoAltoScala.png");


// ********** MOVIMENTO FIAMMA DESTRA *******************//
  bitmapsPg[20] = al_load_bitmap("./Images/fiamma0.png");
  bitmapsPg[21] = al_load_bitmap("./Images/fiamma1.png");
  bitmapsPg[22] = al_load_bitmap("./Images/fiamma2.png");
  bitmapsPg[23] = al_load_bitmap("./Images/fiamma3.png");
  bitmapsPg[24] = al_load_bitmap("./Images/fiamma4.png");
  bitmapsPg[25] = al_load_bitmap("./Images/fiamma5.png");

  bitmapsPg[26] = al_load_bitmap("./Images/siSound.png");
  bitmapsPg[27] = al_load_bitmap("./Images/noSound.png");

  bitmapsPg[28] = al_load_bitmap("./Images/youLose.png");
  bitmapsPg[29] = al_load_bitmap("./Images/youWin.png");

  bitmapsPg[30] = al_load_bitmap("./Images/ghostSx.png");
  bitmapsPg[31] = al_load_bitmap("./Images/ghostDx.png");


// ********** MOVIMENTO FIAMMA SINISTRA *****************//
  bitmapsPg[32] = al_load_bitmap("./Images/fiamma0Sx.png");
  bitmapsPg[33] = al_load_bitmap("./Images/fiamma1Sx.png");
  bitmapsPg[34] = al_load_bitmap("./Images/fiamma2Sx.png");
  bitmapsPg[35] = al_load_bitmap("./Images/fiamma3Sx.png");
  bitmapsPg[36] = al_load_bitmap("./Images/fiamma4Sx.png");
  bitmapsPg[37] = al_load_bitmap("./Images/fiamma5Sx.png");


// ********** MOVIMENTO FIAMMA SOTTO *******************//
  bitmapsPg[38] = al_load_bitmap("./Images/fiamma0Dw.png");
  bitmapsPg[39] = al_load_bitmap("./Images/fiamma1Dw.png");
  bitmapsPg[40] = al_load_bitmap("./Images/fiamma2Dw.png");
  bitmapsPg[41] = al_load_bitmap("./Images/fiamma3Dw.png");
  bitmapsPg[42] = al_load_bitmap("./Images/fiamma4Dw.png");
  bitmapsPg[43] = al_load_bitmap("./Images/fiamma5Dw.png");


  // SFONDO OPZIONI
  bitmapsPg[44] = al_load_bitmap("./Images/sfondoInfo.png");
  bitmapsPg[45] = al_load_bitmap("./Images/info.png");

}




void GameManager::Start(){

// ************************************** start

  int cont = 0;
  field = new GameField(cellSize,numLivello);


  // inizializzo tutto cioò che mi serve nel while(true)
  bool destra = false, sinistra = false, sotto = false, sopra = false, shift = false;

  bool rompiSinistra = false, rompiDestra = false;

  // destra 0 , sinistra 1, sopra 2 , sotto 3
  // salvo qual'è stato l'ultimo spostamento se destra sinistra ecc
  bool ultimoPremuto = 0;

  //array per gli eventi della tastiera: a per muroSx d per muroDx  e tasti di direzione per muoversi
  bool key[7] = { false,false,false,false,false,false,false };
  bool redraw = true;
  bool gameover = false;
  bool perdita = false;  // sconfitta
  bool vittoria = false;
  bool esc=false;
  int boostSpeed = field->getPlayer()->getSpeed()+4;
  int speed  = field->getPlayer()->getSpeed();


  // TEMPO A DISPOSIZIONE PER LA PARTITA
  int time = 90;








  // carico le bitmap prima di iniziare la partita evitando il caricamento delle
  // stesse in fase di start
  caricaBmp();

  bool fine=false;
  al_draw_bitmap(bitmapsPg[16],0,0,0); // sfondo menu
  al_draw_bitmap(bitmapsPg[17],1125,650,0); // scrittaEnter
  al_draw_bitmap(bitmapsPg[27],width/1.20,height/1.20,0); // noSound
  al_draw_bitmap(bitmapsPg[45],1746,910,0); // info

  al_flip_display();
  al_clear_to_color(al_map_rgb(0, 0, 0));

  bool musica = true;
  bool start = false;

  // ******** MUSICA ***** *******//
  al_set_sample_instance_playmode(MusicaMenu, ALLEGRO_PLAYMODE_LOOP);
  al_attach_sample_instance_to_mixer(MusicaMenu, al_get_default_mixer());
  al_play_sample_instance(MusicaMenu);
  // ************ FINE ***********//


  while(!fine && !gameover){

// rimango nel menù del gioco finche non premo enter e start va a true
    if(!start){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, & ev);

    al_draw_bitmap(bitmapsPg[16],0,0,0); // sfondo menu
    al_draw_bitmap(bitmapsPg[17],1125,650,0); // scrittaEnter
    // al_draw_bitmap(bitmapsPg[45],1746,910,0); // info



    if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || fine) {
      break;
    }

    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
      switch (ev.keyboard.keycode) {

        case ALLEGRO_KEY_ENTER:
          al_uninstall_mouse();
          start = true;


          al_start_timer(timer);
          al_start_timer(timer_time);
          // caricaLivello();
          // start();
        break;

        case ALLEGRO_KEY_ESCAPE:
          fine = true;
        break;

      }
    }
    else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {


      if(ev.mouse.x >= monitor_w/1.20 && ev.mouse.x<=monitor_w/1.20+123 && ev.mouse.y>=monitor_h/1.20 && ev.mouse.y<=monitor_h/1.20+118 && musica){
        al_stop_sample_instance(MusicaMenu);
        musica = false;
      }

      else if(ev.mouse.x >= monitor_w/1.20 && ev.mouse.x<=monitor_w/1.20+123 && ev.mouse.y>=monitor_h/1.20 && ev.mouse.y<=monitor_h/1.20+118 && !musica){
          al_play_sample_instance(MusicaMenu);
          musica = true;
      }

      // tasto I
      else if(ev.mouse.x >= 1746 && ev.mouse.x<=1746+100 && ev.mouse.y>=910 && ev.mouse.y<=910+100 ){


        al_draw_bitmap(bitmapsPg[44], 0, 0, 0);

        // devo disegnare anche il bottone back
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        bool escape = false;
        while(!escape){

          ALLEGRO_EVENT ev;
          al_wait_for_event(event_queue, & ev);


          if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || fine) {
            break;
          }

          else if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            switch (ev.keyboard.keycode) {


              case ALLEGRO_KEY_ESCAPE:
                // esc = true;
                escape = true;
                // Menu();
                break;
            }
          }
        }
      }
    }

      al_draw_bitmap(bitmapsPg[45],1746,910,0); // info

      if(musica)
        al_draw_bitmap(bitmapsPg[27],width/1.20,height/1.20,0); // noSound
      else
        al_draw_bitmap(bitmapsPg[26],width/1.20,height/1.20,0); // siSound

    if(start){
      al_clear_to_color(al_map_rgb(0, 0, 0));
      al_flip_display();
    }
    al_flip_display();

} // fine if (!start)

// nell'else c'è
else{

        ALLEGRO_EVENT ev;

        redraw = true;

        if(cont>=1000)
          cont = 0;

        // cout<<"INIZIO START"<<endl;
        //attendo eventi
        al_wait_for_event(event_queue, & ev);

        int xPlayer = field->getPlayer()->getPosX();
        int yPlayer = field->getPlayer()->getPosY();
        int widthPlayer = field->getPlayer()->getWidth();
        int heightPlayer = field->getPlayer()->getHeight();
        //ripulisco tutto prima di ridisegnare
        al_clear_to_color(al_map_rgb(0, 0, 0));


        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
          break;
        }

        if(vittoria && numLivello==0){
          numLivello++;
          delete field;
          field = new GameField(cellSize,numLivello);

           destra = false, sinistra = false, sotto = false, sopra = false, shift = false;

           rompiSinistra = false, rompiDestra = false;


           ultimoPremuto = 0;


           redraw = true;
           gameover = false;
           perdita = false;  // sconfitta
           vittoria = false;
           esc=false;
           boostSpeed = field->getPlayer()->getSpeed()+4;
           speed  = field->getPlayer()->getSpeed();


          // TEMPO A DISPOSIZIONE PER LA PARTITA
          time = 90;

          al_start_timer(timer);
          al_start_timer(timer_time);
        }

        if(vittoria && numLivello==1){
          redraw=false;

          al_draw_bitmap(bitmapsPg[29],width/2-300,height/2,0);
          al_flip_display();
          al_rest(5.0);
          gameover = true;
        }


        if(field->getPlayer()->verificaSconfitta()){
          perdita = true;
          redraw = false;
        }

        if(fine || perdita || time<=0 ){
          redraw=false;
          al_draw_bitmap(bitmapsPg[28],width/2-250,height/2,0);
          al_flip_display();
          al_rest(5.0);
          gameover=true;
        }



        if (ev.timer.source == timer_time && time!=0 ) {
            time--;

        }

        field->checkCollision(rompiSinistra,rompiDestra);
        if(field->checkCollisionWithEnemy(cellSize,width,height)){
          destra = sinistra = sotto = sopra = false;
          ultimoPremuto = 0;
        }




        field->getPlayer()->fuoriMappa(cellSize,width,height);



        // se il punteggio del player diviso 100 è uguale al numero di caramelle ho vinto
        vittoria = field->getVittoria();



        for(int i=0;i<field->getVectorMuro().size();i++){
          int heightMuro = field->getMuro(i)->getHeight();
          int yMuro = field->getMuro(i)->getPosY();


          field->getMuro(i)->setVisibleTrue(time);

        }

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
          switch (ev.keyboard.keycode) {

            case ALLEGRO_KEY_LSHIFT:
              key[ALLEGRO_KEY_LSHIFT] = true;
              shift = true;
              field->getPlayer()->setSpeed(boostSpeed); // MODIFICO LA VELOCITÀ
            break;


            case ALLEGRO_KEY_A: // SPACCO IL MURO SINISTRO
              key[ALLEGRO_KEY_DOWN] = false;
              key[ALLEGRO_KEY_UP] = false;
              rompiSinistra = true;
            break;


            case ALLEGRO_KEY_D: // SPACCO IL MURO DESTRO
              key[ALLEGRO_KEY_DOWN] = false;
              key[ALLEGRO_KEY_UP] = false;
              rompiDestra = true;
            break;

            case ALLEGRO_KEY_LEFT: // VADO A SINISTRA

              sinistra = true;
              destra = false;
              sotto = false;
              sopra = false;
              key[ALLEGRO_KEY_LEFT] = true;

              key[ALLEGRO_KEY_DOWN] = false;
              key[ALLEGRO_KEY_RIGHT] = false;
              key[ALLEGRO_KEY_UP] = false;

            ultimoPremuto = 1;
            break;

            case ALLEGRO_KEY_RIGHT: // VADO A DESTRA
                destra = true;
                sinistra = false;
                sotto = false;
                sopra = false;

                key[ALLEGRO_KEY_RIGHT] = true;
                key[ALLEGRO_KEY_DOWN] = false;
                key[ALLEGRO_KEY_LEFT] = false;
                key[ALLEGRO_KEY_UP] = false;

              ultimoPremuto=0;
            break;

            case ALLEGRO_KEY_UP: // VADO SOPRA
              if(field->canMoveOnLadder()){
                sinistra = true;
                destra = true;
                sopra = true;
                sotto = false;

                key[ALLEGRO_KEY_UP] = true;
                key[ALLEGRO_KEY_DOWN] = false;
                key[ALLEGRO_KEY_LEFT] = false;
                key[ALLEGRO_KEY_RIGHT] = false;
                ultimoPremuto = 2;
              }
            break;

            case ALLEGRO_KEY_DOWN: // VADO SOTTO
              if(field->canMoveOnLadder()){
                sinistra = true;
                destra = true;
                // sinistra = false;
                // destra = false;
                sotto = true;
                sopra = false;

                key[ALLEGRO_KEY_DOWN] = true;
                key[ALLEGRO_KEY_LEFT] = false;
                key[ALLEGRO_KEY_RIGHT] = false;
                key[ALLEGRO_KEY_UP] = false;
                ultimoPremuto = 3;
              }
            break;

            case ALLEGRO_KEY_ESCAPE:
            // cout<<"2"<<endl;
              fine = true;
              redraw = false;
              gameover = true;
            break;

          } // FINE SWITCH KEY DOWN


        } // fine ev.type_key_down

        else if(ev.type == ALLEGRO_EVENT_KEY_UP){
          switch(ev.keyboard.keycode) {

            case ALLEGRO_KEY_LSHIFT:
            key[ALLEGRO_KEY_LSHIFT] = false;
              shift = false;
              field->getPlayer()->setSpeed(speed);
            break;

              case ALLEGRO_KEY_D:
                key[ALLEGRO_KEY_D] = false;
                rompiDestra = false;
              break;

              case ALLEGRO_KEY_A:
                key[ALLEGRO_KEY_A] = false;
                rompiSinistra = false;
              break;

                case ALLEGRO_KEY_UP:
                   key[ALLEGRO_KEY_UP] = false;
                   sopra = false;
                   break;

                case ALLEGRO_KEY_DOWN:
                   key[ALLEGRO_KEY_DOWN] = false;
                   sotto = false;
                   break;

                case ALLEGRO_KEY_LEFT:
                   key[ALLEGRO_KEY_LEFT] = false;
                   sinistra = false;
                   break;

                case ALLEGRO_KEY_RIGHT:
                   key[ALLEGRO_KEY_RIGHT] = false;
                   destra = false;
                   break;


             }
        }

        //  PERMETTE DI TENERE PREMUTO E CAMMINARE E AGGIORNA LE POSIZIONI E APPLICARE LA GRAVITÀ
        if(ev.type == ALLEGRO_EVENT_TIMER){
          al_get_keyboard_state(&keystate);


          // se non collido con una scala e sono in aria allora scendi
          if(!field->checkCollisionLadder() && field->getPlayer()->getInAir()){
            field->getPlayer()->moveDown();
            destra = sinistra = sotto = sopra = false;

          }

            // boost di velocità dato dallo shift sinistro
            if(al_key_down(&keystate,ALLEGRO_KEY_LSHIFT)){
              shift = true;

              field->getPlayer()->setSpeed(boostSpeed);
            }


          // distruggo muro sotto di me a sinistra
            if(al_key_down(&keystate,ALLEGRO_KEY_A)){

              field->checkCollision(rompiSinistra,rompiDestra);

            }

          // distruggo muro sotto di me a destra
            if(al_key_down(&keystate,ALLEGRO_KEY_D)){

                field->checkCollision(rompiSinistra,rompiDestra);
            }


            if(al_key_down(&keystate,ALLEGRO_KEY_DOWN) && field->canMoveOnLadder()){
              sotto = true;
              sinistra = true;
              destra = true;
              sopra = false;

              field->getPlayer()->moveDown();
            }

          else if(al_key_down(&keystate,ALLEGRO_KEY_UP)&& field->canMoveOnLadder() ){
              sopra = true;
              sinistra = true;
              destra = true;
              sotto = false;
              field->getPlayer()->moveUp();

            }

          else if(al_key_down(&keystate,ALLEGRO_KEY_RIGHT) && xPlayer+field->getPlayer()->getSpeed()+cellSize<width){
            destra = true;
              sopra=false;
              sinistra = false;
              sotto = false;
              field->getPlayer()->moveRight(field->checkCollisionLadder());
          }

          else if(al_key_down(&keystate,ALLEGRO_KEY_LEFT) && xPlayer-field->getPlayer()->getSpeed()>0 ){
            sinistra = true;
              destra=false;
              sopra = false;
              sotto = false;
              field->getPlayer()->moveLeft(field->checkCollisionLadder());
            }
          }


          if(numLivello==1 ){
            if(time == 90)
              field->getBarile(0)->setVisibleTrue();

              if(time == 80)
                field->getBarile(1)->setVisibleTrue();

                if(time == 70)
                  field->getBarile(2)->setVisibleTrue();

                  if(time == 60)
                    field->getBarile(3)->setVisibleTrue();

                    if(time == 50)
                      field->getBarile(4)->setVisibleTrue();

                      if(time == 40)
                        field->getBarile(5)->setVisibleTrue();

          }



        // DISEGNO TUTTO IL MONDO
        if(redraw && al_is_event_queue_empty(event_queue) && !fine){
          redraw = false;
          al_draw_bitmap(bitmapsPg[14],0,0,0); // lo sfondo

          cont++; // contatore utile al draw delle animazioni



            // DISEGNO I COIN
            for(int i=0;i<field->getVectorCoin().size();i++){
              if(field->getVectorCoin()[i]->getVisible()){
                int xCoin = field->getVectorCoin()[i]->getPosX();
                int yCoin = field->getVectorCoin()[i]->getPosY();

                al_draw_bitmap(bitmapsPg[15],xCoin,yCoin,0);
              }

            }

            // DISEGNO I MURI

            for(int i=0;i<field->getVectorMuro().size();i++){
                int xMuro = field->getVectorMuro()[i]->getPosX();
                int yMuro = field->getVectorMuro()[i]->getPosY();

                int widthMuro = field->getMuro(i)->getWidth();
                int heightMuro = field->getMuro(i)->getHeight();

                field->getPlayer()->nelMuro(cellSize,width,height,heightMuro,widthMuro,yMuro,xMuro,field->getMuro(i)->getVisible());

                if(field->getMuro(i)->getVisible())
                  al_draw_bitmap(bitmapsPg[12],xMuro,yMuro,0);

            } // chiusura for disegno muri

            // DISEGNO LE SCALE
            for(int i=0;i<field->getVectorScala().size();i++){
              int xScala = field->getVectorScala()[i]->getPosX();
              int yScala = field->getVectorScala()[i]->getPosY();

              al_draw_bitmap(bitmapsPg[13],xScala,yScala,0);
              // al_draw_filled_rectangle(xScala,yScala,xScala+cellSize,yScala+cellSize,al_map_rgb(255,0,0));

            } // chiusura for disegno scala


            // DISEGNO I NEMICI
            for(int i =0;i<field->getVectorEnemy().size();i++){
              int xEnemy = field->getVectorEnemy()[i]->getPosX();
              int yEnemy = field->getVectorEnemy()[i]->getPosY();

              int widthEnemy = field->getVectorEnemy()[i]->getWidth();
              int heightEnemy = field->getVectorEnemy()[i]->getHeight();

              field->getEnemy(i)->move(cellSize,width,height,xPlayer,yPlayer);


              if(field->getEnemy(i)->getDirezione()) // se sto andando a destra
                al_draw_bitmap(bitmapsPg[31],xEnemy,yEnemy,0);
              else // se vado a sinistra
                al_draw_bitmap(bitmapsPg[30],xEnemy,yEnemy,0);

            }// fine disegno nemici



            // DISEGNO IL PLAYER PER ULTIMO COSÌ APPARIRÀ SOPRA TUTTI GLI ALTRI OGGETTI
            if(destra && !field->checkCollisionLadder()){
                al_draw_bitmap(bitmapsPg[cont%6],xPlayer,yPlayer,0);

            }
            else if(!destra && ultimoPremuto==0 && !field->checkCollisionLadder()){
              al_draw_bitmap(pgDxIdle,xPlayer,yPlayer,0);

            }

          else  if(sinistra && !field->checkCollisionLadder()){
              al_draw_bitmap(bitmapsPg[cont%6+6],xPlayer,yPlayer,0);
            }

            else if(!sinistra && ultimoPremuto==1 && !field->checkCollisionLadder()){
              al_draw_bitmap(pgSxIdle,xPlayer,yPlayer,0);
            }


            else if(sopra || sotto){
              al_draw_bitmap(bitmapsPg[cont%2+18],xPlayer,yPlayer,0);
            }

            else if(field->checkCollisionLadder()){
              al_draw_bitmap(bitmapsPg[18],xPlayer,yPlayer,0);

            }

            // DISEGNO LE FIAMME / BARILI
            for(int i = 0; i<field->getVectorBarile().size();i++){
              if(field->getVectorBarile()[i]->getVisible()){
                int xBarile = field->getVectorBarile()[i]->getPosX();
                int yBarile = field->getVectorBarile()[i]->getPosY();
                bool destra = field->getVectorBarile()[i]->getDestra();
                bool scendo = field->getVectorBarile()[i]->getScendo();

                field->getBarile(i)->move(cellSize,width,height);

                  if(destra && !scendo)
                    al_draw_bitmap(bitmapsPg[cont%6+20],xBarile,yBarile,0);

                  else if(!destra && !scendo)
                    al_draw_bitmap(bitmapsPg[cont%6+32],xBarile,yBarile,0);

                  else if(scendo )
                    al_draw_bitmap(bitmapsPg[cont++%6+38],xBarile,yBarile,0);
                  // }
                }
              // al_draw_filled_rectangle(xBarile,yBarile,xBarile+cellSize,yBarile+cellSize,al_map_rgb(255,0,0));

            } // chiusura disegno barili

            // *********** DISEGNO PUNTEGGIO SCORE E VITA ***************** //

            al_draw_text(fontLevel, al_map_rgb(255, 255, 255), width - 300, height -45, 0, "LIFE:");
            al_draw_textf(fontLevel, al_map_rgb(255, 255, 255), width - 230, height -45 , 0, (to_string(field->getPlayer()->getLives())).c_str(),width,height);
            //
            al_draw_text(fontLevel, al_map_rgb(255, 255, 255), width - 150, height -45, 0, "TIME:");
            al_draw_textf(fontLevel, al_map_rgb(255, 255, 255), width - 55, height -45 , ALLEGRO_ALIGN_CENTRE, (to_string(time)).c_str(),width,height);

            //
            al_draw_text(fontLevel, al_map_rgb(255, 255, 255), width - 500, height -45, 0, "SCORE:");
            al_draw_textf(fontLevel, al_map_rgb(255, 255, 255), width - 360, height -45 , ALLEGRO_ALIGN_CENTRE, (to_string(field->getPlayer()->getScore())).c_str(),width,height);

            al_flip_display();


        }// fine redraw

      } // fine else


    } // fine while true

        delete field;
} // fine Start()
