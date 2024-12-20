#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int D = 8 + 1;
int a[D];
int b[D][D];
// int ans = 0, l_ans = 0;

bool place(int r, int c) {
  for (int prev = 0; prev < c; prev++)
    if (abs(a[prev] - r) == abs(prev - c) || r == a[prev]) return false;

  return true;
}

int backtrack(int c) {
  if (c == 8) {
    return 0;
  }

  int ans = -10000;
  for (int i = 0; i < 8; i++) {
    if (!place(i, c)) continue;

    a[c] = i;
    ans = max(ans, (backtrack(c + 1) + b[i][c]));
  }

  return ans;
}

int main() {
  int k;
  scanf("%d", &k);
  while (k--) {
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        scanf("%d", &b[i][j]);

    int ans = backtrack(0);
    printf("%5d\n", ans);
  }
}