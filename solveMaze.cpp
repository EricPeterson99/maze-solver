
#include "solveMaze.h"
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iostream>

#define OPEN 0
#define WALL 1
#define PATH 2

using namespace std;

vector<vector<Node>> aStar(vector<vector<Node>> maze, tuple <int, int> start, tuple <int, int> goal)
{
    maze[get<0>(start)][get<1>(start)].parent = make_tuple(-1,-1);
    maze[get<0>(goal)][get<1>(goal)].parent = make_tuple(-1,-1);

    bool found = false;

    tuple<int,int> current;

    //create open and closed list
    list <tuple<int,int>> openList, closedList;

    //add start node to open
    openList.push_back(start);

    //while open list is not empty
    while(!openList.empty() || !found)
    {
        //Get the current node
        current = openList.front();
        list <tuple<int,int>> :: iterator it;
        for(it = openList.begin(); it != openList.end(); ++it)
        {
            if(maze[get<0>(*it)][get<1>(*it)].f < maze[get<0>(current)][get<1>(current)].f)
            {
                current = *it;
            }
        }

        closedList.push_back(current);
        openList.remove(current);

        //if goal
        if(current == goal)
        {
            found = true;
        }
        else
        {
            //Expand all children
            vector<int> directions = {'U', 'D', 'L', 'R'};
            for(int i = 0; i < 4; i++) {
                int dy = 0, dx = 0;

                switch (directions[i]) {
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
                tuple<int,int> child = make_tuple(x2,y2);

                //if valid location
                if(x2 > -1 && y2 > -1 && x2 < maze.size() && y2 < maze[1].size() && maze[x2][y2].state != WALL)
                {
                    // Check if child is already in the closed list
                    bool closedContains = false;
                    list <tuple<int,int>> :: iterator it;
                    for(it = closedList.begin(); it != closedList.end(); ++it)
                    {
                        if(*it == child)
                        {
                            closedContains = true;
                        }
                    }

                    if(!closedContains)
                    {
                        maze[get<0>(child)][get<1>(child)].parent = current;
                        maze[get<0>(child)][get<1>(child)].g = 1 + maze[get<0>(current)][get<1>(current)].g;
                        maze[get<0>(child)][get<1>(child)].h = sqrt( pow((get<0>(child) - get<0>(goal)), 2) + pow((get<1>(child) - get<0>(goal)), 2));
                        maze[get<0>(child)][get<1>(child)].f = maze[get<0>(child)][get<1>(child)].g + maze[get<0>(child)][get<1>(child)].h;
                        maze[get<0>(child)][get<1>(child)].level = maze[get<0>(child)][get<1>(child)].f;

                        //check if child is already in the list and is better weighted
                        bool openContains = false;
                        list <tuple<int,int>> :: iterator it;
                        for(it = openList.begin(); it != openList.end(); ++it)
                        {
                            if(*it == child && maze[get<0>(*it)][get<1>(*it)].g < maze[get<0>(child)][get<1>(child)].g)
                            {
                                openContains = true;
                            }
                        }

                        //Added child to open list if needed
                        if(!openContains)
                        {
                            openList.push_back(child);
                        }
                    }
                }
            }
        }
    }
    return backtrackByParent(maze, goal);
}

vector<vector<Node>> dijkstra(vector<vector<Node>> maze, tuple <int, int> start, tuple <int, int> goal)
{
    maze[get<0>(start)][get<1>(start)].parent = make_tuple(-1,-1);
    maze[get<0>(goal)][get<1>(goal)].parent = make_tuple(-1,-1);

    bool found = false;

    tuple<int,int> current;

    //create open and closed list
    list <tuple<int,int>> openList, closedList;

    //add start node to open
    openList.push_back(start);

    //while open list is not empty
    while(!openList.empty() || !found)
    {
        //Get the current node
        current = openList.front();
        closedList.push_back(current);
        openList.remove(current);

        //if goal
        if(current == goal)
        {
            found = true;
        }
        else
        {
            //Expand all children
            vector<int> directions = {'U', 'D', 'L', 'R'};
            for(int i = 0; i < 4; i++) {
                int dy = 0, dx = 0;

                switch (directions[i]) {
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
                tuple<int,int> child = make_tuple(x2,y2);

                //if valid location
                if(x2 > -1 && y2 > -1 && x2 < maze.size() && y2 < maze[1].size() && maze[x2][y2].state != WALL)
                {
                    // Check if child is already in the closed list
                    bool closedContains = false;
                    list <tuple<int,int>> :: iterator it;
                    for(it = closedList.begin(); it != closedList.end(); ++it)
                    {
                        if(*it == child)
                        {
                            closedContains = true;
                        }
                    }

                    if(!closedContains)
                    {
                        maze[get<0>(child)][get<1>(child)].parent = current;
                        maze[get<0>(child)][get<1>(child)].g = 1 + maze[get<0>(current)][get<1>(current)].g;

                        //check if child is already in the list and is better weighted
                        bool openContains = false;
                        list <tuple<int,int>> :: iterator it;
                        for(it = openList.begin(); it != openList.end(); ++it)
                        {
                            openContains = true;
                        }

                        //Added child to open list if needed
                        if(!openContains)
                        {
                            openList.push_back(child);
                        }
                    }
                }
            }
        }
    }
    return backtrackByParent(maze, goal);
}

vector<vector<Node>> breathFistSearch(vector<vector<Node>> maze, tuple <int, int> start, tuple <int, int> goal) {
    bool found = false;
    tuple<int, int> current;

    // Describe first node
    maze[get<0>(start)][get<1>(start)].level = 0;
    maze[get<0>(start)][get<1>(start)].seen = 1;

    //queue
    queue<tuple<int, int>> queue;
    queue.push(start);

    //while len of queue is not 0
    while (queue.size() != 0 || !found) {
        current = queue.front();
        queue.pop();

        // search all directions for a new node
        vector<int> directions = {'U', 'D', 'L', 'R'};
        for (int i = 0; i < 4; i++) {
            int dy = 0, dx = 0;

            switch (directions[i]) {
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
            if (x2 == get<0>(goal) && y2 == get<1>(goal)) {
                found = true;
            }

                // update node and add to queue if valid
            else if (x2 > -1 && y2 > -1 && x2 < maze.size() && y2 < maze[1].size()) {
                if (maze[x2][y2].state != WALL && maze[x2][y2].seen != 1) {
                    maze[x2][y2].seen = 1;
                    maze[x2][y2].level = 1 + maze[get<0>(current)][get<1>(current)].level;
                    queue.push(make_tuple(x2, y2));
                }
            }
        }
    }
    return backtrackByDistance(maze, goal);
}

vector<vector<Node>> depthFistSearch(vector<vector<Node>> maze)
{

}

vector<vector<Node>> backtrackByParent(vector<vector<Node>> maze, tuple<int, int> goal)
{
    tuple<int,int> current = maze[get<0>(goal)][get<1>(goal)].parent;
    while(maze[get<0>(current)][get<1>(current)].parent != make_tuple(-1,-1))
    {
        maze[get<0>(current)][get<1>(current)].state = PATH;
        current = maze[get<0>(current)][get<1>(current)].parent;
    }
    return maze;
}

vector<vector<Node>> backtrackByDistance(vector<vector<Node>> maze, tuple<int, int> goal)
{
    //start at the goal and work backwards to find the path
    tuple<int,int>current = goal;
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
