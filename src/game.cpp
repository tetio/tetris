#include "game.h"

Game::Game()
{
    // srand(static_cast<unsigned int>(time(0)));
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        break;
    }
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0, -1);
    if (IsOutside())
    {
        currentBlock.Move(0, 1);
    }
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0, 1);
    if (IsOutside())
    {
        currentBlock.Move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1, 0);
    if (IsOutside())
    {
        currentBlock.Move(-1, 0);
    }
}

bool Game::IsOutside()
{
    std::vector<Position> positions = currentBlock.GetCellPositions();
    for (Position pos : positions)
    {
        if (grid.IsTileOutside(pos.row, pos.column))
        {
            return true;
        }
    }
    return false;
}