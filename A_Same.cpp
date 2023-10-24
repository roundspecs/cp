/**
 * DP:
 * - ready goes with dp
 * BITMASK:
 * - x = a ^ b ^ x
 * GRAPH:
 * - use vis
 * STYLE:
 * - use {} even for 1 line
 */

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define cerr cout
#include "algo/debug.h"
#else
#define deb(...)  122
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin>>n;
  int a[n]; for(int &x:a) cin>>x;
  for(int i=0; i<n; i++) {
    if(a[i]!=a[0]) {
      cout<<"No\n";
      return 0;
    }
  }
  cout<<"Yes\n";
}