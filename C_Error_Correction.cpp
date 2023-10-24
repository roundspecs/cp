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
  string t; cin>>t;
  vector<int> ans;
  for(int tt=1; tt<=n; tt++) {
    string s; cin>>s;
    if(s.size()==t.size()) {
      int unequal=0;
      for(int i=0; i<s.size(); i++) unequal+=(s[i]!=t[i]);
      if(unequal<2) ans.push_back(tt);
    }
    else if(abs(int(s.size()-t.size()))>1) continue;
    else {
      string s1, s2;
      if(s.size()<t.size()) s1=s, s2=t;
      else s1=t, s2=s;
      int i=0,j=0;
      while(i<s1.size() && j<s2.size() && s1[i]==s2[j]) i++,j++;
      j++;
      if(s1.substr(i)==s2.substr(j)) ans.push_back(tt);
    }
  }
  cout<<ans.size()<<"\n";
  for(int x:ans) cout<<x<<' ';
}