#include"block.h"
#include<iostream>

Block::Block(){
  RotationState = 0;
  colors = GetCellColors();
  cellSize = 30;
  rowOffset = 0;
  colOffset = 0;
  offsetX = 10 ;
  offsetY = 10;
}

void Block::DrawBlock(){
  std::vector<Position> block = GetCellPos();
  for(Position item:block){
    DrawRectangle(item.p_col*cellSize+offsetX,item.p_row*cellSize+offsetY,cellSize-1,cellSize-1,colors[id]);
  }
  
}
void Block::DrawNextBlock(){
  std::vector<Position> block = GetCellPos();
  for(Position item:block){
    DrawRectangle(item.p_col*cellSize+250,item.p_row*cellSize+300,cellSize-1,cellSize-1,colors[id]);
  }
  
}

//get cell pos
std::vector<Position> Block::GetCellPos(){
  std::vector<Position> movedTiles;
  std::vector<Position> tile = cells[RotationState];
  for(Position item : tile ){
    Position newPos = Position(item.p_row+rowOffset,item.p_col+colOffset);
    movedTiles.push_back(newPos);
  }
  return movedTiles;
}
//move
void Block::Move(int row,int col){
  rowOffset += row;
  colOffset += col;
  
}
//change rotation state
void Block::ChangeRotationState(){
  if(RotationState == 3){
    RotationState = 0;
  }
  RotationState += 1;
}

