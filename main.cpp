#include"raylib.h"
#include"grid.h"
#include"blocks.cpp"

#define width 300
#define height 600

int main(){
  InitWindow(width,height,"window");
  SetTargetFPS(60);


  //bg color
  Color background = {14,26,73};

  //init grid
  Grid grid = Grid();
  grid.PrintGrid();

  //init block
  JBlock block = JBlock();
  
  while(!WindowShouldClose()){

    //draw
    BeginDrawing();
    ClearBackground(SKYBLUE);

    grid.DrawGrid();
    block.DrawBlock();

    EndDrawing();
  }
  CloseWindow();

  return 0;
}

