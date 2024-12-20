#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > el;

void initEl(int V) {
  el.resize(V);
}

void addEdge(int src, int dest, bool directed = false) {
  if (el.size() == 0) { cout << "EL not initialized" << endl; return; }
  if (src >= el.size() || dest >= el.size()) { cout << "Index overflow" << endl; return; }

  el.at(src).push_back(dest);
  if (!directed) el.at(dest).push_back(src);
}

void printEl() {
  for (int i = 0; i < el.size(); i++) {
    cout << i << " : ";
    for (int j = 0; j < el.at(i).size(); j++)
    {
      cout << el.at(i).at(j) << " ";
    }
    cout << endl;
  }
}

int main() {
  initEl(10);
  addEdge(0, 1);
  addEdge(1, 2);
  addEdge(3, 4, true);
  printEl();
}