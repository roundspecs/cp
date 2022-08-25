/**
 * int +-2e9
 * ll +-9e18
 * __int128_t +-e38
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define foss(i, start, stop, step) for (int i = start; i < stop; i += step)
#define fos(i, start, stop) foss(i, start, stop, 1)
#define fo(i, stop) fos(i, 0, stop)
#define nn "\n"
#define mod 1000000007

void pattern(int n) {
  if (n == 1) {
    cout << 1 << nn;
    return;
  }
  fo(i, n) cout << i + 1 << " ";
  cout << nn;
  pattern(n - 1);
  fo(i, n) cout << i + 1 << " ";
  cout << nn;
}

int main() {
  pattern(4);
  return 0;
}