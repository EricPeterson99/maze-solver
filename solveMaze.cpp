
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
    tuple <int, int> current;

    // Describe first node
    maze[get<0>(start)][get<1>(start)].level = 0;
    maze[get<0>(start)][get<1>(start)].seen = 1;

    //queue
    queue <tuple <int, int>> queue;
    queue.push(start);

    //while len of queue is not 0
    while (queue.size() != 0 || !found)
    {
        current = queue.front();
        queue.pop();

        // search all directions for a new node
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

            // If goal
            if(x2 == get<0>(goal) && y2 == get<1>(goal))
            {
                found = true;
            }

            // update node and add to queue if valid
            else if(x2 > -1 && y2 > -1 && x2 < maze.size() && y2 < maze[1].size())
            {
                if(maze[x2][y2].state != WALL  && maze[x2][y2].seen != 1)
                {
                    maze[x2][y2].seen = 1;
                    maze[x2][y2].level = 1 + maze[get<0>(current)][get<1>(current)].level;
                    queue.push(make_tuple(x2,y2));
                }
            }
        }
    }

    //start at the goal and work backwards to find the path
    current = goal;
    while(get<0>(current) != 0 || get<1>(current) != 0)
    {
        tuple <int, int> min = current;

        // find node with lowest weight
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

            //If valid node
            if(x2 > -1 && y2 > -1 && x2 < maze.size() && y2 < maze[1].size())
            {
                // compare to current min
                if(maze[x2][y2].state != WALL && maze[x2][y2].level < maze[get<0>(min)][get<1>(min)].level)
                {
                    min = make_tuple(x2,y2);
                }
            }
        }

        //set min node to PATH
        current = min;
        maze[get<0>(current)][get<1>(current)].state = PATH;
    }

    maze[0][0].state = 'S';
    return maze;

}

vector<vector<Node>> depthFistSearch(vector<vector<Node>> maze)
{

}
