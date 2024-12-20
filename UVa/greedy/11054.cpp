#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
  int N;
  scanf("%d", &N);

  while (N != 0) {
    int ar[N];
    long long work = 0, last = 0;
    for (int i = 0; i < N; i++) scanf("%d", &ar[i]);

    for (int i = 0; i < N; i++)
    {
      work += abs(last);
      last += ar[i];
    }

    printf("%lld\n", work);
    scanf("%d", &N);
  }
  return 0;
}