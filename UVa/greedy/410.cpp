#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int C, S;
  int set = 1;
  while (scanf("%d", &C) != EOF) {
    scanf("%d", &S);
    vector<int> s(2 * C);

    double tot = 0;
    for (int i = 0; i < S; i++) {
      scanf("%d", &s[i]);
      tot += s[i];
    }

    sort(s.begin(), s.end());

    double im = 0;
    tot /= C;
    printf("Set #%d\n", set++);
    for (int i = 0; i < C;i++) {
      im += abs((s[i] + s[2 * C - 1 - i]) - tot);
      printf(" %d:", i);
      if (s[i]) printf(" %d", s[i]);
      if (s[2 * C - 1 - i]) printf(" %d", s[2 * C - 1 - i]);
      printf("\n");
    }
    printf("IMBALANCE = %.5lf\n\n", im);
  }

  return 0;
}