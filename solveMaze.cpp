
#include "solveMaze.h"
#include <queue>
#include <iostream>

#define OPEN 0
#define WALL 1
#define PATH 2

using namespace std;

vector<vector<Node>> aStar(vector<vector<Node>> maze)
{

}

vector<vector<Node>> dijkstra(vector<vector<Node>> maze)
{

}

vector<vector<Node>> breathFistSearch(vector<vector<Node>> maze, tuple <int, int> start, tuple <int, int> goal)
{
    bool found = false;

    //queue
    queue <tuple <int, int>> queue;
    tuple <int, int> current;
    queue.push(start);

    //while len of queue is not 0
    while (queue.size() != 0 || !found)
    {
        current = queue.front();
        queue.pop();

        vector<int> directions = {'U', 'D', 'L', 'R'};
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

            int x2 = get<0>(current) + (dx);
            int y2 = get<1>(current) + (dy);

            if(x2 == get<0>(goal) && y2 == get<1>(goal))
            {
                found = true;
            }

            else if(x2 > -1 && y2 > -1 && x2 < maze.size() && y2 < maze[1].size())
            {
                if(maze[x2][y2].state != WALL)
                {
                    if (maze[x2][y2].seen != 1)
                    {
                        maze[x2][y2].seen = 1;
                        maze[x2][y2].state = PATH;
                        queue.push(make_tuple(x2,y2));
                    }
                }
            }
        }
    }
        // pop current
        //check all neighbors if they are the goal
        // if not wall append to queue

    // Start at end a keep moving to node with the lowest weight


    return maze;

}

vector<vector<Node>> depthFistSearch(vector<vector<Node>> maze)
{

}
