#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int TC, NV;
vii g;
vi vis;

void dfs(int s) {
  vis[s] = 1;
  for (int i = 0; i < NV; i++) {
    if (g[s][i] != 0 && vis[i] == 0)
      dfs(i);
  }
}

int main() {
  scanf("%d", &TC);
  getchar(); getchar(); // to avoid the blank line
  vi res;
  while (TC--) {
    char LC; scanf("%c\n", &LC);
    NV = LC - 'A' + 1;
    g = vii(NV, vi(NV, 0));
    vis.assign(NV, 0);

    char inp[10];
    while (fgets(inp, sizeof(inp), stdin) && inp[0] != '\n') {
      g[inp[0] - 'A'][inp[1] - 'A'] = 1;
      g[inp[1] - 'A'][inp[0] - 'A'] = 1;
    }

    int rt = 0;
    for (int i = 0; i < NV; i++) {
      if (vis[i] == 0) {
        dfs(i);
        rt++;
      }
    }
    res.push_back(rt);
  }

  for (int i = 0; i < res.size(); i++)
  {
    printf("%d\n", res.at(i));
  }

}