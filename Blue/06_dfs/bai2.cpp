#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
vector<int>ke[100005];
bool vis[100005];
void dfs(int x){
    vis[x]=true;
    for(int v:ke[x]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        int n,e;
        cin>>n>>e;
        
        for (int i=0;i<n;i++) {
            vis[i]=false;
            ke[i].clear();
        }
        for(int i=0;i<e;i++) {
            int x,y;
            cin>>x>>y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i);
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}