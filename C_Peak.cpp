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
  cin.exceptions(cin.failbit);
  int n,m; cin>>n>>m;
  int a[n]; for(int &x:a) cin>>x;
  sort(a,a+n);
  int mx=0;
  for(int i=0, len=0; i<n; i++) {
    while(i+len<n && a[i+len]-a[i]<m) len++;
    mx=max(mx,len);
    len--;
  }
  cout<<mx;
}