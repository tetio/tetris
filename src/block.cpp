#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    columnOffset = 0;
    rowOffset = 0;
}

void Block::Draw()
{
    std::vector<Position> tiles = GetCellPositions();
    for (Position cell : tiles)
    {
        DrawRectangle(cell.column * cellSize + 1, cell.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (Position item : tiles) {
        Position newPosition = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPosition);
    }
    return movedTiles;
}