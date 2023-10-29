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

string grid[5];
vector<string> abcs;
bool a[5]={}, b[5]={}, c[5]={};
int n;
string R,C;

bool ok(string abc) {
  for(int i=0; i<n; i++) {
    if(abc[i]=='A') { if(a[i]) return false; }
    else if(abc[i]=='B') { if(b[i]) return false; }
    else if(abc[i]=='C') { if(c[i]) return false; }
  }
  return true;
}

string left() {
  string x;
  for(int i=0; i<n; i++) {
    int j=0;
    while(grid[i][j]=='.') j++;
    x.push_back(grid[i][j]);
  }
  return x;
}

string top() {
  string x;
  for(int i=0; i<n; i++) {
    int j=0;
    while(grid[j][i]=='.') j++;
    x.push_back(grid[j][i]);
  }
  return x;
}

void recur(int i) {
  if(i==n) {
    if(top()==C && left()==R) {
      cout<<"Yes\n";
      for(int j=0; j<n; j++) {
        cout<<grid[j]<<"\n";
      }
      exit(0);
    }
  }
  for(string abc: abcs) {
    if(ok(abc)) {
      grid[i]=abc;
      for(int j=0; j<n; j++) {
        if(abc[j]=='A') a[j]=1;
        else if(abc[j]=='B') b[j]=1;
        else if(abc[j]=='C') c[j]=1;
      }
      recur(i+1);
      for(int j=0; j<n; j++) {
        if(abc[j]=='A') a[j]=0;
        else if(abc[j]=='B') b[j]=0;
        else if(abc[j]=='C') c[j]=0;
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin>>n;
  cin>>R>>C;
  for(int i=0; i<n; i++) {
    grid[i]=string(n, '.');
  }
  string x="ABC";
  for(int i=3; i<n; i++) x.push_back('.');
  ranges::sort(x);
  do {
    abcs.push_back(x);
  } while(next_permutation(x.begin(),x.end()));
  recur(0);
  cout<<"No\n";
}