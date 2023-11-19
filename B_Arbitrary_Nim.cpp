/**
 * DP: ready goes with dp
 * BITMASK: x = a ^ b ^ x
 * GRAPH: use vis
 * STYLE: use {} even for 1 line
 * EXIT: exit(0);
 */

#include <iostream>
#include <vector>

using namespace std;

int grundy(vector<int> piles) {
  int sg_value = 0;
  for (int pile : piles) {
    int xor_value = 0;
    for (int i = 1; i <= pile; i++) {
      xor_value ^= grundy(vector<int>(piles.begin(), piles.end() - 1));
    }
    sg_value ^= xor_value;
  }
  return sg_value;
}


bool has_winning_strategy(vector<int> &piles, int k) {
  return grundy(piles) != 0;
}

int find_valid_k(vector<int> &piles) {
  int k = 0;
  while (k <= piles.size()) {
    if (has_winning_strategy(piles, k)) {
      return k;
    } else {
      k++;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;

  vector<int> piles(n);
  for (int i = 0; i < n; i++) {
    cin >> piles[i];
  }

  int valid_k = find_valid_k(piles);
  cout << valid_k << endl;

  return 0;
}
