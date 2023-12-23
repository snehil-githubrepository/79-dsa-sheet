class Solution {
    public : 
        //Tc : O(N ^ M) 
        //Sc : O(N) + O(N) 
        bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
          //is it possible to color particular color : checks for adjacent's color
          //col => color we are trying to do on that node
          for (int k = 0; k < n; k++) {
            //check if it is not the node itself && edge from k to node (adj node) && color of adj == col we are trying to do 
            if (k != node && graph[k][node] == 1 && color[k] == col) {
              return false;
            }
          }
          return true;
        }

        bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
          if (node == N) { //colored all the nodes
            return true; 
          }

          for (int i = 1; i <= m; i++) {
            if (isSafe(node, color, graph, N, i)) {
              color[node] = i;
              if (solve(node + 1, color, m, N, graph)) return true;
              color[node] = 0; //backtrack
            }
          }
          return false;
        }

        bool graphColoring(bool graph[101][101], int m, int N) {
          int color[N] = {0};//no nodes are colored initially
          if (solve(0, color, m, N, graph)) return true;
          return false;
        }

}