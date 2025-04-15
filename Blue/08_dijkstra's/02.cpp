#include<bits/stdc++.h>
using namespace std;
// https://vn.spoj.com/problems/MICEMAZE/
/**
 * @brief 
 đề bài là tìm số con chuột đến được đỉnh e trước thời gian t
 thì lần lượt dij từ e đến all đỉnh => nếu dist < t thì ++ans 
 => lưu ý là tìm ngược từ e lên đến đỉnh => đồ thị phải push ngược lại 
 dòng 55
 * 
 */
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
const int MAX = 105;
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
    int n,e,t,m;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
    cin >> n >> e >> t >> m;
    for(int i = 0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[b].push_back({a,c});
    }
    dijkstra(e);
    int ans = 0;
    for(int i = 1;i<= n;i++) {
        if(dist[i] <= t) {
            ans++;
        }
    }
    cout<<ans;
}