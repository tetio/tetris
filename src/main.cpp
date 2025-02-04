#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    Grid grid = Grid();

    // grid.grid[0][0] = 1;
    // grid.grid[3][5] = 4;
    // grid.grid[17][8] = 7;

    IBlock block = IBlock();
    InitWindow(300, 600, "Tetris <raylib>");
    SetTargetFPS(60);
    grid.Print();
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }
    CloseWindow();
}