#include<bits/stdc++.h>
using namespace std;
// HackerEarth : Dhoom 4
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(100000);
int vis[1000001] = {0};
int dist[100001] = {-1};
int a[100001];
int n;
int bfs (int x,int z) {
    ms(dist,-1);
    queue<int>q;
    q.push(x);
    dist[x] = 0;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(int i=0;i<n;i++) {
            int tmp = (1ll * top * a[i]) % MOD;
            if(dist[tmp] == -1) {
                dist[tmp] = dist[top] + 1;
                q.push(tmp);
                if(tmp == z) {
                    return dist[tmp];
                }
            }
            
        }
    }
    return -1;
}
int main(){
    int x,z;
    cin>>x>>z;
    
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<bfs(x,z);

}
