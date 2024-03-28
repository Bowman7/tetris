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
  void MoveBlockDown();
  bool GameOver;
  void Reset();
  int score;
  void AddScore(int);
  
 private:
  int GetKeyboardInput();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockUp();
  void RotateBlock();
  bool IsOutsideWindow();
  void LockBlock();
  bool BlockFits();
  void ClearRow();
  
  
 private:
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
  int completeRows;
};
