#include<bits/stdc++.h>
using namespace std;

// Slick - Spoj

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
int n,m;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

int a[255][255];
int ans[255 * 255] = {0};

void bfs (int i,int j) {
    int cnt = 1;
    queue<pii> q;
    q.push({i,j});
    a[i][j] = 0;
    
    while(!q.empty()) {
        pii top = q.front();
        q.pop();
        for(int k=0;k<4;k++) {
            int x = top.first+dx[k];
            int y = top.second+dy[k];
            if(x>=0 && x<n && y>=0 && y<m&& a[x][y]==1) {
                q.push({x,y});
                a[x][y]=0;
                cnt++;
            }
        }
    }
    ans[cnt]++;
}
int main(){
    while(true) {
        cin >> n >> m;
        if(n==0 && m==0) break;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>a[i][j];
            }
        }
        ms(ans,0);
        int dem=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j]==1){ 
                    dem++;
                    bfs(i,j);
                }
            }
        }
        cout<<dem<<endl;
        for(int i=0;i<=n * m;i++) {
            if(ans[i]!=0){
                cout<<i<<" "<<ans[i]<<endl;
            }
        }
    }
}
