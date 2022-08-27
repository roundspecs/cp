/**
 * int +-2e9
 * ll +-9e18
 * __int128_t +-e38
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pi pair<int, int>
#define fos(i, start, stop) for (int i = start; i < stop; i++)
#define fo(i, stop) fos(i, 0, stop)
#define foss(i, start, stop, step) for (int i = start; i < stop; i += step)
#define nn "\n"
#define mod 1000000007

void solve(int tc) {
  int r, c;
  bool done = false;
  cin >> r >> c;
  cout << "Case #" << tc << ": ";
  char temp;
  if (r == 1) {
    fo(i, c) {
      cin >> temp;
      if (done) continue;
      if (temp == '^') {
        puts("Impossible");
        done = true;
      }
    }
    if (!done) {
      puts("Possible");
      fo(i, c) cout << ".";
      cout << nn;
    }
  } else if (c == 1) {
    fo(i, r) {
      cin >> temp;
      if (done) continue;
      if (temp == '^') {
        puts("Impossible");
        done = true;
      }
    }
    if (!done) {
      puts("Possible");
      fo(i, r) cout << "." << nn;
    }
  } else {
    puts("Possible");
    fo(i, r) {
      fo(j, c) {
        cin >> temp;
        cout << "^";
      }
      cout << nn;
    }
  }
}

int main() {
  int t;
  cin >> t;
  fos(tc, 1, t + 1) solve(tc);

  return 0;
}