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
  string s; cin>>s;
  sort(s.begin(), s.end());
  map<string,int> m;
  for(long long i=0; i<3162278; i++) {
    string x = to_string(i*i);
    if(x.size()>n) break;
    sort(x.begin(),x.end());
    string y(n-x.size(), '0');
    y+=x;
    m[y]++;
  }
  cout<<m[s]<<'\n';
}