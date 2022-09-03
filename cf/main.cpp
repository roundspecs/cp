#include <bits/stdc++.h>
using namespace std;
#define ll       long long
#define vi       vector<int>
#define pi       pair<int, int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define nn       "\n"
#define mod      1000000007
#define all(var) var.begin(), var.end()

void solve(int tc) {
  int n, k, r, c;
  cin >> n >> k >> r >> c;
  int mul = n / k;
  r %= k;
  c %= k;
  if (!r) r = k;
  if (!c) c = k;
  r--;
  c--;
  char arr[k][k];
  memset(arr, '.', sizeof(arr));
  arr[r][c] = 'X';
  for (int i = 0, j = 0; i < k && j < k;) {
    if (i == c) i++;
    if (j == r) j++;
    arr[j][i] = 'X';
    i++;
    j++;
  }
  fo(__, mul) fo(i, k) {
    fo(_, mul) fo(j, k) { cout << arr[i][j]; }
    cout << nn;
  }
}

int main() {
  int t;
  cin >> t;
  fo(tc, t) solve(tc);
}