#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;
typedef vector<int> vi;

class FenwickTree {
private: vi ft;

public:
  FenwickTree(int n) { ft.assign(n + 1, 0); };
  int LSOne(int a) { return (a & -a); };
  void adjust(int i, int v) {
    for (; i < (int)ft.size(); i += LSOne(i)) ft.at(i) += v;
  }

  int rsq(int i, int j) {
    return rsq(j) - rsq(i - 1);
  }

  int rsq(int i) {
    int sum = 0;
    for (; i; i -= LSOne(i)) sum += ft[i];
    return sum;
  }
};

const int MAX_N = 2e5 + 100;
int N, f[MAX_N];

int main() {
  int cs = 0;
  while (scanf("%d", &N) && N) {
    if (cs) printf("\n");
    printf("Case %d:\n", ++cs);
    for (int i = 1; i <= N; i++) scanf("%d", &f[i]);

    FenwickTree ft(N);
    for (int i = 1; i <= N; i++) ft.adjust(i, f[i]);

    char op[10];
    int a, b;
    while (scanf("%s", op) && strcmp(op, "END")) {
      scanf("%d %d", &a, &b);
      if (!strcmp(op, "M")) {
        printf("%d\n", ft.rsq(a, b));
      }
      else if (!strcmp(op, "S")) {
        ft.adjust(a, b - ft.rsq(a, a));
      }
    }
  }

}