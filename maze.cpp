#include "maze.h"

Maze::Maze() {maze = 0;}

bool Maze::initMaze(int rowSize, int colSize)
{
    row = rowSize;
    col  = colSize;

    deallocMemory();

    maze = new int *[rowSize];

    if(!maze) {
        cout << endl << " Memory allocation error!" << endl;
        return false;
    }

    for (int i = 0; i < rowSize; ++i) {
        maze[i] = new int[colSize];

        if(!maze[i]) {
            cout << endl << " Memory alocator error!" << endl;
            return false;
        }

        for (int j = 0; j < colSize; ++j)
            maze[i][j] = FREE_CELL;
    }

    return true;
}

bool Maze::operator==(const Maze& _maze)
{
	if(_maze.getColSize() != col || _maze.getRowSize() != row)
		return false;

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if(maze[i][j] != _maze.operator()(i, j))
				return false;

	return true;
}

void Maze::deallocMemory()
{
    /*if (!maze) return;

    for (int i = 0; i < getRowSize(); ++i)
        if (maze[i] != NULL)
            delete [] maze[i];

    if (maze)
       delete [] maze;*/
}

Maze::Maze(const Maze& _maze)
{
    deallocMemory();
    initMaze(_maze.getRowSize(), _maze.getColSize());

    for (int i = 0; i < getRowSize(); ++i)
        for (int j = 0; j < getColSize(); ++j)
            maze[i][j] = _maze.operator ()(i, j);
}

int Maze::operator ()(int r, int c) const
{
    if (r >= 0 && r < getRowSize() && c >= 0 && c < getColSize())
        return maze[r][c];
    else
        return OUT_OF_RANGE;
}

bool Maze::operator ()(int r, int c, int v)
{
    if (r >= 0 && r < getRowSize() && c >= 0 && c < getColSize())
        maze[r][c] = v;
    else
        return false;

    return true;
}

void Maze::print()
{
    cout << endl;
    for (int row = 0; row < getRowSize(); ++row) {
        for (int col = 0; col < getColSize(); ++col) {
            cout << maze[row][col] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

void Maze::rotateTileClockwise()
{
    int maxLen = getColSize() > getRowSize() ? getColSize() : getRowSize();

    Maze squreTemp;
    squreTemp.initMaze(maxLen, maxLen);

    for (int row = 0; row < getRowSize(); ++row)
        for (int col = 0; col < getColSize(); ++col)
            squreTemp.operator ()(row, col, maze[row][col]);

    // transpose
    for (int i = 0; i < maxLen; ++i)
        for (int j = i + 1; j < maxLen; ++j){
            int temp = squreTemp.operator ()(i, j);
            squreTemp.operator ()(i, j, squreTemp.operator ()(j, i));
            squreTemp.operator ()(j, i, temp);
        }

    // reverse the rows
    for (int i = 0; i < maxLen; ++i)
        for (int j = 0; j < maxLen / 2; ++j){
            int temp = squreTemp.operator ()(i, j);
            squreTemp.operator ()(i, j, squreTemp.operator ()(i, maxLen - j - 1));
            squreTemp.operator ()(i, maxLen - j - 1, temp);
        }

    if (getColSize() < maxLen) {
        int temp = getColSize();

        deallocMemory();
        initMaze(temp, maxLen);

        for (int row = 0; row < getRowSize(); ++row)
            for (int col = 0; col < getColSize(); ++col)
                maze[row][col] = squreTemp.operator ()(row, col);
    }
    else
    {
        int temp = getRowSize();

        deallocMemory();
        initMaze(maxLen, temp);

        for (int row = 0; row < getRowSize(); ++row)
            for (int col = 0; col < getColSize(); ++col)
                maze[row][col] = squreTemp.operator ()(row, col + (maxLen - temp));
    }
}

Maze::~Maze()
{
    deallocMemory();
}
