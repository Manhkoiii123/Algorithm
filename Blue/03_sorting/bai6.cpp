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
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(all(v));
    int len = 0;
    int cnt = 0;
    int j=0;
    for(int i=0;i<n;i++){
        if(v[i] != v[i+1]) {
            cnt++;
            len = max(len, i-j+1);
            j = i+1;
        }
    }
    cout<<len<<" "<<cnt;
}