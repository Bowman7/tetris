#pragma once
#include"grid.h"
#include"blocks.cpp"

class Game{
 public:
  Game();
  ~Game();
  Grid grid;
  std::vector<Block>GetAllBlocks();
  Block GetRandomBlock();
  void GameDraw();

  void HandleEvent();
   
 private:
  int GetKeyboardInput();
  void MoveBlockDown();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockUp();
  void RotateBlock();
  
 private:
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
};
