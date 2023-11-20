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
  int t; cin>>t; while(t--) {
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int b=0;
    for(char c:s) if(c=='B') b++;
    if(b==k) cout<<"0\n";
    else {
      cout<<"1\n";
      if(b<k) {
        int A=k-b;
        int a=0;
        int i=0;
        while(a!=A) {
          if(s[i]=='A') a++;
          i++;
        }
        cout<<i<<" B\n";
      }
      else {
        int A=b-k;
        int a=0;
        int i=0;
        while(a!=A) {
          if(s[i]=='B') a++;
          i++;
        }
        cout<<i<<" A\n";
      }
    }
  }
}