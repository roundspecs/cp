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
#define fo(i, n) for (int i = 0; i < n; i++)
#define nn "\n"
#define mod 1000000007

int main() {
  int n;
  cin >> n;
  ll sum = n * 1ll * (n + 1) / 2;
  if (sum % 2 == 1) puts("NO");
  else {
    puts("YES");
    ll half_sum = sum / 2;
    
  }
  return 0;
}