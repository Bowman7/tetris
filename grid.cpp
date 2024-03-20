#include"grid.h"
#include<iostream>
//grid constructor
Grid::Grid(){
  n_row = 20;
  n_col = 10;
  cellSize = 30;
  Initialize();
}

//initialize grid values
void Grid::Initialize(){
  for(int row =0;row<n_row;row++){
    for(int col=0;col<n_col;col++){
      grid[row][col] = 0;
    }
  }
}
//print the grid values
void Grid::PrintGrid(){
  for(int row =0;row<n_row;row++){
    for(int col=0;col<n_col;col++){
      std::cout<<grid[row][col];
    }
    std::cout<<std::endl;
  }
}
//draw the grids
void Grid::Draw(){
  for(int row =0;row<n_row;row++){
    for(int col=0;col<n_col;col++){
      DrawRectangle(col*cellSize+10,row*cellSize+10,cellSize-1,cellSize-1,BROWN);
    }
  }
}
