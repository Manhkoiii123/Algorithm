#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<ll>v;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<ll>());
    ll P = v[a-1];
    ll V = v[a];
    cout<<P-V;
}

