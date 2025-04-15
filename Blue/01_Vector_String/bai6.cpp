#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int n;
    cin>>n;
    vector<pii>v(n);
    int ans = -1;
    int min_x= MOD;
    int min_y = 0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(min_x > x) {
            min_x = x;
        }
        if(min_y < y) {
            min_y = y;
        }
        v[i] = make_pair(x, y);
    }
    for(int i=0;i<n;i++){
        if(v[i].first <= min_x && v[i].second >= min_y){
            ans=i+1;
        }
    }
    cout<<ans;
}