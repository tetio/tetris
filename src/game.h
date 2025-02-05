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

private:
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    Block currentBlock;
    Block nextBlock;
    std::vector<Block> blocks;
};