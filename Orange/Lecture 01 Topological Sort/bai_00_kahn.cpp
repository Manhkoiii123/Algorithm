#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
int v,e;
bool topo(vector<vector<int>> &g,vector<int> &ans){
    vector<int>in_degree(v,0);
    queue<int>q;
    for(int i=0;i<v;i++){
        for(int j=0;j<g[i].size();j++){
            in_degree[g[i][j]]++;
        }
    }
    for(int i=0;i<v;i++){
        if(in_degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for(int i=0;i<g[top].size();i++){
            in_degree[g[top][i]]--;
            if(in_degree[g[top][i]]==0){
                q.push(g[top][i]);
            }
        }
    }
    return ans.size()==v;
}
int main(){
    vector<vector<int>> graph;
    vector<int> ans;
    cin>>v>>e;
    graph.assign(v,vector<int>());
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    if(topo(graph,ans)){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}