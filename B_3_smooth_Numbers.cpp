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
  long long n; cin>>n;
  while(n%3==0) n/=3;
  while(n%2==0) n/=2;
  if(n==1) cout<<"Yes\n";
  else cout<<"No\n";
}