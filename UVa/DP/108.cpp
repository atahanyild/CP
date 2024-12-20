#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  int s[110][110];

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      scanf("%d", &s[i][j]);
      if (i != 0) s[i][j] += s[i - 1][j];
      if (j != 0) s[i][j] += s[i][j - 1];
      if (i != 0 && j != 0) s[i][j] -= s[i - 1][j - 1];
    }
  int mv = -127 * N * N;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = i; k < N; k++)
        for (int l = j; l < N; l++) {
          int sum = s[k][l];
          if (i != 0 && j != 0) sum += s[i - 1][j - 1];
          if (i != 0) sum -= s[i - 1][l];
          if (j != 0) sum -= s[k][j - 1];

          mv = max(sum, mv);
        }

  printf("%d\n", mv);
}