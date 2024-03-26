#pragma once
#include<vector>
#include<map>
#include"position.h"
#include"colors.h"
#include"grid.h"

class Block{
public:
  Block();
  void DrawBlock();
  void Move(int,int);
  void ChangeRotationState();
  std::vector<Position> GetCellPos();
  
  
public:
  int id;//on this basis color is assigned
  std::map<int,std::vector<Position>>cells;
  int rowOffset;
  int colOffset;
  
private:
  int RotationState;//the rotation states 
  std::vector<Color> colors;
  int cellSize;
};
