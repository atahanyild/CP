#include <stdio.h>

#include <cmath>
using namespace std;

int N, M, *n, c, e;

void sortPrices()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (n[i] > n[j])
      {
        int temp = n[i];
        n[i] = n[j];
        n[j] = temp;
      }
    }
  }
}

bool priceExist(int price)
{
  int low = 0,
      high = N,
      mid = N / 2;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (n[mid] == price)
    {
      return true;
    }
    else if (n[mid] < price)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }
  return false;
}

void selectBooks()
{
  sortPrices();

  int dif = n[N - 1] - n[0];
  for (int i = 0; i < N; i++)
  {
    if (abs(M - 2 * n[i]) <= dif && priceExist(M - n[i]))
    {
      c = M - n[i] > n[i] ? n[i] : M - n[i];
      e = M - n[i] > n[i] ? M - n[i] : n[i];
      dif = e - c;
    }
  }
}

int main()
{
  while (scanf("%d", &N) != EOF)
  {
    n = new int[N];
    for (int i = 0; i < N; i++)
      scanf("%d", &n[i]);

    scanf("%d", &M);

    selectBooks();

    printf("Peter should buy books whose prices are %d and %d.\n\n", c, e);
    scanf("");
  }
  return 0;
}