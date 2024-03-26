#include"grid.h"
#include<iostream>

Grid::Grid(){
  g_Row = 20;
  g_Col = 10;
  cellSize = 30;
  colors = GetCellColors();
  complete =0;
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
      DrawRectangle(col*cellSize,row*cellSize,cellSize-1,cellSize-1,colors[grid[row][col]]);
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

//check if row is complete
int Grid::IsRowComplete(){
  complete = 0;
  for(int row =g_Row-1;row>=0;row-- ){
    for(int col =0;col<g_Col;col++){
      if(grid[row][col] == 0){
	return complete;
      }
    }
    complete++;
  }
  return complete;
}
//clear row in grid
void Grid::ClearRow(int completeRows){
  for(int row =g_Row -1;row>(g_Row-completeRows-1);row--){
    for(int col = 0;col<g_Col;col++){
      grid[row][col] =0;
    }
  }
  MoveRow(completeRows);
}
//move rows
void Grid::MoveRow(int crow){
  for(int row = g_Row-crow-1;row>0;row--){
    for(int col = 0;col<g_Col;col++){
      if(grid[row][col] != 0){
	grid[row+crow][col+crow] = grid[row][col];
	grid[row][col] = 0;
      }
      
    }
  }
}
