#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int a, b, row[8], lineCounter, printCounter = 0;

bool canPlace(int r, int c)
{
  for (int prev = 0; prev < c; prev++)
    if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
    {
      return false;
    }

  return true;
}

void backtrack(int c)
{
  if (c == 8 && row[b] == a)
  {
    printf("%2d \t", ++lineCounter);
    for (int i = 0; i < 8; i++)
      printf("%d ", row[i] + 1);
    printf("\n");
  }
  for (int r = 0; r < 8; r++)
  {
    if (canPlace(r, c))
    {
      row[c] = r;
      backtrack(c + 1);
    }
  }
}

int main()
{
  scanf("%d %d", &a, &b);
  a--;
  b--;
  lineCounter = 0;
  memset(row, 0, sizeof row);
  printf("SOLN \tCOLUMN \n");
  printf("#\t1 2 3 4 5 6 7 8");
  backtrack(0);
  return 0;
}