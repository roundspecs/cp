#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&a, int i, int j, int k) {
  vector<int> tmp; tmp.reserve(k-i);
  for(int I=i,J=j; I<j || J<k;) {
    if(I==j)
      tmp.push_back(a[J++]);
    else if(J==k)
      tmp.push_back(a[I++]);
    else if(a[I]<a[J])
      tmp.push_back(a[I++]);
    else
      tmp.push_back(a[J++]);
  }
  for(int I=0; I<tmp.size(); I++)
    a[i+I]=tmp[I];
}

void mergeSort(vector<int>&a, int i, int j) {
  // will sort [i:j)
  if(j-i<=1) return;
  int m=(i+j)/2;
  mergeSort(a,i,m);
  mergeSort(a,m,j);
  merge(a,i,m,j);
}

int main() {
  vector<int> a {1,5,4,2,4,6,3,2,5,2};
  mergeSort(a, 0, a.size());
  for(int&x:a) cout<<x<<" ";
}