#include <bits/stdc++.h>
#include <string.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string timeConversion(string s)
{
  string ih, ims, iap;

  ih = s.substr(0, 2);
  ims = s.substr(2, 6);
  iap = s.substr(8, 2);

  if (iap == "PM" && ih != "12")
  {
    ih = to_string(stoi(ih) + 12);
  }
  else if (iap == "AM" && ih == "12")
  {
    ih = "00";
  }

  return ih + ims;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = timeConversion(s);

  fout << result << "\n";

  fout.close();

  return 0;
}
