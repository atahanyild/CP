#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//didnt figure out the solution myself, i implemented it

string s, subs;
int Q;


int main() {
  cin >> s;
  vector<vector<int> > v(128);

  for (int i = 0; i < s.length(); i++) {
    v.at(s[i]).push_back(i);
  }

  cin >> Q;
  while (Q--)
  {
    cin >> subs;
    int f, last = -1;
    bool valid = true;
    for (int i = 0; i < subs.length() && valid; i++) {
      auto index = upper_bound(v.at(subs[i]).begin(), v.at(subs[i]).end(), last);
      valid = index != v[subs[i]].end();
      last = *index;
      if (i == 0) f = *index;
    }

    if (!valid) printf("Not matched\n");
    else printf("Matched %d %d\n", f, last);
  }
  return 0;
}