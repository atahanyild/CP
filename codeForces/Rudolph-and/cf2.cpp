#include <stdio.h>

using namespace std;

int TC, N, *num;

bool isCorrect()
{
  for (int i = 1; i < N - 1; i++)
  {
    if (num[i - 1] == 0 && i != N - 2)
      continue;

    if (num[i - 1] == 0 && i == N - 2)
      return false;

    num[i] -= 2 * num[i - 1];
    num[i + 1] -= num[i - 1];
    num[i - 1] -= num[i - 1];
  }

  for (int i = 0; i < N; i++)
    if (num[i] != 0)
      return false;

  return true;
}

int main()
{
  scanf("%d", &TC);

  while (TC--)
  {
    scanf("%d", &N);

    num = new int[N];

    for (int i = 0; i < N; i++)
      scanf("%d", &num[i]);

    bool result = isCorrect();

    if (result)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}