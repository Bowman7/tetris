#pragma once
#include"raylib.h"
#include"colors.h"

class Grid{

 public:
  Grid();
  void Initialize();
  void PrintGrid();
  void DrawGrid();
  bool IsCellOutside(int,int);
  std::vector<Color> colors;
  int grid[20][10];
  bool IsCellEmpty(int,int);
  int ClearFullRows();
  void MoveRowDown(int,int);
  void ClearRow(int);
  bool IsRowFull(int);
  
 private:
  int g_Row;
  int g_Col;
  int cellSize;
  int offsetX;
  int offsetY;
};
