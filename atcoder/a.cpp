#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAX_STONE = 1e5 + 100;

int s[MAX_STONE], sc;

int main() {
  // while ((scanf("%d", &sc) && sc != 0)) {
  int a = 1000, b = 1000, c = 0;
  scanf("%d", &sc);
  for (int i = 0; i < sc; i++) {
    scanf("%d", &s[i]);
    if (i == 1) {
      b = 0;
      c = abs(s[1] - s[0]);
    }
    else if (i > 1) {
      a = b;
      b = c;
      c = min(a + abs(s[i] - s[i - 2]), b + abs(s[i] - s[i - 1]));
    }
  }
  printf("%d\n", c);
  // }
}