#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> al;

void initAl(int V) {
  al.resize(V);
}

void addEdge(int iv, int dv, int weight, bool directed = false) {
  if (al.size() == 0) { cout << "AL not initialized" << endl; return; }
  if (iv >= al.size() || dv >= al.size()) { cout << "Index overflow" << endl; return; }
  al.at(iv).push_back(ii(dv, weight));
  if (!directed) al.at(dv).push_back(ii(iv, weight));
}

void printAl() {
  for (int i = 0; i < al.size(); i++) {
    cout << i << " : ";
    for (int j = 0; j < al.at(i).size(); j++) cout << al.at(i).at(j).first << "(" << al.at(i).at(j).second << ") ";
    cout << endl;
  }
}

int main() {
  initAl(10);
  addEdge(16, 1, 5);
  addEdge(0, 2, 10, true);
  addEdge(2, 4, 3);
  addEdge(4, 3, 1);
  addEdge(8, 6, 8);
  addEdge(9, 8, 7);
  printAl();
}