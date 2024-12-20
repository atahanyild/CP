#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);

  while (!(a == 1 && b == 1)) {
    int lx = 0, ly = 1, mx = 1, my = 1, rx = 1, ry = 0;
    string res;

    while (!(a == mx && b == my)) {
      if (a * my < b * mx) {
        rx = mx;
        ry = my;
        mx += lx;
        my += ly;
        res.append("L");
      }

      else {
        lx = mx;
        ly = my;
        mx += rx;
        my += ry;
        res.append("R");
      }
    }

    printf("%s\n", res.c_str());
    scanf("%d", &a);
    scanf("%d", &b);
  }
}