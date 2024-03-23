#include"raylib.h"
#include"game.h"

#define width 300
#define height 600

int main(){
  InitWindow(width,height,"window");
  SetTargetFPS(60);


  //init block
  //JBlock block = JBlock();

  Game game = Game();
  while(!WindowShouldClose()){

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

