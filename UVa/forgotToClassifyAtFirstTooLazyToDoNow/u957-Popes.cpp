#include <stdio.h>

using namespace std;

int Y, P, *pAr, dif = 0, start, end;

int getUpperBound(int start)
{
  int l = start, r = P - 1, mid = r / 2;
  int t = pAr[start] + Y - 1;
  while (l <= r)
  {
    mid = l + (r - l) / 2;

    if (pAr[mid] <= t)
      l = mid + 1;
    else
      r = mid - 1;
  }

  return l;
}

void findLargest()
{
  for (int i = 0; i < P - 1; i++)
  {
    int upIndex = getUpperBound(i);
    if (upIndex - i > dif)
    {
      dif = upIndex - i;
      start = pAr[i];
      end = pAr[upIndex - 1];
    }
  }
}

int main()
{
  while (scanf("%d", &Y) == 1)
  {
    dif = 0;
    scanf("%d", &P);
    pAr = new int[P];

    for (int i = 0; i < P; i++)
    {
      scanf("%d", &pAr[i]);
    }

    findLargest();

    printf("%d %d %d", dif, start, end);

    delete[] pAr;
  }

  return 0;
}