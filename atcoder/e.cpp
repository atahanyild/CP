#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cstring>
using namespace std;

const int MAX_N = 105;
const int MAX_VALUE = 1e5;
const int MAX_W = 1e9 + 100;

int N, W, v[MAX_N], w[MAX_N], memo[MAX_N][MAX_VALUE], ans;

int giveMinWeight(int item, int val) {
  if (val < 0) return INT_MAX - W;
  if (val == 0) return 0;
  if (item == 0) return INT_MAX - W;


  int& ans = memo[item][val];
  if (ans != -1) return ans;

  int take = w[item] + giveMinWeight(item - 1, val - v[item]);
  int dont_take = giveMinWeight(item - 1, val);
  ans = min(take, dont_take);
  return ans;
}

int main() {
  scanf("%d %d", &N, &W);
  for (int i = 1; i <= N; i++) scanf("%d %d", &w[i], &v[i]);

  memset(memo, -1, sizeof memo);

  for (int i = MAX_VALUE; i >= 0; i--) {
    int minw = giveMinWeight(N, i);
    if (minw <= W) {
      ans = i;
      break;
    }
  }

  printf("%d\n", ans);
}