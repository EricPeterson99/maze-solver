//
// Created by Eric Peterson on 5/14/20.
//

#ifndef THEMAZEPROJECT_SOLVEMAZE_H
#define THEMAZEPROJECT_SOLVEMAZE_H

using namespace std;

#include "maze.h"
vector<vector<Node>> breathFistSearch(vector<vector<Node>> maze, tuple <int, int> start, tuple <int, int> goal);
vector<vector<Node>> dijkstra(vector<vector<Node>> maze);
vector<vector<Node>> breathFistSearch(vector<vector<Node>> maze);
vector<vector<Node>> depthFistSearch(vector<vector<Node>> maze);


#endif //THEMAZEPROJECT_SOLVEMAZE_H
