#include <cstdio>
#include <vector>

using namespace std;
typedef vector<int> vi;

class FenwickTree {
private: vi ft;

public:
  FenwickTree(int n) { ft.assign(n + 1, 0); };
  int LSOne(int a) { return (a & -a); };
  void adjust(int i, int v) {
    for (; i <= (int)ft.size(); i += LSOne(i)) ft.at(i) += v;
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

int main() {
  int f[] = { 2,4,5,5,6,6,6,7,7,8,9 };
  FenwickTree ft(10);
  for (int i = 0; i < 11; i++) ft.adjust(f[i], 1);

  printf("%d\n", ft.rsq(1, 1)); // 0 => ft[1] = 0
  printf("%d\n", ft.rsq(1, 2)); // 1 => ft[2] = 1
  printf("%d\n", ft.rsq(1, 6)); // 7 => ft[6] + ft[4] = 5 + 2 = 7
  printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
  printf("%d\n", ft.rsq(3, 6)); // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1
  ft.adjust(5, 2); // update demo
  printf("%d\n", ft.rsq(1, 10)); // now 13
}