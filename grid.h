#pragma once
#include"raylib.h"
#include"colors.h"

class Grid{

 public:
  Grid();
  void Initialize();
  void PrintGrid();
  void DrawGrid();
  void SealGrid(int,int,int);
  bool IsGridEmpty(int,int);
  std::vector<Color> colors;
  
 private:
  int grid[20][10];
  int g_Row;
  int g_Col;
  int cellSize;
};
