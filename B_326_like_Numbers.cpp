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
  cin.exceptions(cin.failbit);
  int n; cin>>n;
  while(1) {
    int a = n/100;
    int b = n/10%10;
    int c = n%10;
    if(a*b==c) return cout<<n,0;
    n++;
  }
}