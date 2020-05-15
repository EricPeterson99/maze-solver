#ifndef MAZE_H
#define MAZE_H

#include "node.h"
#include <vector>

using namespace std;

class Maze
{
public:
    Maze(int rows, int cols);
    void initialize(int rows, int cols);
    void generate();
    void solve(char approach);
    void print();

private:
    std::vector<std::vector<Node>> maze;
    int numOfRows;
    int numOfCols;

    void Visit(int x, int y);
    void print(vector<vector<Node>> maze);
};

#endif