#include<bits/stdc++.h>
using namespace std;
// https://www.spoj.com/problems/TRVCOST/
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
const int MAX = 501;
const int INF = 1e9;
vector<vector<pii>> graph;
vector<int> dist(MAX,INF);
int path[MAX];
struct option {
    bool operator()(const pii &a, const pii &b) const {
        return a.second > b.second;
    }
};

void dijkstra(int start){
    priority_queue<pii,vector<pii>,option> pq;
    pq.push({start,0});
    dist[start] = 0;
    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
       if(dist[u]!=w) continue;
       for(int i=0;i<graph[u].size();i++){
        pii nei = graph[u][i];
        if(w + nei.second < dist[nei.first]){
            dist[nei.first] = w + nei.second;
            path[nei.first] = u;
            pq.push({nei.first,dist[nei.first]});
        }
       }
    }
}
int main(){
    int n,w,u,v;
    cin>>n;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
    for(int i=0;i<n;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back({y,z});
        graph[y].push_back({x,z});
    }
    cin>>w;
    dijkstra(w);
    cin>>v;
    for(int i=0;i<v;i++){
        int k;
        cin>>k;
        if(dist[k] == INF) cout<<"NO PATH"<<endl;
        else cout<<dist[k]<<endl;
    }
}