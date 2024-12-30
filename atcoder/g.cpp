#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_E_V = 1e5 + 10;

typedef vector<int> vi;
typedef vector<vi> vii;

vi ts;
vii gr(MAX_E_V);
int N, M, vis[MAX_E_V];

void dfs(int i) {
  vis[i] = 1;
  for (auto j : gr[i])
    if (!vis[j])
      dfs(j);

  ts.push_back(i);
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; i++) {
    int _v, _d;
    scanf("%d %d", &_v, &_d);
    gr[_v].push_back(_d);
  }

  for (int i = 1; i <= N; i++) {
    if (!vis[i]) dfs(i);
  }

  reverse(ts.begin(), ts.end());
  vi memo(N + 1, 0);
  for (auto i : ts)
    for (auto j : gr[i])
      memo[j] = max(memo[j], memo[i] + 1);

  printf("%d", (int)*max_element(memo.begin(), memo.end()));
}