#include <bits/stdc++.h>
using namespace std;
#define ll       long long
#define vi       vector<int>
#define pi       pair<int, int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define nn       "\n"
#define mod      1000000007
#define all(var) var.begin(), var.end()

void sl(int n, int a[], int sub[]) {
  // cout << "a  : ";
  // fo(i,n) {
  //   cout << a[i] << " ";
  // }
  // cout << nn << "sub: ";
  // fo (i,n) {
  //   cout << sub[i] << " ";
  // }
  // cout << nn;
  bool done = true, took_action = false;
  fo(i, n) {
    int curr = a[i];
    int next = (i == n - 1) ? a[1] : a[i + 1];
    if (sub[i] == 0) continue;
    done = false;
    if (curr <= next) {
      took_action = true;
      a[i]++;
      sub[i]--;
    }
  }
  if (done) {
    puts("YES");
    return;
  }
  if (!took_action) {
    puts("NO");
    return;
  } else sl(n, a, sub);
}

void solve(int tc) {
  int n;
  cin >> n;
  int a[n];
  fo(i, n) cin >> a[i];
  int b[n];
  fo(i, n) cin >> b[i];
  int sub[n];
  fo(i, n) {
    sub[i] = b[i] - a[i];
    if (sub[i] < 0) {
      puts("NO");
      return;
    }
  }
  sl(n, a, sub);
}

int main() {
  int t;
  cin >> t;
  fo(tc, t) solve(tc);
  return 0;
}