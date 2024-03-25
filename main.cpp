#include"raylib.h"
#include"game.h"
#include<iostream>

#define width 300
#define height 600

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
    
    game.GameDraw();

    EndDrawing();
  }
  CloseWindow();

  return 0;
}

