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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin>>n;
  string s; cin>>s;
  long long sum=0;
  for(int i=0, len; i<n-1; i+=len) {
    len=0;
    if(s[i]=='<') len=1;
    else {
      while(i+len<n && s[i]==s[i+len]) len++;
      sum += 1ll*len*(len+1)/2;
    }
  }
  cout<<sum;
}