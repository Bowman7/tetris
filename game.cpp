#include"game.h"
#include<iostream>

Game::Game(){
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  grid = Grid();
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

//if a grid if empty or not
bool Game::IfBlockTaken(){
  std::vector<Position> pos = currentBlock.GetPosition();
  int rOffset = currentBlock.rowOffset;
  int cOffset = currentBlock.colOffset;
  int count= 0;
  for(Position item : pos){
    if( grid.IsGridEmpty(item.p_row+rOffset,item.p_col+cOffset)){
      count++;
    }
  }
  if(count == pos.size()){
    return false;
  }
  return true;
}
//move blokc down

void Game::MoveBlockDown(){
  currentBlock.Move(1,0);
  if(currentBlock.IsOutsideWindow() || !IfBlockTaken()){
    //std::cout<<"Bblock outside in down"<<std::endl;
    currentBlock.Move(-1,0);
    currentBlock.SealBlock(grid);
    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();
  }
}
void Game::MoveBlockLeft(){
  currentBlock.Move(0,-1);
  if(currentBlock.IsOutsideWindow()){
    currentBlock.Move(0,1);
  }
}
void Game::MoveBlockUp(){
  currentBlock.Move(-1,0);
  if(currentBlock.IsOutsideWindow()){
    currentBlock.Move(1,0);
  }
}
void Game::MoveBlockRight(){
  currentBlock.Move(0,1);
  if(currentBlock.IsOutsideWindow()){
    currentBlock.Move(0,-1);
  }
}
void Game::RotateBlock(){
  currentBlock.ChangeRotationState();
  if(currentBlock.IsOutsideWindow()){
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

