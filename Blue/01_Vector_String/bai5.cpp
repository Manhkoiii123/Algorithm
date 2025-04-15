#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int na,nb,k,m;
    cin>>na>>nb>>k>>m;
    int a[na],b[nb];
    for(int i=0;i<na;i++) cin>>a[i];
    for(int i=0;i<nb;i++) cin>>b[i];
    if(a[k - 1] < b[nb-m]) {
        cout<<"YES";
    }
    else cout<<"NO";
}