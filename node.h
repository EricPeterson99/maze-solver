#ifndef NODE_H
#define NODE_H

#define WALL 1

class Node
{
public:
    Node() {

    }

    int state = WALL;
    int level;
    int priority;
    int seen = 0;
};

#endif
