#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 1e5 + 50;

int n, h = 0, sc[3][MAX_N], memo[3][MAX_N];

int backtrack(int day, int last) {
  if (day == n) return 0;

  if (last >= 0 && memo[last][day] != -1) { return memo[last][day]; }

  int ans = -1;
  if (last != 0) { ans = max(backtrack(day + 1, 0) + sc[0][day], ans); }
  if (last != 1) { ans = max(backtrack(day + 1, 1) + sc[1][day], ans); }
  if (last != 2) { ans = max(backtrack(day + 1, 2) + sc[2][day], ans); }

  return memo[last][day] = ans;
}

int main() {
  scanf("%d", &n);
  memset(memo, -1, sizeof memo);

  for (int i = 0; i < n; i++) scanf("%d %d %d", &sc[0][i], &sc[1][i], &sc[2][i]);

  int ans = backtrack(0, -1);

  printf("%d\n", ans);

  return 0;
}