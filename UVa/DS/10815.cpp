#include <string>
#include <iostream>
#include <set>

using namespace std;

char toLower(char c) {
  if (c >= 'a' && c <= 'z')
    return c;

  else if (c >= 'A' && c <= 'Z') return c + 32;

  else
    return '\0';
}


int main() {
  string s;
  set<string> ss;
  set<string>::iterator it;

  while (cin >> s)
  {
    string current = "";
    for (int i = 0; i < s.size(); i++) {
      int lower = toLower(s[i]);
      if (lower >= 'a' && lower <= 'z')
        current += lower;
    }

    if (!current.empty())
      ss.insert(current);
  }
  for (it = ss.begin(); it != ss.end(); ++it) {
    cout << *it << endl;
  }
}