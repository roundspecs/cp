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
    int n; cin>>n;
    pair<int,int> a[n];
    for(auto&x:a) cin>>x.first;
    for(auto&x:a) cin>>x.second;
    for(auto&[x,y]:a) if(x>y) swap(x,y);
    long long sum=0;
    for(auto&[x,y]:a) sum+=(y-x);
    int mnb=INT_MAX, mxa=INT_MIN;
    for(auto&[x,y]:a) mnb=min(mnb,y), mxa=max(mxa,x);
    if(mnb<mxa) sum+=2*(mxa-mnb);
    cout<<sum<<"\n";
  }
}