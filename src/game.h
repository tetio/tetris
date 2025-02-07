#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{

public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void HandleInput();
    void Draw();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    bool IsOutside();
    Grid grid;
    bool gameOver;
    int score;

private:
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Block currentBlock;
    Block nextBlock;
    std::vector<Block> blocks;
};