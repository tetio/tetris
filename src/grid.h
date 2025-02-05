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
    bool IsCellEmpty(int row, int column);
    void ClearFullRows();
private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int numRows;
    int numCols;
    std::vector<Color> colors;
};