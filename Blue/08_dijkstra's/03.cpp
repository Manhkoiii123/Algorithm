#include<bits/stdc++.h>
using namespace std;
// https://www.spoj.com/problems/SHPATH/
/**
 * @brief 
 đề bài cho s testcase
 n thành phố
 1 thành phố gồm : tên, số neighbor => mỗi neighbor gồm : tên, chi phí
 tìm đ ngắn nhất từ tên A đến B
 lưu lại cities đấy thành 1 mảng index cho dễ dijkstra
 sau mỗi testcase là lại memset lại 2 mảng cities và graph
 * 
 */
#define MAX 10005
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, MOD);
vector<string> cities;
struct option {
    bool operator()(const pii &a, const pii &b) const {
        return a.second > b.second;
    }
};
void dijkstra(int start,int end){
    priority_queue<pii,vector<pii>,option> pq;
    pq.push({start,0});
    dist[start] = 0;
    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
       if(u == end) return;
       if(dist[u]!=w) continue;
       for(int i=0;i<graph[u].size();i++){
        pii nei = graph[u][i];
        if(w + nei.second < dist[nei.first]){
            dist[nei.first] = w + nei.second;
            pq.push({nei.first,dist[nei.first]});
        }
       }
    }
}
int getIndexCity(string name) {
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i] == name) return i;
    }
}
int main(){
    int s;
    cin >> s;
    while(s--) {
         int n;
         cin>>n;
         for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }
        cities.clear();
        // graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
         for(int i=1;i<=n;i++) {
            string name;
            cin>>name;
            cities.push_back(name);
            int p;
            cin>>p;
            for(int j=0;j<p;j++) {
                int x,y;
                cin>>x>>y;
                graph[i].push_back({x,y});
            }
         }
         int r;
         cin>>r;
         for(int i=1;i<=r;i++) {
            string name1,name2;
            cin>>name1>>name2;
            int index1 = getIndexCity(name1) + 1 ;
            int index2 = getIndexCity(name2) + 1;
            dist = vector<int>(n + 1, MOD);
            dijkstra(index1,index2);
            cout<<dist[index2]<<endl;
         }
    }
}