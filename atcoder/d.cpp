#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_ITEM_COUNT = 110;
const int MAX_KNAPSACK_SIZE = 1e5;

int N, W, values[MAX_ITEM_COUNT], weights[MAX_ITEM_COUNT];
long int  memo[MAX_ITEM_COUNT][MAX_KNAPSACK_SIZE];

long int backtrack(int it, int space) {
  if (space < 0) return 0;
  if (it == N) return 0;

  if (memo[it][space] != -1) return memo[it][space];

  long int ans = backtrack(it + 1, space);
  long int took = -1;
  if (space - weights[it] >= 0) took = values[it] + backtrack(it + 1, space - weights[it]);
  ans = max(ans, took);

  return (memo[it][space] = ans);
}

int main() {
  scanf("%d %d", &N, &W);
  for (int i = 0; i < N; i++) scanf("%d %d", &weights[i], &values[i]);

  memset(memo, -1, sizeof memo);

  long int ans = backtrack(0, W);

  printf("%ld", ans);
}