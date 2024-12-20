#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int N;
  while (scanf("%d", &N), N != 0) {
    int sum = 0, ans = 0, tmp;
    for (int i = 0; i < N; i++) {
      scanf("%d", &tmp);
      sum += tmp;

      ans = max(sum, ans);

      if (sum < 0)
        sum = 0;
    }

    if (ans > 0) printf("The maximum winning streak is %d.\n", ans);
    else printf("Losing streak.\n");
  }
}