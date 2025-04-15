#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
int u,v;
void dfs(int u,vector<vector<int>> &g,vector<bool> &vis,vector<int> &ans){
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){
        if(!vis[g[u][i]]){
            dfs(g[u][i],g,vis,ans);
        }
    }
    ans.push_back(u);
}
void topo(vector<vector<int>> &g,vector<int> &ans){
    vector<bool> vis(u,false);
    for(int i=0;i<u;i++){
        if(!vis[i]){
            dfs(i,g,vis,ans);
        }
    }
    reverse(all(ans));
}
int main(){
    vector<vector<int>> graph;
    vector<int> res;
    cin>>u>>v;
    graph.assign(u,vector<int>());
    for(int x,y,i=0;i<v;i++){
        cin>>x>>y;
        graph[x].push_back(y);
    }
    topo(graph,res);
    for(int i=0;i<u;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}