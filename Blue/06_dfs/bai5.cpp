#include<bits/stdc++.h>
using namespace std;
// THE LAST SHOT - SPOJ (ac)
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
vector<int>ke[100005];
int n,m;
bool vis[100005];
int cnt;
int dfs(int x){
    cnt++;
    vis[x] = true;
    for(int v:ke[x]){
        if(!vis[v]){
            dfs(v);
        }
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        // ke[y].push_back(x);
        ke[x].push_back(y);
    }
    int tmp_ans = 0;
    for(int i=1;i<=n;i++) {
        cnt=0;
        cnt = dfs(i);
        ms(vis,false);
        if(cnt>=tmp_ans) {
            tmp_ans = cnt;
        }
    }
    cout<<tmp_ans;
}