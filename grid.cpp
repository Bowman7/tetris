#include"grid.h"
#include<iostream>

Grid::Grid(){
  g_Row = 20;
  g_Col = 10;
  cellSize = 30;
  colors = GetCellColors();
  Initialize();
  offsetX = 10;
  offsetY = 10;
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
      DrawRectangle(col*cellSize+offsetX,row*cellSize+offsetY,cellSize-1,cellSize-1,colors[grid[row][col]]);
    }
  }
}

//chec outside
bool Grid::IsCellOutside(int row,int col){
  if(row >= 0 && row <g_Row && col>=0 && col < g_Col){
    return false;
  }
  return true;
}
//check is cell is empty

bool Grid::IsCellEmpty(int row,int col){
  if(grid[row][col] == 0){
    return true;
  }
  return false;
}


//check if row is full

bool Grid::IsRowFull(int row){
  for(int col = 0;col<g_Col;col++){
    if(grid[row][col] == 0){
      return false;
    }
  }

  return true;
}

//clear row

void Grid::ClearRow(int row){
  for(int col=0;col<g_Col;col++){
    grid[row][col] =0 ;
  }
}
//move row down
void Grid::MoveRowDown(int row,int completed){
  for(int col=0;col<g_Col;col++){
    grid[row+completed][col] = grid[row][col];
    grid[row][col] = 0;
  }
}
//clear full rows

int Grid::ClearFullRows(){
  int completed =0 ;
  for(int row =g_Row-1;row>0;row--){
      if(IsRowFull(row)){
	ClearRow(row);
	completed++;
      }else if(completed > 0){
	MoveRowDown(row,completed);
      }
  }
  return completed;
}
