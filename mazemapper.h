#ifndef MAZEMAPPER_H
#define MAZEMAPPER_H

#include <iostream>
#include <vector>
#include <stack>
#include "maze.h"

using namespace std;

class MazeMapper
{
    public:
        MazeMapper(){ cout << " " ; }

        vector<Maze> SolveThePuzzle(Maze map, vector<Maze> tiles);

    private:
        pair<int, int> whereToPlace(const Maze &map, const Maze tile);

		bool merge(Maze &maze, Maze &tile, int topLeftRow, int topLeftCol);
        bool canPlaceTile(const Maze &map, Maze tile, int topLeftRow, int topRightCol);
        bool isComplate(Maze &maze);

		bool isRotatable(const Maze &tile);

        void rotateTileClockwise(Maze &tile);

        void solver(Maze maze);
};

#endif // MAZEMAPPER_H
