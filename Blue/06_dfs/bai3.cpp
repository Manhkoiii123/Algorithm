#include<bits/stdc++.h>
using namespace std;
// Lakes in Berland - Codeforces
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
int n,m,k;
char a[55][55];
bool vis[55][55];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
vector<vector<pii>>lakes;
bool compare_item (vector<pii>&a,vector<pii>&b) {
    return a.size() < b.size();
}
int onBorder(int x,int y) {
    return x==0||x==n-1||y==0||y==m-1;
}
void dfs(int x,int y,bool &isBorder,vector<pii>&lake_item){
    vis[x][y]=true;
    lake_item.push_back({x,y});
    if(onBorder(x,y)) {
        isBorder = true;
    }
    for(int i=0;i<4;i++) {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy]=='.' && vis[xx][yy]==false) {
            dfs(xx,yy,isBorder,lake_item);
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j] == '.' && vis[i][j]==false) {
                vector<pii>lake_item;
                bool isBorderCheck = false;
                dfs(i,j,isBorderCheck,lake_item);
                if(lake_item.size() != 0 && isBorderCheck == false) {
                    lakes.push_back(lake_item);
                }
            }
        }
    }
    sort(lakes.begin(),lakes.end(),compare_item);
    int ans = 0;
    for(int i=0;i<lakes.size() - k;i++){
         ans += lakes[i].size();
        for(int j=0;j<lakes[i].size();j++) {
            a[lakes[i][j].first][lakes[i][j].second] = '*';
        }
    }

    cout<<ans<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

