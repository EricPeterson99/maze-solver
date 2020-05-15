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
    numOfCols = cols;

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
    //Create Path
    Visit(0,0);

    // Make sure that the end node is free
    maze[numOfRows-1][numOfCols-2].state = OPEN;

    //Change start and end state to reflect that
    maze[0][0].state = 'S';
    maze[numOfRows-1][numOfCols-1].state = 'E';
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
    auto start = chrono::steady_clock::now();
    switch(approach)
    {
        // A*
        case 'a':
        case 'A':
            print(aStar(maze, make_tuple(0,0), make_tuple(numOfRows-1,numOfCols-1)));
            break;

        // dijkstra's
        case 'k':
        case 'K':
            print(dijkstra(maze, make_tuple(0,0), make_tuple(numOfRows-1,numOfCols-1)));
            break;

        //BFS
        case 'b':
        case 'B':
            print(breathFistSearch(maze, make_tuple(0,0), make_tuple(numOfRows-1,numOfCols-1)));
            break;

        //DFS
        case 'd':
        case 'D':
//            depthFistSearch();
            break;
    }
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl << endl;

}

void Maze::print()
{
    print(maze);
}

void Maze::print(vector<vector<Node>> maze)
{
    // Create the top bar
    for(int i = 0; i <= maze[0].size(); i++)
    {
        cout << "__";
    }
    cout << endl;

    // Displaying the 2D vector
    for (int i = 0; i < maze.size(); i++) {
        cout << '|';
        for (int j = 0; j < maze[i].size(); j++)
        {
            if (maze[i][j].state == WALL) {
                cout << "■";
            } else if (maze[i][j].state == PATH) {
                cout << "·";
            } else if (maze[i][j].state == OPEN){
                cout << ' ';
            } else {
                cout << char(maze[i][j].state);
            }
            cout << ' ';
        }
        cout << '|';
        cout << endl;
    }

    // Create the bottom bar
    for(int i = 0; i <= maze[0].size(); i++)
    {
        cout << "‾‾";
    }
    cout << endl;
}

