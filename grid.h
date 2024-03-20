#pragma once
#include"raylib.h"

class Grid{
 public:
  Grid();
  ~Grid(){}
  void Initialize();
  void PrintGrid();
  void Draw();
  
  
 private:
  int n_row;
  int n_col;
  int cellSize;
  int grid[20][10];

};
