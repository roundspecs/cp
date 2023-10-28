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

string s[5];
vector<string> abcs;
bool a[5]={}, b[5]={}, c[5]={};
int n;
string R,C;
bool done=false;

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
    while(s[i][j]=='.') j++;
    x.push_back(s[i][j]);
  }
  return x;
}

string top() {
  string x;
  for(int i=0; i<n; i++) {
    int j=0;
    while(s[j][i]=='.') j++;
    x.push_back(s[j][i]);
  }
  return x;
}

void recur(int i) {
  if(i==n) {
    if(!done && top()==C && left()==R) {
      cout<<"Yes\n";
      for(int j=0; j<n; j++) {
        for(int k=0; k<n; k++) {
          cout<<s[j][k];
        }
        cout<<"\n";
      }
      // cout<<"LEFT: ";
      // cout<<left()<<"\n";
      // cout<<"TOP: ";
      // cout<<top()<<"\n";
      done=true;
    }
  }
  for(string abc: abcs) {
    if(ok(abc)) {
      s[i]=abc;
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
    s[i]=string(n, '.');
  }
  for(int a=0; a<n-2; a++) {
    for(int b=a+1; b<n-1; b++) {
      for(int c=b+1; c<n; c++) {
        string y(n, '.');
        for(string x: {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"}) {
          y[a] = x[0];
          y[b] = x[1];
          y[c] = x[2];
          abcs.push_back(y);
        }
      }
    }
  }
  // deb(abcs.begin(), abcs.end());
  // deb(abcs.size());
  recur(0);
  if(!done) cout<<"No\n";
}