## Problem Statement : M Coloring Problem [Medium]

### _Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise._

```cpp
Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
```

```cpp
Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
```

- if we can't colour with M colors then return false else true

---

```
        0 - 3
        | \ |
        2 - 1

        f(0)
   (T)1 /\
     f(1)
    1/ |2 (T)
    x  f(2)
      1/ |2 \3 (T)
      x  x   f(3)
           1/ |2 \3 (T)
           x  x  f(4)

        we reached f(N) implies we return a True

```

so here's what we can pseudo code

```cpp
f(node) {
    if(node == N) {
        //we were able to color everything
        return true;
    }

    for(col = 1-> N) {
        if(possible) //to color that node
        {
            color[node] = col;
            if(f(node+1) == True) {
                return True;
            }
            color[node] = 0; //backtrack because the col didn't work out
        }
    }
    return false;
}
```

- From above lets try to analyze time Complexity :

> TC : N ^ M (on high level we can say this is t.c.)

> SC : O(N) + O(N) {color Array + auxilary space recursion tree}

---


