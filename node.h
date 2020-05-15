#ifndef NODE_H
#define NODE_H

#define WALL 1

#include <string>

class Node
{
public:
    Node() {

    }
    std::tuple <int,int> parent;
    int state = WALL;
    int level;
    int priority;
    int seen = 0;
    float f = 0;
    float h = 0;
    float g = 0;
};

#endif
