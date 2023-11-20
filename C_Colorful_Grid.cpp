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
    int n,m,k; cin>>n>>m>>k;
    char h[n][m-1], v[n-1][m];
    char x;
    for(int i=0; i<n; i++)
      for(int j=0; j<m-1; j++)
        h[i][j] = 'R';
    for(int i=0; i<n-1; i++)
      for(int j=0; j<m; j++)
        v[i][j] = 'R';
    if(k<(m+n-2) || (k-(m+n-2))%2) {
      cout<<"NO\n";
      goto done;
    }
    cout<<"YES\n";
    x = 'B';
    for(int i=n-2; i>=0; i--, x = (x ^ 'R' ^ 'B')) {
      v[i][m-1]=x;
    }
    x = 'R';
    for(int i=m-2; i>=0; i--, x = (x ^ 'R' ^ 'B')) {
      h[n-1][i]=x;
    }
    for(int j=0; j<n-1; j++) {
      x = ('R' ^ 'B' ^ v[j][m-1]);
      for(int i=m-2; i>=0; i--, x = (x ^ 'R' ^ 'B')) {
        h[j][i]=x;
      }
    }
    for(int j=0; j<m-1; j++) {
      x = ('R' ^ 'B' ^ h[n-1][j]);
      for(int i=n-2; i>=0; i--, x = (x ^ 'R' ^ 'B')) {
        v[i][j]=x;
      }
    }
    if(k-(m+n-2)==2) {
      h[n-2][m-2]='B';
      v[n-2][m-2]=v[n-2][m-1]='R';
    }
    for(int i=0; i<n; i++) {
      for(int j=0; j<m-1; j++)
        cout<<h[i][j]<<" ";
      cout<<"\n";
    }
    for(int i=0; i<n-1; i++) {
      for(int j=0; j<m; j++)
        cout<<v[i][j]<<" ";
      cout<<"\n";
    }
    done:;
  }
}