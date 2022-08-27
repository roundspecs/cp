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
  cout << "Case #" << tc << ": ";
  int n, k;
  int temp;
  cin >> n >> k;
  if (n > k * 2) {
    puts("NO");
    fo(_, n) cin >> temp;
    return;
  }
  map<int, int> m;
  fo(_, n) {
    cin >> temp;
    m[temp]++;
  }
  for (auto p : m) {
    if (p.second > 2) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}

int main() {
  int t;
  cin >> t;
  fos(tc, 1, t + 1) solve(tc);

  return 0;
}