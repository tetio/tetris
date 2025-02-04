#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void Initialize();
    int grid[20][10];
    int cellSize;
    void Print();
    void Draw();
private:
    int numRows;
    int numCols;
    std::vector<Color> colors;
};