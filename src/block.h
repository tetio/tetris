#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
    int id;
    std::map<int, std::vector<Position>> cells;
    Block();
    void Draw();
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};