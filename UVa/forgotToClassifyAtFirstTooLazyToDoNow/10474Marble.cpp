#include <stdio.h>
#include <algorithm>
using namespace std;

//WORKS BUT RUNTIME ERROR ON VJUDGE


int findInArray(int ar[], int start, int end, int target) {
  int tStart = start, tEnd = end, mid;
  while (start <= end) {
    mid = start + (end - start) / 2;

    if (ar[mid] == target) {
      return mid;
    }

    if (ar[mid] < target) start = mid + 1;

    else { end = mid - 1; }
  }

  return -1;
}

bool comp(int a, int b) { return a < b; }
int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);
  int m[N];
  int q[Q];

  int counter = 1;
  while (N || Q) {
    printf("CASE# %d:", counter++);

    for (int i = 0; i < N; i++) scanf("%d", &m[i]);

    for (int i = 0; i < Q; i++) scanf("%d", &q[i]);

    sort(m, m + N, comp);
    for (int i = 0; i < Q; i++) {
      int start = 0, end = N;
      int place = findInArray(m, start, end, q[i]);
      if (place == -1) printf("%d not found\n", q[i]);
      else printf("%d found at %d\n", q[i], ++place);
    }

    scanf("%d %d", &N, &Q);
  }
  return 0;
}