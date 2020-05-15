#include <iostream>
#include "maze.h"
#include <chrono>

using namespace std;

int main() {
    bool run = true;
    char input;

    // Define max maze size
    int rowMax = 5;
    int colMax = 18;

    Maze *maze = new Maze(rowMax, colMax);
    maze -> generate();

    while (run)
    {
        printf("List of commands:\n"
               "G - Generate new maze\n"
               "P - Print maze in console\n"
               "S - Find Solution to the maze\n"
               "Q - Quit\n");
        cin >> input;

        switch (input)
        {
            case 'g':
            case 'G':
                // Generate a random maze that is greater than 5x5
                maze = new Maze(rand() % rowMax + 5, rand() % colMax + 5);
                maze -> generate();
                break;

            case 'p':
            case 'P':
                maze -> print();
                break;

            case 's':
            case 'S':
                char approach;
                printf("What algorithm would you like:\n"
                       "A - A*\n"
                       "K - Dijkstra's\n"
                       "B - BFS\n");
                cin >> approach;
                maze -> solve(approach);
                break;

            case 'q':
            case 'Q':
                run = false;
                break;
        }

    }
    return 0;
}