#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

void bfs(int x,int dis[10000],int vis[10000], vector<int>ke[10000]){
    queue<int>q;
    q.push(x);
    vis[x]=true;
    dis[x]=0;
    while(!q.empty()){
        int top=q.front();q.pop();
        for(int v:ke[top]){
            if(!vis[v]){
                q.push(v);
                vis[v]=true;
                dis[v]=dis[top]+1;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        int n,m;;
        cin>>n>>m;
        int dis[10000] = {-1},vis[10000] = {false};
        vector<int>ke[10000];
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int s;
        cin>>s;
        bfs(s,dis,vis,ke);
        for(int i=1;i<=n;i++){
            if(i!=s){
                if(dis[i]==0) {
                    cout<<-1<<" ";
                }
                else cout<<dis[i] * 6<<" ";
            }
        }
        cout<<endl;
    }
}