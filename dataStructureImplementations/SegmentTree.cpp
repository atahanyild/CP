#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
  vi st, A;
  int N;
  int left(int p) { return p << 1; };
  int right(int p) { return (p << 1) + 1; };
  int parent(int p) { return p >> 1; };

  void build(int p, int L, int R) {
    if (L == R) st[p] = L;
    else {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);

      int pl = st[left(p)], pr = st[right(p)];
      st[p] = (A[pl] <= A[pr]) ? pl : pr;
    }
  };

  int RMQ(int p, int L, int R, int i, int j) {
    if (L >= i && R <= j) return st[p];
    if (i >= R || j < L) return -1;

    int lm = RMQ(left(p), L, (L + R) / 2, i, j);
    int rm = RMQ(right(p), (L + R) / 2 + 1, R, i, j);

    if (lm == -1) return rm;
    else if (rm == -1) return lm;
    else return A[lm] < A[rm] ? lm : rm;
  };

  int _findSTIndex(int p, int num, int L, int R) {
    if (L == num && R == num) return p;

    int new_p;
    if ((L + R) / 2 < num) new_p = _findSTIndex(right(p), num, (L + R) / 2 + 1, R);
    else {
      new_p = _findSTIndex(left(p), num, L, (L + R) / 2);
    }

    return new_p;
  };

  void update(int p, int ai, int newValue) {
    if (p == 0) return;

    int pl = st[left(p)], pr = st[right(p)];

    if (pl == 0 && pr == 0) { A[ai] = newValue; }

    else if (pl != 0 && pr != 0) {
      st[p] = (A[pl] < A[pr]) ? pl : pr;
    }

    update(parent(p), ai, newValue);
  };

public:
  SegmentTree(const vi& _A) {
    A = _A;
    N = (int)A.size();
    st.assign(4 * N, 0);
    build(1, 0, N - 1);
  };

  int rmq(int i, int j) { return RMQ(1, 0, N - 1, i, j); };

  void update(int ai, int newValue) { return update(_findSTIndex(1, ai, 0, N - 1), ai, newValue); }
};

int main() {
  int arr[] = { 18, 17, 13, 19, 15, 11, 20 }; // the original array
  vi A(arr, arr + 7);
  SegmentTree st(A);
  printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
  printf("              A is {18,17,13,19,15, 11,20}\n");
  printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));             // answer = index 2
  printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));             // answer = index 5
  printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));             // answer = index 4
  printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));             // answer = index 0
  printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));             // answer = index 1
  printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));             // answer = index 5

  printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
  printf("Now, modify A into {18,17,13,19,15,100,20}\n");
  st.update(5, 100);                    // update A[5] from 11 to 100
  printf("These values do not change\n");
  printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));                            // 2
  printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));                            // 4
  printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));                            // 0
  printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));                            // 1
  printf("These values change\n");
  printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));                         // 5->2
  printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));                         // 5->4
  printf("RMQ(4, 5) = %d\n", st.rmq(4, 5));                         // 5->4

} // return 0;