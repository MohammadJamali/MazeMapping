#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

#define OUT_OF_RANGE -1
#define FREE_CELL 0

class Maze
{
    public:
        Maze();
        Maze (const Maze& _maze);
        ~Maze();

        int operator ()(int r, int c) const;
        bool operator ()(int r, int c, int v);
		bool operator ==(const Maze& _maze);

        int getColSize() const { return col; }
        int getRowSize() const { return row; }

        bool initMaze(int rowSize, int colSize);
        void deallocMemory();

        void rotateTileClockwise();

        void print();

    private:
       int **maze, col, row;
};

#endif // MAZE_H
