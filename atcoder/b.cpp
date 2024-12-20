#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

const int N = 1e5 + 10;
int h[N], dp[N];
int n, k;

int solve(int s) {
  if (s == 0) return 0;
  if (dp[s] != INT_MAX) return dp[s];


  int ans = INT_MAX;
  for (int i = 1; i <= k && (s - i) >= 0; i++) {
    ans = min(solve(s - i) + abs(h[s] - h[s - i]), ans);
  }

  dp[s] = ans;
  return ans;
}

int main() {
  scanf("%d %d", &n, &k);

  fill(dp, dp + N, INT_MAX);

  for (int i = 0; i < n; i++) scanf("%d", &h[i]);

  dp[0] = 0;
  dp[1] = abs(h[0] - h[1]);

  int ans = solve(n - 1);
  printf("%d\n", ans);
  return 0;
}