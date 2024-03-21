#pragma once
#include<vector>
#include<map>
#include"position.h"
#include"colors.h"

class Block{
public:
  Block();
  void DrawBlock();
  

public:
  int id;//on this basis color is assigned
  std::map<int,std::vector<Position>>cells;
  
private:
  int RotationState;//the rotation states
 
  std::vector<Color> colors;
  int cellSize;
};
