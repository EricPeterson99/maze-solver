#include <iostream>
#include <vector>
#include "node.h"
#include "maze.h"
#include "solveMaze.h"

#define OPEN 0
#define WALL 1
#define PATH 2

using namespace std;

Maze::Maze(int rows, int cols)
{
    numOfRows = rows;
    numOfCols =cols;

    //Fill vector with walls
    for (int i = 0; i < numOfRows; i++) {
        vector<Node> temp;
        for (int j = 0; j < numOfCols; j++){
            temp.push_back(Node());
        }
        maze.push_back(temp);
    }
}

void Maze::initialize(int rows, int cols)
{
    Maze(rows, cols);
}

void Maze::generate()
{
    Visit(0,0);
    maze[numOfRows-1][numOfCols-1].state = PATH;
}

void Maze::Visit(int x, int y)
{
    maze[x][y].state = OPEN;

    vector<int> directions = {'U', 'D', 'L', 'R'};

    //randomize the order
    for(int i = 0; i < 4; i++)
    {
        //pick a random index
        int randIndex = rand() & 3;

        //swap
        int temp = directions[randIndex];
        directions[randIndex] = directions[i];
        directions[i] = temp;
    }

    for(int i = 0; i < 4; i++)
    {
        int dy = 0, dx = 0;

        switch(directions[i])
        {
            case 'U':
                dy = -1;
                break;
            case 'D':
                dy = 1;
                break;
            case 'L':
                dx = -1;
                break;
            case 'R':
                dx = 1;
                break;
        }

        int x2 = x + (dx<<1);
        int y2 = y + (dy<<1);

        if(x2 > -1 && y2 > -1 && x2 < numOfRows && y2 < numOfCols)
        {
            if(maze[x2][y2].state == WALL)
            {
                maze[x2 - dx][y2 - dy].state = OPEN;
                //print();
                Visit(x2,y2);
            }
        }
    }
}

void Maze::solve(char approach)
{
    switch(approach)
    {
        // A*
        case 'a':
        case 'A':
//            aStar();
            break;

        // dijkstra's
        case 'k':
        case 'K':
//            dijkstra();
            break;

        //BFS
        case 'b':
        case 'B':
            maze = breathFistSearch(maze, make_tuple(0,0), make_tuple(numOfRows-1,numOfCols-1));
            break;

        //DFS
        case 'd':
        case 'D':
//            depthFistSearch();
            break;
    }
}

void Maze::print()
{
    // Displaying the 2D vector
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++)
        {
            if (maze[i][j].state == WALL) {
                cout << 'X';
            } else if (maze[i][j].state == PATH) {
                cout << '*';
            } else {
                cout << ' ';
            }
            cout << ' ';
        }
        cout << endl;
    }
    cout << endl;
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

