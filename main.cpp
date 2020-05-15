#include <iostream>
#include "maze.h"
#include <chrono>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    bool run = true;
    char input;

    int rowMax = 20;
    int colMax = 80;

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
                       "B - BFS\n"
                       "D - DFS\n");
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