#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#include <iostream>

#define MAX_NODE_COUNT 1048575

using namespace std;

int main()
{
  int TC;
  scanf("%d", &TC);

  while (TC--)
  {
    int D, I;
    scanf("%d %d", &D, &I);

    bitset<MAX_NODE_COUNT> bits(0);
    int cRes = 1;
    for (int i = 1; i < D; i++)
    {
      if (I % 2)
      {
        cRes = cRes * 2;
        I = (I + 1) / 2;
      }
      else
      {
        cRes = cRes * 2 + 1;
        I /= 2;
      }
    }

    printf("%d\n", cRes);
  }
}