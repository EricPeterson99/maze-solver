# c++-maze-solver

This is a maze solver program that will generate a maze with multiple paths then identify the shortest path through multiple searching algorithms.

Supported searching algorithms:
- A*
- Dijkstra's
- BFS

## Example

Sample generated maze:
```
____________________________
|S     ■   ■           ■   |
|  ■ ■ ■   ■ ■ ■   ■   ■   |
|                  ■       |
|■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■   |
|      ■   ■ ■ ■   ■       |
|  ■   ■   ■ ■ ■   ■   ■ ■ |
|  ■           ■       ■   |
|  ■ ■ ■ ■ ■ ■ ■   ■ ■ ■   |
|      ■           ■       |
|■ ■   ■   ■ ■ ■ ■ ■   ■ ■ |
|      ■           ■       |
|  ■   ■ ■ ■ ■ ■   ■ ■ ■   |
|  ■       ■               |
|  ■   ■   ■   ■ ■ ■ ■ ■ ■ |
|  ■   ■   ■       ■       |
|  ■ ■ ■ ■ ■ ■ ■   ■   ■ ■ |
|              ■       ■   |
|  ■   ■ ■ ■   ■   ■   ■   |
|  ■       ■       ■     E |
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
```

Shortest path found with A* algorithm:
```
Length of the path: 55
____________________________
|S     ■   ■     · · · ■   |
|· ■ ■ ■   ■ ■ ■ · ■ · ■   |
|· · · · · · · · · ■ · · · |
|■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ · |
|      ■   ■ ■ ■   ■ · · · |
|  ■   ■   ■ ■ ■   ■ · ■ ■ |
|  ■           ■ · · · ■   |
|  ■ ■ ■ ■ ■ ■ ■ · ■ ■ ■   |
|      ■ · · · · · ■       |
|■ ■   ■ · ■ ■ ■ ■ ■   ■ ■ |
|      ■ · · · · · ■       |
|  ■   ■ ■ ■ ■ ■ · ■ ■ ■   |
|  ■       ■ · · ·         |
|  ■   ■   ■ · ■ ■ ■ ■ ■ ■ |
|  ■   ■   ■ · · · ■       |
|  ■ ■ ■ ■ ■ ■ ■ · ■   ■ ■ |
|              ■ · · · ■   |
|  ■   ■ ■ ■   ■   ■ · ■   |
|  ■       ■       ■ · · E |
‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
1.38311 ms
```
