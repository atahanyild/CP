#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> vi;

class UFDS {
private:
  vi p, rank, setSize;
  int numSets;

public:
  UFDS(int N) {
    p.assign(N, 0);
    rank.assign(N, 0);
    setSize.assign(N, 1);
    numSets = N;
    for (int i = 0; i < N; i++) p[i] = i;
  };

  int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); };
  int numDisjointSets() { return numSets; };
  int sizeOfSet(int i) { return setSize[findSet(i)]; };

  void unionSet(int i, int j) {
    int x = findSet(i);
    int y = findSet(j);
    if (x != y) {
      if (rank[x] > rank[y]) swap(x, y);

      p[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
      setSize[y] += setSize[x];
      numSets--;
    }
  };
};


int main() {
  UFDS S(5); // create 5 disjoint sets
  printf("%d\n", S.numDisjointSets()); // 5
  S.unionSet(0, 1);
  printf("%d\n", S.numDisjointSets()); // 4
  S.unionSet(2, 3);
  printf("%d\n", S.numDisjointSets()); // 3
  S.unionSet(4, 3);
  printf("%d\n", S.numDisjointSets()); // 2
  printf("isSameSet(0, 3) = %d\n", S.isSameSet(0, 3)); // 0 (false)
  printf("isSameSet(4, 3) = %d\n", S.isSameSet(4, 3)); // 1 (true)
  for (int i = 0; i < 5; ++i) // 1 for {0, 1} and 3 for {2, 3, 4}
    printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n",
      i, S.findSet(i), i, S.sizeOfSet(i));
  S.unionSet(0, 3);
  printf("%d\n", S.numDisjointSets()); // 1
  for (int i = 0; i < 5; ++i) // 3 for {0, 1, 2, 3, 4}
    printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n",
      i, S.findSet(i), i, S.sizeOfSet(i));
  return 0;
}