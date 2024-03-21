#pragma once
#include"raylib.h"

class Grid{

 public:
  Grid();
  void Initialize();
  void PrintGrid();
  void DrawGrid();
  
 private:
  int grid[20][10];
  int g_Row;
  int g_Col;
  int cellSize;
};
