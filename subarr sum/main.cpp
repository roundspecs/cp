/**
 * int +-2e9
 * ll +-9e18
 * __int128_t +-e38
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pi pair<int, int>
#define fos(i, start, stop) for (int i = start; i < stop; i++)
#define fo(i, stop) fos(i, 0, stop)
#define foss(i, start, stop, step) for (int i = start; i < stop; i += step)
#define nn "\n"
#define mod 1000000007

int main() {
  const int N = 7;
  int arr[] = {-1, 2, 3, -5, 6, 7, -10};
  int global_max = 0, local_max;
  for (int i = 0; i < N; i++) {
    if (arr[i] <= 0) continue;
    if (i - 1 >= 0 && arr[i - 1] > 0) continue;
    for (int j = i; j < N; j++) {
      if (arr[j] <= 0) continue;
      if (j + 1 < N && arr[j + 1] > 0) continue;
      cout << i << "," << j << nn;
      local_max = 0;
      for (int k = i; k <= j; k++)
        local_max += arr[k];
      global_max = max(local_max, global_max);
    }
  }
  cout << global_max;
  return 0;
}