#include<bits/stdc++.h>
using namespace std;
//LightOJ : Guilty Prince
// nhập ngược thứ tự m n nên hơi chuối
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int vis[25][25];
char a[25][25];
int n,m;
void bfs(int x,int y,int t,int ans){
    queue<pii> q;
    q.push({x,y});
    vis[x][y] = 1;
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx = top.first + dx[i];
            int yy = top.second + dy[i];
            if(xx >= 0 && xx < m && yy >= 0 && yy < n && vis[xx][yy] == 0 && a[xx][yy] == '.'){
                q.push({xx,yy});
                vis[xx][yy] = 1;
                ans++;
            }
        }
    }
     cout<<"Case "<<++t<<": "<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int ans = 1;
        
        cin>>n>>m;
        int start,end;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                if(a[i][j] == '@') {
                    start = i;
                    end = j;
                }
                vis[i][j] = 0;
            }
        }
        
        bfs(start,end,i,ans);
    }
    
}

