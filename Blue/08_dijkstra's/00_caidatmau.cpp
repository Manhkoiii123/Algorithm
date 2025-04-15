#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
const int MAX = 100;
const INF = 1e9;
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
    int n,s,t;
    cin>>n>>s>>t;
    graph = vector<vector<pii>>(MAX+5, vector<pii>());
    d=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d;
            if(d>0) graph[i].push_back({j,d});
        }
    }
    dijkstra(s);
    cmt = dist[t];
    cout<<cmt<<endl;
}