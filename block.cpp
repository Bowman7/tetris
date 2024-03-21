#include"block.h"

Block::Block(){
  RotationState = 3;
  colors = GetCellColors();
  cellSize = 30;
}

void Block::DrawBlock(){
  std::vector<Position> block = cells[RotationState];
  for(Position item:block){
    DrawRectangle(item.p_col*cellSize,item.p_row*cellSize,cellSize-1,cellSize-1,colors[id]);
  }
  
}
