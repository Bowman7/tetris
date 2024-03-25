#include"block.h"
#include<iostream>

Block::Block(){
  RotationState = 0;
  colors = GetCellColors();
  cellSize = 30;
  rowOffset = 0;
  colOffset = 0;
}

void Block::DrawBlock(){
  std::vector<Position> block = cells[RotationState];
  for(Position item:block){
    DrawRectangle((item.p_col+colOffset)*cellSize,(item.p_row+rowOffset)*cellSize,cellSize-1,cellSize-1,colors[id]);
  }
  
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

void Block::RevertRotationState(){
  if(RotationState == 0){
    RotationState = 3;
  }
  RotationState -= 1;
}
//check if the blockis outside the play area

bool Block::IsOutsideWindow(){
  std::vector<Position> block = cells[RotationState];
  for(Position item : block){

    if((item.p_col+colOffset) < 0 || (item.p_col+colOffset) >= 10 || (item.p_row+rowOffset) >=  20){
      return true;
    }
  }
  return false;
}
//seal the block at the end
void Block::SealBlock(Grid &grid){
  std::vector<Position> block = cells[RotationState];
  for(Position item : block){
    grid.SealGrid(id,item.p_row+rowOffset,item.p_col+colOffset);
  }
  grid.PrintGrid();
}
//return pos

std::vector<Position> Block::GetPosition(){
  std::vector<Position> block = cells[RotationState];

  return block;
}

