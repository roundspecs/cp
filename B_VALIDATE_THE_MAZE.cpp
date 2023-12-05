#include <bits/stdc++.h>
using namespace std;

pair<int,int> d[] {{-1,0},{0,-1},{1,0},{0,1}};

int n,m;
char grid[20][20];
bool vis[20][20];
pair<int,int> a,b;
bool ok;

void dfs(pair<int,int> p) {
  vis[p.first][p.second]=1;
  for(auto dr:d) {
    int I=p.first+dr.first, J=p.second+dr.second;
    if(I<n && J<m && I>=0 && J>=0 && !vis[I][J]) {
      if(b==make_pair(I,J)) {
        ok=1;
      }
      dfs({I,J});
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin>>t; while(t--) {
    cin>>n>>m;
    vector<pair<int,int>> exits;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        cin>>grid[i][j];
        vis[i][j]=grid[i][j]=='#';
        if(grid[i][j]=='.' && (i==0 || j==0 || i==n-1 || j==m-1)) {
          exits.push_back({i,j});
        }
      }
    }
    if(exits.size()!=2) {
      cout<<"invalid\n";
      continue;
    }
    a=exits[0],b=exits[1];
    ok=false;
    dfs(a);
    cout<<(ok?"valid":"invalid")<<"\n";
  }
}