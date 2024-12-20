#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int TC, M, C, it[25][25], memo[201][25];

int shop(int money, int g) {
  if (money < 0) return -100000;
  if (g == C) return M - money;

  if (memo[money][g] != -1) return memo[money][g];
  int ans = -1;
  for (int i = 1; i <= it[g][0]; i++) {
    ans = max(ans, shop(money - it[g][i], g + 1));
  }
  return memo[money][g] = ans;
}

int main() {
  scanf("%d", &TC);
  while (TC--)
  {
    scanf("%d %d", &M, &C);
    for (int i = 0; i < C; i++)
    {
      scanf("%d", &it[i][0]);
      for (int j = 1; j <= it[i][0]; j++)
        scanf("%d", &it[i][j]);
    }
    memset(memo, -1, sizeof memo);
    int spent = shop(M, 0);

    if (spent < 0) printf("no solution\n");
    else printf("%d\n", spent);
  }
  return 0;
}