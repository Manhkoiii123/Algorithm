#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll ans =1ll* x * a[0];
    
    for(int i=1;i<n;i++) {
        x--;
        if(x < 1) x=1;
        ans += 1ll * x * a[i];
    }
    cout<<ans;
}