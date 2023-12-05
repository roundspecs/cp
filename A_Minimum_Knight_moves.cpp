#include <bits/stdc++.h>
using namespace std;

pair<int,int> d[] {{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
int dis[8][8];
bool vis[8][8];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  pair<int,int> a,b;
  int t; cin>>t; while(t--) {
    cin>>s; a={s[0]-'a',s[1]-'1'};
    cin>>s; b={s[0]-'a',s[1]-'1'};
    for(int i=0; i<8; i++) {
      fill(dis[i],dis[i]+8,0);
      fill(vis[i],vis[i]+8,0);
    }
    queue<pair<int,int>> q;
    q.push(a);
    vis[a.first][a.second]=1;
    while(!q.empty()) {
      auto p = q.front();
      q.pop();
      for(auto pr:d) {
        int I=p.first+pr.first, J=p.second+pr.second;
        if(I<8 && J<8 && I>=0 && J>=0 && !vis[I][J]) {
          q.push({I,J});
          vis[I][J]=1;
          dis[I][J]=dis[p.first][p.second]+1;
          if(b==make_pair(I,J)) {
            goto done;
          }
        }
      }
    }
    done:;
    cout<<dis[b.first][b.second]<<"\n";
  }
}