#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);
int n,m;
char arr[25][25];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int vis[25][25];
int ans = 0;
void nhap(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
}

void bfs(pii a,pii b){
    int s = a.first;
    int t = a.second;
    int u =  b.first;
    int v = b.second;
    queue<pii>q;
    q.push({s,t});
    vis[s][t] = 1;
    while(!q.empty()) {
        pii f = q.front();
        q.pop();
        int x = f.first;
        int y = f.second;
        if(x == u && y == v) {
            cout<<"valid"<<endl;
            return;
        }
        for(int i=0;i<4;i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
           if(xx >=0 && xx <n && yy >= 0 && yy < m && arr[xx][yy] == '.' && vis[xx][yy] == 0) {
                q.push({xx,yy});
                vis[xx][yy] = 1;
           }
        }
    }
    cout<<"invalid"<<endl;
}
int main(){
   int t;
   cin>>t;
   while(t--) {
    ans = 0;
    nhap();
    ms(vis,0);
    int cnt = 0;
    vector<pii>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0||j==0||i==n-1||j==m-1)&&arr[i][j]=='.'){
                v.push_back({i,j});
                ms(vis,0);
                cnt++;
            }
        }
    }
    // chỉ có 2 ô bên rìa được cứng
    if(cnt !=2) {
        cout<<"invalid"<<endl;
    }else{
        bfs(v[0],v[1]);
    }
   }
}

// hướng tiếp cận khác hay hơn  =>(do đề yêu cầu chỉ có 2 điểm đó thì mới thỏa mãn) tìm 2 điểm (x_start,y_start),(x_end,y_end) là 2 điểm trên cạnh và là 2 điểm duy nhất trên ma trận có i=0||j=0
// tìm đường đi trên 2 cái điểm đó => nếu có đường thì in valid, nếu ko có đường thì in invalid

