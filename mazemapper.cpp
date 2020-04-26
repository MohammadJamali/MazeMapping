#include "mazemapper.h"

vector<Maze> result;
vector<Maze> tiles;

void MazeMapper::solver(Maze maze)
{
    if(isComplate(maze)) {
		for (int i = 0; i < result.size(); i++)
			if(maze == result.at(i))
				return;

        result.push_back(maze);
        return;
    }

    for (unsigned int i = 0; i < tiles.size(); ++i) {
		Maze tile = tiles.at(i);
        for (int rotation = 0; rotation < 4; ++rotation) {
            pair<int, int> tilePlace = whereToPlace(maze, tile);

            if(tilePlace.first != -1){
				Maze mazeTemp(maze);
                merge(mazeTemp, tile, tilePlace.first, tilePlace.second);
                solver(mazeTemp);
            }

			if(!isRotatable(tile)) break;
			
			tile.rotateTileClockwise();
        }
    }
}

bool MazeMapper::isRotatable(const Maze &tile)
{
	if(tile.getColSize() == 1 && tile.getRowSize() == 1)
		return false;

    if(tile.getColSize() == tile.getRowSize())
        for (int i = 0; i < tile.getRowSize(); i++)
            for (int j = 0; j < tile.getColSize(); j++)
                if(tile.operator()(i, j) == 0)
                    return true;
    else
        return true;

	return false;
}

vector< Maze > MazeMapper::SolveThePuzzle(Maze map, vector< Maze > _tiles)
{
	result.clear();
	tiles.clear();
	tiles = _tiles;

    solver(map);
    
	return result;
}

pair<int, int> MazeMapper::whereToPlace(const Maze &map, const Maze tile)
{
    for (int row = 0; row < map.getRowSize(); ++row)
        for (int col = 0; col < map.getColSize(); ++col)
            if(canPlaceTile(map, tile, row, col))
                return *(new pair<int, int>(row, col));

    return *(new pair<int, int>(-1, -1));
}

bool MazeMapper::canPlaceTile(const Maze &map, Maze tile, int topLeftRow, int topRightCol)
{
    for (int i = 0; i < tile.getRowSize(); ++i)
        for (int j = 0; j < tile.getColSize(); ++j)
            if (tile.operator ()(i, j))
                if(map.operator ()(topLeftRow + i, topRightCol + j))
                    return false;

    return true;
}

bool MazeMapper::merge(Maze &maze, Maze &tile, int topLeftRow, int topLeftCol)
{
    if(topLeftRow + tile.getRowSize() > maze.getRowSize() ||
            topLeftCol + tile.getColSize() > maze.getColSize())
        return false;

    if(! canPlaceTile(maze, tile, topLeftRow, topLeftCol))
        return false;

    for (int i = 0; i < tile.getRowSize(); ++i)
        for (int j = 0; j < tile.getColSize(); ++j)
            if (tile.operator ()(i, j))
                maze.operator ()(topLeftRow + i, topLeftCol + j, tile.operator ()(i, j));

    return true;
}

bool MazeMapper::isComplate(Maze &maze)
{
    for (int i = 0; i < maze.getRowSize(); ++i)
        for (int j = 0; j < maze.getColSize(); ++j)
            if(!maze.operator ()(i, j))
                return false;

    return true;
}
