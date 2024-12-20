#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int> > v;
int a, b, ptr;
vector<char> res;

void backtrack() {
  if (!(v.at(ptr).first == a && v.at(ptr).second == b)) {
    float val = (float)v.at(ptr).first / v.at(ptr).second;
    float ab = (float)a / b;
    if (ab < val) {
      res.push_back('L');
      v.insert(v.begin() + ptr, make_pair(v.at(ptr).first + v.at(ptr - 1).first, v.at(ptr).second + v.at(ptr - 1).second));
    }
    else {
      res.push_back('R');
      v.insert(v.begin() + ptr + 1, make_pair(v.at(ptr).first + v.at(ptr + 1).first, v.at(ptr).second + v.at(ptr + 1).second));
      ptr++;
    }

    backtrack();
  }
}


int main()
{
  scanf("%d", &a);
  scanf("%d", &b);


  while (!(a == 1 && b == 1)) {
    v = vector<pair<int, int> >(0);
    res = vector<char>(0);
    ptr = 1;
    v.push_back(make_pair(0, 1));
    v.push_back(make_pair(1, 1));
    v.push_back(make_pair(1, 0));

    backtrack();

    for (int i = 0; i < res.size(); i++)
    {
      printf("%c", res[i]);
    }

    scanf("%d", &a);
    scanf("%d", &b);
  }
}
