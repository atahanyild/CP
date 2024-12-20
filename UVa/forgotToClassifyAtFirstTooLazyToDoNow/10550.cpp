#include <stdio.h>
using namespace std;

int main()
{
  int i, a, b, c, res = 1080;
  i = a = b = c = 0;

  scanf("%d %d %d %d", &i, &a, &b, &c);

  while (a || b || c || i)
  {
    res += 1080 + ((i - a + 40) % 40 + (b - a + 40) % 40 + (c - b + 40) % 40);
    printf("%d", res);

    scanf("%d %d %d %d", &i, &a, &b, &c);
  }
  return 0;
}