#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_COIN 110
int m, c[MAX_COIN], dif, memo[MAX_COIN][550];

int backtrack(int dif, int coin) {
  // cout << "dif" << dif << "coin" << coin << "memo" << memo[coin][dif] << endl;
  if (dif == 0) return 0;
  if (coin == m) return dif;
  if (memo[coin][dif] != -1) return memo[coin][dif];

  int take = dif - 2 * c[coin] >= 0 ? backtrack(dif - 2 * c[coin], coin + 1) : 1000000;
  if (take == 0) return 0;
  int dont = backtrack(dif, coin + 1);
  if (dont == 0) return 0;

  int ans = min(take, dont);

  memo[coin][dif] = ans;
  return ans;
}

int main() {
  int TC;
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d", &m);
    memset(memo, -1, sizeof memo);
    dif = 0;
    for (int i = 0; i < m; i++) { scanf("%d", &c[i]); dif += c[i]; }

    int ans = backtrack(dif, 0);
    printf("%d\n", ans);
  }
}