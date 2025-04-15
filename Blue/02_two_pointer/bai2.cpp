#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
#define ms(s,n) memset(s,n,sizeof(s))
const int MOD = (int)(1e9+7);

int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    };
    for(int i=0;i<m;i++){
         cin>>b[i];
    }
    int i=0,j=0;
    while(i<n && j<m) {
        if(a[i] > b[j]){
            ++j;
        }else {
            ++i;
            ++j;
        }
    }
    cout<<n-i;
}
