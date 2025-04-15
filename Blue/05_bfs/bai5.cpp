#include<bits/stdc++.h>
using namespace std;
// Kefa and Park : Codeforces
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
//đỉnh lá khi có duy nhất 1 đỉnh kề
vector<int>ke[100005];
int dist[100005];
int vis[100005];
int n,m;
int a[100005];
void bfs(int x) {
    int ans = 0;
    queue<int>q;
    q.push(x);
    vis[x]=1;
    if(a[x] == 1) {
        dist[x] = 1;
    }else{
        dist[x] = 0;
    }
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        
        for(int i=0;i<ke[top].size();i++) {
            int v = ke[top][i];
            if(vis[v] == 0) {
                vis[v] = 1;
                if(a[v] == 1) {
                    dist[v] = dist[top] + 1;
                }
                if(dist[v] <= m) {
                    if(ke[v].size() == 1) {
                        ++ans;
                    }else{
                        q.push(v);
                    }
                }
            }
        }
    }
    cout<<ans;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    bfs(1);
}