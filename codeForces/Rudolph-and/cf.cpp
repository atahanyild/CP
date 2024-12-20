#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int TC, N, M, k, *lp, *rp;

int calculateCount()
{
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    if (lp[i] >= k)
      continue;
    for (int j = 0; j < M; j++)
    {
      if (lp[i] + rp[j] <= k)
      {
        count++;
      }
    }
  }
  return count;
}

int main()
{
  scanf("%d", &TC);

  while (TC--)
  {
    scanf("%d %d %d", &N, &M, &k);

    lp = new int[N];
    rp = new int[M];

    for (int i = 0; i < N; i++)
    {
      scanf("%d", &lp[i]);
    }

    for (int j = 0; j < M; j++)
    {
      scanf("%d", &rp[j]);
    }

    int result = calculateCount();
    printf("%d\n", result);
  }

  return 0;
}