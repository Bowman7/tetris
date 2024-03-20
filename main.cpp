#include"raylib.h"
#include"grid.h"

#define row 20
#define col 10
#define size 30


int main(){
  InitWindow(col*size+100,row*size+100,"window");
  SetTargetFPS(60);

  Grid grid = Grid();
  grid.PrintGrid();

  while(!WindowShouldClose()){

    //draw
    BeginDrawing();
    ClearBackground(DARKBROWN);

    grid.Draw();


    EndDrawing();
  }

  return 0;
}
