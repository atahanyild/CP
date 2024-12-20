#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int TC, r = 1, s;

  scanf("%d", &TC);
  while (TC--)
  {
    scanf("%d", &s);
    int sum = 0, ans = 0;
    int temp;
    int b_start = 1, b_stop = 1, start = 1;
    for (int i = 2; i <= s; i++) {
      scanf("%d", &temp);
      sum += temp;


      if (sum > ans || (sum == ans && (i - start > b_stop - b_start))) {
        ans = sum;
        b_start = start;
        b_stop = i;
      }

      if (sum < 0) {
        sum = 0;
        start = i;
      }
    }
    if (ans > 0) printf("The nicest part of route %d is between stops %d and %d\n", r, b_start, b_stop);
    else printf("Route %d has no nice parts\n", r);
    r++;
  }
  return 0;
}