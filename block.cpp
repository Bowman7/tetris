#include"block.h"

Block::Block(){
  RotationState = 0;
  colors = GetCellColors();
  cellSize = 30;
}

void Block::DrawBlock(){
  std::vector<Position> block = cells[RotationState];
  for(Position item:block){
    DrawRectangle(item.p_col*cellSize,item.p_row*cellSize,cellSize-1,cellSize-1,colors[id]);
  }
  
}
//move
void Block::Move(int row,int col){
  std::vector<Position> block = cells[RotationState];
  std::vector<Position> newPos;
  for(Position item : block){
    item.p_col += col;
    item.p_row += row;
    newPos.push_back(item);
  }

  cells[RotationState] = newPos;
  
}
