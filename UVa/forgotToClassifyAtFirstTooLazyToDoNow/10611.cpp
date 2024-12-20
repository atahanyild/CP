#include <stdio.h>

using namespace std;

int N, *lady, Q, *qAr, shorter, taller;

void findLady(int luchu)
{
  int low = 0, high = N - 1, midPtr = N / 2;
  while (!(shorter && taller))
  {
    if (lady[midPtr] == luchu)
    {
      shorter = lady[midPtr - 1];
      taller = lady[midPtr + 1];
    }

    else if (lady[midPtr] > luchu)
    {
      if (lady[midPtr - 1] <= luchu)
        taller = lady[midPtr];
      high = midPtr;
    }

    else if (lady[midPtr] < luchu)
    {
      if (lady[midPtr + 1] >= luchu)
        shorter = lady[midPtr];
      low = midPtr;
    }

    midPtr = (high - low) / 2;
  }
}

int main()
{
  scanf("%d", &N);

  lady = new int[N];

  for (int i = 0; i < N; i++)
    scanf("%d", &lady[i]);

  int temp = 0;
  scanf("%d", &temp);

  shorter = 0;
  taller = 0;
  findLady(temp);
  printf("%d %d", shorter, taller);

  // scanf("%d", &Q);
  // qAr = new int[Q];
  // for (int j = 0; j < Q; j++)
  //   scanf("%d", &qAr[j]);

  // int counter = 0;
  // printf("here");
  // while (Q--)
  // {
  //   shorter = 0;
  //   taller = 0;
  //   findLady(qAr[counter]);
  //   printf("%d %d", shorter, taller);
  //   counter++;
  // }
  return 0;
}