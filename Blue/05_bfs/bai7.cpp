#include<bits/stdc++.h>
using namespace std;
// Ice Cave - CodeForces
#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
char a[505][505];
int n,m;
void bfs(int x1,int y1,int x2,int y2) {
    queue<pii>q;
    q.push({x1,y1});
    a[x1][y1] = '.';
    while(!q.empty()) {
        pii top = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int x = top.first+dx[i];
            int y = top.second+dy[i];
            // ô đích bắt buộc phải nứt đẻ nhảy đến là rơi luôn xuống dưới để out màn
            if(x == x2 && y == y2 && a[x][y]=='X')  {
                cout<<"YES";
                return;
            }
            // ô đó nguyên thì bật ô đó thành nứt
            if(x>=0 && x<n && y>=0 && y<m&& a[x][y]=='.') {
                
                a[x][y] = 'X';
                q.push({x,y});
            }
        }
    }
    cout<<"NO";
    return;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    --x1;
    --y1;
    --x2;
    --y2;
    bfs(x1,y1,x2,y2);
}