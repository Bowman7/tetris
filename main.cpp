#include"raylib.h"
#include"game.h"
#include<iostream>

#define width 450
#define height 620

double elapsedTime = 0.0;

bool EventTriggered(double val){
  double currentTime = GetTime();
  //std::cout<<"Curtime: "<<currentTime<<std::endl;
  //std::cout<<"Elapime: "<<elapsedTime<<std::endl;
  if(( currentTime -elapsedTime )>=val ){
    elapsedTime = currentTime; 
    return true;

  }
  return false;
}

int main(){
  InitWindow(width,height,"window");
  SetTargetFPS(60);
  
  double currentTime=0;
  double diff;
  //init block
  //JBlock block = JBlock();

  Game game = Game();

  //font
  Font font = LoadFontEx("font/arcade.TTF",64,0,0);
  while(!WindowShouldClose()){

    //update
    if(EventTriggered(0.4)){
      game.MoveBlockDown();
    }
    //handle input
    game.HandleEvent();
    //draw
    BeginDrawing();
    ClearBackground(SKYBLUE);
    //draw score
    DrawTextEx(font,"Score",{320,40},38,2,WHITE);
    DrawTextEx(font,"Next",{320,180},38,2,WHITE);

    //draw score
    char scoreText[10];
    sprintf(scoreText,"%d",game.score);
    Vector2 textSize = MeasureTextEx(font,scoreText,38,2);

    DrawTextEx(font,scoreText,{320+(80-textSize.x)/2,65},45,2,BLACK);
    
    game.GameDraw();

    EndDrawing();
  }
  CloseWindow();

  return 0;
}

