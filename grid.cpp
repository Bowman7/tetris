#include"grid.h"
#include<iostream>

Grid::Grid(){
  g_Row = 20;
  g_Col = 10;
  cellSize = 30;
  Initialize();
}

void Grid::Initialize(){
  for(int row =0;row<g_Row;row++){
    for(int col =0;col<g_Col;col++){
      grid[row][col] = 0;
    }
  }
}

void Grid::PrintGrid(){
  for(int row =0;row<g_Row;row++){
    for(int col =0;col<g_Col;col++){
      std::cout<<grid[row][col];
    }
    std::cout<<std::endl;
  }
}

void Grid::DrawGrid(){
  for(int row =0;row<g_Row;row++){
    for(int col =0;col<g_Col;col++){
      DrawRectangle(col*cellSize,row*cellSize,cellSize-1,cellSize-1,DARKBLUE);
    }
  }
}
