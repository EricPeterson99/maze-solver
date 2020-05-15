#include <iostream>
#include "maze.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    bool run = true;
    char input;

    int rowMax = 10;
    int colMax = 30;

    Maze *maze = new Maze(rowMax, colMax);

    while (run)
    {
        printf("List of commands:\n"
               "C - Generate new maze\n"
               "P - Print maze in console\n"
               "S - Find Solution to the maze\n"
               "Q - Quit\n");
        cin >> input;

        switch (input)
        {
            case 'c':
            case 'C':
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