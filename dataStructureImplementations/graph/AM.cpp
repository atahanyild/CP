#include <iostream>

using namespace std;

#define V 6

void initMatrix(int adjMatrix[V][V]) {
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      adjMatrix[i][j] = 0;
}

void printMatrix(int adjMatrix[V][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      cout << adjMatrix[i][j] << " ";
    cout << endl;
  }
}

void addEdge(int adjMatrix[V][V], int n1, int n2) {
  if (n1 >= V || n2 >= V) return;

  adjMatrix[n1][n2] = 1;
  adjMatrix[n2][n1] = 1;
}


int main() {
  int adjMatrix[V][V];

  initMatrix(adjMatrix);

  addEdge(adjMatrix, 0, 1);
  addEdge(adjMatrix, 0, 3);
  addEdge(adjMatrix, 0, 4);
  addEdge(adjMatrix, 1, 2);
  addEdge(adjMatrix, 1, 4);
  addEdge(adjMatrix, 2, 5);

  printMatrix(adjMatrix);
}