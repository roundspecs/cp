/**
 * DP: ready goes with dp
 * BITMASK: x = a ^ b ^ x
 * GRAPH: use vis
 * STYLE: use {} even for 1 line
 * EXIT: exit(0);
 */

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define cerr cout
#include "algo/debug.h"
#else
#define deb(...)  122
#endif

int getdiv(int cnt) {
  if(cnt==1) return 0;
  return cnt/2 + getdiv(cnt/2 + cnt%2);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t; cin>>t; while(t--) {
    int n; cin>>n;
    int a[n]; for(int&x:a) cin>>x;
    int mn=a[n-1];
    long long div=0;
    for(int i=n-2; i>=0; i--) {
      // deb(mn);
      // deb(i);
      // deb(a[i]);
      int cnt=(a[i]+mn-1)/mn;
      // deb(cnt);
      div+=getdiv(cnt);
      // cout<<getdiv(cnt)<<"\n";
      mn = a[i]/cnt;
    }
    cout<<div<<"\n";
  }
}