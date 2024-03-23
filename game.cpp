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
    
  default:
    break;
  }

}
//get keyboard input
int Game::GetKeyboardInput(){
  if(IsKeyPressed(KEY_S)){
    return KEY_S;
  }

  return 0;
}
//move blokc down

void Game::MoveBlockDown(){
  currentBlock.Move(1,0);
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
