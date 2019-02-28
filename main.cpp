#include "GameManager.h"
using namespace std;

int main(){



  GameManager* manager = new GameManager();


  manager->Start();

  delete manager;




  return 0;
}



/*** INIZIO COMPILAZIONE **********/

// clear; g++ *.cpp -o LodeRunner -lallegro -lallegro_image -lallegro_primitives -lallegro_dialog -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf && ./LodeRunner

/********* FINE COMPILAZIONE **********/
