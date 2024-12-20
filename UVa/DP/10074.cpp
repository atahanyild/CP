#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
const int D = 110;
int l[D][D];
int sum[D][D];

void calculateSum() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i > 0) sum[i][j] += sum[i - 1][j];
      if (j > 0) sum[i][j] += sum[i][j - 1];
      if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
      sum[i][j] += l[i][j];
    }
}


int main() {
  scanf("%d %d", &n, &m);

  while ((n > 0 || m > 0)) {
    memset(l, 0, sizeof l);
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        scanf("%d", &l[i][j]);

    calculateSum();
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int k = i; k < n; k++)
          for (int l = j; l < m; l++) {
            int area = sum[k][l];
            if (i > 0) area -= sum[i - 1][l];
            if (j > 0) area -= sum[k][j - 1];
            if (i > 0 && j > 0) area += sum[i - 1][j - 1];

            if (area == 0) ans = max(ans, (abs(k - i + 1) * abs(l - j + 1)));
          }

    printf("%d\n", ans);
    scanf("%d %d", &n, &m);
  }
}kskdnsknd