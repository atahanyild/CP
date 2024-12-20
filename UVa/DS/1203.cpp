#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, pair<int, int> > mpair;
priority_queue <mpair, vector<mpair>, greater<mpair> >pq;


int main() {
  char s[20];
  int qnum, p;
  while (scanf("%s", s) && strcmp(s, "#"))
  {
    scanf("%d %d", &qnum, &p);

    pq.push(mpair(p, pair<int, int>(qnum, p)));
  }

  int n;
  scanf("%d", &n);
  while (n--) {
    mpair pr = pq.top();
    pq.pop();
    printf("%d\n", pr.second.first);

    pq.push(mpair(pr.first + pr.second.second, pr.second));
  }

}