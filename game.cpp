#include"game.h"
#include<iostream>

Game::Game(){
  grid = Grid();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  completeRows =0;
}

Game::~Game(){

}

//handle event
void Game::HandleEvent(){
  int choice = GetKeyboardInput();
  switch(choice){
  case KEY_S:
    MoveBlockDown();break;
  case KEY_A:
    MoveBlockLeft();break;
  case KEY_D:
    MoveBlockRight();break;
  case KEY_SPACE:
    RotateBlock();break;
  case KEY_W:
    MoveBlockUp();break;
  default:
    break;
  }

}
//get keyboard input
int Game::GetKeyboardInput(){
  if(IsKeyPressed(KEY_S)){
    return KEY_S;
  }
  if(IsKeyPressed(KEY_A)){
    return KEY_A;
  }
  if(IsKeyPressed(KEY_D)){
    return KEY_D;
  }
  if(IsKeyPressed(KEY_SPACE)){
    return KEY_SPACE;
  }
  if(IsKeyPressed(KEY_W)){
    return KEY_W;
  }

  return 0;
}

//if outside
bool Game::IsOutsideWindow(){
  std::vector<Position> block = currentBlock.GetCellPos();
  for(Position item : block){
    if(grid.IsCellOutside(item.p_row,item.p_col)){
      return true;
    }
  }
  return false;
}

//clear bottomrow
void Game::ClearRow(){
  grid.ClearRow(completeRows);
}
//lock block at the end
void Game::LockBlock(){
  std::vector<Position> pos = currentBlock.GetCellPos();
  for(Position item : pos){
    grid.grid[item.p_row][item.p_col]= currentBlock.id;
  }
  currentBlock = nextBlock;
  nextBlock = GetRandomBlock();
  grid.ClearFullRows();
  
}
//see if block fits
bool Game::BlockFits(){
  std::vector<Position> block = currentBlock.GetCellPos();
  for(Position pos : block){
    if(!grid.IsCellEmpty(pos.p_row,pos.p_col)){
      return false;
    }
  }
  return true;
}
//move blokc down

void Game::MoveBlockDown(){
  currentBlock.Move(1,0);
  if(IsOutsideWindow() || BlockFits() == false){
    //std::cout<<"Bblock outside in down"<<std::endl;
    currentBlock.Move(-1,0);
    LockBlock();
  }
}
void Game::MoveBlockLeft(){
  currentBlock.Move(0,-1);
  if(IsOutsideWindow() || BlockFits() == false){
    currentBlock.Move(0,1);
  }
}
void Game::MoveBlockUp(){
  currentBlock.Move(-1,0);
  if(IsOutsideWindow() || BlockFits() == false){
    currentBlock.Move(1,0);
  }
}
void Game::MoveBlockRight(){
  currentBlock.Move(0,1);
  if(IsOutsideWindow() || BlockFits() == false){
    currentBlock.Move(0,-1);
  }
}
void Game::RotateBlock(){
  currentBlock.ChangeRotationState();
  if(IsOutsideWindow() || BlockFits() == false){
    //std::cout<<"Rotated outside window"<<std::endl;
    RotateBlock();
  }
}

void Game::GameDraw(){
  grid.DrawGrid();
  currentBlock.DrawBlock();
}
Block Game::GetRandomBlock(){
  if(blocks.empty()){
    blocks = GetAllBlocks();
  }
  int b = rand()%blocks.size();
  std::cout<<"Block: "<<b<<std::endl;
  Block temp = blocks[b];
  blocks.erase(blocks.begin()+b);

  return temp;

}
std::vector<Block> Game::GetAllBlocks(){
  return {JBlock(),OBlock(),IBlock(),SBlock(),ZBlock(),LBlock(),TBlock()};
}

//check if time has correctly elapsed to move block

