#include <stdio.h>

int TC, n;
char *s;

int removalCount()
{
  int count = 0;
  for (int i = 0; i < n - 2; i++)
  {
    if (s[i] != 'm' && s[i] != 'p')
      continue;

    if (s[i] == 'm' && i + 2 < n)
    {
      if (s[i + 1] == 'a' && s[i + 2] == 'p')
      {
        count++;
        i += 2;
      }
    }

    else if (s[i] == 'p' && i + 2 < n)
    {
      if (s[i + 1] == 'i' && s[i + 2] == 'e')
      {
        count++;
        i += 2;
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
    scanf("%d", &n);
    s = new char[n];

    char blank;
    scanf("%c", &blank);

    for (int i = 0; i < n; i++)
      scanf("%c", &s[i]);

    int count = removalCount();
    printf("%d\n", count);
  }

  return 0;
}