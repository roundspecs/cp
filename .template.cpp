#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set                                       \
  __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, \
                   __gnu_pbds::rb_tree_tag,               \
                   __gnu_pbds::tree_order_statistics_node_update>

void solve() {

}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
}