#include <iostream>
#include <vector>
#include <thread>
#include "window.h"
#include "box.h"
#include "mazemapper.h"
#include "maze.h"

using namespace std;


void drawFunction(vector<Maze> result, vector<Box *> objBoxes)
{
    for (int i = result.size()/2; ; i+= ((rand()%5) +1 )) {
        if (i >= result.size()-1) i = 0;
        int counter = 0;
        for (int row = 0; row < result.at(i).getRowSize(); ++row) {
            for (int col = 0; col < result.at(i).getColSize(); ++col) {
                if(result.at(i).operator()(row, col) == 1)
                    objBoxes.at(counter++)->changeColor(QColor(0, 0, 0, 255));
                else if(result.at(i).operator()(row, col) == 2)
                    objBoxes.at(counter++)->changeColor(QColor(128, 0, 0, 255));
                else if(result.at(i).operator()(row, col) == 3)
                    objBoxes.at(counter++)->changeColor(QColor(0, 128, 0, 255));
                else if(result.at(i).operator()(row, col) == 4)
                    objBoxes.at(counter++)->changeColor(QColor(0, 0, 128, 255));
                else if(result.at(i).operator()(row, col) == 5)
                    objBoxes.at(counter++)->changeColor(QColor(0, 128, 128, 255));
                else if(result.at(i).operator()(row, col) == 6)
                    objBoxes.at(counter++)->changeColor(QColor(128, 128, 0, 255));
                else if(result.at(i).operator()(row, col) == 7)
                    objBoxes.at(counter++)->changeColor(QColor(128, 0, 128, 255));
                else if(result.at(i).operator()(row, col) == 8)
                    objBoxes.at(counter++)->changeColor(QColor(128, 128, 255, 255));
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

int main(int argc, char **argv)
{
    cout << endl << "\t\t<*** Welcome to MazeMapper ***>";

    cout << endl << " Please enter size of map ( X Y ) :";

	int mapSizeX = 1, mapSizeY = 1;

	cin >> mapSizeX >> mapSizeY;

	Maze map;
	map.initMaze(mapSizeX, mapSizeY);

	for (int i = 0; i < map.getRowSize(); i++)
		for (int j = 0; j < map.getColSize(); j++)
		{
			int val = 0;
			
			cin >> val;

			if(val != 0 && val != 1)
			{
				cout << endl << "\tWrong input ! input must be '1' that declared as blocked ,'0' that declared as free cells ." << endl << endl;
				j--;
			}
			else
				map.operator()(i, j, val);
		}

	cout << endl;
	vector<Maze> tiles;

	int tileNumber = 1;
	cout << " Please Enter Tiles number : " ;
	cin >> tileNumber;

	for (int count = 0; count < tileNumber; count++)
	{
		int tileSizeX = 0, tileSizeY = 0;

		cout << endl << " Please enter size of your tile #" << count + 1 << " ( X Y ) :" ;
		cin >> tileSizeX >> tileSizeY ;
		
		Maze tile;
		tile.initMaze(tileSizeX, tileSizeY);

		cout << endl;

		for (int i = 0; i < tile.getRowSize(); i++)
			for (int j = 0; j < tile.getColSize(); j++)
			{
				int val = 0;

				cin >> val;

				if(val != 0 && val != 1)
				{
					cout << endl << "\tWrong input ! input must be '1' that declared as blocked ,'0' that declared as free cells ." << endl << endl;
					j--;
				}
				else tile.operator()(i, j, val * (count + 2));
			}

		tiles.push_back(tile);
	}

    cout << "\t-Working ... " << endl;

	MazeMapper objMazeMapper;
	vector< Maze > result  = objMazeMapper.SolveThePuzzle(map, tiles);

    cout << endl << "\t-Loading ..." << endl;

    if(result.size()>0){

        Window objWindow(argc, argv, "Maze Mapper !", 300, 300);

        vector<Box *> Boxes;

        int x = 0, y = 0;
        for (int i = 0; i < map.getRowSize(); ++i) {
            for (int j = 0; j < map.getColSize(); ++j) {
                Box *objBox = new Box(40, 40,x, y);
                objBox->changeColor(QColor(0, 0, 0, 255));
                objWindow.getQGraphicsScene()->addItem(objBox);
                Boxes.push_back(objBox);
                y+=20;
            }
            x+=20;
            y=0;
        }

        thread objThread(drawFunction, result, Boxes);

        objWindow.showWindow();

        for (int i = 0; i < Boxes.size(); ++i)
            delete Boxes.at(i);
    }
    else
    {
        cout << " There is no answere to show !"   << endl;
        getchar();
    }
    return 0;
}

