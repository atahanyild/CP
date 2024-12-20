#include <cstdio>

using namespace std;

const int MAX_N = 1000;
int c[MAX_N], n, TC;

int main() {
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    int sum = 1, coins = n > 1 ? 2 : 1;

    for (int i = 1; i < n - 1; i++) {
      if (sum + c[i] < c[i + 1]) { coins++; sum += c[i]; }
    }

    printf("%d\n", coins);
  }
}