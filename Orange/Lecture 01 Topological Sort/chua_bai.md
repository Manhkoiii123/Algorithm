# bài 2 Hierarchy (SPOJ)

ví dụ cho

4 2

1 3

2 3 4

thì người 1 muốn làm xếp ng 3, ng 2 làm xếp ng 3 4 => ng 1 đứng trước người 3, người 2 đứng trước ng 3 và 4

=> build topo => 2 4 1 3 =>

khi đó ans[2] = 0, ans[4] = 2, ans[1] = 4, ans[3] = 1

=> cơ bản là đảo cái dãy topo lại là được

```cpp
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
    cin>>u>>v;
    vector<vector<int>> graph;
    vector<int> res;
    graph.assign(u,vector<int>());
    for(int i=0;i<v;i++){
        int x;
        cin>>x;
        while(x--){
            int z;
            cin>>z;
            graph[i].push_back(z - 1);
        }
    }
    topo(graph,res);
    vector<int> ans(u+1);
    for(int i=0;i<u;i++){
       if(i==0){
        ans[res[i] + 1] = 0;
       }else{
        ans[res[i] + 1] = res[i-1] + 1;
       }
    }
    for(int i=1;i<u+1;i++){
        cout<<ans[i]<<endl;;
    }
    return 0;
}
```

# bài 3: Fox and Names (Codeforces)
