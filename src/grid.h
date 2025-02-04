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
    bool IsTileOutside(int row, int column);

private:
    int numRows;
    int numCols;
    std::vector<Color> colors;
};