#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
vector<int>ke[1005];
bool vis[1005];
int dist[1005] = {-1};
void dfs(int x){
    vis[x]=true;
    for(int v:ke[x]){
        if(!vis[v]){
            dist[v]= dist[x]+1;
            dfs(v);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    int q;
    cin>>q;
    int v[q];
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    dist[1]=0;
    dfs(1);
    int ans = 0;
    int max_val = MOD;
    sort(v,v+q);
    for(int i=0;i<q;i++) {
        if(dist[v[i]] < max_val){
            ans = v[i];
            max_val = dist[v[i]];
        }
    }
    cout<<ans;
}