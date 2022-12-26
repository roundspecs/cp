
#include <bits/stdc++.h>
#define nn '\n';
using namespace std;

template <typename T> vector<T> inputVec() {
  string s;
  getline(cin, s);
  stringstream ss(s);
  vector<T> ans;
  T tmp;
  while (ss >> tmp) ans.push_back(tmp);
  return ans;
}

template <typename T> T get() {
  T tmp;
  cin >> tmp;
  cin.ignore();
  return tmp;
}

string inputStr() {
  string s;
  getline(cin, s);
  return s;
}

template <typename T> void output(vector<T> data) {
  for (int d : data) cout << d << " ";
  cout << "\n";
}

template <typename T> void output(T data) { cout << data << "\n"; }